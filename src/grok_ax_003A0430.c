typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;

extern int func_00174470(const void *);
extern int func_00175700(u8 *);
extern void func_001E7F60(u8 *);
extern void func_003A0510(u8 *, u8 *);

void func_003A0430(u8 *p, u8 *q)
{
    if (p[1] == q[1]) {
        s16 t = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = t;
        if (t && !*(s8 *)(p + 0x1B2) && func_00174470(p)) {
            *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
            *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
            *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
            func_00175700(p);
            func_001E7F60(p);
            return;
        }
    }
    func_003A0510(p, q);
}
