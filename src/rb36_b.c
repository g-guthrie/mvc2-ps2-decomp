typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 D_004D18A0[];
extern s32 *D_004C2840;

void func_00255460(u8 *o) {
    extern void func_00176090(u8 *, s32, s32, s32);
    u16 *c;
    s16 n;
    s32 v;

    n = *(s16 *)(o + 0x2B8);
    c = (u16 *)(o + 0x2B8);
    if (n == 0) {
        *c = 0;
        if (c[2] == 0) func_00176090(o, 0, 0, 1);
        return;
    }
    if (D_004D18A0[0] >= 5) {
        *c = 0;
        if (c[2] == 0) func_00176090(o, 0, 0, 1);
        return;
    }
    if (o[0x425] != 0) {
        *c = 0;
        if (c[2] == 0) func_00176090(o, 0, 0, 1);
        return;
    }
    if (*(s16 *)(o + 0x434) <= 0) {
        *c = 0;
        if (c[2] == 0) func_00176090(o, 0, 0, 1);
        return;
    }
    *c = n - 1;
    o[0x33C] = 5;
    if (c[2] != 0) return;
    { s32 t = D_004C2840[7] % 4; v = t & 0xFF; }
    if (v >= 2) func_00176090(o, 0, 6, 1);
    else if (v >= 0) func_00176090(o, 0, 7, 1);
    else func_00176090(o, 0, 0, 1);
}
