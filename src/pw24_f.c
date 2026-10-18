typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00174470();
extern s32 func_001C47D0();
extern s8 func_00175700();

void func_001C45E0(u8 *a, u8 *b) {
    u8 *p = b + 0x2B8;
    *(f32 *)(a + 0x34) += *(f32 *)(a + 0x5C);
    *(f32 *)(a + 0x5C) += *(f32 *)(a + 0x68);
    if (func_00174470(a) == 0) {
        p[3] = 0;
        {
            u32 n = a[4];
            a[4] = n + 1;
        }
        a[7] = 0;
        a[6] = 0;
        a[5] = 0;
    } else {
        if (func_001C47D0(a, b) != 0) {
            a[6] = 4;
            a[7] = 0;
        }
        func_00175700(a);
    }
}

void func_00337A90(u8 *a) {
    s16 t;
    *(f32 *)(a + 0x38) += *(f32 *)(a + 0x60);
    if (a[6] != 0) {
        if (a[5] != 0) {
            if (!(*(f32 *)(a + 0x38) < (f32)*(s32 *)(a + 0xDC))) {
                *(s32 *)(a + 0xD8) = 500;
                a[4] = 3;
            }
        } else {
            if (*(f32 *)(a + 0x38) <= (f32)*(s32 *)(a + 0xDC)) {
                *(s32 *)(a + 0xD8) = 500;
                a[4] = 3;
            }
        }
    }
    t = *(s16 *)(a + 0x1C) - 1;
    *(s16 *)(a + 0x1C) = t;
    if (t == 0) {
        *(s16 *)(a + 0x1C) = 200;
        a[4] = 2;
    }
}
