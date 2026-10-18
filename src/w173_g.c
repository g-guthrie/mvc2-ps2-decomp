typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x160]; s8 b[8]; } S2C9D80;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G2C9D80;
extern G2C9D80 *D_004C2794;

void func_002C9D80(u8 *p, u8 *q)
{
    extern void func_00175700();
    extern void func_001E3710(u8 *, s32);
    s8 *r, *r1;
    s8 f;
    f32 v;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700();
    r = ((S2C9D80 *)p)->b;
    f = r[1];
    r1 = r + 1;
    if (f != 0) {
        p[6]++;
        *r1 = 0;
        p[0x1B5] = 0x3D;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        q[5] = 2;
        if (p[0x1E6] != 0) v = 23.333332061767578f; else v = -23.333332061767578f;
        *(f32 *)(p + 0x5C) = v;
        if (p[0x1E6] != 0) v = -0.8333333134651184f; else v = 0.8333333134651184f;
        *(f32 *)(p + 0x68) = v;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x6C) = 0;
        func_001E3710(p, 0x29);
    }
}
