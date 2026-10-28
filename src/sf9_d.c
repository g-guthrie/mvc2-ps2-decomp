/* func_003424F0, func_00342910: MWWARM@src/bobbing_position_003421e0.c, 3.0.3 "-O3 -Op -fp off -sdatathreshold 8" */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;
typedef struct { f32 x, y, z; } V3;
extern f32 D_004C1968;
extern s32 D_00460C50[];
extern f32 D_00460C70[];
extern f32 D_00460C74[];
extern V3 D_00460C98;
void func_003424F0(u8 *o) {
    extern f32 func_00417440(u32);
    extern f32 func_00417500(u32);
    extern void func_00154390(u8 *, s32);
    extern void func_0032E690(u8 *);
    extern void func_003DAA40(u8 *);
    s16 v;
    switch (o[4]) {
    case 0:
        o[4] = o[4] + 1;
        *(f32 *)(o + 0x5C) = D_004C1968 * func_00417440((u32)(s32)(0.5 + 65536.0 * (f64)D_00460C50[o[0x20]] / 360.0) & 0xFFFF);
        *(u32 *)(o + 0x60) = 0;
        *(f32 *)(o + 0x64) = D_004C1968 * func_00417500((u32)(s32)(0.5 + 65536.0 * (f64)D_00460C50[o[0x20]] / 360.0) & 0xFFFF);
        *(V3 *)(o + 0x68) = D_00460C98;
        break;
    case 1:
        o[4] = o[4] + 1;
        func_00154390(o + 0x34, 1);
        break;
    case 2:
        func_0032E690(o);
        *(s32 *)(o + 0x40) += (u32)(s32)(0.5 + 65536.0 * (f64)D_00460C70[o[0x20] * 2] / 360.0) & 0xFFFF;
        *(s32 *)(o + 0x48) += (u32)(s32)(0.5 + 65536.0 * (f64)D_00460C74[o[0x20] * 2] / 360.0) & 0xFFFF;
        if (*(f32 *)(o + 0x34) > -250.0f && *(f32 *)(o + 0x34) < 250.0f) {
            if (*(f32 *)(o + 0x38) <= 300.0f) {
                *(f32 *)(o + 0x38) = 300.0f;
                *(f32 *)(o + 0x60) *= -0.30000001192092896f;
                v = *(s16 *)(o + 0x1C) + 1;
                *(s16 *)(o + 0x1C) = v;
                if (v > 2) {
                    o[4]++;
                    *(s16 *)(o + 0x1C) = 0;
                }
            }
        } else {
            if (*(f32 *)(o + 0x38) <= 0.0f) {
                *(f32 *)(o + 0x38) = 0.0f;
                *(f32 *)(o + 0x60) *= -0.30000001192092896f;
                v = *(s16 *)(o + 0x1C) + 1;
                *(s16 *)(o + 0x1C) = v;
                if (v > 2) {
                    o[4]++;
                    *(s16 *)(o + 0x1C) = 0;
                }
            }
        }
        break;
    case 3:
        v = *(s16 *)(o + 0x1C) + 1;
        *(s16 *)(o + 0x1C) = v;
        if (v >= 15) func_003DAA40(o);
        break;
    }
}

void func_00342910(u8 *o) {
    extern f32 func_00417440(u32);
    extern f32 func_00417500(u32);
    extern void func_00154390(u8 *, s32);
    extern void func_0032E690(u8 *);
    extern void func_003DAA40(u8 *);
    s16 v;
    switch (o[4]) {
    case 0:
        o[4] = o[4] + 1;
        *(f32 *)(o + 0x5C) = D_004C1968 * func_00417440((u32)(s32)(0.5 + 65536.0 * (f64)D_00460C50[o[0x20]] / 360.0) & 0xFFFF);
        *(u32 *)(o + 0x60) = 0;
        *(f32 *)(o + 0x64) = D_004C1968 * func_00417500((u32)(s32)(0.5 + 65536.0 * (f64)D_00460C50[o[0x20]] / 360.0) & 0xFFFF);
        *(V3 *)(o + 0x68) = D_00460C98;
        break;
    case 1:
        o[4] = o[4] + 1;
        func_00154390(o + 0x34, 1);
        break;
    case 2:
        func_0032E690(o);
        *(s32 *)(o + 0x40) += (u32)(s32)(0.5 + 65536.0 * (f64)D_00460C70[o[0x20] * 2] / 360.0) & 0xFFFF;
        *(s32 *)(o + 0x48) += (u32)(s32)(0.5 + 65536.0 * (f64)D_00460C74[o[0x20] * 2] / 360.0) & 0xFFFF;
        if (*(f32 *)(o + 0x34) > -250.0f && *(f32 *)(o + 0x34) < 250.0f) {
            if (*(f32 *)(o + 0x38) <= 300.0f) {
                *(f32 *)(o + 0x38) = 300.0f;
                *(f32 *)(o + 0x60) *= -0.30000001192092896f;
                v = *(s16 *)(o + 0x1C) + 1;
                *(s16 *)(o + 0x1C) = v;
                if (v > 2) {
                    o[4]++;
                    *(s16 *)(o + 0x1C) = 0;
                }
            }
        } else {
            if (*(f32 *)(o + 0x38) <= 0.0f) {
                *(f32 *)(o + 0x38) = 0.0f;
                *(f32 *)(o + 0x60) *= -0.30000001192092896f;
                v = *(s16 *)(o + 0x1C) + 1;
                *(s16 *)(o + 0x1C) = v;
                if (v > 2) {
                    o[4]++;
                    *(s16 *)(o + 0x1C) = 0;
                }
            }
        }
        break;
    case 3:
        v = *(s16 *)(o + 0x1C) + 1;
        *(s16 *)(o + 0x1C) = v;
        if (v >= 15) func_003DAA40(o);
        break;
    }
}
