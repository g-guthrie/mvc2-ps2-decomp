typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_003616D0(u8 *p, u8 *q)
{
    extern void func_00361900(u8 *, s32);
    extern void func_00175700(u8 *);
    extern void func_001E7F60(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern s32 func_00174470(u8 *);
    extern void func_00361850(u8 *, u8 *);
    u16 *r;
    u32 t;

    r = (u16 *)(p + 0xD0);
    { s32 a = *(s32 *)(p + 0x14); *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68); func_00361900(p, a); }
    func_00175700(p);
    func_001E7F60(p);
    if (q[0x2C0] != 0 || *(u16 *)(q + 0x168) != *r) {
        t = p[5];
        p[5] = t + 1;
        if (p[0x20] == 2) func_001757E0(p, 0x17, 0x13); else func_001757E0(p, 0x17, 0x15);
        return;
    }
    {
    if (func_00174470(p) == 0) {
        t = p[4];
        p[4] = t + 1;
        func_00361850(p, q);
        return;
    }
    }
}
