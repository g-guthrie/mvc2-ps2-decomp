typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u8 pad[0x7C];
    s16 f7c[16];
} G;

extern G *D_004C2794;
extern u8 D_00452150[];
extern u8 D_00452151[];

void func_002371C0(u8 *a, u8 *b)
{
    extern void func_001266A0(u8 *, s32, s8);
    extern void func_003290B0(u8 *);
    extern u8 func_00237E40(u8 *, u32);
    extern void func_00237D40(u8 *, u8);
    extern void func_001E3210(u8 *, s32);
    extern void func_001757E0(u8 *, s32, u8);
    u32 t;
    s32 h;
    s32 hh;
    u8 v;
    s32 r;
    s32 x;
    u8 y;
    u32 idx;
    u8 k;

    a[0x40C] = 2;
    a[0x33C] = 5;
    t = a[7];
    a[7] = t + 1;
    *(s16 *)(a + 0x140) = 0;
    *(s16 *)(a + 0x1C) = 0x1E;
    b[0x1B] = 0;
    k = a[2] ? 3 : 4;
    func_001266A0(a, 1, k);
    func_003290B0(a);
    h = (u16)(*(s16 *)(a + 0x354) & 0x3C00);
    if (h == 0) {
        b[0x1E] = a[0x22];
        r = func_00237E40(a, *(u32 *)(a + 0x220)) & 0xFF;
        if (r & 0x20) {
            r = (0x40 - r) & 0x1F;
        }
        v = r;
        if (v > 0x12) {
            y = 0x15;
            x = 0;
        } else if (v > 0xE) {
            y = 0x10;
            x = 2;
        } else {
            y = 8;
            x = 1;
        }
    } else {
        hh = h & 0xFFFF;
        idx = (u16)((hh >> 11) | ((hh >> 10) & 1)) << 1;
        y = D_00452150[idx];
        x = D_00452151[idx];
    }
    if (a[0x1E6] == 0) {
        y = (0x40 - (s8)y) & 0x3F;
    }
    a[0x22] = y;
    if (a[0x20] == 0) {
        x += 0x45;
    } else {
        x += 0x49;
    }
    a[0x1B5] = x;
    a[0x1B2] = *(u16 *)(a + 0x1C0) = 0;
    *(u32 *)(a + 0x1D8) = 0;
    D_004C2794->f7c[a[2]]++;
    *(u16 *)(a + 0x1C0) = 0x20;
    a[0x1E6] = 0;
    func_00237D40(a, a[0x22]);
    func_001E3210(a, 0x14);
    func_001757E0(a, 0x16, (a[0x22] >> 2) + 0xC);
}
