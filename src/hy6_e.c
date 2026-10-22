typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G381;
extern G381 *D_004C2794;
typedef struct { u8 pad[0x1C]; u32 w1C; } H381;
extern H381 *D_004C2840;
extern u8 *D_004C29A0, *D_004C29A4;
extern u16 D_004D18DC[];
extern u8 D_004D18DB[];

void func_00381C50(u8 *p)
{
    extern void func_00381650(u8 *);
    extern s32 func_00381710();
    extern void func_001E7F60(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    if ((*(u8 **)(p + 0x18))[4] >= 2) {
        u32 t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
        return;
    }
    if ((D_004D18DC[0] & (1 << D_004D18DB[0])) != 0) return;
    if (p[0x23] != 0) {
        s32 v = D_004C29A0[1];
        if (v < p[0x23]) {
            p[0x13C] = 0;
            return;
        }
        if (p[0x23] != v) *D_004C29A4 = 1;
    }
    func_00381650(p);
    p[0x13C] = func_00381710();
    if (*(s8 *)(p + 0x1B2) != 0) {
        s8 d;
        D_004C29A0[3] = 0xFF;
        d = *(s8 *)(p + 0x1B4) - 1;
        *(s8 *)(p + 0x1B4) = d;
        if (d == 0) {
            u16 a = p[0x1B7] + 0x33;
            u32 t = D_004C29A4[2];
            D_004C29A4[2] = t + 1;
            if (((u8)(t + 1) & 1) != 0) a = p[0x1B7] + 0x35;
            p[0x1B5] = a;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
        }
    }
    if (*(s8 *)(p + 0x13C) != 0)
        func_001757E0(p, 0x19, p[0x1B7] + *D_004C29A4 * 2);
    if (D_004C29A0[3] == 0) {
        if ((p[0x23] & 1) == (D_004C2840->w1C & 1)) func_001E7F60(p);
    }
}
