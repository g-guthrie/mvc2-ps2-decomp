typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x1C]; u32 f1c; } G2840;
extern G2840 *D_004C2840;

void func_0031F060(u8 *p) {
    extern void func_00183D90(u8 *);
    extern s8 func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, u8);
    f32 z = 0.0f;
    if (z != *(f32 *)(p + 0x5C)) {
        if (D_004C2840->f1c & 1) {
            func_00183D90(p);
        }
        p[0x206] = 3;
    }
    if (!(*(f32 *)(p + 0x5C) * *(f32 *)(p + 0x68) < z)) {
        p[0x206] = 0;
        *(f32 *)(p + 0x5C) = z;
        *(f32 *)(p + 0x68) = z;
    }
    if (func_00175700(p) < 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[7] = 0;
        p[0x20D] = 0;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        func_001757E0(p, 0x15, p[0x1B7] + 0x29);
    }
}
