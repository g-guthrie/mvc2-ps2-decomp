typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2840;
extern s32 D_004AD200[];
extern s32 D_004AD230[];
extern s32 D_004AD260[];
extern s32 D_004AD290[];

static s32 func_0012BFB0(s32 a) {
    u32 *w = (u32 *)(D_004C2840 + 0x30);
    if (a >= 0x18) w = (u32 *)((u8 *)w + 4);
    if (*w & (1 << (a & 0x1F))) return 1;
    return 0;
}

s32 func_0012BFF0(s32 a)
{
    s32 *tab;
    s32 i;
    s32 off;
    if (a != 0x20 && a != 0x36 && a != 0x3A && a != 0x34) return 1;
    switch (a) {
    case 0x20: tab = D_004AD200; break;
    case 0x36: tab = D_004AD230; break;
    case 0x34: tab = D_004AD260; break;
    case 0x3A: tab = D_004AD290; break;
    }
    i = 0;
    off = 0;
    do {
        if (func_0012BFB0(*(s32 *)((u8 *)tab + off))) return 1;
        i++;
        off += 4;
    } while (i < 12);
    return 0;
}
