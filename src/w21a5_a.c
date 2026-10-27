typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_002379D0(u8 *p, u8 *q) {
    extern int func_00175700(u8 *);
    extern void func_00184540(u8 *);
    extern void func_001865B0(u8 *);
    extern void func_00183d50(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001843A0(u8 *);
    if (q[0x19] != 0) {
        if ((s8)func_00175700(p) < 0) {
            func_00184540(p);
            return;
        }
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
            *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
            p[0x20D] = 0;
            func_001865B0(p);
            func_00183d50(p);
        }
    } else if (p[7] == 0) {
        f32 z = 0.0f;
        func_00175700(p);
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        if (*(f32 *)(p + 0x60) < z) {
            if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
                u32 t = p[7];
                p[7] = t + 1;
                *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
                p[0x20D] = 0;
                func_001757E0(p, 1, 3);
                func_00183d50(p);
            }
        }
    } else {
        if ((s8)func_00175700(p) >= 0) return;
        func_001843A0(p);
    }
}

typedef struct { u16 f; u8 pad[18]; } E20;
extern E20 D_004F4480[];

