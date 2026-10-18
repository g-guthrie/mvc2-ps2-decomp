typedef float f32;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern f32 D_004643BC[];
extern u8 *D_004C2794;
extern void (*D_00455458[])(u8 *);
extern void (*D_00463DB0[])(u8 *, u8 *, u8 *);

void func_001BB3F0(u8 *p) {
    extern void func_00175670();
    s16 v;
    f32 a, b;
    func_00175670(p);
    a = 0.10900000482797623f;
    b = 0.4360000193119049f;
    *(f32 *)(p + 0x50) -= a;
    *(f32 *)(p + 0x54) += b;
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        p[4] = 4;
        *(s16 *)(p + 0x1C) = 10;
    } else {
        p[0x13C] = (*(s16 *)(p + 0x1C) % 2) ? 1 : 0;
    }
}

typedef struct { f32 x, y, z; } V3_80090;
extern V3_80090 D_00464350;
typedef struct { s16 a, b; } P16_;
extern P16_ D_00464328[];
extern s32 D_004C283C;
void func_00380090(u8 *p) {
    extern u8 *func_003DA750();
    extern void func_00380040();
    extern s32 func_00417A40();
    u8 *o;
    s32 r;
    if ((o = func_003DA750(0, 8, 1)) != 0) {
        *(u8 **)(o + 0x18) = p;
        *(s16 *)(o + 0x26) = 0x1804;
        o[0x13C] = 1;
        *(void (**)())(o + 0x10) = func_00380040;
        *(s32 *)(o + 0xD0) = 0x1F;
        r = func_00417A40();
        *(s32 *)(o + 0x48) = r % 0x4000;
        *(V3_80090 *)(o + 0x50) = D_00464350;
        *(s16 *)(o + 0xCC) = D_00464328[p[0x23]].a;
        *(s32 *)(o + 0x84) = D_004C283C;
    }
}

void func_0032F890(u8 *p) {
    f32 z;
    u32 t;
    s16 h;
    *(f32 *)(p + 0x34) += -145.0f;
    *(f32 *)(p + 0x38) += -84.0f;
    switch (p[5]) {
    case 0:
        h = *(s16 *)(p + 0x1C) + 1;
        *(s16 *)(p + 0x1C) = h;
        if (h >= 0x32) {
            t = p[5];
            p[5] = t + 1;
            *(s16 *)(p + 0x1C) = 0;
        }
        break;
    case 1:
        *(f32 *)(p + 0x78) -= 0.019999999552965164f;
        *(f32 *)(p + 0x7C) -= 0.019999999552965164f;
        *(f32 *)(p + 0x80) -= 0.019999999552965164f;
        z = 0.0f;
        if (*(f32 *)(p + 0x78) <= z) {
            p[4] = 0;
            p[0x13C] = 0;
        }
        break;
    }
}
