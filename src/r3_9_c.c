/* nearmiss func_003433A0: 3.0.3 -O3 -Op -fp off -sdatathreshold 0 cold: 7/214 words, dispatch temp a1 where retail a2 (needs warm from func_00342D40, unmatched) */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;
typedef struct { f32 x, y, z; } V3;

extern s32 D_004F1CDC;
extern V3 D_00460770[];
extern s32 D_00460810[];
extern f32 D_00460870[];
extern V3 D_00460CA8;
extern f32 D_00460830[];
extern f32 D_00460834[];
extern f32 D_004607D0[][2];

extern f32 D_004606E0[];
extern f32 D_004606EC[];
extern f32 D_00460700[];
extern f32 D_0046070C[];

void func_00342D40(u8 *o) {
    extern void func_003440E0(s32);
    extern void func_001E3630(s32);
    u8 s;
    s16 v;
    f32 t;
    f32 h;
    f32 h2;
    f32 h3;
    s = o[4];
    switch (s) {
    case 0:
        if (D_004F1CDC == 1) {
            o[4] = s + 1;
            *(s16 *)(o + 0x1E) = 0x78;
        }
        break;
    case 1:
        v = *(s16 *)(o + 0x1C) + 1;
        *(s16 *)(o + 0x1C) = v;
        if (v > 0xF0) {
            o[4]++;
            *(s16 *)(o + 0x1C) = 0;
            *(s16 *)(o + 0x1E) = 0xF0;
            *(u32 *)(o + 0xD0) |= 0x400;
            *(f32 *)(o + 0x78) = 1.0f;
            *(f32 *)(o + 0x7C) = 1.0f;
            *(f32 *)(o + 0x80) = 1.0f;
            func_003440E0(0);
            func_003440E0(1);
            func_001E3630(0x1F);
            return;
        }
        break;
    case 2:
        t = (f32)*(s16 *)(o + 0x1C) / (f32)*(s16 *)(o + 0x1E);
        *(f32 *)(o + 0x34) = D_004606E0[0] + t * (D_004606EC[0] - D_004606E0[0]);
        *(f32 *)(o + 0x38) = D_004606E0[1] + t * (D_004606EC[1] - D_004606E0[1]);
        *(f32 *)(o + 0x3C) = D_004606E0[2] + t * (D_004606EC[2] - D_004606E0[2]);
        *(s32 *)(o + 0x40) = (u32)(s32)(0.5 + 65536.0 * (f64)(D_00460700[0] + t * (D_0046070C[0] - D_00460700[0])) / 360.0) & 0xFFFF;
        *(s32 *)(o + 0x44) = (u32)(s32)(0.5 + 65536.0 * (f64)(D_00460700[1] + t * (D_0046070C[1] - D_00460700[1])) / 360.0) & 0xFFFF;
        *(s32 *)(o + 0x48) = (u32)(s32)(0.5 + 65536.0 * (f64)(D_00460700[2] + t * (D_0046070C[2] - D_00460700[2])) / 360.0) & 0xFFFF;
        h = 1.0f - t / 2.0f;
        *(f32 *)(o + 0x78) = h;
        *(f32 *)(o + 0x7C) = 1.0f;
        *(f32 *)(o + 0x80) = h;
        if (*(s16 *)(o + 0x1C) % 2) *(f32 *)(o + 0x34) += 5.0f;
        else *(f32 *)(o + 0x34) -= 5.0f;
        v = *(s16 *)(o + 0x1C) + 1;
        *(s16 *)(o + 0x1C) = v;
        if (v >= *(s16 *)(o + 0x1E)) {
            o[4]++;
            *(s16 *)(o + 0x1C) = 0;
            *(f32 *)(o + 0x78) = 0.5f;
            *(f32 *)(o + 0x7C) = 1.0f;
            *(f32 *)(o + 0x80) = 0.5f;
        }
        break;
    case 3:
        if (D_004F1CDC >= 2) {
            o[4] = s + 1;
            *(s16 *)(o + 0x1C) = 0;
            *(s16 *)(o + 0x1E) = 0xF0;
            func_001E3630(0x1F);
        }
        break;
    case 4:
        t = (f32)*(s16 *)(o + 0x1C) / (f32)*(s16 *)(o + 0x1E);
        *(f32 *)(o + 0x38) += -2.0f;
        h = 0.5f + t / 2.0f;
        h3 = 0.5f - t / 2.0f;
        h2 = 1.0f - t;
        *(f32 *)(o + 0x78) = h;
        *(f32 *)(o + 0x7C) = h2;
        *(f32 *)(o + 0x80) = h3;
        if (*(s16 *)(o + 0x1C) % 2) *(f32 *)(o + 0x34) += 5.0f;
        else *(f32 *)(o + 0x34) -= 5.0f;
        v = *(s16 *)(o + 0x1C) + 1;
        *(s16 *)(o + 0x1C) = v;
        if (v > 0xF0) {
            o[4]++;
            *(f32 *)(o + 0x78) = 1.0f;
            *(f32 *)(o + 0x7C) = 0.0f;
            *(f32 *)(o + 0x80) = 0.0f;
        }
        break;
    case 5:
        break;
    }
}

void func_003433A0(u8 *o) {
    extern f32 func_00417440(u32);
    extern f32 func_00417500(u32);
    extern void func_0032E690(u8 *);
    extern void func_003DAA40(u8 *);
    u32 t;
    s16 v;
    f32 r;
    switch (o[4]) {
    case 0:
        o[4] = o[4] + 1;
        *(V3 *)(o + 0x34) = D_00460770[o[0x20]];
        break;
    case 1:
        if (D_004F1CDC == 1) {
            o[4] = o[4] + 1;
            *(f32 *)(o + 0x5C) = D_00460870[o[0x20]] * func_00417440((u32)(s32)(0.5 + 65536.0 * (f64)D_00460810[o[0x20]] / 360.0) & 0xFFFF);
            *(u32 *)(o + 0x60) = 0;
            *(f32 *)(o + 0x64) = D_00460870[o[0x20]] * func_00417500((u32)(s32)(0.5 + 65536.0 * (f64)D_00460810[o[0x20]] / 360.0) & 0xFFFF);
            *(V3 *)(o + 0x68) = D_00460CA8;
        }
        break;
    case 2:
        func_0032E690(o);
        *(s32 *)(o + 0x40) += (u32)(s32)(0.5 + 65536.0 * (f64)D_00460830[o[0x20] * 2] / 360.0) & 0xFFFF;
        *(s32 *)(o + 0x48) += (u32)(s32)(0.5 + 65536.0 * (f64)D_00460834[o[0x20] * 2] / 360.0) & 0xFFFF;
        if (*(f32 *)(o + 0x38) <= D_004607D0[o[0x20]][*(s16 *)(o + 0x1C)]) {
            *(f32 *)(o + 0x60) *= -0.30000001192092896f;
            v = *(s16 *)(o + 0x1C) + 1;
            *(s16 *)(o + 0x1C) = v;
            if (v >= 2) {
                o[4]++;
                *(s16 *)(o + 0x1C) = 0;
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
