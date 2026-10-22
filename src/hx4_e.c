typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G_e;
extern G_e *D_004C2794;
extern u8 D_004C08D4[2];
extern u8 D_004C08BC[2];
extern u8 D_004C08D8[2];
extern u8 D_004C08C0[2];
extern u8 D_004C08DC[2];
extern u8 D_004C08C4[2];

void func_00282130(u8 *p)
{
    extern void func_001E3710(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    u32 t;
    s32 a;
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 0xF;
        func_001E3710(p, 0x14);
        if (p[0x210] == 0) *(u8 **)(p + 0x408) = D_004C08BC;
        else *(u8 **)(p + 0x408) = D_004C08D4;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 0x10;
        func_001E3710(p, 0x15);
        if (p[0x210] == 0) *(u8 **)(p + 0x408) = D_004C08C0;
        else *(u8 **)(p + 0x408) = D_004C08D8;
        p[0x1BB] = 1;
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 0x1A;
        t = *(u16 *)(p + 0x20E);
        if ((t & 0x1000) != 0) {
            t = p[6];
            p[6] = t + 1;
            p[0x168] = 6;
            p[0x1B5] = 0x13;
        } else if ((t & 0x800) != 0) {
            p[0x168] = 5;
            p[0x1B5] = 0x14;
        }
        func_001E3710(p, 0x16);
        if (p[0x210] == 0) *(u8 **)(p + 0x408) = D_004C08C4;
        else *(u8 **)(p + 0x408) = D_004C08DC;
        p[0x1BB] = 2;
        break;
    }
    t = *(volatile u8 *)(p + 0x1B5);
    p[0x1B5] = t;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]] += 1;
    func_001757E0(p, 0xC, p[0x168]);
    a = *(s8 *)(p + 0x1EA);
    if ((a & 0xF0) != 0) p[0x1EA] = a - 0x10;
}
