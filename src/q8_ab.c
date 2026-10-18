typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_00463BB0[];

void func_0036E8D0(u8 *p, u8 *q) {
    extern void func_001757E0();
    extern void func_00175700();
    extern void func_0036EB40();
    u8 *r = *(u8 **)(p + 0x1E0);
    u32 t;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(r + 0x38) < *(f32 *)(q + 0x430)) {
        t = p[5];
        p[5] = t + 1;
        *(s16 *)(p + 0x1E) = 0x14;
        *(f32 *)(r + 0x38) = *(f32 *)(q + 0x430);
        r[0x20D] = 0;
        *(s16 *)(p + 0x140) = *(s16 *)(q + 0x140) ^ 1;
        func_001757E0(p, 0x17, (u8)(D_00463BB0[r[1]] + 0x25));
        func_00175700(p);
    } else {
        *(s16 *)(p + 0x1E) = 2;
        func_0036EB40(p);
    }
}
