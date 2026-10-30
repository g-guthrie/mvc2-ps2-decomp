/*
 * "Arcade accuracy" option (port/docs/ARCADE_DIFF.md section 5).
 *
 * The user's own NAOMI `mvsc2.zip` (MAME set, Export/Korea Rev A) is read at
 * run time; nothing from it is in the repository or in the public build.
 * After func_0016F2D0 binds a character's PS2 PAK (func_0016F1B0), the
 * player's table pointers are repointed to tables built from the NAOMI files
 * for that character:
 *
 *   (a) frames + boxes   +0x178 TBL, +0x17C HIT, +0x180 HIT_FM, +0x142 top table
 *   (b) damage / hit     +0x184 HIT_DT (padded to 128 x 28 bytes, as PS2)
 *   (c) CPU AI           +0x198 TAIKI, +0x19C ATCK, +0x1A0 WARI, +0x1A4 YOK, +0x1A8 LIB
 *
 * Options (all off by default):
 *   MVC2_ARCADE=abc        any of the letters a, b, c ("all" = abc); app: --arcade abc
 *   MVC2_NAOMI=PATH        the zip (web default /mvsc2.zip); app: --naomi PATH
 *   MVC2_ARCADE_TRACE=1    log every player animation script run (frames,
 *                          ticks) and every hit (base damage, health); app: --arcade-trace
 *
 * TBL (a): the NAOMI file is used as is, so its own offsets and gotos stay
 * valid.  Its top table is rewritten to point at new group arrays (each as
 * long as the longer of the NAOMI and PS2 arrays), and a copy of the PS2 TBL
 * is appended.  A (group, strength) entry falls back to the PS2 script when
 * NAOMI has none (PS2-only variants: Sentinel's regrouped set, extra PS2
 * moves the PS2 code may start), when a displayed NAOMI frame's sprite is
 * not in the PS2 sprite bank, or when the NAOMI chain has a goto outside the
 * file (Ryu 0b/00).  Fallback chains are relocated (gotos + the appended PS2
 * HIT selections); their rect indices are u8 in several readers, so they use
 * the NAOMI rect table (the count of fallback frames whose rects differ is
 * logged).  +0x142 = the NAOMI top-table offset found by the tool's scan
 * (0x100 for all 59, Sentinel too).
 *
 * arcade_hash(): FNV-1a 64 over the toggles and every NAOMI table they
 * select (all 59 characters), for a future netplay handshake.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "host.h"
#include "inflate.h"

#define A_FRAMES 1
#define A_DAMAGE 2
#define A_AI 4

int mvc2_arcade_flags;      /* A_* requested (settings arcade.* via fe_arcade.c, or MVC2_ARCADE) */
int mvc2_arcade_trace;
static int arc_ok;          /* NAOMI tables loaded */
static unsigned long long arc_hash;

/* ---------------------------------------------------------------- the ROM set */
static const struct { const char *name; u32 size, crc; } ROMS[] = {
    {"epr-23085a.ic11", 0x400000, 0x5d5b7ad1}, {"mpr-23048.ic17s", 0x800000, 0x93d7a63a},
    {"mpr-23049.ic18", 0x800000, 0x003dcce0},  {"mpr-23050.ic19s", 0x800000, 0x1d6b88a7},
    {"mpr-23051.ic20", 0x800000, 0x01226aaa},  {"mpr-23052.ic21s", 0x800000, 0x74bee120},
    {"mpr-23053.ic22", 0x800000, 0xd92d4401},  {"mpr-23054.ic23s", 0x800000, 0x78ba02e8},
    {"mpr-23055.ic24", 0x800000, 0x84319604},  {"mpr-23056.ic25s", 0x800000, 0xd7386034},
    {"mpr-23057.ic26", 0x800000, 0xa3f087db},  {"mpr-23058.ic27s", 0x800000, 0x61a6cc5d},
    {"mpr-23059.ic28", 0x800000, 0x64808024},  {"mpr-23060.ic29", 0x800000, 0x67519942},
    {"mpr-23061.ic30s", 0x800000, 0xfb1844c4}, {"mpr-23083.ic31", 0x400000, 0xc61d2dfe},
    {"mpr-23084.ic32s", 0x400000, 0x4ebbbdd9},
};
#define N_ROMS ((int)(sizeof ROMS / sizeof ROMS[0]))
#define ROM_PROGRAM 0       /* file table at cart 0x2085D4 */
#define ROM_TABLES 11       /* every per-character table file lives in this mask ROM */
#define FTAB_OFF 0x2085D4u
#define FTAB_N 787

