typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s32 x[0x31]; } S31;
typedef struct { f32 x, y, z; } V3;
typedef struct { f32 a, b, c; } T12;

extern T12 D_0044A6C0[];
extern void func_001757E0(u8 *, s32, s32);

void func_00199AE0(u8 *p)
{
    f32 k;
    *(S31 *)(p + 0xEC) = *(S31 *)(*(u8 **)(p + 0x14) + 0xEC);
    p[0x13C] = 1;
    p[2] = (*(u8 **)(p + 0x14))[2];
    p[1] = (*(u8 **)(p + 0x14))[1];
    *(f32 *)(p + 0x50) = *(f32 *)(*(u8 **)(p + 0x14) + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(*(u8 **)(p + 0x14) + 0x54);
    p[0x1B7] = (*(u8 **)(p + 0x14))[0x1B7];
    p[0x1B8] = (*(u8 **)(p + 0x14))[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(*(u8 **)(p + 0x14) + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(*(u8 **)(p + 0x14) + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(*(u8 **)(p + 0x14) + 0x24);
    *(s16 *)(p + 0x140) = p[0x22];
    p[0x24] = 0xC;
    if (*(s16 *)(p + 0x140) != 0) {
        k = -D_0044A6C0[p[0x21]].a;
    } else {
        k = D_0044A6C0[p[0x21]].a;
    }
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x14) + 0x34) + k;
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x14) + 0x38) + D_0044A6C0[p[0x21]].b;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    if (*(s16 *)(p + 0x140) != 0) {
        k = D_0044A6C0[p[0x21]].c;
    } else {
        k = -D_0044A6C0[p[0x21]].c;
    }
    *(f32 *)(p + 0x5C) = k;
    p[0x14C] = 0x10;
    p[0x14D] = 0x10;
    p[0x14E] = 0x30;
    p[0x14F] = 0x30;
    func_001757E0(p, 0x17, 0xF);
}
