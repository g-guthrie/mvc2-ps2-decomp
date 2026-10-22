typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G4a;
extern G4a *D_004C2794;
extern u8 D_004C10C8[4];
extern u8 D_004C10CC[4];
extern u8 D_004C10D0[4];
extern u8 D_004C10E0[4];
extern u8 D_004C10E4[4];
extern u8 D_004C10E8[4];

void func_002E4D60(u8 *p) {
    extern void func_001E3710(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    s32 a, b;
    s32 t;
    switch (p[0x1FC]) {
    case 0: {
        a = 0xC;
        b = 0;
        if (p[0x210] == 0) *(u8 **)(p + 0x408) = D_004C10C8;
        else *(u8 **)(p + 0x408) = D_004C10E0;
        p[0x1BB] = 0;
        func_001E3710(p, 0x14);
        break; }
    case 1: {
        b = 1;
        a = 0xD;
        if (p[0x210] == 0) *(u8 **)(p + 0x408) = D_004C10CC;
        else *(u8 **)(p + 0x408) = D_004C10E4;
        p[0x1BB] = 1;
        func_001E3710(p, 0x15);
        break; }
    case 2: {
        b = 5;
        a = 0xE;
        if (*(u16 *)(p + 0x20E) & 0x2000) {
            b = 2;
            a = 0x13;
        }
        if (p[0x210] == 0) *(u8 **)(p + 0x408) = D_004C10D0;
        else *(u8 **)(p + 0x408) = D_004C10E8;
        p[0x1BB] = 2;
        break; }
    default: break;
    }
    p[0x1B5] = a;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 0xB, b & 0xFF);
    t = *(s8 *)(p + 0x1EA);
    if (t & 0xF) p[0x1EA] = t - 1;
}
