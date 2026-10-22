typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G25a;
typedef struct { u8 pad[0x38]; f32 f38; u8 pad2[0x430 - 0x3C]; f32 f430; } S25a;
extern G25a *D_004C2794;
extern u8 D_004BFB94[4];
extern u8 D_004BFB98[4];
extern u8 D_004BFB9C[4];
extern u8 D_004BFBAC[4];
extern u8 D_004BFBB0[4];
extern u8 D_004BFBB4[4];

void func_001EF1B0(u8 *p) {
    extern void func_001E3710(u8 *, s32);
    extern void func_001865B0(u8 *);
    extern void func_001757E0(u8 *, s32, u8);
    u32 t;
    s32 a;
    switch (p[0x1FC]) {
    case 0:
        if ((*(u16 *)(p + 0x20E) & 0x1000) != 0) {
            p[6] = 1;
            p[7] = 0;
            p[0x1EA] = *(s8 *)(p + 0x1EA) & 0xF;
            p[0x1B5] = 0x16;
            if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
                ((S25a *)p)->f38 = *(f32 *)(p + 0x430);
                func_001865B0(p);
                break;
            }
            p[0x168] = 6;
            func_001E3710(p, 0x16);
            if (p[0x210] == 0) *(u8 **)(p + 0x408) = D_004BFB98;
            else *(u8 **)(p + 0x408) = D_004BFBB0;
            p[0x1BB] = 1;
        } else {
            p[0x168] = 0;
            p[0x1B5] = 0xF;
            func_001E3710(p, 0x14);
            if (p[0x210] == 0) *(u8 **)(p + 0x408) = D_004BFB94;
            else *(u8 **)(p + 0x408) = D_004BFBAC;
            p[0x1BB] = 0;
        }
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 0x10;
        func_001E3710(p, 0x15);
        if (p[0x210] == 0) *(u8 **)(p + 0x408) = D_004BFB98;
            else *(u8 **)(p + 0x408) = D_004BFBB0;
        p[0x1BB] = 1;
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 0x11;
        if (p[0x210] == 0) *(u8 **)(p + 0x408) = D_004BFB9C;
            else *(u8 **)(p + 0x408) = D_004BFBB4;
        p[0x1BB] = 2;
        break;
    }
    t = p[0x1B5];
    p[0x1B5] = t;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 0xC, p[0x168]);
    a = *(s8 *)(p + 0x1EA);
    if ((a & 0xF0) != 0) p[0x1EA] = a - 0x10;
}
