typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern f32 D_004B86B0[];
extern f32 D_004B86B4[];
extern f32 D_004B86D0[];
extern f32 D_004B86D4[];
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_001757E0(u8 *, s32, s32);
extern void func_001C9490(u8 *, s32, s32);
extern void func_00390650(u8 *);

void func_003903F0(u8 *p)
{
    s32 n;
    s32 *d;
    s32 *s;
    u32 t;
    s32 a;
    s32 b;
    s32 c;
    s32 e;

    n = 0x31;
    t = p[4];
    d = (s32 *)(p + 0xEC);
    p[4] = t + 1;
    s = (s32 *)(*(u8 **)(p + 0x18) + 0xEC);
    do {
        *d = *s;
        n--;
        s++;
        d++;
        asm { nop }
        asm { nop }
    } while (n > 0);
    a = 1;
    b = -8;
    c = 0x60;
    e = 0x42;
    p[0x13C] = (u8)a;
    p[2] = (*(u8 **)(p + 0x18))[2];
    p[1] = (*(u8 **)(p + 0x18))[1];
    *(f32 *)(p + 0x50) = *(f32 *)(*(u8 **)(p + 0x18) + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(*(u8 **)(p + 0x18) + 0x54);
    p[0x1B7] = (*(u8 **)(p + 0x18))[0x1B7];
    p[0x1B8] = (*(u8 **)(p + 0x18))[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(*(u8 **)(p + 0x18) + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(*(u8 **)(p + 0x18) + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(*(u8 **)(p + 0x18) + 0x24);
    p[0x13C] = (u8)a;
    *(s8 *)(p + 0x31) = (s8)b;
    *(s16 *)(p + 0x1C) = (s16)c;
    p[0x1B0] = (u8)e;
    p[0x1B1] = (u8)e;
    *(f32 *)(p + 0x34) = D_004B86B0[p[0x20] & 6];
    *(f32 *)(p + 0x38) = D_004B86B4[p[0x20] & 6];
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    *(f32 *)(p + 0x5C) = D_004B86D0[p[0x20] * 2];
    *(f32 *)(p + 0x60) = D_004B86D4[p[0x20] * 2];
    {
        u8 *r = p + 2;
        if (*(s16 *)(p + 0x140)) {
            *(f32 *)(p + 0x34) = -*(f32 *)(p + 0x34);
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        }
        *(f32 *)(p + 0x34) += *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
        *(f32 *)(p + 0x38) += *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
        p[0x1B5] = (u8)(*(s8 *)(p + 0x1B7) + 0x30);
        p[0x1B2] = *(u16 *)(p + 0x1C0) = (u8)(0 & 0xFFFF);
        *(u32 *)(p + 0x1D8) = 0;
        ((s16 *)(D_004C2794 + 0x7C))[*r]++;
    }
    func_001757E0(p, 0x17, (p[0x20] + 4) & 0xFF);
    func_001C9490(p, 2, 0);
    func_00390650(p);
}
