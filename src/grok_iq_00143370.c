typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0016C9B0_pad(u8 *p) {
    *(f32 *)(p + 0x108) -= 0.00052083336f;
    *(f32 *)(p + 0x110) -= 0.00052083336f;
    {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v == 0) {
            u32 t = p[4];
            p[4] = t + 1;
            *(s16 *)(p + 0x1C) = 0xF0;
        }
    }
}

void func_003739E0_pad(u8 *p) {
    s16 v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v <= 0) {
        u32 t = p[4];
        p[4] = t + 1;
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
}

extern void func_004177A0(s32, f32, f32, f32);
extern void func_00414A40();
extern void func_00416AB0();
extern void func_004171E0();
void func_00143370(void) {
    f32 c = 12000.0f, a = 1.0f, b = 0.100000001f;
    func_00414A40();
    func_00416AB0(3);
    func_004171E0();
    func_004177A0(0x4000, a, b, c);
    func_00416AB0(1);
}
