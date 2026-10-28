#define _POSIX_C_SOURCE 200809L
#define _FILE_OFFSET_BITS 64
#include "fs.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SECTOR 2048u

static uint32_t rd32(const uint8_t *p) { return p[0] | p[1] << 8 | p[2] << 16 | (uint32_t)p[3] << 24; }

/* ---- sources ---- */
static size_t file_read_at(void *ctx, uint64_t off, void *dst, size_t n)
{
    FILE *f = (FILE *)ctx;
#if defined(_WIN32)
    if (_fseeki64(f, (long long)off, SEEK_SET)) return 0;
#else
    if (fseeko(f, (off_t)off, SEEK_SET)) return 0;
#endif
    return fread(dst, 1, n, f);
}
static void file_close(void *ctx) { fclose((FILE *)ctx); }

int fs_source_open_file(FsSource *src, const char *path)
{
    FILE *f = fopen(path, "rb");
    if (!f) return -1;
    fseeko(f, 0, SEEK_END);
    src->size = (uint64_t)ftello(f);
    src->ctx = f;
    src->read_at = file_read_at;
    src->close = file_close;
    return 0;
}

typedef struct { const uint8_t *p; size_t n; } MemSrc;
static size_t mem_read_at(void *ctx, uint64_t off, void *dst, size_t n)
{
    MemSrc *m = (MemSrc *)ctx;
    if (off >= m->n) return 0;
    if (n > m->n - off) n = (size_t)(m->n - off);
    memcpy(dst, m->p + off, n);
    return n;
}
static void mem_close(void *ctx) { free(ctx); }

void fs_source_memory(FsSource *src, const void *data, size_t size)
{
    MemSrc *m = (MemSrc *)malloc(sizeof *m);
    m->p = (const uint8_t *)data;
    m->n = size;
    src->ctx = m;
    src->read_at = mem_read_at;
    src->close = mem_close;
    src->size = size;
}

void fs_source_close(FsSource *src)
{
    if (src->close) src->close(src->ctx);
    memset(src, 0, sizeof *src);
}

/* ---- ISO9660 ---- */
static int iso_sectors(const Iso *iso, uint32_t lba, uint32_t n, uint8_t *dst)
{
    size_t want = (size_t)n * SECTOR;
    return iso->src.read_at(iso->src.ctx, (uint64_t)lba * SECTOR, dst, want) == want ? 0 : -1;
}

static void iso_add(Iso *iso, const char *path, uint32_t lba, uint32_t size)
{
    if (iso->n_files == iso->cap_files) {
        iso->cap_files = iso->cap_files ? iso->cap_files * 2 : 64;
        iso->files = (IsoFile *)realloc(iso->files, sizeof(IsoFile) * iso->cap_files);
    }
    IsoFile *f = &iso->files[iso->n_files++];
    snprintf(f->path, sizeof f->path, "%s", path);
    for (char *c = f->path; *c; c++) *c = (char)toupper((unsigned char)*c);
    f->lba = lba;
    f->size = size;
}

static int iso_walk(Iso *iso, uint32_t lba, uint32_t size, const char *prefix, int depth)
{
    if (depth > 8) return -1;
    uint32_t ns = (size + SECTOR - 1) / SECTOR;
    uint8_t *data = (uint8_t *)malloc((size_t)ns * SECTOR);
    if (!data || iso_sectors(iso, lba, ns, data)) { free(data); return -1; }
    size_t p = 0, total = (size_t)ns * SECTOR;
    while (p < total) {
        uint8_t ln = data[p];
        if (ln == 0) { p = (p / SECTOR + 1) * SECTOR; continue; } /* records never straddle sectors */
        if (p + 33 > total) break;
        uint32_t ext = rd32(data + p + 2), sz = rd32(data + p + 10);
        uint8_t flags = data[p + 25], nl = data[p + 32];
        const uint8_t *name = data + p + 33;
        p += ln;
        if (nl == 1 && (name[0] == 0 || name[0] == 1)) continue;
        char nm[64], full[96];
        int k;
        for (k = 0; k < nl && k < 63 && name[k] != ';'; k++) nm[k] = (char)name[k];
        nm[k] = 0;
        snprintf(full, sizeof full, "%s/%s", prefix, nm);
        if (flags & 2) iso_walk(iso, ext, sz, full, depth + 1);
        else iso_add(iso, full, ext, sz);
    }
    free(data);
    return 0;
}

int iso_open(Iso *iso, FsSource src)
{
    uint8_t pvd[SECTOR];
    memset(iso, 0, sizeof *iso);
    iso->src = src;
    if (iso_sectors(iso, 16, 1, pvd) || memcmp(pvd + 1, "CD001", 5)) {
        fs_source_close(&iso->src);
        return -1;
    }
    const uint8_t *root = pvd + 156;
    return iso_walk(iso, rd32(root + 2), rd32(root + 10), "", 0);
}

void iso_close(Iso *iso)
{
    fs_source_close(&iso->src);
    free(iso->files);
    memset(iso, 0, sizeof *iso);
}

