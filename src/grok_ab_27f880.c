typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern s32 func_00175700(u8 *);
extern int func_001757E0(u8 *, s32, s32);
extern void func_00280330(void *);

void func_0027F880(u8 *p)
{
    p[0x2B9] = 1;
    switch (p[6]) {
    case 0:
        p[6]++;
        p[0x20D] = 0;
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
        *(s16 *)(p + 0x1C) = 0x10E;
        func_001757E0(p, 0x13, 8);
        break;
    case 1:
        func_00175700(p);
        if (p[7] == 0) {
            if (*(s8 *)(p + 0x151) != 0) {
                p[0x151] = 0;
                p[7]++;
            }
        } else if (*(s8 *)(p + 0x151) == 0) {
            *(f32 *)(p + 0x118) = (f32)*(s8 *)(p + 0x152) / (f32)*(s8 *)(*(u8 **)(p + 0x164) + 2);
        } else {
            p[6]++;
            p[7] = 0;
        }
        break;
    case 2:
        p[0x13C] = 0;
        if ((s16)(--*(s16 *)(p + 0x1C)) < 0)
            func_00280330(p);
        break;
    }
}
