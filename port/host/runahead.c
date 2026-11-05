/* Run-ahead: the game state snapshot (see runahead.h). */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "host.h"
#include "runahead.h"
#include "../audio/tsd_client.h"

extern unsigned char mvc2_hole_00424200[];
extern u8 *host_ee_heap_base(void);
extern u8 *host_ee_heap_top(void);
#define IMAGE_BYTES (0x004C2580u - 0x00424200u)
#define BSS_BYTES (0x00634380u - EE_BSS_START)

int mvc2_speculating;

#define MAX_BLOCKS 64
static struct { void *p; size_t n; const char *name; } blk[MAX_BLOCKS];
static int nblk;
static u8 *snap;
static size_t snap_cap, snap_heap;
static unsigned long unsafe_events;
static const char *last_unsafe;

void ra_register(void *p, size_t n, const char *name);
RA_REGISTER(tsdc_ra_state) { tsdc_state_blocks(ra_register); }

void ra_register(void *p, size_t n, const char *name)
{
    if (nblk < MAX_BLOCKS) {
        blk[nblk].p = p;
        blk[nblk].n = n;
        blk[nblk].name = name;
        nblk++;
    }
}

static size_t heap_used(void)
{
    u8 *b = host_ee_heap_base(), *t = host_ee_heap_top();
    return b && t > b ? (size_t)(t - b) : 0;
}

size_t ra_state_bytes(void)
{
    size_t n = IMAGE_BYTES + BSS_BYTES + heap_used();
    for (int i = 0; i < nblk; i++) n += blk[i].n;
    return n;
}

int ra_save(void)
{
    size_t need = ra_state_bytes(), o = 0;
    if (need > snap_cap) {
        u8 *p = (u8 *)realloc(snap, need);
        if (!p) return -1;
        snap = p;
        snap_cap = need;
    }
    memcpy(snap + o, mvc2_hole_00424200, IMAGE_BYTES), o += IMAGE_BYTES;
    memcpy(snap + o, mvc2_ee_bss, BSS_BYTES), o += BSS_BYTES;
    snap_heap = heap_used();
    if (snap_heap) memcpy(snap + o, host_ee_heap_base(), snap_heap), o += snap_heap;
    for (int i = 0; i < nblk; i++) memcpy(snap + o, blk[i].p, blk[i].n), o += blk[i].n;
    return 0;
}

void ra_restore(void)
{
    size_t o = 0;
    memcpy(mvc2_hole_00424200, snap + o, IMAGE_BYTES), o += IMAGE_BYTES;
    memcpy(mvc2_ee_bss, snap + o, BSS_BYTES), o += BSS_BYTES;
    /* the break only moves in loads, which are never speculated (the
     * game's malloc arena is one block from the first request); if it did,
     * the part above the saved break is dead after the restore anyway */
    if (snap_heap) memcpy(host_ee_heap_base(), snap + o, snap_heap), o += snap_heap;
    for (int i = 0; i < nblk; i++) memcpy(blk[i].p, snap + o, blk[i].n), o += blk[i].n;
}

void ra_unsafe(const char *why)
{
    unsafe_events++;
    if (mvc2_speculating && why != last_unsafe) {
        host_log("run-ahead: a speculative frame did host work a restore cannot undo (%s); backing off", why);
        last_unsafe = why;
    }
}
unsigned long ra_unsafe_events(void) { return unsafe_events; }

static unsigned long long fnv(unsigned long long h, const u8 *p, size_t n)
{
    while (n--) h = (h ^ *p++) * 0x100000001B3ull;
    return h;
}
unsigned long long ra_state_hash(void)
{
    unsigned long long h = 0xCBF29CE484222325ull;
    h = fnv(h, mvc2_hole_00424200, IMAGE_BYTES);
    /* not D_004C2A78: func_003DF7B0 stores the EE timer (T0_COUNT) there for
     * the performance meter; it is wall-clock time, so it differs between any
     * two runs and has no effect on the game */
    {
        const u32 skip = 0x004C2A78u - EE_BSS_START;
        h = fnv(h, mvc2_ee_bss, skip);
        h = fnv(h, mvc2_ee_bss + skip + 4, BSS_BYTES - skip - 4);
    }
    h = fnv(h, host_ee_heap_base(), heap_used());
    for (int i = 0; i < nblk; i++) h = fnv(h, (const u8 *)blk[i].p, blk[i].n);
    return h;
}

/* testing: one hash per region, to find state a restore misses */
void ra_log_regions(long frame)
{
    unsigned long long h0 = 0xCBF29CE484222325ull;
    char line[2048];
    int o = snprintf(line, sizeof line, "state regions frame %ld: image %016llx bss %016llx heap %016llx", frame,
                     fnv(h0, mvc2_hole_00424200, IMAGE_BYTES), fnv(h0, mvc2_ee_bss, BSS_BYTES),
                     fnv(h0, host_ee_heap_base(), heap_used()));
    for (int i = 0; i < nblk && o < (int)sizeof line - 64; i++)
        o += snprintf(line + o, sizeof line - o, " %s %08llx", blk[i].name,
                      fnv(h0, (const u8 *)blk[i].p, blk[i].n) & 0xFFFFFFFFull);
    host_log("%s", line);
}

/* testing: dump one BSS page as words */
void ra_log_bss_words(long frame, u32 ee)
{
    char line[9000];
    int o = snprintf(line, sizeof line, "bss words %08X frame %ld:", ee, frame);
    for (u32 a = 0; a < 4096; a += 4)
        o += snprintf(line + o, sizeof line - o, " %08x", *(u32 *)(mvc2_ee_bss + (ee - EE_BSS_START) + a));
    host_log("%s", line);
}

/* testing: the BSS in 4 KB pages, to find which words differ between runs */
void ra_log_bss_pages(long frame)
{
    unsigned long long h0 = 0xCBF29CE484222325ull;
    char line[16384];
    int o = snprintf(line, sizeof line, "bss pages frame %ld:", frame);
    for (u32 a = 0; a < BSS_BYTES && o < (int)sizeof line - 16; a += 4096)
        o += snprintf(line + o, sizeof line - o, " %04llx",
                      fnv(h0, mvc2_ee_bss + a, a + 4096 <= BSS_BYTES ? 4096 : BSS_BYTES - a) & 0xFFFF);
    host_log("%s", line);
}
