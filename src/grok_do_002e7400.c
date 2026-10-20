typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern void func_001E3320(u8 *, int, f32);
extern void func_00126400(void);

void func_002E7400(u8 *p)
{
    u8 *q = p + 696;
    u8 *a1;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x1FE] = 1;
    if ((*(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) - 1) == 0) {
        func_001E3320(p, 34, 2.0999999046325684f);
        a1 = *(u8 **)(p + 0x1DC);
        *(u8 **)(a1 + 0x1C8) = p;
        a1[0x20A] = 1;
        a1[0x1E6] = p[0x1E6];
        a1[0x20D] = 2;
        a1[0x1B5] = 36;
        a1[6] = 0;
        a1[0x24A] = 0;
        func_00126400();
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        p[7]++;
        p[0x20] = 0;
        *(s16 *)(p + 0x1C) = 64;
        *(signed char *)(q + 8) = -1;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x68) = 0;
    }
}
