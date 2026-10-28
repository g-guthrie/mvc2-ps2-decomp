typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

typedef struct { f32 x, y, z; } F3_a;
typedef struct { F3_a pos; f32 c, d, e; u16 h18; u8 b1a; s8 b1b; } E_a;
extern E_a *D_00443960[];
extern u16 D_004435E0[];
extern f32 D_004435C8[];
extern F3_a D_00442AA0;
extern s32 D_004C2804;
extern u8 *D_004C2840;

void func_00147B70(u8 *p, s32 a1)
{
    extern void func_003DAA40();
    E_a *e;
    u16 v;
    u32 i;
    { u32 t = p[4]; p[4] = t + 1; }
    p[0x13C] = 1;
    i = p[0x21];
    e = D_00443960[i];
    if (e == 0) {
        func_003DAA40(p, a1);
        return;
    }
    { u32 k = p[0x20]; e += k; if (k == 4) v = D_004435E0[i]; else v = e->h18; }
    *(u16 *)(p + 0xCC) = v;
    *(s32 *)(p + 0x84) = D_004C2804;
    *(F3_a *)(p + 0x34) = e->pos;
    *(F3_a *)(p + 0x50) = D_00442AA0;
    *(s32 *)(p + 0x48) = (u16)((u32)(s32)(0.5 + 65536.0 * (double)D_004435C8[e->b1b] / 360.0));
    *(u32 *)(p + 0xD0) |= 0x428;
    *(f32 *)(p + 0x74) = 1.0f;
    *(f32 *)(p + 0x78) = e->c;
    *(f32 *)(p + 0x7C) = e->d;
    *(f32 *)(p + 0x80) = e->e;
    *(s32 *)(p + 0xDC) = ((s8)D_004C2840[3] << 8) | (s8)D_004C2840[4];
    if (p[0x20] == 1) {
        *(u32 *)(p + 0xD0) |= 0x800000;
    }
}
