/* Palette callback: table 00454F70, installed by func_0027AC60.
 * The existing 48-byte palette record view is used only for code access. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef struct { s32 f0, f4, dirty, fC; u16 colors[16]; } PaletteRecord;
extern PaletteRecord D_004F54D0[];
extern u8 *D_004C2794;
extern int func_00186CE0(u8 *, u8);
void func_0027AF80(u8 *p)
{
    PaletteRecord *e = &D_004F54D0[*(s16 *)(p + 0x13E)];
    u8 *q = p + 0x2B8;
    u8 *work;
    switch (q[0]) {
    case 0:
        q[0]++;
        e->dirty = 1;
        e->colors[10] |= 0xC000;
        e->colors[11] |= 0xC000;
        e->colors[12] |= 0xC000;
        e->colors[13] |= 0xC000;
        e->colors[14] |= 0xC000;
        q[1] = 4;
    case 1:
        if (q[1]-- == 0) {
            q[1] = 4;
            e->dirty = 1;
            e->colors[10] -= 0x1000;
            e->colors[11] -= 0x1000;
            e->colors[12] -= 0x1000;
            e->colors[13] -= 0x1000;
            e->colors[14] -= 0x1000;
            if ((e->colors[10] & 0xF000) == 0x7000) q[0]++;
        }
        break;
    case 2:
        if (q[1]-- == 0) {
            q[1] = 4;
            e->dirty = 1;
            e->colors[10] += 0x1000;
            e->colors[11] += 0x1000;
            e->colors[12] += 0x1000;
            e->colors[13] += 0x1000;
            e->colors[14] += 0x1000;
            if ((e->colors[10] & 0xF000) == 0xF000) q[0] = 1;
        }
        break;
    }
    work = D_004C2794;
    if (work[0] >= 5 && ((s8)work[0x3E] < 0 || (s8)work[0x3E] != p[2]) && p[5] == 0 && p[0x1E4] == 0) {
        func_00186CE0(p, 0x15);
        p[0x1FD] = 4;
    }
    if (*(s16 *)(p + 0x434) == 0) p[0x209] = 1;
}
