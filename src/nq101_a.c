typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
extern u8 *D_004C2794;

void func_00354B00(u8 *p, u8 *q)
{
    extern void func_00354DD0(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    s32 i;
    u32 *d;
    u32 *s;
    u32 t;
    s = (u32 *)(q + 0xEC);
    i = 0x31;
    t = p[4];
    p[4] = t + 1;
    d = (u32 *)(p + 0xEC);
    do {
        *d++ = *s++;
        i--;
    } while (i > 0);
    p[0x13C] = 1;
    p[2] = q[2];
    p[1] = q[1];
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
    p[0x1B7] = q[0x1B7];
    p[0x1B8] = q[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(q + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    *(s16 *)(p + 0x1C) = 4;
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    p[0x24] = p[0x21] ? 0xC : 0xB;
    *(s16 *)(p + 0x140) = p[0x21] ? 0 : 1;
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = 85.71427917480469f + *(f32 *)(q + 0x38);
    p[0x1B5] = 0x44;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    {
        u32 c;
        c = (u32)D_004C2794;
        c = (p[2] << 1) + c;
        c += 0x7C;
        ++*(s16 *)c;
    }
    func_00354DD0(p);
    func_001757E0(p, 0x17, (u8)(p[0x20] + 0xE));
}
