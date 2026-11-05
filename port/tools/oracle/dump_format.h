/*
 * Per-frame gameplay state dump shared by the oracle (Play! running the
 * retail executable, port/tools/oracle/mvc2_oracle.cpp) and the port
 * (port/host/state_dump.c).  Read by port/tools/oracle/compare.py.
 *
 * One record per game frame, taken at the start of main's loop iteration
 * (before func_0012F460), little endian:
 *   u32 magic 'MVF2', u32 frame, u16 pad1, u16 pad2, u32 game state g[0..2],
 *   u64 newlib rand seed (*D_0043B6F8 + 0xA8),
 *   u32 game RNG (func_00174170): D_004C26AC | D_004C26B0 << 8,
 *   REGION bytes of [0x004F20B0, 0x004F4500): the six player records
 *     (stride 0x5B8) and the game block D_004F4300 + the pad area,
 *   REGION bytes again as stored (before fix: the port's host pointers;
 *     the comparison accepts a word whose raw value equals the oracle's,
 *     since an integer can look like a host address),
 *   u32 BSS block hashes, one per ORACLE_HASH_BLOCK bytes of
 *     [ORACLE_HASH_LO, ORACLE_HASH_HI) (FNV-1a over the words),
 *   the sound commands the game issued since the previous record (see
 *   "Sound commands" below): u32 count, then ORACLE_SND_MAX entries of
 *   ORACLE_SND_WORDS u32 (the first min(count, MAX) used, the rest 0).
 * Words are given to the dump in EE terms: the port translates its host
 * pointers into EE addresses first (fix callback); the oracle passes them as
 * they are.
 */
#ifndef ORACLE_DUMP_FORMAT_H
#define ORACLE_DUMP_FORMAT_H
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#define ORACLE_MAGIC 0x3546564Du /* "MVF5" */
#define ORACLE_REGION_LO 0x004F20B0u
#define ORACLE_REGION_HI 0x004F4500u
#define ORACLE_HASH_LO 0x004C2580u
#define ORACLE_HASH_HI 0x00634380u
#define ORACLE_HASH_BLOCK 0x400u
#define ORACLE_NBLOCKS ((ORACLE_HASH_HI - ORACLE_HASH_LO + ORACLE_HASH_BLOCK - 1) / ORACLE_HASH_BLOCK)

/* MVC2_DUMP_EXTRA=LO:HI (both sides, testing; port/tools/oracle/fuzz.py
 * scan): every record also carries the bytes of [LO, HI) inside the hashed
 * BSS range, as given to the dump (after fix), after the block hashes, so a
 * comparison can see the words of an area the hashes only flag. */
static uint32_t oracle_extra_lo, oracle_extra_hi;
static int oracle_extra_init;
static void oracle_extra_parse(void)
{
    const char *e = getenv("MVC2_DUMP_EXTRA");
    oracle_extra_init = 1;
    if (e) {
        char *c;
        unsigned long lo = strtoul(e, &c, 0), hi = *c == ':' ? strtoul(c + 1, NULL, 0) : 0;
        if (lo >= ORACLE_HASH_LO && hi > lo && hi <= ORACLE_HASH_HI) {
            oracle_extra_lo = (uint32_t)lo & ~3u;
            oracle_extra_hi = (uint32_t)hi & ~3u;
        }
    }
}

/* ---- Sound commands ------------------------------------------------------
 * The calls the game makes into the sound layers, at their EE entry points,
 * which the port replaces at the same addresses (port/host/tsd_host.c,
 * port/host/cri.c): the Tamsoft sound driver client (effects, voices) and
 * the CRI ADXT player (music).  Each entry is {EE entry address, arg[0..6]}:
 * the arguments the entry takes, in EE argument-register order ($a0..$a3,
 * $t0..$t2), the low 32 bits.  Arguments past the entry's count and the ADXT
 * handle (a CRI object on the PS2, a host struct on the port) are written as
 * 0; pointer arguments as EE addresses (the port's fix()).
 * The oracle logs only calls whose return address lies outside the two
 * libraries (calls between library functions are not the game's).  The
 * buffer is per record: the commands issued since the previous record. */
