typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern u8 *D_004C2794;
extern s32 func_003D6850(s32, s32, u8 *, s32);
extern void func_003D72F0(void);

void func_003D68B0(u8 *p, s32 a1)
{
    s8 idx = *(s8 *)(p + 0x2C) - 1;
    s32 r;
    s32 g;
    if (*(s8 *)(p + 0x1A) == 0) {
        *(s16 *)(p + 0x2A) = 0;
        if (*(s16 *)(p + 0xA) != 0)
            *(s16 *)(p + 0xA) = *(s16 *)(p + 0xA) - 1;
        else
            p[0x1A] = *(s8 *)(p + 0x1A) + 1;
    } else {
        g = **(u8 **)(*(u8 **)(D_004C2794 + idx * 12 + 0x18) + 0x1AC);
        r = func_003D6850(idx, a1, p, (s16)g);
        if (r & 0x2000)
            *(s16 *)(p + 0x2A) = *(s16 *)(p + 0x2A) - 1;
        if (r & 0x1000)
            *(s16 *)(p + 0x2A) = *(s16 *)(p + 0x2A) + 1;
        *(s16 *)(p + 0x2A) = (*(s16 *)(p + 0x2A) + (s16)g) % (s16)g;
    }
    func_003D72F0();
}
