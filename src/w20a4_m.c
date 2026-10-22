typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 D_004C2838;

void func_001628C0(u8 *p) {
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_00162640();
    extern s32 func_00174170();
    extern s32 func_00417A40();
    extern s32 func_00118FA8(f32);
    u8 *o;
    u8 i;
    s32 r;
    s32 m;
    s32 t;
    s32 z;
    for (i = 0; i < 5; i++) {
        if ((o = func_003DA750(0, 0x31, 1)) == 0) {
            return;
        }
        o[0x13C] = 0;
        *(void **)(o + 0x10) = (void *)func_00162640;
        *(s32 *)(o + 0xD0) = 0x2F;
        o[0x23] = i;
        *(f32 *)(o + 0x50) = 1.0f;
        *(f32 *)(o + 0x54) = 1.0f;
        *(s32 *)(o + 0xD8) = o[0x23] << 3;
        *(u8 **)(o + 0x18) = p;
        *(s32 *)(o + 0x44) = (*(s16 *)(p + 0x140) != 0) ? 0 : 0x8000;
        *(s32 *)(o + 0xDC) = func_00174170();
        *(s32 *)(o + 0xDC) = *(s32 *)(o + 0xDC) % 2;
        if (*(s32 *)(o + 0xDC) != 0) {
            *(s16 *)(o + 0xCC) = 0x50;
            *(s32 *)(o + 0x84) = D_004C2838;
        } else {
            *(s16 *)(o + 0xCC) = 0x56;
            *(s32 *)(o + 0x84) = D_004C2838;
        }
        r = func_00417A40();
        m = func_00118FA8(1.6666666269302368f * (f32)(u32)p[0x14E] * *(f32 *)(p + 0x50));
        if (r % 2 != 0) {
            t = r % m;
        } else {
            t = -(r % m);
        }
        *(f32 *)(o + 0x5C) += (f32)t;
        r = func_00417A40();
        m = func_00118FA8(2.142857074737549f * (f32)(u32)p[0x14C] * *(f32 *)(p + 0x54));
        *(f32 *)(o + 0x60) += (f32)(r % m);
        *(f32 *)(o + 0x34) = *(f32 *)(p + 0x34) + *(f32 *)(o + 0x5C);
        *(f32 *)(o + 0x38) = *(f32 *)(p + 0x38) + *(f32 *)(o + 0x60);
        z = func_00417A40() % 2;
        *(s32 *)(o + 0x40) = (z != 0) ? 0 : 0x8000;
        z = func_00417A40() % 2;
        *(s32 *)(o + 0x44) = (z != 0) ? 0 : 0x8000;
        z = func_00417A40() % 2;
        *(s32 *)(o + 0x48) = (z != 0) ? 0 : 0x8000;
    }
}
