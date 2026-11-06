/*
 * Per-frame gameplay state dump for the oracle comparison (testing only):
 * MVC2_STATE_DUMP=FILE (app: --state-dump FILE) writes one record per game
 * frame at the start of mvc2_frame(), in the format of
 * port/tools/oracle/dump_format.h, which mvc2_oracle (the retail executable
 * in the Play! core) writes at the same point.  MVC2_STATE_DUMP_FROM=N skips
 * the frames before N.  port/tools/oracle/compare.py reads both.
 *
 * Host pointers stored in game memory are written as the EE addresses they
 * stand for: the EE BSS (mvc2_ee_bss), the EE data image (from
 * mvc2_hole_00424200), the EE heap (sbrk block, EE base 0x00634380) and, on
 * ELF builds, game functions (func_XXXXXXXX / residual_XXXXXXXX / alabel
 * symbols of /proc/self/exe).
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "host.h"
#include "../tools/oracle/dump_format.h"

extern unsigned char mvc2_hole_00424200[];
extern u8 *host_ee_heap_base(void);
#define IMAGE_EE 0x00424200u
#define IMAGE_END 0x004C2580u
#define EE_HEAP 0x00634380u
#define HOST_EE_HEAP (28u << 20)

static FILE *dump_f;
static long dump_from;
static int dump_init;
#define MAX_SNAPS 8
static int nsnaps;
static long snap_frame[MAX_SNAPS];
static char snap_path[MAX_SNAPS][512];

/* ---- game function addresses (host -> EE) ------------------------------- */
typedef struct { uintptr_t host; u32 ee; } FnMap;
static FnMap *fns;
static int nfns;

static int fn_cmp(const void *a, const void *b)
{
    uintptr_t x = ((const FnMap *)a)->host, y = ((const FnMap *)b)->host;
    return x < y ? -1 : x > y;
}

#if defined(__linux__) && !defined(__EMSCRIPTEN__)
#include <elf.h>
void host_state_dump_open(const char *path);

static uintptr_t load_bias;
static void load_fn_map(void)
{
    FILE *f = fopen("/proc/self/exe", "rb");
    long sz;
    u8 *b;
    Elf32_Ehdr *eh;
    int i;
    if (!f)
        return;
    fseek(f, 0, SEEK_END);
    sz = ftell(f);
    fseek(f, 0, SEEK_SET);
    b = (u8 *)malloc(sz);
    if (fread(b, 1, sz, f) != (size_t)sz) { fclose(f); free(b); return; }
    fclose(f);
    eh = (Elf32_Ehdr *)b;
    if (eh->e_ident[EI_CLASS] != ELFCLASS32) { free(b); return; }
    for (i = 0; i < eh->e_shnum; i++) {
        Elf32_Shdr *sh = (Elf32_Shdr *)(b + eh->e_shoff + i * eh->e_shentsize);
        Elf32_Shdr *strs;
        Elf32_Sym *sy;
        u32 k, n;
        if (sh->sh_type != SHT_SYMTAB)
            continue;
        strs = (Elf32_Shdr *)(b + eh->e_shoff + sh->sh_link * eh->e_shentsize);
        sy = (Elf32_Sym *)(b + sh->sh_offset);
        n = sh->sh_size / sizeof(Elf32_Sym);
        fns = (FnMap *)malloc(n * sizeof(FnMap));
        /* load bias (PIE): this function's address against its symbol */
        for (k = 0; k < n; k++)
            if (!strcmp((const char *)(b + strs->sh_offset + sy[k].st_name), "host_state_dump_open"))
                load_bias = (uintptr_t)&host_state_dump_open - sy[k].st_value;
        for (k = 0; k < n; k++) {
            const char *nm = (const char *)(b + strs->sh_offset + sy[k].st_name);
            const char *hex = NULL;
            if (ELF32_ST_TYPE(sy[k].st_info) != STT_FUNC || !sy[k].st_value)
                continue;
            if (!strncmp(nm, "func_", 5)) hex = nm + 5;
            else if (!strncmp(nm, "residual_", 9)) hex = nm + 9;
            else if (!strncmp(nm, "alabel_", 7)) hex = nm + 7;
            if (!hex || strlen(hex) != 8 || strstr(nm, "__"))
                continue;
            fns[nfns].host = load_bias + sy[k].st_value;
            fns[nfns].ee = (u32)strtoul(hex, NULL, 16);
            nfns++;
        }
    }
    free(b);
    qsort(fns, nfns, sizeof(FnMap), fn_cmp);
}
#else
static void load_fn_map(void) {}
#endif

