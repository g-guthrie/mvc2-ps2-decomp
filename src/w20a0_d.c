typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u32 D_004C2838;
extern u8 *func_003DA750(s32 a, s32 b, s32 c);
extern s32 func_00417A40(void);
extern void func_00162410(void);

void func_001621F0(u8 *p) {
    u8 *o;
    s32 r;
    f32 f;
    if ((o = func_003DA750(0, 0x35, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = (void *)func_00162410;
        *(u32 *)(o + 0xD0) = 0x820415;
        *(u8 **)(o + 0xC8) = p + 0x88;
        *(u8 **)(o + 0x18) = p;
        *(s16 *)(o + 0xCC) = 0x4D;
        *(u32 *)(o + 0x84) = D_004C2838;
        r = func_00417A40() % 6000;
        if (r % 2) f = 3000.0f + (f32)r;
        else f = (f32)(-r) - 3000.0f;
        *(f32 *)(o + 0x34) += f;
        r = func_00417A40() % 1000;
        *(u32 *)(o + 0x38) = 0x447A0000;
        r = (r % 2) ? r : -r;
        *(f32 *)(o + 0x38) += (f32)r;
        r = func_00417A40() % 2400;
        r = (r % 2) ? r : -r;
        *(f32 *)(o + 0x3C) += (f32)r;
        *(f32 *)(o + 0x3C) += -1600.0f;
        *(s16 *)(o + 0x1E) = 0xA0;
        (*(u8 **)(o + 0x18))[6] += 1;
        *(u32 *)(o + 0x44) = (func_00417A40() % 2) ? 0 : 0x8000;
        *(u32 *)(o + 0x78) = 0x3F800000;
        *(u32 *)(o + 0x7C) = 0x3F800000;
        *(u32 *)(o + 0x80) = 0x3F800000;
        *(u32 *)(o + 0x50) = 0x40800000;
        *(u32 *)(o + 0x54) = 0x40800000;
        *(u32 *)(o + 0x58) = 0x3F800000;
    }
}
