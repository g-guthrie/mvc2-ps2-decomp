/* func_0036D550: MW 3.0.3 "-O3 -Op -sdatathreshold 8". C380-sibling style: tt = D_004C1C90 set just before it is indexed, tab = D_00463B50 and sc set just before the table copy. */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } Gb;
extern Gb *D_004C2794;
extern u16 D_004C1C90[4];
extern f32 D_00463B50[];

void func_0036D550(u8 *p)
{
    extern void func_001757E0(u8 *, s32, s32);
    f32 sc;
    const u16 *tt;
    f32 *tab;

    p[0x13C] = 1;

    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x14) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x14) + 0x38);
    *(f32 *)(p + 0x3C) = *(f32 *)(*(u8 **)(p + 0x14) + 0x3C);
    *(f32 *)(p + 0x38) += 34.28571319580078f;
    *(s16 *)(p + 0x140) = *(s16 *)(*(u8 **)(p + 0x14) + 0x140);

    p[0x24] = 10;

    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    p[0x1B5] = 0x40;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]] += 1;
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x6C) = 0;
    p[0x21] = 0;
    tt = D_004C1C90; 
    tt += *(u8 *)(*(u8 **)(p + 0x18) + 0x1B7);
    *(u16 *)(p + 0x1C) = *tt;
    *(s16 *)(p + 0x1E) = 0x5A;
    tab = D_00463B50; sc = 0.4000000059604645f; 
    tab += p[0x23] * 4;
    *(f32 *)(p + 0x5C) = tab[0];
    *(f32 *)(p + 0x68) = tab[1];
    *(f32 *)(p + 0x60) = tab[2];
    *(f32 *)(p + 0x6C) = tab[3];
    *(f32 *)(p + 0x50) = sc;
    *(f32 *)(p + 0x54) = sc;
    *(f32 *)(p + 0x5C) = *(s16 *)(p + 0x140) ? *(f32 *)(p + 0x5C) : -*(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x68) = *(s16 *)(p + 0x140) ? -*(f32 *)(p + 0x68) : *(f32 *)(p + 0x68);
    p[0x169] = 0x17;
    func_001757E0(p, p[0x169], 0x39);
}
