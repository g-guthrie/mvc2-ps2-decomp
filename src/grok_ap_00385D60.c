typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef float f32;

extern s32 func_00174470(u8 *);
extern void func_001757E0(u8 *, s32, s32);
extern void func_00175700(u8 *);
extern void func_001E7F60(u8 *);

void residual_00385D60(u8 *p, u8 *q)
{
    if (!func_00174470(p)) {
        p[4] = 3;
        p[0x13C] = 0;
        return;
    }
    if (*(s8 *)(p + 0x1B2) || *(s8 *)(p + 0x1B3)) {
        p[5]++;
        if (q[1] == 0x1C)
            func_001757E0(p, 0x17, 1);
        else
            func_001757E0(p, 0x17, 3);
        return;
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    func_001E7F60(p);
}
