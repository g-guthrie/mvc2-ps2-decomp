typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

void residual_00355400(u8 *p)
{
    extern s32 func_00174470();
    extern s32 func_00417A40();
    extern void func_0019BA70(u8 *, s32);
    extern void func_00175700(u8 *);
    extern void func_001E7F60(u8 *);
    u8 *o = *(u8 **)(p + 0x18);
    if (*(s8 *)(p + 0x1B2) != 0 || !(51.42856979370117f + *(f32 *)(o + 0x430) <= *(f32 *)(p + 0x38))) {
        p[4]++;
        return;
    }
    if (func_00174470(p) == 0) {
        p[0x13C] = 0;
        p[4] = 3;
        return;
    }
    *(s16 *)(p + 0x1C) -= 1;
    if (*(s16 *)(p + 0x1C) == 0) {
        *(s16 *)(p + 0x1C) = func_00417A40();
        *(s16 *)(p + 0x1C) &= 3;
        *(s16 *)(p + 0x1C) += 1;
        func_0019BA70(p, 0);
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    func_001E7F60(p);
}
