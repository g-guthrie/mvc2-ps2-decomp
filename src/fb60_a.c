typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u8 b0, b1, b2, b3, b4, b5, b6, b7;
    u16 h8, hA, hC, hE;
    u8 pad10[4];
    s32 w14;
    s8 b18;
    u8 pad19[0x11];
    s8 b2A;
    u8 pad2B[0x5E];
    u8 b89;
} FA;

extern FA *D_004C2840;
extern u16 D_004F4484[];
extern u16 D_004F4498[];
extern u8 D_004F20B0[];
extern u8 D_004F2580[];
extern u8 D_004F2B38[];
extern u8 D_004F258C[];
extern u8 D_004F2B44[];

void func_003D2520(void) {
    extern void func_0011D8F8(u8 *, s32, s32);
    extern void func_00173F90(u8 *);
    s8 r;
    s8 i;
    s32 off;
    u8 *q;
    FA *p;
    s8 *f;

    r = 0;
    if (D_004F4484[0] & 0x8000) {
        r++;
    }
    if (D_004F4498[0] & 0x8000) {
        r = r + 2;
    }
    if (r != 0) {
        if (D_004C2840->b2A != 0) {
            r = 3;
        }
        D_004C2840->b18 = r;
        i = 0;
        D_004C2840->b89 = r;
        off = 0;
        D_004C2840->w14 = 0x60;
        for (; i < 6; i++) {
            q = D_004F20B0 + off;
            func_0011D8F8(q, 0, 0x5B8);
            q[0x538] = i;
            func_00173F90(q);
            off += 0x5B8;
        }
        p = D_004C2840;
        f = &p->b18;
        if (p->b18 & 1) {
            D_004F2580[0] = 1;
        }
        if (*f & 2) {
            D_004F2B38[0] = 1;
        }
        D_004F258C[0] = 1;
        D_004F2B44[0] = 2;
        p->b0 = 3;
        D_004C2840->b1 = 0;
        D_004C2840->b2 = 0;
        D_004C2840->b3 = 0;
        D_004C2840->b4 = 0;
        D_004C2840->b5 = 0;
        D_004C2840->b6 = 0;
        D_004C2840->b7 = 0;
        D_004C2840->h8 = 0;
        D_004C2840->hA = 0;
        D_004C2840->hC = 0;
        D_004C2840->hE = 0;
    }
}
