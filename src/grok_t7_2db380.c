typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_001830D0(u8 *, f32 *, int);

void func_002DB380(u8 *p)
{
    struct { union { f32 values[2]; u32 bits[2]; } pair; u32 padding[2]; } position __attribute__((aligned(16)));
    p[0x40C] = 2;
    p[0x33C] = 5;
    {
        int mode;
        if (p[0x269] == 6)
            mode = 2;
        else
            mode = 0;
        p[0x405] = mode;
    }
    *(u32 *)(p + 0x2F8) = 0x60;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    {
        s16 t = *(s16 *)(p + 0x1C);
        t = t - 1;
        *(s16 *)(p + 0x1C) = t;
        if (t == 0) {
            p[0x404] = 0;
            p[0x405] = 0;
            p[6]++;
            *(s16 *)(p + 0x1C) = 8;
            position.pair.bits[0] = 0xC2AD5555;
            position.pair.bits[1] = 0x432B6DB6;
            func_001830D0(p, position.pair.values, 1);
        }
    }
}
