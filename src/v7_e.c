typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00175700();
extern void func_001843A0();
extern void func_001C3A80();

void func_002B9A60(u8 *p) {
    s8 r = func_00175700(p);
    if (r < 0) {
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        func_001843A0(p);
        return;
    }
    {
        f32 f;
        if (*(s8 *)(p + 0x151) != 0)
            f = 3.33333325386047363281f;
        else
            f = 13.33333301544189453125f;
        if (p[0x1E6] != 0)
            f = -f;
        *(f32 *)(p + 0x5C) = f;
        *(f32 *)(p + 0x34) += f;
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    }
}

void func_001C3610(u8 *p, u8 *q) {
    if (q[0x2C3] == 0) {
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
        func_001C3A80(p);
        return;
    }
    if (*(s16 *)(p + 0x140) == 0) {
        *(f32 *)(p + 0x34) += (80.0f + *(f32 *)(q + 0x34) - *(f32 *)(p + 0x34)) / 8.0f;
    } else {
        *(f32 *)(p + 0x34) += (*(f32 *)(q + 0x34) - 80.0f - *(f32 *)(p + 0x34)) / 8.0f;
    }
    *(f32 *)(p + 0x38) += (*(f32 *)(q + 0x430) - *(f32 *)(p + 0x38)) / 8.0f;
}

extern f32 D_004B33C0[6];

void func_001450C0(u8 *p) {
    f32 *b = &D_004B33C0[3];
    *(f32 *)(p + 0x34) = D_004B33C0[0] + (f32)*(s16 *)(p + 0x1C) * (b[0] - D_004B33C0[0]) / 20.0f;
    *(f32 *)(p + 0x38) = D_004B33C0[1] + (f32)*(s16 *)(p + 0x1C) * (b[1] - D_004B33C0[1]) / 20.0f;
    *(f32 *)(p + 0x3C) = D_004B33C0[2] + (f32)*(s16 *)(p + 0x1C) * (b[2] - D_004B33C0[2]) / 20.0f;
}

extern f32 D_004B31E0[6];

void func_001444D0(u8 *p) {
    f32 *b = &D_004B31E0[3];
    *(f32 *)(p + 0x34) = D_004B31E0[0] + (f32)*(s16 *)(p + 0x1C) * (b[0] - D_004B31E0[0]) / 60.0f;
    *(f32 *)(p + 0x38) = D_004B31E0[1] + (f32)*(s16 *)(p + 0x1C) * (b[1] - D_004B31E0[1]) / 60.0f;
    *(f32 *)(p + 0x3C) = D_004B31E0[2] + (f32)*(s16 *)(p + 0x1C) * (b[2] - D_004B31E0[2]) / 60.0f;
    *(f32 *)(p + 0x34) /= 10.0f;
    *(f32 *)(p + 0x38) /= 10.0f;
    *(f32 *)(p + 0x3C) /= 10.0f;
}
