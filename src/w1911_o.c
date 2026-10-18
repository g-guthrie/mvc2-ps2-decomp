typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef struct { u8 pad[0x7C]; s16 h7C[8]; } G;
extern G *D_004C2794;
extern s32 D_004C1400, D_004C13E8, D_004C1404, D_004C13EC, D_004C1408, D_004C13F0;
void func_002FCF70(u8 *p) {
    extern void func_001E3710(u8 *, u8);
    extern void func_001757E0(u8 *, s32, s32);
    u8 t;
    s8 v;
    s32 *a;
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 0xF;
        func_001E3710(p, 0x14);
        if (p[0x210] == 0) {
            *(s32 **)(p + 0x408) = &D_004C13E8;
        } else {
            *(s32 **)(p + 0x408) = &D_004C1400;
        }
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 0x10;
        if (p[0x210] == 0) {
            *(s32 **)(p + 0x408) = &D_004C13EC;
        } else {
            *(s32 **)(p + 0x408) = &D_004C1404;
        }
        p[0x1BB] = 1;
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 0x11;
        if (p[0x210] == 0) {
            *(s32 **)(p + 0x408) = &D_004C13F0;
        } else {
            *(s32 **)(p + 0x408) = &D_004C1408;
        }
        p[0x1BB] = 2;
        break;
    default:
        break;
    }
    t = *(volatile u8 *)(p + 0x1B5);
    p[0x1B5] = t;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->h7C[p[2]]++;
    func_001757E0(p, 0xC, p[0x168]);
    v = p[0x1EA];
    if ((v & 0xF0) != 0) p[0x1EA] = v - 0x10;
}
