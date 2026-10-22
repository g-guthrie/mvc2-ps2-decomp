typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad[0x18]; s8 b18; u8 pad2[0x10]; s8 b29; } G2840;
extern G2840 *D_004C2840;
extern u8 D_0043E8E0[];

void func_00133CE0(u8 *p, u8 *q)
{
    extern void func_001347D0(u8 *, u8 *);
    extern void func_00134230(u8 *, u8 *);
    extern void func_001345B0(u8 *, u8 *);
    extern void func_00134610(u8 *, u8 *);
    extern void func_001E3CE0(u8);
    s16 v;
    s16 h;
    s16 t;
    s32 x;
    func_001347D0(p, q);
    v = *(s16 *)(p + 0x1C);
    *(s16 *)(p + 0x1C) = v + 1;
    if (v < 0x1F) {
        if (v == 0x1E) {
            func_00134230(p, q);
        }
        return;
    }
    h = *(s16 *)(p + 0x13E);
    if (h < 3) {
        p[5] = 0;
        p[0x20] = 1;
        func_001345B0(p, q);
        return;
    }
    t = *(s16 *)(p + 0x140) & 1;
    *(s16 *)(p + 0x140) = t;
    if (t != 0 && (q[0x288] & 1) != 0) {
        *(s16 *)(p + 0x140) = 0;
        p[0x14C] = 10;
        if (D_004C2840->b29 != 0) p[0x14C] = 11;
        if (h >= 6 && (D_004C2840->b18 & (1 << p[2])) != 0) {
            if (D_004C2840->b29 == 0) func_001E3CE0(12);
            else func_001E3CE0(13);
        }
    } else {
        s32 r = 13;
        if (h >= 4) r = 4;
        if (h >= 6) r = 5;
        if (h >= 8) r = 6;
        if (h >= 10) r = 7;
        if (h >= 30) r = 8;
        if (h >= 50) r = 14;
        if (h >= 100) r = 9;
        p[0x14C] = r;
    }
    p[5] = 0;
    p[0x20] = 3;
    func_00134610(p, q);
    func_001345B0(p, q);
    x = D_0043E8E0[p[0x14C] & 0xF];
    if (x != 0) func_001E3CE0(x);
}
