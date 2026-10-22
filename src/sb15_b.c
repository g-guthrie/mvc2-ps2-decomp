typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

extern s32 D_004C283C[2];
extern V3 D_004B81A8;
extern f32 D_004B81BC[];

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

void func_0033A240(void)
{
    extern u8 *func_003DA750();
    extern void func_0033A190();
    u8 *o;
    double k;
    if ((o = func_003DA750(0, 5, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = (void *)func_0033A190;
        *(s16 *)(o + 0xCC) = 0x13;
        *(s32 *)(o + 0x84) = D_004C283C[0];
        *(s32 *)(o + 0xD0) = 0x807;
        *(V3 *)(o + 0x34) = D_004B81A8;
        k = 65536.0;
        *(s32 *)(o + 0x44) = (u32)(s32)(0.5 + k * (double)D_004B81BC[0] / 360.0) & 0xFFFF;
    }
}
