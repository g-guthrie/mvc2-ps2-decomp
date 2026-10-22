typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef float f32;

extern u8 *D_004C2840;

void func_001AE6B0(u8 *p)
{
    u8 *q;
    s16 v;
    extern void func_00175670();
    extern void func_001AFC90(u8 *);
    extern double func_00119058(f32);
    q = *(u8 **)(p + 0x18);
    if (p[5] == 0) {
        func_00175670();
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        if (*(f32 *)(p + 0x38) <= *(f32 *)(q + 0x430)) {
            u32 t = p[5];
            p[5] = t + 1;
            *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
            *(f32 *)(p + 0x60) = (f32)(func_00119058(-*(f32 *)(p + 0x60)) / 2.0);
            *(s16 *)(p + 0x1C) = 0x20;
        }
    } else {
        func_00175670();
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        if (*(f32 *)(p + 0x38) <= *(f32 *)(*(u8 **)(p + 0x18) + 0x430)) {
            *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
            *(f32 *)(p + 0x60) = (f32)(func_00119058(-*(f32 *)(p + 0x60)) / 2.0);
        }
        v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v == 0) {
            func_001AFC90(p);
            return;
        }
        p[0x13C] = D_004C2840[0x1C] & 1;
    }
}
