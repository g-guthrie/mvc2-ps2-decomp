typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

extern s32 D_004C283C[2];

extern V3 D_004B8148;
extern f32 D_004B815C[];
extern V3 D_004B8188;
extern f32 D_004B819C[];
extern V3 D_004B8030;
extern f32 D_004B8044[];
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

void func_00339690(void)
{
    extern u8 *func_003DA750();
    u8 *o;
    double k;
    if ((o = func_003DA750(0, 5, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = (void *)func_003395E0;
        *(s16 *)(o + 0xCC) = 0x10;
        *(s32 *)(o + 0x84) = D_004C283C[0];
        *(s32 *)(o + 0xD0) = 0x807;
        *(V3 *)(o + 0x34) = D_004B8148;
        k = 65536.0;
        *(s32 *)(o + 0x44) = (u32)(s32)(0.5 + k * (double)D_004B815C[0] / 360.0) & 0xFFFF;
    }
}

void func_0033A0B0(void)
{
    extern u8 *func_003DA750();
    extern void func_0033A000();
    u8 *o;
    double k;
    if ((o = func_003DA750(0, 5, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = (void *)func_0033A000;
        *(s16 *)(o + 0xCC) = 0x12;
        *(s32 *)(o + 0x84) = D_004C283C[0];
        *(s32 *)(o + 0xD0) = 0x807;
        *(V3 *)(o + 0x34) = D_004B8188;
        k = 65536.0;
        *(s32 *)(o + 0x44) = (u32)(s32)(0.5 + k * (double)D_004B819C[0] / 360.0) & 0xFFFF;
    }
}

void func_00337F30(void)
{
    extern u8 *func_003DA750();
    extern void func_00337D50();
    u8 *o;
    double k;
    if ((o = func_003DA750(0, 6, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = (void *)func_00337D50;
        *(s16 *)(o + 0xCC) = 0x29;
        *(s32 *)(o + 0x84) = D_004C283C[0];
        *(s32 *)(o + 0xD0) = 0x800C05;
        *(V3 *)(o + 0x34) = D_004B8030;
        k = 65536.0;
        *(s32 *)(o + 0x44) = (u32)(s32)(0.5 + k * (double)D_004B8044[0] / 360.0) & 0xFFFF;
        *(s16 *)(o + 0x1E) = 1;
    }
}

void func_0033A4B0(void)
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
