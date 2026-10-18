typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 b[12]; } E12;
extern u8 *D_00444478[];
extern E12 D_00444490[];
extern s32 D_004C27DC;
extern s32 D_004C27E0;
extern s32 D_004C27F8;

void func_00150ED0(s32 idx) {
    extern void func_00150FD0(s32, s32, s32, E12 *, s32);
    u8 *p = D_00444478[idx];
    while (p[0] != 0xFF) {
        if (p[1] == 0x80) {
            func_00150FD0(p[0], p[1], p[2], &D_00444490[p[3]], D_004C27DC);
            p += 4;
        } else if (p[1] == 0x81) {
            func_00150FD0(p[0], p[1], p[2], &D_00444490[p[3]], D_004C27E0);
            p += 4;
        } else {
            func_00150FD0(p[0], p[1], p[2], &D_00444490[p[3]], D_004C27F8);
            p += 4;
        }
    }
}

typedef struct { u8 pad[0x7C]; s16 h7C[1]; } G94;
extern G94 *D_004C2794;

void func_002DCF30(u8 *p) {
    extern void func_001E3710(u8 *, u8);
    extern void func_001757E0(u8 *, s32, u8);
    extern u8 D_004C1078[2];
    extern u8 D_004C107C[2];
    extern u8 D_004C1080[2];
    s32 x, z;
    u32 y;
    s8 t;
    switch (p[0x1FC]) {
    case 0:
        x = 12;
        y = 0;
        z = 20;
        *(u8 **)(p + 0x408) = D_004C1078;
        p[0x1BB] = 0;
        break;
    case 1:
        x = 13;
        y = 1;
        z = 21;
        *(u8 **)(p + 0x408) = D_004C107C;
        p[0x1BB] = 1;
        break;
    case 2:
        x = 14;
        y = 2;
        z = 22;
        *(u8 **)(p + 0x408) = D_004C1080;
        p[0x1BB] = 2;
        break;
    }
    p[0x1B5] = x;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->h7C[p[2]]++;
    func_001E3710(p, z);
    func_001757E0(p, 0xB, y);
    t = p[0x1EA];
    if ((t & 0xF) != 0) p[0x1EA] = t - 1;
}