enum { G_TBL, G_HIT, G_FM, G_DT, G_TAIKI, G_ATCK, G_WARI, G_YOK, G_LIB, G_N };
static const int G_BASE[G_N] = {256, 315, 374, 433, 492, 551, 610, 669, 728}; /* PS2 AFS02 id - 12 */
static const char *const G_NAME[G_N] = {"TBL", "HIT", "HIT_FM", "HIT_DT", "TAIKI", "ATCK", "WARI", "YOK", "LIB"};
static struct { u8 *p; u32 n; } NF[59][G_N];

static u32 rd32(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static u16 rd16(const u8 *p) { return (u16)(p[0] | p[1] << 8); }
static void wr32(u8 *p, u32 v) { p[0] = (u8)v; p[1] = (u8)(v >> 8); p[2] = (u8)(v >> 16); p[3] = (u8)(v >> 24); }
static void wr16(u8 *p, u16 v) { p[0] = (u8)v; p[1] = (u8)(v >> 8); }

static int zip_member(FILE *f, long cd_off, long cd_n, const char *want, u8 **out, u32 *crc_cd, u32 *usize)
{
    u8 h[46], lh[30];
    char nm[64];
    long o = cd_off;
    for (long i = 0; i < cd_n; i++) {
        u32 nl, el, cl, csz, lo;
        if (fseek(f, o, SEEK_SET) || fread(h, 1, 46, f) != 46 || rd32(h) != 0x02014b50u)
            return -1;
        nl = rd16(h + 28); el = rd16(h + 30); cl = rd16(h + 32);
        csz = rd32(h + 20); lo = rd32(h + 42);
        if (nl < sizeof nm && fread(nm, 1, nl, f) == nl) {
            nm[nl] = 0;
            if (!strcmp(nm, want)) {
                u8 *cbuf;
                *crc_cd = rd32(h + 16);
                *usize = rd32(h + 24);
                if (!out)
                    return 0;
                if (fseek(f, (long)lo, SEEK_SET) || fread(lh, 1, 30, f) != 30 || rd32(lh) != 0x04034b50u)
                    return -1;
                if (fseek(f, (long)lo + 30 + rd16(lh + 26) + rd16(lh + 28), SEEK_SET))
                    return -1;
                cbuf = (u8 *)malloc(csz ? csz : 1);
                *out = (u8 *)malloc(*usize);
                if (!cbuf || !*out || fread(cbuf, 1, csz, f) != csz) {
                    free(cbuf);
                    return -1;
                }
                if (rd16(h + 10) == 0 && csz == *usize)
                    memcpy(*out, cbuf, csz);
                else if (rd16(h + 10) != 8 || host_inflate(*out, *usize, cbuf, csz) != (long)*usize) {
                    free(cbuf);
                    return -1;
                }
                free(cbuf);
                return 0;
            }
        }
        o += 46 + nl + el + cl;
    }
    return 1; /* absent */
}

static int load_naomi(const char *path)
{
    FILE *f = fopen(path, "rb");
    u8 tail[22];
    long sz, cd_off = 0, cd_n = 0, i;
    u8 *prog = NULL, *tabs = NULL;
    u32 crc, us;
    int r = -1, c, g;
    if (!f) {
        host_log("arcade: cannot open %s (the NAOMI set mvsc2.zip)", path);
        return -1;
    }
    fseek(f, 0, SEEK_END);
    sz = ftell(f);
    /* end of central directory (no archive comment in MAME sets; scan 64 KB back) */
    for (i = sz - 22; i >= 0 && i >= sz - 65557; i--) {
        if (fseek(f, i, SEEK_SET) || fread(tail, 1, 22, f) != 22)
            break;
        if (rd32(tail) == 0x06054b50u) {
            cd_n = rd16(tail + 10);
            cd_off = (long)rd32(tail + 16);
            break;
        }
    }
    if (!cd_n) {
        host_log("arcade: %s is not a zip", path);
        goto done;
    }
    /* every listed member that is present must be the Rev A one */
    for (i = 0; i < N_ROMS; i++) {
        int k = zip_member(f, cd_off, cd_n, ROMS[i].name, NULL, &crc, &us);
        if (k == 0 && (crc != ROMS[i].crc || us != ROMS[i].size)) {
            host_log("arcade: %s: %s has CRC %08x size %u, expected %08x (mvsc2 Rev A)", path,
                     ROMS[i].name, crc, us, ROMS[i].crc);
            goto done;
        }
        if (k < 0)
            goto bad;
    }
    if (zip_member(f, cd_off, cd_n, ROMS[ROM_PROGRAM].name, &prog, &crc, &us) ||
        zip_member(f, cd_off, cd_n, ROMS[ROM_TABLES].name, &tabs, &crc, &us)) {
        host_log("arcade: %s lacks %s or %s", path, ROMS[ROM_PROGRAM].name, ROMS[ROM_TABLES].name);
        goto done;
    }
    if (host_crc32(0, prog, ROMS[ROM_PROGRAM].size) != ROMS[ROM_PROGRAM].crc ||
        host_crc32(0, tabs, ROMS[ROM_TABLES].size) != ROMS[ROM_TABLES].crc)
        goto bad;
    for (c = 0; c < 59; c++)
        for (g = 0; g < G_N; g++) {
            const u8 *e = prog + FTAB_OFF + 8 * (u32)(G_BASE[g] + c);
            u32 o = rd32(e), n = rd32(e + 4), lo = 0x800000u * ROM_TABLES;
            if (o < lo || n == 0 || n > 0x100000 || o + n > lo + 0x800000u) {
                host_log("arcade: file %d (%s %02x) at %#x+%#x is not in %s", G_BASE[g] + c, G_NAME[g], c,
                         o, n, ROMS[ROM_TABLES].name);
                goto done;
            }
            NF[c][g].p = (u8 *)malloc(n);
            NF[c][g].n = n;
            memcpy(NF[c][g].p, tabs + (o - lo), n);
        }
    r = 0;
    goto done;
bad:
    host_log("arcade: %s: unreadable or corrupt member", path);
done:
    free(prog);
    free(tabs);
    fclose(f);
    return r;
}

static unsigned long long fnv(unsigned long long h, const u8 *p, u32 n)
{
    while (n--)
        h = (h ^ *p++) * 0x100000001b3ull;
    return h;
}

unsigned long long arcade_hash(void) { return arc_hash; }
int arcade_active(void) { return arc_ok ? mvc2_arcade_flags : 0; }

/* ---------------------------------------------------------------- TBL parsing (port/tools/arcade_diff.py) */
static int find_top(const u8 *b, u32 n)
{
    for (u32 t = 0x100; t + 64 * 4 < n; t += 4) {
        u32 w[48], f = 0xFFFFFFFFu, k, i;
        for (i = 0; i < 48; i++) {
            w[i] = rd32(b + t + 4 * i);
            if (w[i] && w[i] < f)
                f = w[i];
        }
        if (f == 0xFFFFFFFFu || w[0] == 0 || f <= t || (f - t) % 4 || (f - t) / 4 > 48)
            continue;
        k = (f - t) / 4;
        if (k < 20)
            continue;
        for (i = 0; i < k; i++)
            if (w[i] && !(w[i] >= f && w[i] < n))
                break;
        if (i == k)
            return (int)t;
    }
    return -1;
}

typedef struct {
    int top, ng;
    u32 goff[64];
    int glen[64];
} Tbl;

static int parse_tbl(const u8 *b, u32 n, Tbl *T)
{
    u32 first = 0xFFFFFFFFu;
    int i;
    memset(T, 0, sizeof *T);
    T->top = find_top(b, n);
    if (T->top < 0)
        return -1;
    for (i = 0; i < 64; i++) {
        u32 v = rd32(b + T->top + 4 * i);
        if (v > (u32)T->top && v < first)
            first = v;
    }
    T->ng = (int)(first - (u32)T->top) / 4;
    for (i = 0; i < T->ng; i++)
        T->goff[i] = rd32(b + T->top + 4 * i);
    for (i = 0; i < T->ng; i++) {
        u32 g = T->goff[i];
        int k = 0, j;
        if (!g)
            continue;
        while (k <= 64) {
            u32 o = g + 4 * (u32)k, v;
            int stop = 0;
            if (k)
                for (j = 0; j < T->ng; j++)
                    if (T->goff[j] == o)
                        stop = 1;
            if (stop || o + 4 > n)
                break;
            v = rd32(b + o);
            if (v && !(v >= first && v < n))
                break;
            k++;
        }
        T->glen[i] = k;
    }
    return 0;
}

static u32 tbl_script(const u8 *b, const Tbl *T, int g, int s)
{
    if (g >= T->ng || !T->goff[g] || s >= T->glen[g])
        return 0;
    return rd32(b + T->goff[g] + 4 * (u32)s);
}

static int glen_max(const Tbl *a, const Tbl *b, int g)
{
    int la = g < a->ng ? a->glen[g] : 0, lb = g < b->ng ? b->glen[g] : 0;
    return la > lb ? la : lb;
}

/* 8-byte records (func_001754A0 / func_00175670: groups 0x1B, 0x1C), 20-byte
 * records (func_001757E0: player code starts groups 0x00..0x1A) */
static int rec_size(int g) { return g == 0x1B || g == 0x1C ? 8 : 20; }

/* walk a chain the way func_00175700 does: 0 = every record's selection is
 * in the HIT table, every displayed frame's sprite is in the PS2 bank and the
 * chain ends in an aligned in-file goto; -1 = not such a chain; -2 = sprite */
static int chain_check(const u8 *b, u32 n, u32 o, int rs, int nf, u32 nhit)
{
    int steps = 0;
    while (o + (u32)rs <= n && steps++ < 400) {
        const u8 *r = b + o;
        u32 spr = rd32(r + 4), id = spr & 0x8000 ? spr & 0x1FF : spr & 0x7FFF;
        if (rs == 20 && rd16(r + 18) >= nhit && rd16(r + 18) != 0xFFFF)
            return -1;
        if (nf > 0 && (s8)r[2] > 0 && spr <= 0xFFFF && id >= (u32)nf)
            return -2;
        if (r[3] & 0x80) {
            u32 t;
            if (o + (u32)rs + 4 > n)
                return -1;
            t = rd32(b + o + (u32)rs);
            return t + (u32)rs <= n && t % 4 == 0 ? 0 : -1;
        }
        o += (u32)rs;
    }
    return -1;
}

/* relocate a PS2 chain copied at +xp of the merged buffer: gotos += xp,
 * 20-byte records' selections += hit_add; done[] marks visited records */
static void reloc_chain(u8 *m, u32 xp, u32 n, u32 o, int rs, u32 hit_add, u32 hit_lim, u8 *done)
{
    int steps = 0;
    while (o + (u32)rs <= n && steps++ < 4000) {
        u8 *r = m + xp + o;
        if (done[o / 4])
            return;
        done[o / 4] = 1;
        if (rs == 20 && rd16(r + 18) < hit_lim)
            wr16(r + 18, (u16)(rd16(r + 18) + hit_add));
        if (r[3] & 0x80) {
            u32 t;
            if (o + (u32)rs + 4 > n)
                return;
            t = rd32(r + rs);
            if (t + (u32)rs > n)
                return;
            wr32(r + rs, t + xp);
            o = t;
            continue;
        }
        o += (u32)rs;
    }
}

typedef struct {
    int built;
    u8 *tbl, *hit, *fm, *dt;
    int top;
    u32 tbl_n, hit_n;
} Merged;
static Merged MG[59];

static void build_char(int c, const u8 *ptbl, u32 ptbl_n, const u8 *phit, u32 phit_n, const u8 *pfm,
                       const u8 *pdt, u32 pdt_n, int nf)
{
    Merged *M = &MG[c];
    const u8 *ntbl = NF[c][G_TBL].p, *nhit = NF[c][G_HIT].p, *nfm = NF[c][G_FM].p;
    u32 ntbl_n = NF[c][G_TBL].n, nhit_n = NF[c][G_HIT].n & ~15u;
    Tbl TN, TP;
    int ng, g, s, n_naomi = 0, n_fb = 0, n_fb_missing = 0, n_fb_sprite = 0, n_fb_goto = 0, n_box = 0;
    u32 garr, xp, total, minscr = 0xFFFFFFFFu;
    u8 *done;
    M->built = -1;
    if (parse_tbl(ntbl, ntbl_n, &TN) || parse_tbl(ptbl, ptbl_n, &TP)) {
        host_log("arcade: char %02x: TBL top table not found; PS2 frame data kept", c);
        return;
    }
    ng = TN.ng > TP.ng ? TN.ng : TP.ng;
    /* lowest script offset: an extended top table must not run into scripts */
    for (g = 0; g < TN.ng; g++)
        for (s = 0; s < TN.glen[g]; s++) {
            u32 v = tbl_script(ntbl, &TN, g, s);
            if (v && v < minscr)
                minscr = v;
        }
    if ((u32)TN.top + 4u * (u32)ng > minscr) {
        host_log("arcade: char %02x: %d PS2 groups do not fit the NAOMI top table; using %d", c, ng, TN.ng);
        ng = TN.ng;
    }
    /* layout: [NAOMI TBL][group arrays][PS2 TBL copy] */
    garr = (ntbl_n + 3) & ~3u;
    total = garr;
    for (g = 0; g < ng; g++)
        total += 4u * (u32)glen_max(&TN, &TP, g);
    xp = (total + 15) & ~15u;
    total = xp + ptbl_n;
    M->tbl = (u8 *)calloc(1, total);
    done = (u8 *)calloc(1, ptbl_n / 4 + 1);
    memcpy(M->tbl, ntbl, ntbl_n);
    memcpy(M->tbl + xp, ptbl, ptbl_n);
    M->tbl_n = total;
    M->top = TN.top;
    {
        u32 at = garr;
        for (g = 0; g < ng; g++) {
            int l = glen_max(&TN, &TP, g);
            wr32(M->tbl + TN.top + 4 * g, l ? at : 0);
            for (s = 0; s < l; s++) {
                u32 on = tbl_script(ntbl, &TN, g, s), op = tbl_script(ptbl, &TP, g, s), v = 0;
                int rs = rec_size(g), ok = on ? chain_check(ntbl, ntbl_n, on, rs, nf, nhit_n / 16) : -3;
                if (ok == 0) {
                    v = on;
                    n_naomi++;
                } else if (op && g <= 0x1C && chain_check(ptbl, ptbl_n, op, rs, nf, (phit_n & ~15u) / 16) == 0) {
                    /* PS2 fallback: NAOMI has none, a missing sprite, or a bad goto */
                    v = xp + op;
                    n_fb++;
                    n_fb_missing += ok == -3;
                    n_fb_sprite += ok == -2;
                    n_fb_goto += ok == -1;
                    reloc_chain(M->tbl, xp, ptbl_n, op, rs, nhit_n / 16, (phit_n & ~15u) / 16, done);
                } else {
                    v = on; /* no usable PS2 script (or groups 0x1D+, effect formats): NAOMI's */
                    n_naomi += on != 0;
                }
                wr32(M->tbl + at + 4 * s, v);
            }
            at += 4u * (u32)l;
        }
    }
    /* HIT = NAOMI selections, then the PS2 ones (reached by fallback frames) */
    M->hit_n = nhit_n + (phit_n & ~15u);
    M->hit = (u8 *)malloc(M->hit_n);
    memcpy(M->hit, nhit, nhit_n);
    memcpy(M->hit + nhit_n, phit, phit_n & ~15u);
    for (u32 k = 0; k < (phit_n & ~15u) / 16; k++) {
        const u8 *e = phit + 16 * k;
        int sl;
        for (sl = 0; sl < 6; sl++) {
            u32 ri = (sl == 1 ? rd16(e + 2) & 0xFF : rd16(e + 2 * sl) & 0xFFF);
            if (ri && ri < 256 && memcmp(pfm + 8 * ri, nfm + 8 * ri, 8)) {
                n_box++;
                break;
            }
        }
    }
    M->fm = (u8 *)malloc(NF[c][G_FM].n < 2048 ? 2048 : NF[c][G_FM].n);
    memset(M->fm, 0, 2048);
    memcpy(M->fm, nfm, NF[c][G_FM].n);
    /* HIT_DT: the NAOMI records, padded to 128 with the PS2 records beyond them */
    M->dt = (u8 *)calloc(128, 28);
    if (pdt_n > 128 * 28)
        pdt_n = 128 * 28;
    memcpy(M->dt, pdt, pdt_n);
    memcpy(M->dt, NF[c][G_DT].p, NF[c][G_DT].n < 128 * 28 ? NF[c][G_DT].n : 128 * 28);
    free(done);
    M->built = 1;
    host_log("arcade: char %02x tables: TBL %u bytes (top %#x, %d groups), %d NAOMI scripts, %d PS2 fallback "
             "(%d PS2-only, %d sprite not in PS2 bank, %d bad chain); %u+%u selections (%d PS2 selections "
             "whose rects differ); HIT_DT %u NAOMI records",
             c, M->tbl_n, M->top, ng, n_naomi, n_fb, n_fb_missing, n_fb_sprite, n_fb_goto, nhit_n / 16,
             (phit_n & ~15u) / 16, n_box, NF[c][G_DT].n / 28);
}

#define PLAYERS ((u8 *)EE_BSS_PTR(0x004F20B0))
#define PSTRIDE 0x5B8
static int player_index(const u8 *p)
{
    long d = p - PLAYERS;
    return d >= 0 && d < 6 * PSTRIDE && d % PSTRIDE == 0 ? (int)(d / PSTRIDE) : -1;
}

static void bind_player(u8 *p)
{
    int c = (s8)p[0x540];
    u8 *base = (u8 *)(uintptr_t)*(u32 *)(p + 0x53C);
    const u8 *bank;
    u32 off[15], sz[15];
    int i, nf;
    unsigned long long h = 0xcbf29ce484222325ull;
    if (c < 0 || c >= 59 || !base)
        return;
    for (i = 0; i < 15; i++)
        off[i] = rd32(base + 4 * i);
    for (i = 5; i < 14; i++)
        sz[i] = off[i + 1] - off[i];
    bank = base + off[0];
    nf = (int)(rd32(bank + rd32(bank + 0xC)) / 4);
    if (!MG[c].built)
        build_char(c, base + off[5], sz[5], base + off[6], sz[6], base + off[7], base + off[8], sz[8], nf);
    if ((mvc2_arcade_flags & A_FRAMES) && MG[c].built > 0) {
        *(u32 *)(p + 0x178) = (u32)(uintptr_t)MG[c].tbl;
        *(u32 *)(p + 0x17C) = (u32)(uintptr_t)MG[c].hit;
        *(u32 *)(p + 0x180) = (u32)(uintptr_t)MG[c].fm;
        *(u16 *)(p + 0x142) = (u16)MG[c].top;
        h = fnv(h, MG[c].tbl, MG[c].tbl_n);
        h = fnv(h, MG[c].hit, MG[c].hit_n);
        h = fnv(h, MG[c].fm, 2048);
    }
    if ((mvc2_arcade_flags & A_DAMAGE) && MG[c].built > 0) {
        *(u32 *)(p + 0x184) = (u32)(uintptr_t)MG[c].dt;
        h = fnv(h, MG[c].dt, 128 * 28);
    }
    if (mvc2_arcade_flags & A_AI) {
        static const int fld[5] = {0x198, 0x19C, 0x1A0, 0x1A4, 0x1A8};
        for (i = 0; i < 5; i++) {
            *(u32 *)(p + fld[i]) = (u32)(uintptr_t)NF[c][G_TAIKI + i].p;
            h = fnv(h, NF[c][G_TAIKI + i].p, NF[c][G_TAIKI + i].n);
        }
    }
    host_log("arcade: player %d = char %02x bound to NAOMI tables (%s%s%s), table hash %016llx",
             player_index(p), c, mvc2_arcade_flags & A_FRAMES ? "a" : "", mvc2_arcade_flags & A_DAMAGE ? "b" : "",
             mvc2_arcade_flags & A_AI ? "c" : "", h);
}

void arcade_init(void)
{
    const char *e = getenv("MVC2_ARCADE"), *path = getenv("MVC2_NAOMI"), *t = getenv("MVC2_ARCADE_TRACE");
    int c, g;
    mvc2_arcade_trace = t && *t && *t != '0';
    if (e) {
        if (!strcmp(e, "all") || !strcmp(e, "1"))
            e = "abc";
        mvc2_arcade_flags = (strchr(e, 'a') ? A_FRAMES : 0) | (strchr(e, 'b') ? A_DAMAGE : 0) | (strchr(e, 'c') ? A_AI : 0);
    }
    if (!mvc2_arcade_flags || arc_ok)
        return;
#ifdef __EMSCRIPTEN__
    if (!path)
        path = "/mvsc2.zip";
#endif
    if (!path) {
        host_log("arcade: toggles set but no NAOMI set given (--naomi PATH); PS2 data kept");
        mvc2_arcade_flags = 0;
        return;
    }
    if (load_naomi(path) != 0) {
        host_log("arcade: NAOMI tables not loaded; PS2 data kept");
        mvc2_arcade_flags = 0;
        return;
    }
    arc_ok = 1;
    arc_hash = 0xcbf29ce484222325ull;
    {
        u8 fl = (u8)mvc2_arcade_flags;
        arc_hash = fnv(arc_hash, &fl, 1);
    }
    for (c = 0; c < 59; c++)
        for (g = 0; g < G_N; g++)
            if ((g <= G_FM && (mvc2_arcade_flags & A_FRAMES)) || (g == G_DT && (mvc2_arcade_flags & A_DAMAGE)) ||
                (g >= G_TAIKI && (mvc2_arcade_flags & A_AI)))
                arc_hash = fnv(arc_hash, NF[c][g].p, NF[c][g].n);
    host_log("arcade: NAOMI mvsc2 Rev A tables loaded from %s; toggles %s%s%s; session hash %016llx", path,
             mvc2_arcade_flags & A_FRAMES ? "a(frames+boxes) " : "", mvc2_arcade_flags & A_DAMAGE ? "b(damage) " : "",
             mvc2_arcade_flags & A_AI ? "c(cpu ai) " : "", arc_hash);
}

/* ---------------------------------------------------------------- hooks */
void func_0016F2D0(void *pv, int index)
{
    func_0016F2D0__game(pv, index);
    if (arc_ok && mvc2_arcade_flags)
        bind_player((u8 *)pv);
}

/* trace: per player, the running script */
static struct { int on, anim, str, frames, ticks, tab_recs, tab_ticks; u32 rec; } TR[6];

/* the started script's length in the bound table (records and ticks to its goto) */
static void tab_len(u8 *p, int anim, int str, int *recs, int *ticks)
{
    u8 *base = (u8 *)(uintptr_t)*(u32 *)(p + 0x178);
    u8 *top = base + *(u16 *)(p + 0x142);
    u8 *r = base + rd32(base + rd32(top + 4 * anim) + 4 * (u32)str);
    *recs = *ticks = 0;
    while ((*recs)++ < 400) {
        if ((s8)r[2] > 0)
            *ticks += (s8)r[2];
        if (r[3] & 0x80)
            return;
        r += 20;
    }
}

static void tr_end(int i, u8 *p, const char *how)
{
    if (!TR[i].on)
        return;
    host_log("arcade-trace: player %d char %02x script %02x/%02x %s: %d frames %d ticks (table: %d records %d ticks)",
             i, p[0x540], TR[i].anim, TR[i].str, how, TR[i].frames, TR[i].ticks, TR[i].tab_recs, TR[i].tab_ticks);
    TR[i].on = 0;
}

int func_001757E0(void *pv, int animation, int strength)
{
    u8 *p = (u8 *)pv;
    int r = func_001757E0__game(pv, animation, strength), i;
    if (mvc2_arcade_trace && (i = player_index(p)) >= 0) {
        tr_end(i, p, "interrupted");
        TR[i].on = 1;
        TR[i].anim = (u8)animation;
        TR[i].str = (u8)strength;
        TR[i].frames = 1;
        TR[i].ticks = 0;
        TR[i].rec = *(u32 *)(p + 0x164);
        tab_len(p, (u8)animation, (u8)strength, &TR[i].tab_recs, &TR[i].tab_ticks);
    }
    return r;
}

/* MVC2_ARCADE_PLAY=GG/SS (testing, with the trace): every few seconds of
 * standing, player 0 starts script GG/SS through the game's own
 * func_001757E0; its stand state then steps it with func_00175700 like any
 * script, so the trace measures the bound table's frame timing. */
static void trace_play(u8 *p)
{
    static int anim = -2, str, count;
    if (anim == -2) {
        const char *e = getenv("MVC2_ARCADE_PLAY");
        anim = -1;
        if (e && sscanf(e, "%x/%x", &anim, &str) != 2)
            anim = -1;
    }
    if (anim < 0 || p != PLAYERS || TR[0].anim != 0 || TR[0].ticks < 120 || count >= 6)
        return;
    count++;
    host_log("arcade-trace: test start of %02x/%02x on player 0", anim, str);
    func_001757E0(p, anim, str);
}

int func_00175700(void *pv)
{
    u8 *p = (u8 *)pv;
    int r = func_00175700__game(pv), i;
    if (mvc2_arcade_trace)
        trace_play(p);
    if (mvc2_arcade_trace && (i = player_index(p)) >= 0 && TR[i].on) {
        TR[i].ticks++;
        if (r) {
            tr_end(i, p, "complete");
        } else if (*(u32 *)(p + 0x164) != TR[i].rec) {
            TR[i].frames++;
            TR[i].rec = *(u32 *)(p + 0x164);
        }
    }
    return r;
}

void func_0018B500(void *pv, void *qv)
{
    u8 *p = (u8 *)pv, *q = (u8 *)qv;
    s16 hp = *(s16 *)(p + 0x434);
    u8 *r = (u8 *)(uintptr_t)*(u32 *)(p + 0x1D0);
    func_0018B500__game(pv, qv);
    if (mvc2_arcade_trace && r) {
        u8 *atk = PLAYERS + q[0x1B8] * PSTRIDE;
        u32 dt = *(u32 *)(atk + 0x184);
        long id = dt ? ((long)(uintptr_t)r - (long)dt) / 28 : -1;
        host_log("arcade-trace: hit on player %d (char %02x) by char %02x attack %02lx: base damage %d, health %d -> %d",
                 player_index(p), p[0x540], atk[0x540], id, r[0], hp, *(s16 *)(p + 0x434));
    }
}

/* --cpu-team a,b,c (testing): the game's own pick runs, then the forced ids
 * replace its choices (the old host stand-in did this before the pick was
 * credited C). */
extern s8 D_004405A0[];
static void force_rec(u8 *rec, int id, const char *who, int t)
{
    rec[0x540] = (u8)id;
    rec[1] = (u8)id;
    rec[0x4DD] = (u8)D_004405A0[id];
    host_log("%s pick %d: character %#x (forced)", who, t, id);
}

static int forced_id(const char *env, int t)
{
    const char *f = getenv(env);
    int ids[3] = {-1, -1, -1};
    if (!f)
        return -1;
    sscanf(f, "%i,%i,%i", &ids[0], &ids[1], &ids[2]);
    return ids[t] >= 0 && ids[t] <= 58 ? ids[t] : -1;
}

void func_0032DF90(int a0)
{
    u8 *g = EE_BSS(u8 *, 0x004C2840);
    s32 side = (s8)a0, t;
    func_0032DF90__game(a0);
    if (*(s8 *)(g + 0x85) == 7)
        return;
    for (t = 0; t < 3; t++) {
        int id = forced_id("MVC2_CPU_TEAM", t);
        if (id >= 0)
            force_rec(PLAYERS + (side + t * 2) * PSTRIDE, id, "CPU", t);
    }
}

/* --p1-team a (testing): side 0's point character, forced as its PAK is
 * queued (func_0012EF50 / func_0012EF80, src/grok_w5_0012.c), after the
 * human's pick.  Only the point character: the partners' PAKs are already
 * resident from the menu, so forcing them would pair one character's code
 * with another's sprites.  The HUD keeps the menu's names. */
static void force_p1(u8 *p)
{
    int i = player_index(p), id;
    if (i != 0)
        return;
    id = forced_id("MVC2_P1_TEAM", i / 2);
    if (id >= 0 && (s8)p[0x540] != id)
        force_rec(p, id, "P1", i / 2);
}

void func_0012EF50(void *p)
{
    force_p1((u8 *)p);
    func_0012EF50__game(p);
}

void func_0012EF80(void *p)
{
    force_p1((u8 *)p);
    func_0012EF80__game(p);
}
