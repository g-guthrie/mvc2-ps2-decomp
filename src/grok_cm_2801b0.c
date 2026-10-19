typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern f32 D_004F1F4C;
extern void func_00155490(u8 *);
extern void func_003298B0(s32, s32);

void func_002801B0(u8 *p)
{
    f32 f1;
    u8 *slot;
    int one = 1;
    p[0x13C] = 0;
    p[0x201] = 0x10;
    p[0x1B1] = 0;
    p[0x159] = 0xFF;
    if (p[6] == one) {
        if ((s16)(--*(s16 *)(p + 0x1C)) <= 0) {
            p[6]++;
            func_003298B0(-1, 0x20);
        }
    } else if (p[6] == 0) {
        f1 = 40.0f * *(f32 *)(p + 0x50);
        if (*(s16 *)(p + 0x140) == 0)
            f1 = -f1;
        *(f32 *)(p + 0x34) = D_004F1F4C - f1;
        slot = p + 0x2B8;
        slot[1] = one;
        if (D_004C2794[0] >= 9) {
            p[6]++;
            slot[1] = 0;
            func_00155490(p);
            *(s16 *)(p + 0x1C) = 0xDC;
        }
    }
}
