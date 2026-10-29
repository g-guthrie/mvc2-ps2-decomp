/*
 * CRI middleware at its API (Port J): ADXF (AFS / disc reads) and ADXT
 * (ADX music), plus the CRI file-system and server entry points the game's
 * glue calls (func_00418910, func_00418B80, func_004189A0, func_00418B10,
 * func_003ECBE0).  CRI's own internals (CVFS, DVCI/HTCI, SRD, SJ, DTX/DTR,
 * PS2RNA, SVM, LSC) are never reached.
 *
 * ADXF reads come from the user's disc image through port/platform/fs.c and
 * complete immediately: ADXF_ReadNw fills the buffer and ADXF_GetStat then
 * answers READEND (3), which is a state the game's loaders already handle
 * (func_0012DA40, func_0012DF30).  Partitions: ptid 0..3 = /PS2/AFS00..03.AFS.
 *
 * ADXT keeps CRI's status values (0 STOP .. 5 PLAYEND).  Without a frontend
 * it is a state machine only (StartAfs -> PREP, next server tick -> PLAYING);
 * the frontend plugs the port's ADX player in through host_adxt_ops.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "host.h"
#include "fs.h"
#include "host_cri.h"

static GameDisc disc;
static int disc_ok;
const HostAdxtOps *host_adxt_ops;

int host_disc_open(const char *iso_path)
{
    int i;
    if (disc_ok)
        disc_close(&disc);
    disc_ok = disc_open(&disc, iso_path) == 0;
    if (!disc_ok) {
        host_log("cannot open the disc image %s", iso_path);
        return -1;
    }
    for (i = 0; i < 4; i++)
        if (!disc.afs_ok[i])
            host_log("disc: AFS0%d missing", i);
    host_log("disc: %s (%d files, AFS02 %d entries)", iso_path, disc.iso.n_files, disc.afs[2].count);
    return 0;
}

int host_disc_open_source(FsSource src)
{
    if (disc_ok)
        disc_close(&disc);
    disc_ok = disc_open_source(&disc, src) == 0;
    return disc_ok ? 0 : -1;
}

GameDisc *host_disc(void)
{
    return disc_ok ? &disc : 0;
}

/* ---- ADXF -------------------------------------------------------------- */
typedef struct HostAdxf {
    int used;
    const IsoFile *loose; /* loose ISO file, or */
    const Afs *afs;       /* an AFS entry */
    int index;
    uint64_t base;        /* absolute offset in the image */
    uint32_t size;
    int stat;             /* 1 STOP, 2 READING, 3 READEND, 4 ERROR */
    int nread;            /* sectors read so far */
} HostAdxf;

#define MAX_ADXF 64
static HostAdxf adxf[MAX_ADXF];
static int pt_stat[4];

static HostAdxf *adxf_new(void)
{
    int i;
    for (i = 0; i < MAX_ADXF; i++)
        if (!adxf[i].used) {
            memset(&adxf[i], 0, sizeof adxf[i]);
            adxf[i].used = 1;
            adxf[i].stat = 1;
            return &adxf[i];
        }
    host_log("ADXF: out of handles");
    return 0;
}

/* ADXF_LoadPartitionNw(ptid, fname, dir, ptinfo) */
int func_003FBE88(int ptid, int fname, int dir, void *ptinfo)
{
    (void)dir; (void)ptinfo;
    if (ptid < 0 || ptid > 3 || !disc_ok || !disc.afs_ok[ptid]) {
        host_log("ADXF_LoadPartitionNw(%d, %s): no such partition on the disc", ptid,
                 fname ? (const char *)(uintptr_t)fname : "?");
        if (ptid >= 0 && ptid < 4)
            pt_stat[ptid] = 4;
        return -1;
    }
    pt_stat[ptid] = 3;
    if (host_verbose)
        host_log("ADXF_LoadPartitionNw(%d, %s): %d entries", ptid, (const char *)(uintptr_t)fname,
                 disc.afs[ptid].count);
    return 0;
}

