/*
 * The EE data that has no C (Port J).
 *
 * The host links the EE data image contiguously in EE address order (R18):
 * each credited C data unit, then a "hole" up to the next unit.  The holes
 * hold data no C source defines (tables the game reads, e.g. the round-time
 * table D_004C21E8, strings, the VU microcode) and are zero in the build,
 * which carries no game bytes.  At boot the holes are filled from the
 * user's own executable on the disc (SLUS_204.86, ELF PT_LOAD segments).
 *
 * Words that look like EE addresses (0x00100000..0x0063FFFF, aligned) are
 * left zero: an EE pointer means nothing in host memory.
 */
#include <stdlib.h>
#include <string.h>
#include "host.h"
#include "host_cri.h"

extern const unsigned int mvc2_ee_holes[][2];
extern const int mvc2_ee_nholes;
extern unsigned char mvc2_hole_00424200[];
#define IMAGE_EE 0x00424200u

static u32 rd32(const u8 *p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
static u16 rd16(const u8 *p) { return (u16)(p[0] | p[1] << 8); }

/* bytes of EE address range [ee, ee+n) from the ELF image, 0 if not loaded */
static const u8 *elf_at(const u8 *elf, size_t size, u32 ee, u32 n)
{
    u32 phoff = rd32(elf + 0x1C), i;
    u16 phnum = rd16(elf + 0x2C), phsz = rd16(elf + 0x2A);
    for (i = 0; i < phnum; i++) {
        const u8 *ph = elf + phoff + i * phsz;
        u32 off = rd32(ph + 4), va = rd32(ph + 8), fsz = rd32(ph + 16);
        if (rd32(ph) != 1)
            continue;
        if (ee >= va && ee + n <= va + fsz && off + (ee - va) + n <= size)
            return elf + off + (ee - va);
    }
    return 0;
}

int host_fill_ee_holes(void)
{
    GameDisc *d = host_disc();
    size_t size = 0;
    u8 *elf;
    int i, filled = 0, ptrs = 0;
    if (!d)
        return -1;
    elf = iso_load(&d->iso, "/SLUS_204.86", &size);
    if (!elf || size < 0x34 || memcmp(elf, "\x7f" "ELF", 4) != 0) {
        host_log("ee image: SLUS_204.86 not found on the disc; EE data without C stays zero");
        free(elf);
        return -1;
    }
    for (i = 0; i < mvc2_ee_nholes; i++) {
        u32 lo = mvc2_ee_holes[i][0], n = mvc2_ee_holes[i][1], k;
        const u8 *src = elf_at(elf, size, lo, n);
        u8 *dst = mvc2_hole_00424200 + (lo - IMAGE_EE);
        if (!src)
            continue;   /* .bss-like (beyond the file image): stays zero */
        memcpy(dst, src, n);
        for (k = (4 - (lo & 3)) & 3; k + 4 <= n; k += 4) {
            u32 w = rd32(dst + k);
            if (w >= 0x00100000u && w < 0x00640000u && (w & 3) == 0) {
                memset(dst + k, 0, 4);
                ptrs++;
            }
        }
        filled += (int)n;
    }
    free(elf);
    host_log("ee image: %d bytes of EE data without C filled from SLUS_204.86 (%d EE pointers left zero)",
             filled, ptrs);
    return 0;
}
