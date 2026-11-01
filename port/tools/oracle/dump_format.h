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
 *     [ORACLE_HASH_LO, ORACLE_HASH_HI) (FNV-1a over the words).
 * Words are given to the dump in EE terms: the port translates its host
 * pointers into EE addresses first (fix callback); the oracle passes them as
 * they are.
 */
#ifndef ORACLE_DUMP_FORMAT_H
#define ORACLE_DUMP_FORMAT_H
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define ORACLE_MAGIC 0x3446564Du /* "MVF4" */
#define ORACLE_REGION_LO 0x004F20B0u
#define ORACLE_REGION_HI 0x004F4500u
#define ORACLE_HASH_LO 0x004C2580u
#define ORACLE_HASH_HI 0x00634380u
#define ORACLE_HASH_BLOCK 0x400u
#define ORACLE_NBLOCKS ((ORACLE_HASH_HI - ORACLE_HASH_LO + ORACLE_HASH_BLOCK - 1) / ORACLE_HASH_BLOCK)

/* rd(ee, dst, n): copy n bytes of EE address ee; fix(w): EE value of a word */
typedef void (*oracle_rd_fn)(uint32_t ee, void *dst, uint32_t n);
typedef uint32_t (*oracle_fix_fn)(uint32_t w);

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
