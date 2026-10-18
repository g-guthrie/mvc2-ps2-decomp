typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s32 a[2]; } T8I;
typedef struct { f32 a[2]; } T8F;
extern T8I D_004BF408;
extern T8F D_004BF410;
extern s32 D_004C27E8;

static void func_00150520(u8 *o, f32 a, f32 b, f32 c) {
    *(f32 *)(o + 0x40) = a;
    *(f32 *)(o + 0x44) = b;
    *(f32 *)(o + 0x48) = c;
}

void func_00150AE0(u8 *a, s16 b, s32 n, f32 x, f32 y, f32 z) {
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_00150C00(void);
    T8I ia;
    T8F fa;
    u8 *o;
    ia = D_004BF408;
    fa = D_004BF410;
    if ((o = func_003DA750(0, 0xD, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = (void *)func_00150C00;
        *(s32 *)(o + 0xD0) = 0x431;
        *(f32 *)(o + 0x34) = x + fa.a[n];
        *(f32 *)(o + 0x38) = y;
        *(f32 *)(o + 0x3C) = z;
        *(s16 *)(o + 0x1E) = b;
        func_00150520(o, 0.4991999864578247f, 1.0f, 1.0f);
        *(u32 *)(o + 0x50) = 0x3F800000;
        *(u32 *)(o + 0x54) = 0x3F800000;
        *(u32 *)(o + 0x58) = 0x3F800000;
        *(u8 **)(o + 0xC8) = a + 0x88;
        *(u8 **)(o + 0x18) = a;
        *(s16 *)(o + 0xCC) = ia.a[n];
        *(s32 *)(o + 0x84) = D_004C27E8;
    }
}
