typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;

extern int func_00174170(void);
extern void func_001757E0(u8 *, int, int);

void func_003BF2E0(u8 *p, u8 *q)
{
    int r;
    u8 *owner;
    f32 t;
    p[0x13C] = 2;
    p[0x24] = 0;
    {
        f32 x = *(f32 *)(q + 0x34);
        f32 y = *(f32 *)(q + 0x38);
        f32 z = *(f32 *)(q + 0x3C);
        *(f32 *)(p + 0x34) = x;
        *(f32 *)(p + 0x38) = y;
        *(f32 *)(p + 0x3C) = z;
    }
    r = (unsigned)func_00174170() & 0xFF;
    owner = *(u8 **)(q + 0x18);
    t = *(f32 *)(q + 0x34) + 1.6666666269302368f * (f32)((s16)((r * 3) >> 2) - 0x60);
    *(f32 *)(p + 0x5C) = (t - *(f32 *)(p + 0x34)) / 12.0f;
    *(f32 *)(p + 0x60) = (*(f32 *)(owner + 0x430) - *(f32 *)(p + 0x38)) / 12.0f;
    *(int *)(p + 0x6C) = 0;
    *(int *)(p + 0x68) = 0;
    r = (unsigned)func_00174170() & 3;
    func_001757E0(p, 0x16, (u8)(p[0x22] + 0x3B + r));
}
