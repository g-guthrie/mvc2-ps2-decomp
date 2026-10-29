typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u32 D_004C28B8;
extern u32 D_004C28BC;
extern u32 D_004CA170[];
extern u32 D_004CA174[];
extern u32 D_004CA178[];
extern u32 D_004CA17C[];
extern u32 D_004CA180[];
extern u32 D_004CA184[];
extern u32 D_004CA190[];
extern u32 D_004CA194[];
extern u32 D_004CA198[];
extern u32 D_004CA19C[];
extern u32 D_004CA1A0[];
extern u32 D_004CA1A4[];
extern u32 D_004CA1B0[];
extern u32 D_004CA1B4[];
extern u32 D_004CA1B8[];
extern u32 D_004CA1BC[];
extern u32 D_004CA1C0[];
extern u32 D_004CA1C4[];
extern u32 D_004CA1D0[];
extern u32 D_004CA1D4[];
extern u32 D_004CA1D8[];
extern u32 D_004CA1DC[];
extern u32 D_004CA1E0[];
extern u32 D_004CA1E4[];
extern u32 D_004CA1F0[];
extern u32 D_004CA1F4[];
extern u32 D_004CA1F8[];
extern u32 D_004CA1FC[];
extern u32 D_004CA200[];
extern u32 D_004CA204[];
void func_0012DC00(void) {
    u32 b = D_004C28BC;
    u32 c = D_004C28B8;
    D_004CA1F4[0] = b + 0x3F0000;
    D_004CA1F8[0] = b + 0x150000;
    D_004CA1FC[0] = b + 0x540000;
    D_004CA200[0] = b + 0x2A0000;
    D_004CA1F0[0] = b;
    D_004CA170[0] = c;
    D_004CA174[0] = c;
    D_004CA178[0] = c;
    D_004CA17C[0] = c;
    D_004CA204[0] = b + 0x690000;
    D_004CA180[0] = c;
    D_004CA184[0] = c;
    D_004CA1D0[0] = b + 0x141000;
    D_004CA1D4[0] = c + 0x67000;
    D_004CA1B0[0] = c + 0x67000;
    D_004CA1D8[0] = b + 0x291000;
    D_004CA1DC[0] = b + 0x7C0000;
    D_004CA1E0[0] = b + 0x3E1000;
    D_004CA1E4[0] = b + 0x7D1000;
    D_004CA1B4[0] = b + 0x531000;
    D_004CA1B8[0] = b + 0x3D0000;
    D_004CA194[0] = b + 0x531000;
    D_004CA1BC[0] = b + 0x681000;
    D_004CA19C[0] = b + 0x681000;
    D_004CA1C0[0] = b + 0x3E1000;
    D_004CA190[0] = b + 0x141000;
    D_004CA198[0] = b + 0x291000;
    D_004CA1A0[0] = b + 0x3E1000;
    D_004CA1C4[0] = b + 0x7D1000;
    D_004CA1A4[0] = b + 0x7D1000;
}

typedef struct { u8 pad0[4]; s8 f4; } S2840;
extern S2840 *D_004C2840;
extern s32 D_004C27FC;
extern s32 D_004C27E8;

void func_0014A530(u8 *p) {
    s8 m = D_004C2840->f4;
    if (m == 0) {
        *(s32 *)(p + 0xD0) = 1;
        *(u32 *)(p + 0x34) = 0;
        *(u32 *)(p + 0x38) = 0xBF800000;
        *(u32 *)(p + 0x3C) = 0;
        *(s16 *)(p + 0xCC) = 0x8A;
        *(s32 *)(p + 0x84) = D_004C27FC;
        return;
    } else if (m == 1) {
        *(s32 *)(p + 0xD0) = 0x11;
        *(u32 *)(p + 0x34) = 0x3FC00000;
        *(u32 *)(p + 0x38) = 0xC0AFF7CF;
        *(u32 *)(p + 0x3C) = 0xC13CCCCD;
        *(u32 *)(p + 0x50) = 0x3F666666;
        *(u32 *)(p + 0x54) = 0x3F666666;
        *(u32 *)(p + 0x58) = 0x3F666666;
        *(s16 *)(p + 0xCC) = 0xD;
        *(s32 *)(p + 0x84) = D_004C27E8;
        return;
    } else if (m == 2) {
        *(s32 *)(p + 0xD0) = 1;
        *(u32 *)(p + 0x34) = 0;
        *(u32 *)(p + 0x38) = 0xBF800000;
        *(u32 *)(p + 0x3C) = 0;
        *(s16 *)(p + 0xCC) = 0x8B;
        *(s32 *)(p + 0x84) = D_004C27FC;
        return;
    } else if (m > 2) {
        *(s32 *)(p + 0xD0) = 1;
        *(u32 *)(p + 0x34) = 0;
        *(u32 *)(p + 0x38) = 0xBFF33333;
        *(u32 *)(p + 0x3C) = 0;
        *(s16 *)(p + 0xCC) = 0x8E;
        *(s32 *)(p + 0x84) = D_004C27FC;
        return;
    }
}