static u32 fix(u32 w)
{
    uintptr_t p = (uintptr_t)w;
    static u8 *heap;
    static uintptr_t lo_addr = 1, hi_addr;
    int lo, hi;
    if (sizeof(void *) != 4)
        return w;
    if (!heap)
        heap = host_ee_heap_base();
    if (hi_addr < lo_addr) {
        /* every host address fix() translates lies in [lo_addr, hi_addr]:
         * one compare rejects the small integers and floats of a dump */
        uintptr_t b = (uintptr_t)mvc2_ee_bss, m = (uintptr_t)mvc2_hole_00424200;
        lo_addr = b < m ? b : m;
        hi_addr = b + (EE_BSS_END - EE_BSS_START);
        if (m + (IMAGE_END - IMAGE_EE) > hi_addr)
            hi_addr = m + (IMAGE_END - IMAGE_EE);
        if (heap && (uintptr_t)heap < lo_addr)
            lo_addr = (uintptr_t)heap;
        if (heap && (uintptr_t)heap + HOST_EE_HEAP > hi_addr)
            hi_addr = (uintptr_t)heap + HOST_EE_HEAP;
        if (nfns && fns[0].host < lo_addr)
            lo_addr = fns[0].host;
        if (nfns && fns[nfns - 1].host > hi_addr)
            hi_addr = fns[nfns - 1].host;
        if (!heap)
            hi_addr = 0, lo_addr = 1; /* recompute once the heap exists */
    }
    if (heap && (p < lo_addr || p > hi_addr))
        return w;
    if (p >= (uintptr_t)mvc2_ee_bss && p < (uintptr_t)mvc2_ee_bss + (EE_BSS_END - EE_BSS_START))
        return EE_BSS_START + (u32)(p - (uintptr_t)mvc2_ee_bss);
    if (p >= (uintptr_t)mvc2_hole_00424200 && p < (uintptr_t)mvc2_hole_00424200 + (IMAGE_END - IMAGE_EE))
        return IMAGE_EE + (u32)(p - (uintptr_t)mvc2_hole_00424200);
    if (heap && p >= (uintptr_t)heap && p < (uintptr_t)heap + HOST_EE_HEAP)
        return EE_HEAP + (u32)(p - (uintptr_t)heap);
    lo = 0;
    hi = nfns - 1;
    while (lo <= hi) {
        int m = (lo + hi) / 2;
        if (fns[m].host == p)
            return fns[m].ee;
        if (fns[m].host < p) lo = m + 1;
        else hi = m - 1;
    }
    return w;
}

static void rd(uint32_t ee, void *dst, uint32_t n)
{
    /* EE BSS, or the EE heap (the host sbrk block from EE 0x00634380) */
    if (ee < EE_HEAP && ee + n > EE_HEAP) {
        rd(ee, dst, EE_HEAP - ee);
        rd(EE_HEAP, (u8 *)dst + (EE_HEAP - ee), n - (EE_HEAP - ee));
        return;
    }
    if (ee >= EE_HEAP) {
        u8 *heap = host_ee_heap_base();
        if (heap && ee - EE_HEAP + n <= HOST_EE_HEAP)
            memcpy(dst, heap + (ee - EE_HEAP), n);
        else
            memset(dst, 0, n);
        return;
    }
    memcpy(dst, EE_BSS_PTR(ee), n);
}

