typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

extern s32 D_004C281C[2];
extern s32 D_004C283C[2];
extern u8 D_004BF37C[8];
extern V3 D_00440690[];
extern f32 D_004406B8[];
extern f32 D_004406BC[];
extern f32 D_004406C0[];
extern V3 D_004B1A18;
extern V3 D_004B1A30[];
typedef struct { u8 pad[0x93]; s8 b93; } G;
extern G *D_004C2840;

extern V3 D_004B8240;
extern f32 D_004B8254[];

static void func_003395E0(u8 *p)
{
    s32 t;
    switch (p[4]) {
    case 0:
        *(u32 *)(p + 0x40) = ((u32)(s32)((double)*(s16 *)(p + 0x1C) * 0.5 * 65536.0 / 360.0 + 0.5) & 0xFFFFu);
        t = *(s16 *)(p + 0x1C) + 1;
        *(s16 *)(p + 0x1C) = (s16)t;
        if (!((s16)t < 0x2D0))
            *(s16 *)(p + 0x1C) = 0;
        break;
    }
}


static void func_0033A4B0(void)
{
    extern u8 *func_003DA750();
    extern void func_0033A590();
    u8 *o;
    double k;
    if ((o = func_003DA750(0, 6, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = (void *)func_0033A590;
        *(s16 *)(o + 0xCC) = 1;
        *(s32 *)(o + 0x84) = D_004C283C[0];
        *(s32 *)(o + 0xD0) = 0x807;
        *(V3 *)(o + 0x34) = D_004B8240;
        k = 65536.0;
        *(s32 *)(o + 0x44) = (u32)(s32)(0.5 + k * (double)D_004B8254[0] / 360.0) & 0xFFFF;
    }
}

void func_0013F100(s32 id)
{
    extern u8 *func_003DA750();
    extern void func_0013F350();
    u8 *o;
    double k;
    if ((o = func_003DA750(0, 6, 1)) != 0) {
        o[0x13C] = 1;
        o[0x20] = id;
        *(void **)(o + 0x10) = (void *)func_0013F350;
        *(s16 *)(o + 0xCC) = D_004BF37C[id];
        *(s32 *)(o + 0x84) = D_004C281C[0];
        *(V3 *)(o + 0x34) = D_00440690[id];
        k = 65536.0;
        *(s32 *)(o + 0x40) = (u32)(s32)(0.5 + k * (double)D_004406B8[0] / 360.0) & 0xFFFF;
        k = 65536.0;
        *(s32 *)(o + 0x44) = (u32)(s32)(0.5 + k * (double)D_004406BC[0] / 360.0) & 0xFFFF;
        k = 65536.0;
        *(s32 *)(o + 0x48) = (u32)(s32)(0.5 + k * (double)D_004406C0[0] / 360.0) & 0xFFFF;
        *(V3 *)(o + 0x50) = D_004B1A18;
        *(s32 *)(o + 0xD0) = 0xC00C1F;
        *(f32 *)(o + 0x78) = 1.0f;
        *(f32 *)(o + 0x7C) = 1.0f;
        *(f32 *)(o + 0x80) = 1.0f;
        if (id == 2) {
            *(V3 *)(o + 0x34) = D_004B1A30[D_004C2840->b93];
            if (D_004C2840->b93 == 0x3A) {
                *(f32 *)(o + 0x50) = 0.75f;
                *(f32 *)(o + 0x54) = 0.75f;
                *(f32 *)(o + 0x58) = 0.75f;
            }
        }
    }
}
