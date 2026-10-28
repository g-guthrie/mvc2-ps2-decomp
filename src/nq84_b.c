typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
typedef struct { u8 pad0[0x7C]; s16 tab[64]; } G_003B66B0;
extern G_003B66B0 *D_004C2794;

void func_003B66B0(u8 *p, u8 *o)
{
    extern void func_001757E0(u8 *, s32, s32);
    s32 i;
    u32 *d;
    f32 *v;
    u32 *s;
    u8 *q;
    u8 *b;
    u32 t;

    q = *(u8 **)(p + 0x18);
    v = (f32 *)(p + 0x88);
    d = (u32 *)(p + 0xEC);
    i = 0x31;
    *(u32 *)(p + 0x14C) = 0x08080808;
    s = (u32 *)(q + 0xEC);
    t = p[4];
    p[4] = t + 1;
    do {
        *d = *s;
        i--;
        s++;
        d++;
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
    v[0] = 25.0f;
    v[1] = 30.0f;
    b = p + 2;
    if (*(s16 *)(o + 0x140) == 0) {
        v[0] = -v[0];
    }
    *(f32 *)(p + 0x34) = *(f32 *)(o + 0x34) + v[0];
    *(f32 *)(p + 0x38) = *(f32 *)(o + 0x38) + v[1];
    p[0x1B0] = 0x44;
    p[0x1B1] = 0x44;
    p[0x1B5] = 0x22;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->tab[*b]++;
    func_001757E0(p, 0x15, 0x1A);
}
