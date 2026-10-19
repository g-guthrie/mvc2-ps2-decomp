typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern u8 *D_004C2988 __attribute__((section(".sdata")));
extern u16 *D_004C2984 __attribute__((section(".sdata")));

void residual_00369340(u8 *p)
{
    s32 n;
    s32 *d;
    s32 *s;
    u8 *q;
    u32 t = p[4];
    d = (s32 *)(p + 0xEC);
    n = 0x31;
    p[4] = t + 1;
    q = *(u8 **)(p + 0x18);
    s = (s32 *)(q + 0xEC);
    do {
        *d = *s;
        n--;
        s++;
        d++;
    } while (n > 0);
    p[0x13C] = 1;
    p[2] = (*(u8 **)(p + 0x18))[2];
    p[1] = (*(u8 **)(p + 0x18))[1];
    *(f32 *)(p + 0x50) = *(f32 *)(*(u8 **)(p + 0x18) + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(*(u8 **)(p + 0x18) + 0x54);
    p[0x1B7] = (*(u8 **)(p + 0x18))[0x1B7];
    p[0x1B8] = (*(u8 **)(p + 0x18))[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(*(u8 **)(p + 0x18) + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(*(u8 **)(p + 0x18) + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(*(u8 **)(p + 0x18) + 0x24);
    p[0x13C] = 0;
    D_004C2988[9] = 1;
    *D_004C2984 = *(u16 *)(*(u8 **)(p + 0x18) + 0x168);
}
