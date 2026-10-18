typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 h7C[8]; } G2D9;
extern G2D9 *D_004C2794;
extern u8 D_004C1028[4];
extern u8 D_004C1030[4];
extern u8 D_004C1038[4];
extern u8 D_004C1040[4];
extern s32 D_0045A860[];

void func_002D9B00(u8 *p)
{
    extern void func_001757E0(u8 *, s32, u8);
    u32 s;
    u8 a2;
    u32 h;
    s = p[0x1FC];
    if (p[0x212] != 0) s = (u8)(s + 3);
    *(s32 *)(p + 0x2D8) = 0;
    p[0x1BB] = D_004C1030[p[0x1FC]];
    p[0x1B5] = D_004C1028[(u8)s];
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->h7C[p[2]]++;
    func_001757E0(p, D_004C1040[(u8)s], D_004C1038[(u8)s]);
    if ((u8)s == 1) {
        *(s32 *)(p + 0x2D8) = 1;
        a2 = 1;
        h = *(u16 *)(p + 0x20E);
        if (h & 0x2000) a2 = 7;
        if (h & 0x1000) a2 = 6;
        func_001757E0(p, 0xB, a2);
    }
    if (p[0x210] != 0) s = (u8)(s + 6);
    *(s32 *)(p + 0x408) = D_0045A860[(u8)s];
    if (p[0x212] == 0) {
        s32 t = *(s8 *)(p + 0x1EA);
        if ((t & 0xF) != 0) {
            p[0x1EA] = t - 1;
        }
        *(s32 *)(p + 0x300) = 0x20;
        *(s32 *)(p + 0x304) = *(u16 *)(p + 0x168);
    } else {
        s32 t = *(s8 *)(p + 0x1EA);
        if ((t & 0xF0) != 0) p[0x1EA] = t - 0x10;
    }
}