#define ORACLE_SND_MAX 32
#define ORACLE_SND_WORDS 8
typedef struct
{
    uint32_t fn;
    uint8_t nargs, skip_mask, ptr_mask;
    const char *name;
} oracle_snd_def;
static const oracle_snd_def oracle_snd_defs[] = {
    {0x00422EA0u, 4, 0, 0, "tsd_play"},
    {0x00422FB0u, 1, 0, 0, "tsd_stop"},
    {0x004230B0u, 4, 0, 0, "tsd_change"},
    {0x004231D0u, 0, 0, 0, "tsd_stop_all_tq"},
    {0x00423240u, 1, 0, 0, "tsd_master_volume"},
    {0x004232C0u, 3, 0, 0, "tsd_cmd77"},
    {0x00423480u, 7, 0, 0x2A, "tsd_load_bank"}, /* slot, hd, hd_size, bd, bd_size, tq, tq_size */
    {0x004235D0u, 1, 0, 0, "tsd_unload_bank"},
    {0x00423650u, 0, 0, 0, "tsd_stop_all"},
    {0x004236C0u, 1, 0, 0, "tsd_stereo"},
    {0x00402C20u, 3, 1, 0, "ADXT_StartAfs"}, /* adxt, ptid, fid */
    {0x00401868u, 1, 1, 0, "ADXT_Stop"},
    {0x004020D8u, 2, 1, 0, "ADXT_SetOutVol"},
    {0x004026B0u, 2, 1, 0, "ADXT_Pause"},
    {0x00402BC0u, 1, 0, 0, "ADXT_SetOutputMono"},
};
#define ORACLE_SND_NDEFS (sizeof oracle_snd_defs / sizeof oracle_snd_defs[0])
/* the libraries whose internal calls are not logged (oracle side) */
#define ORACLE_SND_LIB_IN(ra) (((ra) >= 0x003F5F88u && (ra) < 0x00411C10u) || ((ra) >= 0x00422BE0u && (ra) < 0x00423E30u))

static uint32_t oracle_snd_buf[ORACLE_SND_MAX][ORACLE_SND_WORDS];
static uint32_t oracle_snd_n;

static const oracle_snd_def *oracle_snd_find(uint32_t fn)
{
    unsigned i;
    for (i = 0; i < ORACLE_SND_NDEFS; i++)
        if (oracle_snd_defs[i].fn == fn)
            return &oracle_snd_defs[i];
    return NULL;
}

/* args[0..6] as the entry received them; fix (port) translates pointers */
typedef uint32_t (*oracle_fix_fn)(uint32_t w);
static void oracle_snd_log(uint32_t fn, const uint32_t *args, oracle_fix_fn fix)
{
    const oracle_snd_def *d = oracle_snd_find(fn);
    uint32_t *e;
    unsigned k;
    if (!d)
        return;
    if (oracle_snd_n < ORACLE_SND_MAX) {
        e = oracle_snd_buf[oracle_snd_n];
        e[0] = fn;
        for (k = 0; k < 7; k++) {
            uint32_t v = k < d->nargs && !(d->skip_mask >> k & 1) ? args[k] : 0;
            if (fix && (d->ptr_mask >> k & 1))
                v = fix(v);
            e[1 + k] = v;
        }
    }
    oracle_snd_n++;
}

static void oracle_snd_write(FILE *f)
{
    uint32_t n = oracle_snd_n;
    fwrite(&n, 4, 1, f);
    if (n < ORACLE_SND_MAX)
        memset(oracle_snd_buf[n], 0, (ORACLE_SND_MAX - n) * sizeof oracle_snd_buf[0]);
    fwrite(oracle_snd_buf, 4, ORACLE_SND_MAX * ORACLE_SND_WORDS, f);
    oracle_snd_n = 0;
}

/* a frame whose record is not written: its commands are dropped too */
static void oracle_snd_reset(void) { oracle_snd_n = 0; }

/* rd(ee, dst, n): copy n bytes of EE address ee; fix(w): EE value of a word */
typedef void (*oracle_rd_fn)(uint32_t ee, void *dst, uint32_t n);

static uint8_t oracle_ram_buf[ORACLE_HASH_HI - ORACLE_HASH_LO];

