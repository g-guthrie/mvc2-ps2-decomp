typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern u8 D_004D18A5;
extern s8 D_004D18DE;
extern u8 D_004D18A3;

s32 func_002803A0(u8 *p, u8 m)
{
    extern void func_00186A60(u8 *, u8);
    extern void func_001757E0(u8 *, s32, s32);
    s32 v;
    u8 a;
    p[0x13C] = 1;
    func_00186A60(p, m);
    p[7] = 0;
    p[6] = 0;
    p[5] = 0;
    *(u32 *)(p + 0x48) = 0;
    *(V3 *)(p + 0x50) = *(V3 *)(p + 0x298);
    D_004D18A5 = 1;
    switch (m) {
    case 1:
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        p[0x210] = 0;
        p[0x20D] = 0;
        break;
    case 0x16:
        v = D_004D18DE;
        if (v < 0) {
            a = 4;
        } else {
            a = 0;
            if (v != p[2])
                a = 1;
            if (D_004D18A3 != 0)
                a += 2;
        }
        p[0x20] = a;
        p[0x20D] = 0;
        break;
    case 0:
    default:
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        *(s8 *)(p + 0x1E7) = -1;
        p[0x210] = 0;
        p[0x20D] = 0;
        if ((p[0x216] & 0x80) != 0)
            p[0x168] = 1;
        else
            p[0x168] = 0;
        func_001757E0(p, 0, p[0x168]);
        break;
    }
    return 1;
}
