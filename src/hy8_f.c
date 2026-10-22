typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 s7C[8]; } H8G;
extern H8G *D_004C2794;
extern s32 D_004BFB1C;
extern s32 D_004BFB20;
extern s32 D_004BFB24;
extern s32 D_004BFB34;
extern s32 D_004BFB38;
extern s32 D_004BFB3C;

void func_001E9DE0(u8 *p)
{
    extern void func_001E3710(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    u32 t;
    s32 v;
    p[0x169] = 12;
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 3;
        p[0x1B5] = 0xF;
        p[0x169] = 0x14;
        func_001E3710(p, 0x14);
        if (p[0x210] == 0) *(s32 *)(p + 0x408) = (s32)&D_004BFB1C;
        else *(s32 *)(p + 0x408) = (s32)&D_004BFB34;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x169] = 0x14;
        p[0x168] = 4;
        p[0x1B5] = 0x10;
        if (*(u16 *)(p + 0x20E) & 0x2000) {
            p[0x169] = 12;
            p[0x168] = 1;
            p[0x1B5] = 0x18;
        }
        func_001E3710(p, 0x15);
        if (p[0x210] == 0) *(s32 *)(p + 0x408) = (s32)&D_004BFB20;
        else *(s32 *)(p + 0x408) = (s32)&D_004BFB38;
        p[0x1BB] = 1;
        break;
    case 2:
        p[0x168] = 5;
        p[0x1B5] = 0x19;
        if (*(u16 *)(p + 0x20E) & 0x2000) {
            p[0x168] = 2;
            p[0x1B5] = 0x11;
        } else {
            p[0x169] = 0x14;
        }
        func_001E3710(p, 0x16);
        if (p[0x210] == 0) *(s32 *)(p + 0x408) = (s32)&D_004BFB24;
        else *(s32 *)(p + 0x408) = (s32)&D_004BFB3C;
        p[0x1BB] = 2;
        break;
    default:
        break;
    }
    t = *(volatile u8 *)(p + 0x1B5);
    p[0x1B5] = t;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->s7C[p[2]]++;
    func_001757E0(p, p[0x169], p[0x168]);
    v = *(s8 *)(p + 0x1EA);
    if (v & 0xF0) *(s8 *)(p + 0x1EA) = v - 0x10;
}
