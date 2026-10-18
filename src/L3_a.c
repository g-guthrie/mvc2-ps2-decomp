typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G3a;
extern G3a *D_004C2794;
extern void (*D_00475AE0[])(u8 *, u8 *);

void func_003BDC80(u8 *p, u8 *q) {
    extern void func_003BE5C0(u8 *, u8 *);
    extern void func_003BE240(u8 *, u8 *);
    s32 t;
    *(s32 *)(q + 0x2D4) = 4;
    if (*(s8 *)(p + 0x1B2) != 0) {
        *(s32 *)(p + 0xD4) = 1;
        t = *(s32 *)(p + 0xD8) + 0x20000000;
        *(s32 *)(p + 0xD8) = t;
        if (t == 0) {
            t = *(s32 *)(p + 0xD0) - 1;
            *(s32 *)(p + 0xD0) = t;
            if (t > 0) {
                p[0x1B5] = 0x42;
                p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
                *(s32 *)(p + 0x1D8) = 0;
                D_004C2794->f7c[p[2]]++;
            } else {
                *(s32 *)(p + 0xDC) = 1;
                *(f32 *)(p + 0x5C) /= 2.0f;
                *(f32 *)(p + 0x60) /= 2.0f;
            }
        }
    }
    if (q[5] != 0) {
        *(s32 *)(p + 0xDC) = 1;
        *(f32 *)(p + 0x5C) /= 2.0f;
        *(f32 *)(p + 0x60) /= 2.0f;
    }
    if (*(s32 *)(p + 0xDC) != 0) {
        f32 v;
        *(s8 *)(p + 0x13C) ^= 1;
        v = *(f32 *)(p + 0x50) - 0.05f;
        *(f32 *)(p + 0x50) = v;
        if (v < 0.01f) {
            func_003BE5C0(p, q);
            return;
        }
        *(f32 *)(p + 0x54) = v;
    }
    if (*(s8 *)(p + 0x1B4) != 0) {
        func_003BE240(p, q);
        t = *(s8 *)(p + 0x1B4) - 1;
        *(s8 *)(p + 0x1B4) = t;
        if ((s8)t != 0) return;
    }
    D_00475AE0[p[5]](p, q);
}
