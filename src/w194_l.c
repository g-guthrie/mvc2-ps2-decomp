typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G244;
extern G244 *D_004C2794;
extern u8 D_004C0330[2], D_004C0334[2], D_004C0338[2], D_004C0348[2], D_004C034C[2], D_004C0350[2];

void func_00244450(u8 *p) {
    u8 *q = p + 0x2B8;
    u8 t;
    s32 a0;
    extern void func_001E3710(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);

    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 0xC;
        func_001E3710(p, 0x14);
        if (p[0x210] == 0) {
            *(u8 **)(p + 0x408) = D_004C0330;
        } else {
            *(u8 **)(p + 0x408) = D_004C0348;
        }
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 0xD;
        if (p[0x210] == 0) {
            *(u8 **)(p + 0x408) = D_004C0334;
        } else {
            *(u8 **)(p + 0x408) = D_004C034C;
        }
        p[0x1BB] = 1;
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 0xE;
        if (p[0x210] == 0) {
            *(u8 **)(p + 0x408) = D_004C0338;
        } else {
            *(u8 **)(p + 0x408) = D_004C0350;
        }
        p[0x1BB] = 2;
        p[6] = 2;
        q[8] = 0;
        break;
    default:
        break;
    }
    t = *(volatile u8 *)(p + 0x1B5);
    p[0x1B5] = t;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 0xB, p[0x168]);
    a0 = *(s8 *)(p + 0x1EA);
    if ((a0 & 0xF) != 0) {
        p[0x1EA] = a0 - 1;
    }
}
