typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;

extern void func_001E3320(u8 *, int, float);
extern void func_00126400(void);

void func_002E7400(u8 *p)
{
    u8 *q = p + 696;
    u8 *a1;
    p[1036] = 2;
    p[828] = 5;
    p[510] = 1;
    if ((*(s16 *)(p + 28) = *(s16 *)(p + 28) - 1) == 0) {
        func_001E3320(p, 34, *(float *)&(u32){0x40066666u});
        a1 = *(u8 **)(p + 476);
        *(u8 **)(a1 + 456) = p;
        a1[522] = 1;
        a1[486] = p[486];
        a1[525] = 2;
        a1[437] = 36;
        a1[6] = 0;
        a1[586] = 0;
        func_00126400();
        p[1037] = 0;
        p[1036] = 0;
        p[827] = 0;
        p[828] = 0;
        p[7]++;
        p[32] = 0;
        *(s16 *)(p + 28) = 64;
        *(signed char *)(q + 8) = -1;
        *(u32 *)(p + 92) = 0;
        *(u32 *)(p + 104) = 0;
    }
}