static void oracle_dump_record(FILE *f, uint32_t frame, uint16_t b0, uint16_t b1,
                               oracle_rd_fn rd, oracle_fix_fn fix, uint64_t seed)
{
    uint32_t hdr[3], st = 0, i, j;
    uint8_t g3[3];
    uint32_t hashes[ORACLE_NBLOCKS];
    static uint8_t raw[ORACLE_REGION_HI - ORACLE_REGION_LO];
    rd(ORACLE_HASH_LO, oracle_ram_buf, ORACLE_HASH_HI - ORACLE_HASH_LO);
    memcpy(raw, oracle_ram_buf + (ORACLE_REGION_LO - ORACLE_HASH_LO), sizeof raw);
    if (fix)
        for (i = 0; i + 4 <= sizeof oracle_ram_buf; i += 4) {
            uint32_t w;
            memcpy(&w, oracle_ram_buf + i, 4);
            w = fix(w);
            memcpy(oracle_ram_buf + i, &w, 4);
        }
    memcpy(g3, oracle_ram_buf + (0x004F4300u - ORACLE_HASH_LO), 3);
    st = (uint32_t)g3[0] << 16 | (uint32_t)g3[1] << 8 | g3[2];
    hdr[0] = ORACLE_MAGIC;
    hdr[1] = frame;
    hdr[2] = (uint32_t)b0 | (uint32_t)b1 << 16;
    fwrite(hdr, 4, 3, f);
    fwrite(&st, 4, 1, f);
    fwrite(&seed, 8, 1, f);
    {
        uint32_t grng = oracle_ram_buf[0x004C26ACu - ORACLE_HASH_LO] |
                        (uint32_t)oracle_ram_buf[0x004C26B0u - ORACLE_HASH_LO] << 8;
        fwrite(&grng, 4, 1, f);
    }
    fwrite(oracle_ram_buf + (ORACLE_REGION_LO - ORACLE_HASH_LO), 1, ORACLE_REGION_HI - ORACLE_REGION_LO, f);
    fwrite(raw, 1, sizeof raw, f);
    for (i = 0; i < ORACLE_NBLOCKS; i++) {
        uint32_t h = 2166136261u, lo = i * ORACLE_HASH_BLOCK, hi = lo + ORACLE_HASH_BLOCK;
        if (hi > sizeof oracle_ram_buf)
            hi = sizeof oracle_ram_buf;
        for (j = lo; j < hi; j++)
            h = (h ^ oracle_ram_buf[j]) * 16777619u;
        hashes[i] = h;
    }
    fwrite(hashes, 4, ORACLE_NBLOCKS, f);
    oracle_snd_write(f);
    if (!oracle_extra_init)
        oracle_extra_parse();
    if (oracle_extra_hi > oracle_extra_lo)
        fwrite(oracle_ram_buf + (oracle_extra_lo - ORACLE_HASH_LO), 1, oracle_extra_hi - oracle_extra_lo, f);
    fflush(f);
}

/* --resync STATE (both sides): at the first frame of STATE, the counters that
 * run during loads (which take frames on the PS2 and none on the port) and the
 * rand seed are set to the same values, so a run can be compared from there.
 * wr(ee, value) writes an EE BSS word. */
#define ORACLE_RESYNC_SEED 0x00000000075BCD15ull
typedef void (*oracle_wr_fn)(uint32_t ee, uint32_t v);
typedef void (*oracle_wr8_fn)(uint32_t ee, uint8_t v);
static void oracle_resync(oracle_wr_fn wr, oracle_wr8_fn wr8)
{
    wr8(0x004C26ACu, 0x5A); /* the game's RNG (func_00174170) */
    wr8(0x004C26B0u, 0xA5);
    wr(0x004F4310u, 10000); /* g+0x10: frame counter (func_0012F460) */
    wr(0x004F431Cu, 10000); /* g+0x1C */
    wr(0x004F4320u, 0);     /* g+0x20 */
    wr(0x004C2ADCu, 10000); /* D_004C2ADC: counter (func in src/r12_09_a.c) */
}

/* EE RAM [ORACLE_HASH_LO, ORACLE_SNAP_HI): the BSS and the heap
 * (EE 0x00634380.., the game's newlib arena), words after fix, raw */
#define ORACLE_SNAP_HI 0x01F00000u
static void oracle_snap(const char *path, oracle_rd_fn rd, oracle_fix_fn fix)
{
    FILE *f = fopen(path, "wb");
    uint32_t a, i;
    static uint8_t chunk[0x10000];
    if (!f)
        return;
    for (a = ORACLE_HASH_LO; a < ORACLE_SNAP_HI; a += sizeof chunk) {
        uint32_t n = ORACLE_SNAP_HI - a < sizeof chunk ? ORACLE_SNAP_HI - a : (uint32_t)sizeof chunk;
        rd(a, chunk, n);
        if (fix)
            for (i = 0; i + 4 <= n; i += 4) {
                uint32_t w;
                memcpy(&w, chunk + i, 4);
                w = fix(w);
                memcpy(chunk + i, &w, 4);
            }
        fwrite(chunk, 1, n, f);
    }
    fclose(f);
}

#endif
