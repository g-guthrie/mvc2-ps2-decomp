typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern s32 func_00174780(u8 *);
extern s32 func_00174470(u8 *);
extern void func_003CAB00(u8 *, u8 *);
extern void func_003CAB20(u8 *, u8 *, s32);
extern int func_00175700(u8 *);
extern void func_001E7F60(u8 *);

void func_003CBF20(u8 *p, u8 *q)
{
    if (*(s16 *)(p + 0x1E) != 0) {
        p[0x13C] = 0;
        *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1E) - 1;
        return;
    }
    if (func_00174780(p) == 0 || func_00174470(p) == 0) {
        func_003CAB00(p, q);
        return;
    }
    p[0x13C] = 1;
    *(s32 *)(q + 0x2B8) = 4;
    if (*(s8 *)(p + 0x1B3) != 0) {
        func_003CAB20(p, q, 9);
        return;
    }
    if (*(s8 *)(p + 0x1B4) != 0) {
        p[0x1B4] = *(s8 *)(p + 0x1B4) - 1;
    } else {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        func_00175700(p);
    }
    func_001E7F60(p);
}
