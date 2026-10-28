typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0038DF80(u8 *p)
{
    extern s32 func_00174470();
    extern void func_0038E120(u8 *);
    extern void func_0038E0B0(u8 *);
    extern void func_00175700(u8 *);
    extern void func_001E7F60(u8 *);
    u8 *o = *(u8 **)(p + 0x18);

    if (func_00174470() == 0) {
        func_0038E120(p);
        return;
    }
    if (*(f32 *)(p + 0x38) <= *(f32 *)(o + 0x430)) {
        *(f32 *)(p + 0x38) = *(f32 *)(o + 0x430);
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
        func_0038E0B0(p);
    }
    if (*(s8 *)(p + 0x1B2) != 0) {
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
        func_0038E0B0(p);
    } else if (*(s8 *)(p + 0x1B3) != 0) {
        *(s8 *)(p + 0x1B3) = 0;
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
        func_0038E0B0(p);
    } else {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        func_00175700(p);
        func_001E7F60(p);
    }
}
