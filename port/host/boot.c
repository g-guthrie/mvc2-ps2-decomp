/*
 * Platform init, heap, vsync and flip on the host (Port J).
 *
 *   func_003EC160  flInitialize(640, 480)  (C-less, asm 0x003EC160..0x003ECBDC)
 *   func_001044E0  sbrk                    (credited; EE kernel heap end)
 *   func_003ECBE0  vsync interrupt handler (credited; GS register writes)
 *   func_003ECD00  flip                    (C-less; GS CSR polling, DMA kick)
 *   func_003DC720  start the built DMA chain (credited; DMAC)
 *
 * func_003EC160 is a C port of the asm: every memory-side step runs the
 * game's own C in the original order (the 22 MB arena, the 6 MB handle pool,
 * the packet heaps, the video/VRAM bookkeeping, the DMA queues, the double
 * buffer structs, the VRAM allocator, pad/state init, the default render
 * state).  The IOP reboot, the IRX loads, sceGsResetGraph, the GS VRAM clear
 * (func_003ED000) and the INTC/DMAC register writes are skipped: there is no
 * IOP and no GS.  The memory card, sound driver and CRI file system inits are
 * called (they are host-implemented further down: cri.c, iop.c).
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "host.h"

extern int func_00418CC0(void); /* memory card wrapper init (credited C) */
extern void func_003DCD40(void *, unsigned char, int);
extern void *func_0011CB70(int);
extern void func_003F12C0(void *, ...);
extern int func_003F0940(void *, unsigned int, unsigned int, unsigned int);
extern void *func_003DCFC0(int);
extern void func_003DB980(void *, unsigned int, unsigned int);
extern void *func_003DCF70(int);
extern void func_0011CBC8(void *);
extern void func_003DD070(void);
extern void func_003DC250(void *, int, int);
extern int func_003DC3C0(int);
extern void func_001020E0(void *, short, short, short, short, short, short);
extern void func_003EB900(void);
extern int func_00419F70(void);
extern int func_00418B80(void);
extern int func_003DAD60(void);
extern int func_003DF7D0(void);
extern void func_003DD0D0(void);
extern int func_00419FC0(int);
extern int func_003FE9E8(int);

int host_verbose;
void (*host_present_hook)(void);
unsigned long host_frame_count;

void host_log(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    fputs("[host] ", stderr);
    vfprintf(stderr, fmt, ap);
    fputc('\n', stderr);
    va_end(ap);
}

/* ---- sbrk ------------------------------------------------------------
 * The EE heap runs from the end of the BSS to the top of the 32 MB RAM
 * (EndOfHeap).  newlib malloc (the game's own, func_0011CE68) grows it with
 * this; the first request is flInitialize's 22 MB arena. */
#define HOST_EE_HEAP (28u << 20)
static u8 *ee_heap, *ee_brk;

void *func_001044E0(int increment)
{
    u8 *old;
    if (!ee_heap) {
        ee_heap = (u8 *)calloc(1, HOST_EE_HEAP + 64);
        if (!ee_heap)
            return (void *)-1;
        ee_brk = (u8 *)(((uintptr_t)ee_heap + 63) & ~(uintptr_t)63);
    }
    if (increment < 0 ? (size_t)-increment > (size_t)(ee_brk - ee_heap)
                      : (size_t)increment > (size_t)(ee_heap + HOST_EE_HEAP - ee_brk))
        return (void *)-1;
    old = ee_brk;
    ee_brk += increment;
    return old;
}

/* ---- DMA channels (sceDmaGetChan results) -----------------------------
 * The render library writes CHCR-ish fields of the channel struct before a
 * send (func_003DC720).  Plain memory on the host. */
static u8 host_dmac[10][0x100] __attribute__((aligned(16)));

