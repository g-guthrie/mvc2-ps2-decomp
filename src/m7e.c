typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

extern void func_00175700();
extern void func_001757E0();
void func_00252520(u8 *a, u8 *b) {
    a[0x40C] = 2;
    a[0x33C] = 5;
    func_00175700(a);
    *(f32 *)(a + 0x34) += *(f32 *)(a + 0x5C);
    *(f32 *)(a + 0x5C) += *(f32 *)(a + 0x68);
    if (*(s8 *)(b + 0xB)) {
        u32 t = a[6];
        a[6] = t + 1;
        func_001757E0(a, 0x16, 0xB);
    }
}

extern void func_0019B110();
void func_0021C5F0(u8 *a, u8 *b) {
    a[0x151] = 0xE;
    *(u32 *)(a + 0x5C) = 0x40A00000;
    *(u32 *)(a + 0x68) = 0;
    *(u32 *)(a + 0x60) = 0x412B6DB6;
    *(u32 *)(a + 0x6C) = 0xBF2B6DB6;
    func_0019B110(a, 0);
    *(u8 **)(b + 0x1C8) = a;
    b[0x20A] = 1;
    *(s8 *)(b + 0x1E6) = *(s8 *)(a + 0x1E6) ^ 1;
    b[0x1B5] = 0x25;
    b[0x20D] = 2;
}

extern s32 func_00174240();
extern void func_003C80A0();
void func_003C6430(u8 *a, u8 *b) {
    *(f32 *)(a + 0x34) += *(f32 *)(a + 0x5C);
    *(f32 *)(a + 0x5C) += *(f32 *)(a + 0x68);
    *(f32 *)(a + 0x38) += *(f32 *)(a + 0x60);
    *(f32 *)(a + 0x60) += *(f32 *)(a + 0x6C);
    if (func_00174240(a)) {
        a[0x13C] = 1;
    } else {
        func_003C80A0(a, b);
    }
}

void func_001C5CB0(u8 *a, u8 *b) {
    u8 *s = b + 0x2B8;
    if (!b[0x2C3] || s[0xA]) {
        *(s16 *)(a + 0x140) = *(s16 *)(b + 0x140);
        *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34);
        *(f32 *)(a + 0x38) = *(f32 *)(b + 0x38) + 85.7142792f;
        a[7] = 5;
        a[0] = 1;
        a[0x13C] = 1;
        if (*(s16 *)(a + 0x140) == 0) {
            *(u32 *)(a + 0x5C) = 0xC0D55555;
        } else {
            *(u32 *)(a + 0x5C) = 0x40D55555;
        }
        *(u32 *)(a + 0x68) = 0;
        *(u32 *)(a + 0x60) = 0x40892492;
        *(u32 *)(a + 0x6C) = 0;
    }
    func_00175700(a);
}
