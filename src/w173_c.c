typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0031D380(u8 *p)
{
    extern void func_00175700(u8 *);
    extern s32 func_001864A0(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    s16 t;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    t = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = t;
    if (t == 0) {
        if (func_001864A0(p) != 0) {
            p[6]++;
            p[7] = 0;
            *(f32 *)(p + 0x34) -= *(f32 *)(p + 0x5C);
            p[0x20D] = 0;
            func_001757E0(p, 0x12, 2);
        }
    } else {
        p[7]++;
        func_001757E0(p, 0x12, 1);
    }
}
