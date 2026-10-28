typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;
typedef struct { f32 x, y, z; } V3;

extern void *D_004C2838;

extern u8 D_004449E0[];
extern u8 D_00444A00[];
extern u8 D_00444A20[];
extern u8 D_00444A30[];

/* Verified copy of retail func_00154E10 (src/z9_k.c), the address-order
   neighbour three functions before func_001551A0; exact at 0x00154E10 under
   this file's flags. Kept referenced so MWCC compiles it first. */
static void func_00154E10(u8 *p) {
    extern void func_003DAA40(struct Object *);
    extern f32 func_00154710(u8 *, u8 *, s16);
    extern double func_00119058(f32);
    f32 f;
    if (*(s16 *)(p + 0x1C) > 10) {
        func_003DAA40((struct Object *)p);
        return;
    }
    *(f32 *)(p + 0x54) = func_00154710(D_004449E0, p + 4, *(s16 *)(p + 0x1C));
    *(f32 *)(p + 0x58) = func_00154710(D_00444A00, p + 5, *(s16 *)(p + 0x1C));
    f = func_00154710(D_00444A20, p + 6, *(s16 *)(p + 0x1C));
    *(u32 *)(p + 0x40) = (u16)((u32)(s32)(65536.0 * func_00119058(f) / 360.0 + 0.5));
    f = func_00154710(D_00444A30, p + 7, *(s16 *)(p + 0x1C));
    *(f32 *)(p + 0x78) = f;
    *(f32 *)(p + 0x7C) = f;
    *(f32 *)(p + 0x80) = *(f32 *)(p + 0x78);
    *(s16 *)(p + 0x1C) += 1;
}
static void (*keep_00154E10)(u8 *) = func_00154E10;

void func_001551A0(f32 *pos, u32 n, f32 scale, int type) {
    extern void *func_003DA750(void *, int, int);
    extern void func_001553B0(u8 *);
    extern s32 func_00417A40(void);
    extern f32 func_00417440(u32);
    extern f32 func_00417500(u32);
    extern f32 func_00417F60(void);
    u8 *o;
    u16 ang;
    f32 k, r, t;
    u8 effect_kind = ((u8)type == 9) ? 0x18 : 0x3C;
    if ((o = func_003DA750(0, effect_kind, 1)) != 0) {
        o[0x13C] = 1;
        *(void (**)(u8 *))(o + 0x10) = func_001553B0;
        *(s16 *)(o + 0xCC) = func_00417A40() % 3 + 0x60;
        *(void **)(o + 0x84) = D_004C2838;
        *(V3 *)(o + 0x34) = *(V3 *)pos;
        ang = (u16)(s32)(0.5 + 65536.0 * (double)(11.25f * (f32)n) / 360.0);
        k = 0.5f * func_00417440(ang);
        r = func_00417F60();
        *(f32 *)(o + 0x5C) = scale * (r - 0.5f + k);
        k = func_00417F60() - 0.5f;
        t = func_00417500(ang);
        *(f32 *)(o + 0x60) = scale * (k + 0.5f * t);
        *(f32 *)(o + 0x64) = scale * (0.5f * func_00417F60());
        *(f32 *)(o + 0x68) = -*(f32 *)(o + 0x5C) / 30.0f;
        *(f32 *)(o + 0x6C) = -*(f32 *)(o + 0x60) / 30.0f;
        *(f32 *)(o + 0x70) = -*(f32 *)(o + 0x64) / 30.0f;
        *(s32 *)(o + 0x74) = 0x3F800000;
        *(s32 *)(o + 0xD0) = 0x21;
    }
}