s32 func_003EC160(void)
{
    void *arena;
    s32 s2, s1, a2, t2;
    u32 bc68;
    int i;

    func_003DCD40(EE_BSS_PTR(0x0062BC00), 0, 0x420);
    arena = func_0011CB70(0x1600000);
    if (!arena) {
        func_003F12C0((void *)"flInitialize: no memory for the 22 MB arena\n");
        return 0;
    }
    func_003F0940(EE_BSS_PTR(0x0062C020), (u32)(uintptr_t)arena, 0x1600000, 0x40);
    EE_BSS(s32, 0x0062BFD0) = 0x600000;
    EE_BSS(void *, 0x0062BFCC) = func_003DCFC0(EE_BSS(s32, 0x0062BFD0));
    func_003DB980(EE_BSS(void *, 0x0062BFCC), EE_BSS(u32, 0x0062BFD0), 0x10);
    EE_BSS(void *, 0x004C2B0C) = (void *)func_003DCF70;
    EE_BSS(void *, 0x004C2B08) = (void *)func_0011CBC8;
    func_003DD070();

    /* video parameters: NTSC, half height (FRAME mode), PSMCT32, Z32 */
    EE_BSS(s32, 0x0062BC00) = 0;
    EE_BSS(s32, 0x0062BC04) = 4;
    EE_BSS(s32, 0x0062BC1C) = 4;
    s2 = 0x280;
    s1 = EE_BSS(s32, 0x0062BC00) ? 0x1C0 : 0xE0;
    EE_BSS(s32, 0x0062BF8C) = 0;
    EE_BSS(s32, 0x0062BF90) = 0;
    /* BC04 == 4 */
    EE_BSS(s32, 0x0062BC08) = 0;
    EE_BSS(s32, 0x0062BC0C) = 0x40;
    EE_BSS(s32, 0x0062BC10) = 0x20;
    EE_BSS(s32, 0x0062BC14) = 0;
    if (EE_BSS(s32, 0x0062BC00) == 1)
        EE_BSS(s32, 0x0062BC18) = 0;
    else
        EE_BSS(s32, 0x0062BC18) = (s32)((((u32)s2 + EE_BSS(u32, 0x0062BC0C) - 1) / EE_BSS(u32, 0x0062BC0C)) *
                                         (((u32)s1 + EE_BSS(u32, 0x0062BC10) - 1) / EE_BSS(u32, 0x0062BC10)) << 5);
    /* BC1C == 4, BC04 != 2: Z = PSMZ32 */
    EE_BSS(s32, 0x0062BC20) = 0x30;
    EE_BSS(s32, 0x0062BC24) = 0x40;
    EE_BSS(s32, 0x0062BC28) = 0x20;
    EE_BSS(u32, 0x0062BC30) = 0x4B7FFF28u; /* 16777000.0f */

    EE_BSS(s32, 0x004C2AE4) = s2;
    EE_BSS(s32, 0x004C2AE0) = s1;
    EE_BSS(s32, 0x0062BF84) = 0x800 - (s2 >> 1);
    EE_BSS(s32, 0x0062BF88) = 0x800 - (s1 >> 1);
    a2 = EE_BSS(s32, 0x0062BC0C);
    t2 = EE_BSS(s32, 0x0062BC10);
    EE_BSS(s32, 0x0062BC2C) = EE_BSS(s32, 0x0062BC18) +
        (s32)((((u32)s2 + a2 - 1) / (u32)a2) * (((u32)s1 + t2 - 1) / (u32)t2) << 5);
    EE_BSS(s32, 0x0062BC34) = EE_BSS(s32, 0x0062BC2C) +
        (s32)((((u32)s2 + EE_BSS(u32, 0x0062BC24) - 1) / EE_BSS(u32, 0x0062BC24)) *
              (((u32)s1 + EE_BSS(u32, 0x0062BC28) - 1) / EE_BSS(u32, 0x0062BC28)) << 5);

    /* skipped: sceSifInitRpc, sceCdInit, sceCdMmode, IOP reboot (IOPRP255.IMG),
     * SIO2MAN/PADMAN/USBD/USBMLOAD/USBKB, MCMAN/MCSERV (func_00418C70),
     * LIBSD/MODHSYN/MODMIDI/MODMSIN/TSNDDRV (func_00419EE0), CRI_ADXI
     * (func_00418B50), sceDmaReset (func_00100478), func_001025A8, VU0 init
     * (func_00103958). */
    for (i = 0; i < 10; i++)
        EE_BSS(void *, 0x0062BF9C + 4 * i) = host_dmac[i];

    EE_BSS(s32, 0x0062BBD0) = 2;
    func_003DC250(EE_BSS_PTR(0x0062BBD0), 0x400, (int)(uintptr_t)func_003DC3C0);
    EE_BSS(s32, 0x0062BBA0) = 1;
    func_003DC250(EE_BSS_PTR(0x0062BBA0), 0xC00, (int)(uintptr_t)func_003DC3C0);
    /* skipped: sceGsResetGraph(0, INTERLACE, NTSC, FRAME) */
    func_001020E0(EE_BSS_PTR(0x0062BC50), (short)EE_BSS(s32, 0x0062BC08), (short)s2, (short)s1, 3,
                  (short)EE_BSS(s32, 0x0062BC20), 1);
    /* BC00 != 2, BC04 != 2: no field patches */
    EE_BSS(unsigned long long, 0x0062BF40) = 0;
    EE_BSS(unsigned long long, 0x0062BDD0) = 0;
    EE_BSS(s32, 0x0062C048) = s1;
    EE_BSS(s32, 0x0062C044) = s2;
    EE_BSS(s32, 0x0062C050) = 0;
    EE_BSS(s32, 0x0062C040) = 0;
    bc68 = EE_BSS(u32, 0x0062BC68);
    EE_BSS(u32, 0x0062BF94) = EE_BSS(u16, 0x0062BC68) & 0xFFF;
    EE_BSS(s32, 0x0062C054) = EE_BSS(s32, 0x0062BC04);
    EE_BSS(u32, 0x0062BF98) = (bc68 >> 12) & 0x7FF;
    EE_BSS(s32, 0x0062C04C) = s2 * EE_BSS(s32, 0x0062BC04);
    /* BC04 == 4: RGBA8888 channel layout */
    EE_BSS(s32, 0x0062C05C) = 0;
    EE_BSS(s32, 0x0062C058) = 8;
    EE_BSS(s32, 0x0062C074) = 0x10;
    EE_BSS(s32, 0x0062C060) = 0xFF;
    EE_BSS(s32, 0x0062C080) = 0x18;
    EE_BSS(s32, 0x0062C064) = 8;
    EE_BSS(s32, 0x0062C068) = 8;
    EE_BSS(s32, 0x0062C06C) = 0xFF;
    EE_BSS(s32, 0x0062C070) = 8;
    EE_BSS(s32, 0x0062C07C) = 8;
    EE_BSS(s32, 0x0062C078) = 0xFF;
    EE_BSS(s32, 0x0062C084) = 0xFF;

    EE_BSS(s32, 0x0062BC3C) = 0;
    EE_BSS(s32, 0x0062BC38) = 1;
    EE_BSS(s32, 0x0062BC40) = 0;
    func_003EB900();
    EE_BSS(s32, 0x004C2AEC) = 1;
    func_00418CC0();
    func_00419F70();
    func_00418B80();
    func_003DAD60();
    EE_BSS(s32, 0x004C2AD8) = 100;
    /* skipped: func_003ED000 (clears GS VRAM through 16 image uploads) */
    EE_BSS(s32, 0x0062BC38) = 0; /* field after the sceGsSyncV(0) loop */
    /* skipped: sceGsSyncVCallback(func_003ECBE0): the host calls host_vsync_irq */
    EE_BSS(s32, 0x0062BFC8) = 0;
    EE_BSS(s32, 0x0062BFC4) = -1;
    func_003DF7D0();
    /* skipped: INTC/DMAC mask writes 0x10000810 / 0x10000800 */
    host_log("platform init done: arena %p (22 MB), handle pool %p (6 MB)", arena,
             EE_BSS(void *, 0x0062BFCC));
    return 1;
}

