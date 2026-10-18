typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef struct { u8 pad[0x7C]; s16 h7C[8]; } G;
extern G *D_004C2794;
extern s32 D_004C1338, D_004C133C, D_004C1340;
void func_002F7740(u8 *p) {
    extern void func_002FA0B0(u8 *);
    extern void func_001E3710(u8 *, u8);
    extern void func_001757E0(u8 *, s32, s32);
    u8 t;
    if (p[0x2CE] != 0) {
        func_002FA0B0(p);
        return;
    }
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 6;
        *(s32 **)(p + 0x408) = &D_004C1338;
        p[0x1BB] = 0;
        func_001E3710(p, 0x14);
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 7;
        *(s32 **)(p + 0x408) = &D_004C133C;
        p[0x1BB] = 1;
        func_001E3710(p, 0x15);
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 8;
        *(s32 **)(p + 0x408) = &D_004C1340;
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
    func_001757E0(p, 9, p[0x168]);
}
