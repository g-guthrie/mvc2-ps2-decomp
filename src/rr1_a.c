typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004D18D8[];

void func_00266B60(u8 *p, u8 *q) {
    extern s8 func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001B53E0(u8 *, s32, s32);
    extern void func_00176160(u8 *, s32, s32, s32);
    extern void func_001E3210(u8 *, s32);
    extern void func_001E3710(u8 *, s32);
    extern void func_00191210(u8 *);
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    if (func_00175700(p) < 0) {
        t = p[7];
        p[7] = t + 1;
        *(u32 *)(q + 0xC) = 0x3F000000;
        *(u32 *)(q + 0x14) = 0x3F000000;
        *(f32 *)(p + 0x50) = *(f32 *)(q + 0xC);
        *(f32 *)(p + 0x54) = *(f32 *)(q + 0x14);
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        func_001757E0(p, 0x16, 0x3F);
        if ((D_004D18D8[0] & (1 << p[2])) == 0) func_001B53E0(p, 0, 1);
        func_00176160(p, 0, p[0x25] + 6, 1);
        func_00176160(p, 2, 0xC, 2);
        func_001E3210(p, 0x22);
        func_001E3710(p, 0x35);
        p[0x216] |= 0x80;
        p[0x1FF] = 2;
        func_00191210(p);
    }
}
