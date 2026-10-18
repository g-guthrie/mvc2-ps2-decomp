typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004B5830[];
extern u8 D_004B58B0[];
extern u8 D_004B58B4[];

void func_001C9B70(u8 *p)
{
    extern void func_00175670(u8 *);
    extern void func_001754A0(u8 *, s32, s32);
    u8 *e;
    u8 *q;
    s32 a;
    s8 b;
    s16 h;
    q = *(u8 **)(p + 0x18);
    p[0x13C] = 0;
    a = *(s8 *)(q + 0x161);
    if (a != 0) p[0x13C] = 1;
    b = a;
    e = D_004B5830 + b * 2;
    if (b == p[0x22]) {
        func_00175670(p);
    } else {
        p[0x22] = a;
        func_001754A0(p, 0x1B, e[0]);
    }
    *(s8 *)(p + 0x31) = -8;
    if (*(s8 *)(p + 0x151) != 0) *(s8 *)(p + 0x31) = 8;
    *(f32 *)(p + 0x34) = *(f32 *)(D_004B58B0 + (e[1] << 3));
    *(f32 *)(p + 0x38) = *(f32 *)(D_004B58B4 + (e[1] << 3));
    h = *(s16 *)(q + 0x140);
    *(s16 *)(p + 0x140) = h;
    if (h != 0) *(f32 *)(p + 0x34) = -*(f32 *)(p + 0x34);
    *(f32 *)(p + 0x34) += *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) += *(f32 *)(q + 0x38);
}
