typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern int func_00175700(u8 *);
typedef struct PairXY { s16 x; s16 y; } PairXY;
extern PairXY D_0045B180[];

void func_002E7030(u8 *p)
{
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x1FE] = 1;
    if ((s8)func_00175700(p) < 0) {
        p[7]++;
        p[0x20D] = 2;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
    }
    {
        s8 st = *(s8 *)(p + 0x151);
        if (st & 1) {
            p[0x151] = st ^ 1;
            {
                PairXY *slot = &D_0045B180[p[0x20D]];
                f32 dx = 1.6666666269302368f * (f32)slot->x;
                if (p[0x1E6]) {
                    dx = -dx;
                }
                *(f32 *)(p + 0x34) += dx;
                *(f32 *)(p + 0x38) += 2.142857074737549f * (f32)slot->y;
            }
        }
    }
}
