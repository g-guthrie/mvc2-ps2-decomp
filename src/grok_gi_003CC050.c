typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_003CAB20(u8 *, u8 *, s32);
extern s32 func_00185980(u8 *);
extern void func_003CC420(u8 *, u8 *);
extern void func_001E3710(u8 *, s32);
extern void func_001757E0(u8 *, s32, s32);
extern void func_00175700(u8 *);
extern s32 func_00174470(u8 *);
extern void func_003CAB00(u8 *, u8 *);
extern void func_001E7F60(u8 *);

void residual_003CC050(u8 *p, u8 *q)
{
    if (q[5] != 0) {
        *(f32 *)(p + 0x5C) = *(f32 *)(p + 0x5C) / 2.0f;
        func_003CAB20(p, q, 0x11);
        return;
    }
    *(s32 *)(q + 0x2B8) = 4;
    if (*(s8 *)(p + 0x1B3) != 0) {
        func_003CAB20(p, q, 9);
        return;
    }
    if (*(s8 *)(p + 0x1B2) != 0) {
        if (func_00185980(p) == 0) {
            func_003CAB20(p, q, 0xD);
            return;
        }
        {
            u32 t = p[6];
            p[6] = t + 1;
        }
        p[0x24] = 8;
        func_003CC420(p, q);
        func_001E3710(p, 0x23);
        func_001757E0(p, 0x17, 0x26);
        return;
    }
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (func_00174470(p) == 0)
        func_003CAB00(p, q);
    else
        func_001E7F60(p);
}
