typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3a;
typedef struct { s32 w[0x31]; } S31;

extern f32 D_0044EF70[];
extern f32 D_0044EF74[];

void func_001E07F0(u8 *a, u8 *b)
{
    extern void func_001754A0(u8 *, s32, s32);
    extern void func_0015E630(u8 *);
    u32 t;
    s32 i;
    s32 *d;
    s32 *s;
    s32 x, y;
    s32 k;
    f32 fv;

    t = a[4];
    a[4] = t + 1;
    *(S31 *)(a + 0xEC) = *(S31 *)(b + 0xEC);
    a[0x13C] = 1;
    a[2] = b[2];
    a[1] = b[1];
    *(f32 *)(a + 0x50) = *(f32 *)(b + 0x50);
    *(f32 *)(a + 0x54) = *(f32 *)(b + 0x54);
    a[0x1B7] = b[0x1B7];
    a[0x1B8] = b[0x1B8];
    *(s8 *)(a + 0x30) = *(s8 *)(b + 0x30);
    *(V3a *)(a + 0x50) = *(V3a *)(b + 0x50);
    *(s8 *)(a + 0x24) = *(s8 *)(b + 0x24);
    a[0] = 1;
    a[0x24] = 8;
    *(V3a *)(a + 0x34) = *(V3a *)(b + 0x34);
    k = a[0x20];
    x = (s32)(*(f32 *)((u8 *)D_0044EF70 + k * 8));
    y = (s32)(*(f32 *)((u8 *)D_0044EF74 + k * 8));
    if (*(s16 *)(a + 0x140) != 0) {
        x = -x;
        y = -y;
    }
    *(f32 *)(a + 0x34) += (f32)x;
    *(f32 *)(a + 0x5C) = (f32)y;
    a[0x14F] = 0x20;
    a[0x14E] = 0x20;
    a[0x14D] = 0x20;
    a[0x14C] = 0x20;
    *(u32 *)(a + 0xD0) = b[0x169];
    func_001754A0(a, 0x1B, a[0x20]);
    if (a[0x20] == 0) {
        a[0] = 1;
        a[0x159] = 0x1A;
        func_0015E630(a);
    }
}
