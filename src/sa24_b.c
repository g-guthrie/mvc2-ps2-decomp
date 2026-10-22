typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 f0;
    u8 pad[0x7B];
    s16 f7c[1];
} G24;
extern G24 *D_004C2794;

extern u8 D_004C0BDC[4];
extern u8 D_004C0BE0[4];
extern u8 D_004C0BE4[4];

void func_002A7B60(u8 *p)
{
    extern void func_001E3710(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    u32 h;
    u32 t;
    f32 f;
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 3;
        func_001E3710(p, 0x14);
        *(u8 **)(p + 0x408) = D_004C0BDC;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 4;
        func_001E3710(p, 0x15);
        *(u8 **)(p + 0x408) = D_004C0BE0;
        p[0x1BB] = 1;
        break;
    case 2:
        h = *(u16 *)(p + 0x20E);
        if ((h & 0x800) != 0) {
            p[6] = 2;
            p[0x168] = 4;
            p[0x1B5] = 0x14;
            if (p[0x1E6] != 0)
                f = 6.666666507720947f;
            else
                f = -6.666666507720947f;
            *(f32 *)(p + 0x5C) = f;
            *(s32 *)(p + 0x68) = 0;
        } else if ((h & 0x400) != 0) {
            p[6] = 1;
            p[0x168] = 3;
            p[0x1B5] = 0x13;
        } else {
            p[0x168] = 2;
            p[0x1B5] = 5;
        }
        func_001E3710(p, 0x16);
        *(u8 **)(p + 0x408) = D_004C0BE4;
        p[0x1BB] = 2;
        break;
    default:
        break;
    }
    t = p[0x1B5];
    p[0x1B5] = t;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 8, p[0x168]);
}
