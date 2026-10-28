/* s5d: MW 3.0.3, ./try.sh src/s5d_f.c "-O3 -sdatathreshold 0" (also 3.0). static func_00220260 is the real callee (credited in src/q0.c); assignment in the test (h &= 0x3C00) keeps the raw load in a1. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;

extern s32 func_00175700(u8 *);
extern void func_00220F50(u8 *);
static u16 func_00220260(u8 *actor, s32 b) {
    u16 t = b & 0x3C00;
    u16 hi = (t & 0x3000) / 0x1000;
    u16 lo = (t & 0xC00) / 0x100;
    hi |= lo;
    return hi;
}
extern void func_00220E40(u8 *);
extern void func_001E3210(u8 *, s32);

void func_00220D50(u8 *p)
{
    u8 *q;
    u16 h;
    if ((s8)func_00175700(p) >= 0) {
        if (*(u16 *)(p + 0x362) & 0x360) {
            p[7] = 1;
            return;
        }
        return;
    }
    *(s32 *)(p + 0x5C) = 0;
    *(s32 *)(p + 0x60) = 0;
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x6C) = 0;
    q = p + 0x2B8;
    if (*(s8 *)(p + 0x539) == 0) {
        if (p[7] == 0) {
            func_00220F50(p);
            return;
        }
        h = *(u16 *)(p + 0x35E);
    } else {
        h = *(u16 *)(q + 0x2A);
    }
    if ((h &= 0x3C00) != 0) {
        p[6]++;
        *(s16 *)(q + 0x24) = 0x10;
        *(s16 *)(q + 0x1C) = func_00220260(p, h);
        func_00220E40(p);
        func_001E3210(p, 0x22);
        return;
    }
    func_00220F50(p);
}
