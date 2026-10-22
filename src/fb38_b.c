typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } GB;
typedef struct { s32 w[0x31]; } CB;
typedef struct { f32 x, y, z; } V3b;
typedef struct { u8 pad[0x38]; f32 f38; } PB;
extern GB *D_004C2794;

void func_00372ED0(u8 *p)
{
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_0015E630(u8 *);
    u8 *q, *i2;
    u32 t4;
    f32 f, c;

    t4 = p[4];
    p[4] = t4 + 1;
    *(s16 *)(p + 0x1C) = 0x14;
    q = *(u8 **)(p + 0x18);
    *(CB *)(p + 0xEC) = *(CB *)(q + 0xEC);
    p[0x13C] = 1;
    p[2] = (*(u8 **)(p + 0x18))[2];
    p[1] = (*(u8 **)(p + 0x18))[1];
    *(f32 *)(p + 0x50) = *(f32 *)(*(u8 **)(p + 0x18) + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(*(u8 **)(p + 0x18) + 0x54);
    p[0x1B7] = (*(u8 **)(p + 0x18))[0x1B7];
    p[0x1B8] = (*(u8 **)(p + 0x18))[0x1B8];
    p[0x30] = *(s8 *)(*(u8 **)(p + 0x18) + 0x30);
    *(V3b *)(p + 0x50) = *(V3b *)(*(u8 **)(p + 0x18) + 0x50);
    p[0x24] = *(s8 *)(*(u8 **)(p + 0x18) + 0x24);
    p[0x14C] = 0x40;
    p[0x14D] = 0;
    p[0x14F] = 0x40;
    p[0x14E] = 0x40;
    p[0x24] = 0xB;
    i2 = p + 2;
    if (*(u16 *)(p + 0xD0) != *(u16 *)(q + 0x168)) {
        p[4] = 2;
    } else {
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
        f = 0.0f;
        if (*(s16 *)(q + 0x140) != 0) f = -f;
        *(f32 *)(p + 0x34) += f;
        c = 171.42855834960938f;
        *(f32 *)(p + 0x38) += c;
        if (q[0x20D] == 2) ((PB *)p)->f38 += c;
        *(f32 *)(p + 0x5C) = f;
        *(f32 *)(p + 0x68) = f;
        *(u32 *)(p + 0x60) = 0x424DB6DB;
        *(u32 *)(p + 0x6C) = 0;
        p[0x1B0] = 0x42;
        p[0x1B1] = 0x42;
        p[0x1B5] = 0x39;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[*i2]++;
        q[0x1B5] = 0x39;
        q[0x1B2] = *(u16 *)(q + 0x1C0) = 0;
        *(s32 *)(q + 0x1D8) = 0;
        D_004C2794->f7c[q[2]]++;
        func_001757E0(p, 0x16, 2);
        p[0] = 1;
        func_0015E630(p);
    }
}
