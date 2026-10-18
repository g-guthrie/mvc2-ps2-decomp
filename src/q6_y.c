typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[16]; } G2794;
extern G2794 *D_004C2794;
extern u8 D_004C1800[8];
extern u8 D_004C1808[8];
extern u8 D_004C1810[8];
extern u8 D_004C1818[8];
extern u32 D_0045DD60[];

void func_00322BC0(u8 *p) {
    extern void func_001757E0(u8 *, s32, s32);
    u32 v;
    u32 s;
    s8 w;
    p[7] = 0;
    p[6] = 0;
    v = p[0x1FC];
    s = v;
    if (p[0x212] != 0) {
        s = (u8)(v + 3);
    }
    p[0x1BB] = D_004C1808[(u8)v];
    p[0x1B5] = D_004C1800[(u8)s];
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, D_004C1818[(u8)s], D_004C1810[(u8)s]);
    if (p[0x210] != 0) {
        s = (u8)(s + 6);
    }
    *(u32 *)(p + 0x408) = D_0045DD60[(u8)s];
    if (p[0x212] == 0) {
        w = p[0x1EA];
        if ((w & 0xF) != 0) {
            p[0x1EA] = w - 1;
        }
    } else {
        w = p[0x1EA];
        if ((w & 0xF0) != 0) {
            p[0x1EA] = w - 0x10;
        }
    }
}
