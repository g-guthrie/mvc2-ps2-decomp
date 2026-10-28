typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { s32 w[0x31]; } B3c;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G3c;
typedef struct { u8 pad[0x34]; f32 f34; } PK;
typedef struct { s16 a; s16 b; s8 c; u8 d; u8 e; u8 f; } T8;
extern G3c *D_004C2794;
extern T8 D_00464270[];

void residual_0037EAC0(u8 *p)
{
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_0037ECD0(u8 *);
    u8 *o;
    u8 *s;
    T8 *t;
    u8 *q;
    o = *(u8 **)(p + 0x18);
    p[4]++;
    *(u16 *)(p + 0x26) = 0x1802;
    *(B3c *)(p + 0xEC) = *(B3c *)(o + 0xEC);
    p[0x13C] = 1;
    p[2] = o[2];
    p[1] = o[1];
    *(f32 *)(p + 0x50) = *(f32 *)(o + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(o + 0x54);
    p[0x1B7] = o[0x1B7];
    p[0x1B8] = o[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(o + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(o + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(o + 0x24);
    p[0x13C] = 1;
    t = &D_00464270[p[0x20]];
    *(s8 *)(p + 0x24) = t->c;
    q = p + 2;
    if (p[0x20] == 0 || p[0x20] == 1) {
        s = *(u8 **)(p + 0x18);
    } else {
        s = *(u8 **)(p + 0x14);
    }
    *(V3 *)(p + 0x34) = *(V3 *)(s + 0x34);
    if (*(s16 *)(s + 0x140) == 0) {
        ((PK *)p)->f34 += 1.6666666269302368f * (f32)t->a;
    } else {
        ((PK *)p)->f34 -= 1.6666666269302368f * (f32)t->a;
    }
    *(f32 *)(p + 0x38) += 2.142857074737549f * (f32)t->b;
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    p[0x1B5] = t->f;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[*q]++;
    func_001757E0(p, 0x17, t->e);
    func_0037ECD0(p);
}
