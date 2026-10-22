typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s32 w[49]; } W49_g;
typedef struct { u8 pad0[2]; u8 b02; u8 pad34[0x31]; f32 f34; f32 f38; u8 pad3C[0x20]; f32 f5c; f32 f60; u8 pad64[4]; f32 f68; f32 f6c; } K_g;
typedef struct { f32 x, y, z; } V3_g;
typedef struct { u8 pad[0x7C]; s16 f7c[8]; } G_g;
extern G_g *D_004C2794;
extern u8 D_004C1E00[8];
extern f32 D_004B8660[];
extern f32 D_004B8664[];
extern f32 D_004B8680[];
extern f32 D_004B8684[];
extern f32 D_004B8688[];
extern f32 D_004B868C[];

void func_0038F9E0(u8 *p)
{
    u32 t;
    K_g *k;
    u8 *r;
    extern s32 func_001757E0(u8 *, s32, u8);
    extern void func_0038FC40(u8 *);

    k = (K_g *)p;
    t = p[4];
    p[4] = t + 1;
    *(W49_g *)(p + 0xEC) = *(W49_g *)(*(u8 **)(p + 0x18) + 0xEC);
    p[0x13C] = 1;
    p[2] = (*(u8 **)(p + 0x18))[2];
    p[1] = (*(u8 **)(p + 0x18))[1];
    *(f32 *)(p + 0x50) = *(f32 *)(*(u8 **)(p + 0x18) + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(*(u8 **)(p + 0x18) + 0x54);
    p[0x1B7] = (*(u8 **)(p + 0x18))[0x1B7];
    p[0x1B8] = (*(u8 **)(p + 0x18))[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(*(u8 **)(p + 0x18) + 0x30);
    *(V3_g *)(p + 0x50) = *(V3_g *)(*(u8 **)(p + 0x18) + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(*(u8 **)(p + 0x18) + 0x24);
    p[0x13C] = 1;
    *(s8 *)(p + 0x31) = -8;
    p[0x22] = 0;
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    k->f34 = *(f32 *)((u8 *)D_004B8660 + (p[0x20] << 3));
    k->f38 = *(f32 *)((u8 *)D_004B8664 + (p[0x20] << 3));
    k->f5c = *(f32 *)((u8 *)D_004B8680 + (p[0x20] << 4));
    k->f68 = *(f32 *)((u8 *)D_004B8684 + (p[0x20] << 4));
    k->f60 = *(f32 *)((u8 *)D_004B8688 + (p[0x20] << 4));
    k->f6c = *(f32 *)((u8 *)D_004B868C + (p[0x20] << 4));
    r = p + 2;
    if (*(s16 *)(p + 0x140) != 0) {
        k->f34 = -k->f34;
        k->f5c = -k->f5c;
        k->f68 = -k->f68;
    }
    k->f34 += *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    k->f38 += *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    p[0x1B5] = D_004C1E00[p[0x20]];
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[*r]++;
    func_001757E0(p, 0x17, p[0x20] + 1);
    func_0038FC40(p);
}
