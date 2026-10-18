typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0013B770(u8 *p) {
    s16 v = *(s16 *)(p + 0x1C) + 1;
    *(s16 *)(p + 0x1C) = v;
    if (*(s16 *)(p + 0x1C) >= 500) *(s16 *)(p + 0x1C) = 0;
    *(u32 *)(p + 0xD0) |= 0x20000;
    *(u32 *)(p + 0xE0) = 0;
    *(f32 *)(p + 0xE4) = 0.002f * (f32)*(s16 *)(p + 0x1C);
}


extern s16 D_00446C40[];
void func_0018CD70(u8 *p, u8 idx) {
    f32 v = 1.666666627f * (f32)D_00446C40[idx] / 256.0f;
    *(u32 *)(p + 0x68) = 0x3FFD5555;
    if (p[0x1E6] == 0) {
        *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        v = -v;
    }
    *(f32 *)(p + 0x22C) = v;
}

extern void func_001E7F60(void *p);
extern void func_00175700();
void func_003B9170(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    if (q[4] != 1) {
        u32 t = p[4]; p[4] = t + 1;
        p[0x13C] = 0;
    } else {
        if (p[0x21] != 0) *(f32 *)(p + 0x38) = 497.1428528f + *(f32 *)(q + 0x38);
        func_00175700(p);
        func_001E7F60(p);
    }
}

extern void func_003DAA40();
void func_003439D0(u8 *p) {
    switch (p[4]) {
    case 0:
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) -= 1.0f;
        if (*(f32 *)(p + 0x38) <= 0.0f) {
            u32 t = p[4]; p[4] = t + 1;
        }
        break;
    case 1:
        func_003DAA40(p);
        break;
    }
}