void host_state_dump_open(const char *path)
{
    const char *e;
    dump_init = 1;
    if (!path)
        path = getenv("MVC2_STATE_DUMP");
    if (!path || !*path)
        return;
    dump_f = fopen(path, "wb");
    if (!dump_f) {
        host_log("state dump: cannot write %s", path);
        return;
    }
    /* F:FILE[,F:FILE...]: the raw EE BSS and heap at frame F (up to 8) */
    e = getenv("MVC2_STATE_SNAP");
    while (e && *e && strchr(e, ':') && nsnaps < MAX_SNAPS) {
        const char *c = strchr(e, ':') + 1, *end = strchr(c, ',');
        size_t n = end ? (size_t)(end - c) : strlen(c);
        if (n >= sizeof snap_path[0])
            n = sizeof snap_path[0] - 1;
        snap_frame[nsnaps] = atol(e);
        memcpy(snap_path[nsnaps], c, n);
        snap_path[nsnaps][n] = 0;
        nsnaps++;
        e = end ? end + 1 : NULL;
    }
    e = getenv("MVC2_STATE_DUMP_FROM");
    dump_from = e ? atol(e) : 0;
    load_fn_map();
    host_log("state dump: %s (from frame %ld, %d game functions mapped)", path, dump_from, nfns);
}

static void wr(uint32_t ee, uint32_t v)
{
    memcpy(EE_BSS_PTR(ee), &v, 4);
}

static void wr8(uint32_t ee, uint8_t v)
{
    *(u8 *)EE_BSS_PTR(ee) = v;
}

/* MVC2_RESYNC=STATE: as mvc2_oracle --resync (dump_format.h) */
static void resync_check(void)
{
    static int done;
    const char *want = getenv("MVC2_RESYNC");
    char cur[32];
    u8 *g = (u8 *)EE_BSS_PTR(0x004F4300);
    size_t n;
    if (done || !want || !*want)
        return;
    /* five levels (g[0..4]), so a resync can name a sub-state ("2/1/2/3" =
     * a fight's first playable frame); a shorter STATE matches as a prefix */
    snprintf(cur, sizeof cur, "%d/%d/%d/%d/%d", g[0], g[1], g[2], g[3], g[4]);
    n = strlen(want);
    if (strncmp(cur, want, n) != 0 || !(cur[n] == 0 || cur[n] == '/' || want[n - 1] == '/'))
        return;
    done = 1;
    oracle_resync(wr, wr8);
    {
        extern unsigned char D_0043B6F8[];
        u8 *reent;
        uint64_t seed = ORACLE_RESYNC_SEED;
        memcpy(&reent, D_0043B6F8, sizeof reent);
        if (reent)
            memcpy(reent + 0xA8, &seed, 8);
    }
    host_log("state dump: resync at state %s", cur);
}

void host_state_dump_frame(long frame, unsigned b0, unsigned b1)
{
    extern unsigned char D_0043B6F8[];
    u8 *reent;
    uint64_t seed = 0;
    if (!dump_init)
        host_state_dump_open(NULL);
    resync_check();
    if (!dump_f || frame < dump_from) {
        oracle_snd_reset();
        return;
    }
    memcpy(&reent, D_0043B6F8, sizeof reent);
    if (reent)
        memcpy(&seed, reent + 0xA8, 8);
    {
        int k;
        for (k = 0; k < nsnaps; k++)
            if (frame == snap_frame[k]) {
                char raw[600];
                oracle_snap(snap_path[k], rd, fix);
                snprintf(raw, sizeof raw, "%s.raw", snap_path[k]); /* untranslated: snapdiff.py */
                oracle_snap(raw, rd, NULL);
            }
    }
    oracle_dump_record(dump_f, (uint32_t)frame, (uint16_t)b0, (uint16_t)b1, rd, fix, seed);
}

/* a sound command the game issued (an entry of dump_format.h
 * oracle_snd_defs: tsd_host.c, cri.c); goes into the next record */
void host_snd_log(u32 fn, u32 a0, u32 a1, u32 a2, u32 a3, u32 t0, u32 t1, u32 t2)
{
    uint32_t a[7];
    if (!dump_init)
        host_state_dump_open(NULL);
    if (!dump_f)
        return;
    a[0] = a0; a[1] = a1; a[2] = a2; a[3] = a3; a[4] = t0; a[5] = t1; a[6] = t2;
    oracle_snd_log(fn, a, fix);
}

/* for gdb: `call host_state_snap_now("file")` at any point (the oracle's
 * --snap-at ADDR:FRAME:FILE takes the same snapshot at a function entry) */
void host_state_snap_now(const char *path)
{
    char raw[600];
    if (!fns && !nfns)
        load_fn_map();
    oracle_snap(path, rd, fix);
    snprintf(raw, sizeof raw, "%s.raw", path);
    oracle_snap(raw, rd, NULL);
}
