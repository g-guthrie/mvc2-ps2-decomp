typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_003BD160(u8 *a) {
    u16 v = *(s16 *)(*(u8 **)(a + 0x18) + 0x35E) & 0x3000;
    if (v) {
        if (v == 0x1000) {
            *(f32 *)(a + 0x38) -= 1.07142854f;
        } else {
            *(f32 *)(a + 0x38) += 3.21428561f;
        }
    }
}

extern s8 func_00175700();
extern void func_001843A0();
extern void func_00183920();
void func_00277880(u8 *a) {
    f32 v[3];
    if (func_00175700(a) < 0) {
        func_001843A0(a);
    } else if (*(s8 *)(a + 0x151) == 0xF) {
        a[0x151] = 0;
        v[0] = 26.666666f;
        v[1] = 85.7142792f;
        func_00183920(a, v);
    }
}

extern s8 *D_004C2840;
extern void func_003DAA40();
void func_0013E070(u8 *a) {
    if (D_004C2840[3] == 2 && *(s16 *)(a + 0x1C) != 8) {
        f32 x;
        *(s16 *)(a + 0x1C) = *(s16 *)(a + 0x1C) + 1;
        x = 1.0f + 0.375f * (f32)*(s16 *)(a + 0x1C);
        *(f32 *)(a + 0x50) = x;
        *(f32 *)(a + 0x54) = x;
    } else {
        func_003DAA40(a);
    }
}