/* ---- vsync ------------------------------------------------------------
 * func_003ECBE0: count the vsync, and when a flip is pending toggle the
 * displayed buffer.  The GS display registers and the CRI vsync server tick
 * (func_003FE9E8) are not needed on the host. */
void host_vsync_irq(void)
{
    EE_BSS(s32, 0x0062BC40) += 1;
    if (EE_BSS(s32, 0x0062BC44) == 1) {
        EE_BSS(s32, 0x0062BC44) = 0;
        EE_BSS(s32, 0x0062BC3C) ^= 1;
    }
    EE_BSS(s32, 0x0062BC38) ^= 1; /* interlace field */
}

void func_003ECBE0(void)
{
    host_vsync_irq();
}

/* ---- DMA kick ------------------------------------------------------------
 * func_003DC720 starts the VIF1 chain of the buffer that was just built;
 * the DMAC interrupt handler func_003DC3C0 then walks it and clears the
 * per-buffer counters when it drains.  The host draws at call time (port/
 * render), so the chain is complete as soon as it is "started": clear the
 * counters of both queues for that buffer. */
void func_003DC720(void)
{
    s32 idx = EE_BSS(s32, 0x0062BFD8) ^ 1;
    s32 *q;
    int k;
    for (k = 0; k < 2; k++) {
        q = (s32 *)EE_BSS_PTR(k ? 0x0062BBD0 : 0x0062BBA0);
        q[5 + idx] = 0;
        q[7 + idx] = 0;
        q[9 + idx] = 0;
    }
}

/* ---- flip -------------------------------------------------------------
 * func_003ECD00: flush the sound queue, wait for the other buffer's chain
 * (instant here), wait for a vsync, mark the flip pending, write the display
 * registers, swap the draw buffer index, kick the built chain and reset the
 * packet heap.  The host presents the picture here (frontend hook). */
s32 func_003ECD00(void)
{
    func_00419FC0(1);
    if (EE_BSS(s32, 0x0062BC40) == 0)
        host_vsync_irq();
    EE_BSS(s32, 0x0062BC44) = 1;
    if (host_present_hook)
        host_present_hook();
    host_vsync_irq(); /* the vsync that shows it */
    EE_BSS(s32, 0x0062BC40) = 0;
    EE_BSS(s32, 0x004C2ADC) += 1;
    EE_BSS(s32, 0x0062BFD8) ^= 1;
    func_003DC720();
    func_003DD0D0();
    EE_BSS(s32, 0x0062BFC8) = 0;
    EE_BSS(s32, 0x0062BFC4) = -1;
    host_frame_count++;
    return 0;
}

/* sceGsSyncV(0): wait for a vsync, return the field (GS CSR.FIELD). */
int func_00100E68(void)
{
    host_vsync_irq();
    return EE_BSS(s32, 0x0062BC38);
}
