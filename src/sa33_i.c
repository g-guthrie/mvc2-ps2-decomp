typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } HI;
extern u8 D_004C1228[8];
extern u8 D_004C1238[8];
extern u8 D_004C1220[8];
extern u8 D_004C1230[8];
extern s32 D_0045B6F0[];
extern s32 D_0045B708[];
extern HI *D_004C2794;

void func_002EE5C0(u8 *p)
{
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_002F1D90(u8 *);
    u8 k;
    u8 v;
    s32 a1;
    v = p[0x1FC];
    k = v;
    if (p[0x212] != 0) k += 3;
    p[0x1BB] = D_004C1228[v];
    p[0x1B5] = D_004C1220[k];
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]] += 1;
    func_001757E0(p, D_004C1238[k], D_004C1230[k]);
    if (p[0x210] != 0) k += 6;
    a1 = D_0045B6F0[k];
    if (*(s32 *)(p + 0x2D4) == 1) a1 = D_0045B708[k % 6];
    *(s32 *)(p + 0x408) = a1;
    if (k != 3 && k != 9) func_002F1D90(p);
    if (p[0x212] == 0) {
        s32 t = *(s8 *)(p + 0x1EA);
        if ((t & 0xF) != 0) p[0x1EA] = t - 1;
    } else {
        s32 t = *(s8 *)(p + 0x1EA);
        if ((t & 0xF0) != 0) p[0x1EA] = t - 0x10;
    }
}
