typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[0x7C];
    s16 h7C[1];
} G23F;

extern G23F *D_004C2794;
extern u8 data_s8_004C02C0[2];
extern u8 D_004C02C4[2];
extern u8 D_004C02C8[2];
extern u8 D_004C02D8[2];
extern u8 D_004C02DC[2];
extern u8 D_004C02E0[2];

void func_0023FB40(u8 *p)
{
    extern void func_001E3710(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    s32 x;
    s32 y;
    s32 z;
    s32 b;

    switch (p[0x1FC]) {
    case 0:
        x = 0xC;
        z = 0;
        y = 0x14;
        if (p[0x210] == 0) {
            *(u8 **)(p + 0x408) = data_s8_004C02C0;
        } else {
            *(u8 **)(p + 0x408) = D_004C02D8;
        }
        p[0x1BB] = 0;
        break;
    case 1:
        z = 1;
        x = 0xD;
        y = 0x15;
        if (p[0x210] == 0) {
            *(u8 **)(p + 0x408) = D_004C02C4;
        } else {
            *(u8 **)(p + 0x408) = D_004C02DC;
        }
        p[0x1BB] = 1;
        break;
    case 2:
        z = 2;
        x = 0xE;
        y = 0x16;
        if (p[0x210] == 0) {
            *(u8 **)(p + 0x408) = D_004C02C8;
        } else {
            *(u8 **)(p + 0x408) = D_004C02E0;
        }
        p[0x1BB] = 2;
        break;
    default:
        break;
    }
    p[0x1B5] = x;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->h7C[p[2]]++;
    func_001E3710(p, (u8)y);
    func_001757E0(p, 0xB, (u8)z);
    b = *(s8 *)(p + 0x1EA);
    if ((b & 0xF) != 0) {
        *(s8 *)(p + 0x1EA) = b - 1;
    }
}
