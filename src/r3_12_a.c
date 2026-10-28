typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

static u16 func_00220260(u8 *actor, s32 b) {
    u16 t = b & 0x3C00;
    u16 hi = (t & 0x3000) / 0x1000;
    u16 lo = (t & 0xC00) / 0x100;
    hi |= lo;
    return hi;
}

void func_002202B0(u8 *p) {
    extern s32 func_00175700(u8 *);
    extern void func_001830D0(u8 *, u32 *, s32);
    extern void func_001E3210(u8 *, s32);
    extern void func_002206A0(u8 *);
    u32 v[3];
    u16 h;
    u8 *q;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
if ((s8)func_00175700(p) >= 0) { if (*(s8 *)(p + 0x151) != 0) { p[0x151] = 0; p[0x404] = 0; p[0x405] = 0; if (*(f32 *)(p + 0x38) > *(f32 *)(p + 0x430)) { v[0] = 0xC0555555; v[1] = 0x43632492; } else { v[0] = 0xC23AAAAA; v[1] = 0x43610000; } v[2] = 0; func_001830D0(p, v, 1); } return; } { func_001E3210(p, 0x16);
        func_001E3210(p, 0x22);
        *(s16 *)(p + 0x2DC) = *(s16 *)(p + 0x2DE) + 0x1E;
        *(s16 *)(p + 0x2DE) = 0;
        q = p + 0x2B8;
        if (*(s8 *)(p + 0x539) != 0) h = *(u16 *)(q + 0x2A);
        else h = *(u16 *)(p + 0x35E);
if ((h &= 0x3C00) != 0) {
            *(u16 *)(q + 0x1C) = func_00220260(p, h);
            *(u16 *)(q + 0x1C) &= 0xF;
        }
        { u32 t = p[6]; p[6] = t + 1; }
        p[7] = 0;
        func_002206A0(p); }
}
