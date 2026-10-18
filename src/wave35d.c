typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern s32 func_00175700();
extern void func_001757E0(u8 *a, s32 b, s32 c);

void func_0022AD10(u8 *a0) {
    a0[0x40C] = 2;
    a0[0x33C] = 5;
    if ((s8)func_00175700(a0) < 0) {
        f32 v;
        u32 t = a0[6];
        a0[6] = t + 1;
        *(s16 *)(a0 + 0x1C) = 0x12;
        a0[0x21] = 0;
        v = -8.333333015f;
        if (*(s16 *)(a0 + 0x140) != 0) v = -v;
        *(f32 *)(a0 + 0x5C) = v;
        func_001757E0(a0, 0x16, 0xB);
    }
}

void func_001C7640(u8 *a0, u8 *a1) {
    *(f32 *)(a0 + 0x34) += *(f32 *)(a0 + 0x5C);
    *(f32 *)(a0 + 0x5C) += *(f32 *)(a0 + 0x68);
    *(f32 *)(a0 + 0x38) += *(f32 *)(a0 + 0x60);
    *(f32 *)(a0 + 0x60) += *(f32 *)(a0 + 0x6C);
    if (*(f32 *)(a0 + 0x38) <= 51.4285698f + *(f32 *)(a1 + 0x430)) {
        u32 t = a0[7];
        a0[7] = t + 1;
        *(s16 *)(a0 + 0x1C) = 8;
        *(u32 *)(a0 + 0x6C) = 0x40092492;
        *(s16 *)(a1 + 0x1C) = 0;
    }
}
