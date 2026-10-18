typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

static void func_0014E770(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    if (*(s32 *)(q + 0xDC) != 0) {
        if (q[4] == 1) {
            *(s16 *)(p + 0x1E) = *(s16 *)(q + 0x1E);
        } else {
            *(s16 *)(p + 0x1E) = *(s16 *)(q + 0x1E);
        }
    }
}

void func_0014EE80(u8 *p) {
    func_0014E770(p);
    *(s8 *)(p + 0x13C) = *(s8 *)(*(u8 **)(p + 0x18) + 0x13C);
    *(f32 *)(p + 0x74) = *(f32 *)(*(u8 **)(p + 0x18) + 0x74);
}

typedef struct { f32 x, y, z; } V3;
extern void func_001754A0(u8 *p, s32 a, s32 b);

void func_0019A8D0(u8 *p, u8 *q) {
    *(s8 *)(p + 0x31) = -1;
    *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
    *(f32 *)(p + 0x60) = 207.857131958f;
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    func_001754A0(p, 0x1B, 4);
}

extern void func_001757E0(u8 *p, s32 a, s32 b);

void func_00136BF0(u8 *p) {
    *(s32 *)(p + 0x44) -= 0x100;
    switch (p[4]) {
    case 0:
        *(f32 *)(p + 0x50) -= 0.0500000007f;
        *(f32 *)(p + 0x54) -= 0.0500000007f;
        if (*(f32 *)(p + 0x50) < 1.0f) {
            u32 t = p[4];
            p[4] = t + 1;
            *(f32 *)(p + 0x50) = 1.0f;
            *(f32 *)(p + 0x54) = 1.0f;
        }
        break;
    case 1:
        break;
    }
}

extern f32 D_004F1FD8;
extern f32 D_004F1FDC;

