typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_003A4670(u8 *p, u8 *q)
{
    extern int func_00175700(u8 *);
    extern void func_003A4970(u8 *, u8 *);
    extern s32 func_00174240(u8 *);
    extern void func_001E7F60(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_003A4970(p, q);
    if (func_00174240(p) == 0) {
        p[4] = 2;
        p[0x13C] = 0;
        return;
    }
    if (*(f32 *)(p + 0x38) < *(f32 *)(q + 0x430)) {
        p[5]++;
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
        func_001E7F60(p);
        func_001757E0(p, 0x17, 0x1D);
        return;
    }
    if (*(s8 *)(p + 0x1B3) != 0) {
        p[5] = 3;
        func_001757E0(p, 0x17, 0x1E);
    } else if (*(s8 *)(p + 0x1B2) == 0) {
        func_001E7F60(p);
    }
}