int func_003FC090(int ptid) /* ADXF_GetPtStat */
{
    return (ptid >= 0 && ptid < 4) ? pt_stat[ptid] : 4;
}

static HostAdxf *open_afs(int ptid, int fid)
{
    HostAdxf *h;
    const Afs *a;
    if (!disc_ok || ptid < 0 || ptid > 3 || !disc.afs_ok[ptid])
        return 0;
    a = &disc.afs[ptid];
    if (fid < 0 || fid >= a->count)
        return 0;
    if (!(h = adxf_new()))
        return 0;
    h->afs = a;
    h->index = fid;
    h->base = (uint64_t)a->file.lba * 2048u + a->entries[fid].offset;
    h->size = a->entries[fid].size;
    return h;
}

int func_003FCBC0(int ptid, int fid) /* ADXF_OpenAfs (locked) */
{
    HostAdxf *h = open_afs(ptid, fid);
    if (host_verbose)
        host_log("ADXF_OpenAfs(%d, %d) %s %u bytes", ptid, fid,
                 h && h->afs->entries[fid].name[0] ? h->afs->entries[fid].name : "", h ? h->size : 0);
    return (int)(uintptr_t)h;
}

int func_003FCA60(int fname, int dir) /* ADXF_Open (locked) */
{
    const char *name = (const char *)(uintptr_t)fname;
    char path[128];
    const IsoFile *f;
    HostAdxf *h;
    int i;
    (void)dir;
    if (!disc_ok || !name)
        return 0;
    snprintf(path, sizeof path, "%s%s", name[0] == '/' || name[0] == '\\' ? "" : "/", name);
    for (i = 0; path[i]; i++)
        if (path[i] == '\\')
            path[i] = '/';
    f = iso_find(&disc.iso, path);
    if (!f) {
        snprintf(path, sizeof path, "/PS2/%s", name);
        f = iso_find(&disc.iso, path);
    }
    if (f) {
        if (!(h = adxf_new()))
            return 0;
        h->loose = f;
        h->base = (uint64_t)f->lba * 2048u;
        h->size = f->size;
    } else {
        /* the game's name table (D_0043CDA0) is AFS02's: open it by name there */
        i = disc.afs_ok[2] ? afs_find(&disc.afs[2], name) : -1;
        h = i >= 0 ? open_afs(2, i) : 0;
    }
    if (host_verbose || !h)
        host_log("ADXF_Open(%s) %s", name, h ? "ok" : "not found");
    return (int)(uintptr_t)h;
}

void func_003FCCF0(void *p) /* ADXF_Close */
{
    HostAdxf *h = (HostAdxf *)p;
    if (h && h >= adxf && h < adxf + MAX_ADXF)
        h->used = 0;
}

int func_003FD450(void *p) /* ADXF_GetFsizeSct */
{
    HostAdxf *h = (HostAdxf *)p;
    return h ? (int)((h->size + 2047u) / 2048u) : 0;
}

/* ADXF_ReadNw(adxf, nsct, buf): whole sectors, as the PS2 read them.
 * The tail of the last sector past the file end is read from the image too
 * (what DVCI's sector reads put there). */
int func_003FD0F8(int p, int nsct, int buf)
{
    HostAdxf *h = (HostAdxf *)(uintptr_t)p;
    size_t want, got;
    if (!h || !buf || nsct <= 0) {
        if (h)
            h->stat = 4;
        return 0;
    }
    want = (size_t)nsct * 2048u;
    got = disc.iso.src.read_at(disc.iso.src.ctx, h->base + (uint64_t)h->nread * 2048u,
                               (void *)(uintptr_t)buf, want);
    if (got < want)
        memset((u8 *)(uintptr_t)buf + got, 0, want - got);
    h->nread += nsct;
    h->stat = 3;
    return nsct;
}

