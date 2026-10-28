typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0036BDD0(u8 *p)
{
    extern void func_00175700(u8 *);
    extern double func_00119058(f32);
    extern void func_001757E0(u8 *, s32, s32);
    s16 h;
    u32 t;

    func_00175700(p);
    *(f32 *)(p + 0x50) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    if (*(s16 *)(p + 0x1C) < 3) {
        switch (func_00119058(*(f32 *)(p + 0x118) -= 0.20000000298023224f) < 0.1) {
        case 0: break;
        default: *(f32 *)(p + 0x118) = 0.10000000149011612f; break;
        }
    }
    h = *(s16 *)(p + 0x1C);
    *(s16 *)(p + 0x1C) = h - 1;
    if (h < 0) {
        t = p[5];
        p[5] = t + 1;
        *(s16 *)(p + 0x1C) = 6;
        *(f32 *)(p + 0x118) = 1.0f;
        *(f32 *)(p + 0x50) = 1.0f;
        *(f32 *)(p + 0x54) = 1.0f;
        *(f32 *)(p + 0x5C) = 0.009999999776482582f;
        *(f32 *)(p + 0x68) = -0.0003000000142492354f;
        *(f32 *)(p + 0x60) = 0.019999999552965164f;
        *(f32 *)(p + 0x6C) = -0.0003000000142492354f;
        func_001757E0(p, 0x17, 9);
    }
}
