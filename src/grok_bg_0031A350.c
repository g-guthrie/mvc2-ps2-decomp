/* ./try.sh src/grok_bg_0031A350.c "-O3 -sdatathreshold 8" */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed int s32;

extern u8 D_004C1768[];
extern s32 func_001E7FD0(void);
extern s32 func_00174170(void);

s32 func_0031A350(u8 *p)
{
    s32 r;

    if (p[0x20D] != 0 && p[0x20D] != 2)
        return 0;
    *(u16 *)(p + 0x2C2) = *(u16 *)(p + 0x20E);
    if ((*(u16 *)(p + 0x2C2) & 0xC00) == 0)
        return 0;
    if (p[0x1B7] == 0)
        return 0;
    r = func_001E7FD0();
    if (r == 0)
        return 0;
    if (p[0x212] == 1) {
        if (p[0x20D] == 2)
            return 0;
        p[0x20B] = 2;
        return r;
    }
    if (p[0x20D] == 2) {
        p[0x20B] = 1;
        return r;
    }
    if (*(s8 *)(p + 0x2BF)) {
        p[0x20B] = 2;
        return r;
    }
    p[0x2BE] = (u8)(func_00174170() & 3);
    p[0x20B] = D_004C1768[(s8)p[0x2BE] * 2];
    return r;
}
