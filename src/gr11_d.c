typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad[0x1C]; s32 f1C; } G_b;

extern G_b *D_004C2840;
extern u8 D_004D18E6[];
extern s8 D_0044FFE0[];
extern s8 D_0044FFE1[];

void func_001FE7F0(u8 *p)
{
    extern s32 func_001841C0(u8 *);
    extern s32 func_00417A40(void);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001978B0(u8 *, s32);
    u32 m;
    s32 v;
    u8 *q;

    m = *(u16 *)(p + 0x354);
    q = p + 0x2B8;
    switch (m & 0x3F0) {
    default:
        if ((m & 0x200) != 0) v = 0;
        else if ((m & 0x100) != 0) v = 4;
        else if ((m & 0x80) != 0) v = 6;
        else if ((m & 0x40) != 0) v = 8;
        else if ((m & 0x20) != 0) v = 0xA;
        else if (D_004D18E6[0] != 0 && func_001841C0(p) == 1) v = 0xC;
        else v = (s8)((D_004C2840->f1C + func_00417A40()) & 7);
        break;
    case 0:
        if (D_004D18E6[0] != 0 && func_001841C0(p) == 1)
            v = (s8)((D_004C2840->f1C + func_00417A40()) & 0xF);
        else v = (s8)((D_004C2840->f1C + func_00417A40()) & 7);
        break;
    }
    v = (s8)v;
    p[0x168] = D_0044FFE0[v * 2];
    p[0x21] = D_0044FFE0[v * 2];
    q[0xC] = D_0044FFE1[v * 2];
    func_001757E0(p, 0x13, p[0x168]);
    if (p[0x21] == 5) func_001978B0(p, 2);
}
