typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 count[2]; } Counters;
extern Counters *D_004C2794;
extern u8 D_004C1638[8];
extern u8 D_004C1640[8];
extern u8 D_004C1648[8];
extern u8 D_004C1650[8];
extern s32 D_0045CFF0[];

void func_0030D080(u8 *p)
{
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00176160(u8 *, s32, s32, s32);
    u8 k;
    u8 *b5, *c0, *b2, *d8, *c2;
    u8 k2;
    u8 *a;
    f32 c;

    a = p;
    a[7] = 0;
    a[6] = 0;
    k = a[0x1FC];
    if (a[0x212] != 0) {
        k += 3;
    }
    *(s32 *)(a + 0x334) = 0;
    a[0x1BB] = D_004C1640[a[0x1FC]];
    b5 = a + 0x1B5;
    c0 = a + 0x1C0;
    b2 = a + 0x1B2;
    d8 = a + 0x1D8;
    c2 = a + 2;
    a[0x1B5] = D_004C1638[k];
    a[0x1B2] = *(u16 *)(a + 0x1C0) = 0;
    *(s32 *)(a + 0x1D8) = 0;
    ++D_004C2794->count[a[2]];
    func_001757E0(a, D_004C1650[k], D_004C1648[k]);
    k2 = k;
    if (k2 == 5) {
        if (*(u16 *)(a + 0x20E) & 0x1000) {
            c = 171.42855834960938f;
            if (!(*(f32 *)(a + 0x38) <= c + *(f32 *)(a + 0x430))) {
                *(f32 *)(a + 0x5C) = 0;
                *(f32 *)(a + 0x60) = 0;
                *(f32 *)(a + 0x68) = 0;
                *(f32 *)(a + 0x6C) = 0;
                *(s32 *)(a + 0x334) = 1;
                *(s8 *)(a + 0x1EA) &= 0xF;
                *b5 = 0x12;
                *b2 = *(u16 *)c0 = 0;
                *(s32 *)d8 = 0;
                ++D_004C2794->count[*c2];
                func_001757E0(a, 0xC, 5);
                func_00176160(a, 1, 0xE, 1);
            }
        }
    }
    if (k2 == 2) {
        func_00176160(a, 1, 0xF, 1);
    }
    if (a[0x210] != 0) {
        k += 6;
    }
    *(s32 *)(a + 0x408) = D_0045CFF0[k];
    if (a[0x212] == 0) {
        if (*(s8 *)(a + 0x1EA) & 0xF) {
            *(s8 *)(a + 0x1EA) -= 1;
        }
    } else {
        if (*(s8 *)(a + 0x1EA) & 0xF0) {
            *(s8 *)(a + 0x1EA) -= 0x10;
        }
    }
}
