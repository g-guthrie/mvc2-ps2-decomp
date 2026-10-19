typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern void func_00175700(u8 *);
extern void func_001757E0(u8 *, s32, s32);
extern void func_001E7F60(u8 *);

void residual_003627E0(u8 *p)
{
    s16 t;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    t = *(s16 *)(p + 0x1C);
    t--;
    *(s16 *)(p + 0x1C) = t;
    if (t == 0) {
        p[6]++;
        *(f32 *)(p + 0x5C) = *(f32 *)(p + 0x5C) / 2.0f;
        *(f32 *)(p + 0x60) = *(f32 *)(p + 0x60) / 2.0f;
        *(s32 *)(p + 0x6C) = 0xBF4DB6DB;
        func_001757E0(p, 0x17, 0x1D);
    }
    func_001E7F60(p);
}