static int ieq(const char *a, const char *b)
{
    for (; *a && *b; a++, b++)
        if (toupper((unsigned char)*a) != toupper((unsigned char)*b)) return 0;
    return *a == *b;
}

const IsoFile *iso_find(const Iso *iso, const char *path)
{
    for (int i = 0; i < iso->n_files; i++)
        if (ieq(iso->files[i].path, path)) return &iso->files[i];
    return NULL;
}

size_t iso_read(const Iso *iso, const IsoFile *f, uint64_t off, void *dst, size_t n)
{
    if (off >= f->size) return 0;
    if (n > f->size - off) n = (size_t)(f->size - off);
    return iso->src.read_at(iso->src.ctx, (uint64_t)f->lba * SECTOR + off, dst, n);
}

uint8_t *iso_load(const Iso *iso, const char *path, size_t *size_out)
{
    const IsoFile *f = iso_find(iso, path);
    if (!f) return NULL;
    uint8_t *buf = (uint8_t *)malloc(f->size ? f->size : 1);
    if (!buf || iso_read(iso, f, 0, buf, f->size) != f->size) { free(buf); return NULL; }
    if (size_out) *size_out = f->size;
    return buf;
}

/* ---- AFS ----
 * "AFS\0", u32 count, count x {u32 offset, u32 size}, then {u32 nameOfs, u32 nameSize}.
 * Name table (AFS02 only): 48-byte entries {char name[32]; u16 date[6]; u32 size}. */
int afs_open(Afs *afs, const Iso *iso, int ptid)
{
    char path[32];
    uint8_t hdr[8];
    memset(afs, 0, sizeof *afs);
    snprintf(path, sizeof path, "/PS2/AFS%02d.AFS", ptid);
    const IsoFile *f = iso_find(iso, path);
    if (!f) return -1;
    afs->iso = iso;
    afs->file = *f;
    afs->ptid = ptid;
    if (iso_read(iso, f, 0, hdr, 8) != 8 || memcmp(hdr, "AFS\0", 4)) return -1;
    uint32_t n = rd32(hdr + 4);
    if (n > 65536) return -1;
    uint8_t *tab = (uint8_t *)malloc(8 * ((size_t)n + 1));
    if (iso_read(iso, f, 8, tab, 8 * ((size_t)n + 1)) != 8 * ((size_t)n + 1)) { free(tab); return -1; }
    afs->entries = (AfsEntry *)calloc(n ? n : 1, sizeof(AfsEntry));
    afs->count = (int)n;
    for (uint32_t i = 0; i < n; i++) {
        afs->entries[i].offset = rd32(tab + 8 * i);
        afs->entries[i].size = rd32(tab + 8 * i + 4);
    }
    uint32_t nt_off = rd32(tab + 8 * n), nt_size = rd32(tab + 8 * n + 4);
    free(tab);
    if (nt_off && nt_size >= 48 * n) {
        uint8_t *nt = (uint8_t *)malloc(nt_size);
        if (iso_read(iso, f, nt_off, nt, nt_size) == nt_size)
            for (uint32_t i = 0; i < n; i++) {
                memcpy(afs->entries[i].name, nt + 48 * i, 32);
                afs->entries[i].name[32] = 0;
            }
        free(nt);
    }
    return 0;
}

void afs_close(Afs *afs)
{
    free(afs->entries);
    memset(afs, 0, sizeof *afs);
}

int afs_find(const Afs *afs, const char *name)
{
    for (int i = 0; i < afs->count; i++)
        if (ieq(afs->entries[i].name, name)) return i;
    return -1;
}

uint8_t *afs_load(const Afs *afs, int index, size_t *size_out)
{
    if (index < 0 || index >= afs->count) return NULL;
    const AfsEntry *e = &afs->entries[index];
    uint8_t *buf = (uint8_t *)malloc(e->size + 16); /* +16: LZ decoders may over-read */
    if (!buf) return NULL;
    if (iso_read(afs->iso, &afs->file, e->offset, buf, e->size) != e->size) { free(buf); return NULL; }
    memset(buf + e->size, 0, 16);
    if (size_out) *size_out = e->size;
    return buf;
}

/* ---- disc ---- */
int disc_open_source(GameDisc *d, FsSource src)
{
    memset(d, 0, sizeof *d);
    if (iso_open(&d->iso, src)) return -1;
    int any = 0;
    for (int i = 0; i < 4; i++) {
        d->afs_ok[i] = afs_open(&d->afs[i], &d->iso, i) == 0;
        any |= d->afs_ok[i];
    }
    return any ? 0 : -1;
}

int disc_open(GameDisc *d, const char *iso_path)
{
    FsSource s;
    if (fs_source_open_file(&s, iso_path)) return -1;
    return disc_open_source(d, s);
}

void disc_close(GameDisc *d)
{
    for (int i = 0; i < 4; i++) afs_close(&d->afs[i]);
    iso_close(&d->iso);
}

uint8_t *disc_load(GameDisc *d, int ptid, int index, size_t *size_out)
{
    if (ptid < 0 || ptid > 3 || !d->afs_ok[ptid]) return NULL;
    return afs_load(&d->afs[ptid], index, size_out);
}