int func_003FD530(void *p) /* ADXF_GetStat */
{
    HostAdxf *h = (HostAdxf *)p;
    return h ? h->stat : 4;
}

/* ---- CRI system / file-system setup: nothing to do on the host ----- */
void func_003FDAA0(void) {}                      /* ADXT_Init */
void func_003FE5D8(void *p) { (void)p; }         /* SVM / server setup */
int func_003FE9E8(int a) { (void)a; return 0; }  /* vsync server */
void func_00400D18(int a) { (void)a; }
void func_00400D38(void *p) { (void)p; }         /* DVCI CD/DVD file system */
int func_00400DE0(void *p) { (void)p; return 1; }/* DVCI cache (0flist.dir) */
void func_00400F08(void *p) { (void)p; }         /* cvFsInit */
int func_00402818(void *f, void *o) { (void)f; (void)o; return 0; } /* ADXERR_EntryErrFunc */
int func_0010F148(int mode) { (void)mode; return 0; } /* sceCdSync: idle */

/* ---- ADXT ---------------------------------------------------------------- */
static struct {
    int created, stat, paused, vol, mono, ptid, fid, ticks;
} adxt;

void *func_00401150(int maxch, int work, int worksize) /* ADXT_Create */
{
    (void)maxch; (void)work; (void)worksize;
    adxt.created = 1;
    adxt.stat = 0;
    return &adxt;
}

void func_00402208(void *a, int nsct) { (void)a; (void)nsct; } /* ADXT_SetReloadSct */
void func_00402458(void *a, int mode) { (void)a; (void)mode; } /* stall-recovery mode */

void func_00402C20(void *a, int ptid, int fid) /* ADXT_StartAfs */
{
    (void)a;
    adxt.ptid = ptid;
    adxt.fid = fid;
    adxt.ticks = 0;
    if (host_adxt_ops && host_adxt_ops->start_afs) {
        host_adxt_ops->start_afs(ptid, fid);
        return;
    }
    adxt.stat = 2;
}

void func_00401868(void *a) /* ADXT_Stop */
{
    (void)a;
    if (host_adxt_ops && host_adxt_ops->stop)
        host_adxt_ops->stop();
    adxt.stat = 0;
}

int func_00401920(void *a) /* ADXT_GetStat */
{
    (void)a;
    if (host_adxt_ops && host_adxt_ops->get_stat)
        return host_adxt_ops->get_stat();
    return adxt.stat;
}

void func_004020D8(void *a, int vol) /* ADXT_SetOutVol */
{
    (void)a;
    adxt.vol = vol;
    if (host_adxt_ops && host_adxt_ops->set_out_vol)
        host_adxt_ops->set_out_vol(vol);
}

void func_004026B0(void *a, int sw) /* ADXT_Pause */
{
    (void)a;
    adxt.paused = sw;
    if (host_adxt_ops && host_adxt_ops->pause)
        host_adxt_ops->pause(sw);
}

void func_00402BC0(int mono) /* ADXT_SetOutputMono */
{
    adxt.mono = mono;
    if (host_adxt_ops && host_adxt_ops->set_mono)
        host_adxt_ops->set_mono(mono);
}

void func_00402498(void) /* ADXT_ExecServer (once per frame) */
{
    if (host_adxt_ops && host_adxt_ops->exec) {
        host_adxt_ops->exec();
        return;
    }
    if (adxt.stat == 2 && ++adxt.ticks >= 2)
        adxt.stat = 3;
}

/* ADXM / SVM server exec: the game's synchronous loaders spin on these
 * (func_0012DA40 waits for the ADXT handle to leave PREP) while the main
 * loop's ADXT_ExecServer does not run; on the PS2 the ADX server thread
 * kept running, so advance the ADXT state here as well. */
int func_003FEAD0(void)
{
    func_00402498();
    return 0;
}

int func_003FEBD8(void)
{
    return 0;
}
