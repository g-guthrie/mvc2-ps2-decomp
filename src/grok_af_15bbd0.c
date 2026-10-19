typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern void (*D_004BF460[])(u8 *, u8 *);
extern u8 *D_004D18C4;

void func_0015BBD0(u8 *p)
{
    u8 *g = D_004D18C4;
    p[0x13C] = 0;
    if (*(s8 *)(*(u8 **)(p + 0x14) + 0x13C) == 0) {
        s16 v = 0;
        if (*(s16 *)(g + 0x140) == 0)
            v = -0xB4;
        *(s16 *)(p + 0x1C) = v;
        *(u32 *)(p + 0x48) = (u16)(65536.0 * (double)*(s16 *)(p + 0x1C) / 360.0 + 0.5);
    } else {
        D_004BF460[p[4]](p, g);
    }
}
