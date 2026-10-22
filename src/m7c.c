typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

extern u8 *D_004C2840;
extern void func_00175700();
void func_0038FF20(u8 *p) {
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) < *(f32 *)(*(u8 **)(p + 0x18) + 0x430)) {
        u32 t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x430);
    }
    func_00175700(p);
}

extern s32 func_00174470();
extern void func_0034DC00();
void func_0034DB80(u8 *p) {
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (!func_00174470(p)) func_0034DC00(p);
}

extern void func_00389170();
extern void (*D_00464B30[])();
void func_00388E00(u8 *a, u8 *b) {
    u8 *s = b + 0x2B8;
    if (*(s16 *)(b + 0x2D6) == 0) {
        u32 t = a[5];
        a[5] = t + 1;
        a[6] = 0;
        a[0x13C] = 1;
        func_00389170(a, b);
    } else {
        a[0x13C] = 1;
        if (s[0x19]) a[0x13C] = 0;
        D_00464B30[a[6]](a, b);
    }
}

extern V3 D_004B33CC, D_004B33C0;
extern void func_001450C0(u8 *p);
typedef struct { u8 pad0[4]; u8 b4; u8 b6x; u8 pad6[0x16]; s16 h1c; } S1;
/* func_00145F30: not yet matched without a stand-in callee. */

