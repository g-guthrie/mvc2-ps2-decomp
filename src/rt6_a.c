typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_003B0E00(u8 *p, u8 *q)
{
    u32 t;
    u32 u;
    extern void func_00174910(u8 *, s32);
    extern void func_00175700(u8 *);
    extern s32 func_00174470(u8 *);

    if (p[7] == 0) {
        t = p[7];
        p[7] = t + 1;
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
        p[0x22] = 0x20 - *(s8 *)(p + 0x22);
        u = *(volatile u8 *)(p + 0x22);
        p[0x22] = u & 0x1F;
        func_00174910(p, 0x258);
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    } else {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        func_00175700(p);
        if (func_00174470(p) == 0) {
            p[4] = 3;
            return;
        } else if (*(f32 *)(q + 0x430) > *(f32 *)(p + 0x38)) {
            p[4] = 2;
            p[6] = 0;
            p[7] = 0;
            return;
        }
        return;
    }
}
