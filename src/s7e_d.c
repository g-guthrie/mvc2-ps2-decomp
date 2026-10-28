/* func_0012C470: MW 3.0.3 -O3 -sdatathreshold 8. Static copies of the two real callees let MW keep p in $a2 across the first jal and leave $v0 untouched, as retail does. */
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
typedef float f32;
typedef signed char s8;
typedef unsigned short u16;
typedef signed int s32;
typedef struct { f32 x, y, z; } V3;
typedef struct T {
    u8 p0[0x34];
    u32 w34, w38, w3C;
    u8 p40[0x10];
    u32 w50, w54;
    u8 p58[0x78 - 0x58];
    u32 w78, w7C, w80, w84;
    u8 p88[0xCC - 0x88];
    s16 hCC;
    u8 pCE[0xD8 - 0xCE];
    struct T *oD8;
    u8 pDC[0x13C - 0xDC];
    u8 b13C;
} T;
typedef struct {
    T *a;
    u8 p4[8];
    T *c;
    u8 p10[2];
    s16 h12;
    u8 p14[0x36 - 0x14];
    s16 h36;
} P;
extern u32 D_004C27FC;
extern f32 D_0043CD18[];

typedef struct {
    u8 *p0;
    u8 *p4;
    u8 pad8[0x8];
    s16 h10;
    s16 h12;
    s16 h14[4];
    u8 pad1c[0x38 - 0x1C];
    s16 h38;
} G;

/* verbatim copy of func_0012B8D0 (src/z6_a.c), the real callee */
static s16 func_0012B8D0(s16 a, s16 b)
{
    if (b >= 3) return 4;
    return (a + b + 4) % 4;
}

/* verbatim copy of func_0012B920 (src/w1911_u.c), the real callee and address-order predecessor */
static void func_0012B920(P *p) {
    T *v;
    v = p->a->oD8;
    if (p->h12 == 3) {
        p->a->hCC = 0xBC;
        p->a->w84 = D_004C27FC;
        p->a->w34 = 0;
        p->a->w38 = 0xC0300000;
        p->a->w3C = 0xC150CCCD;
        p->a->w50 = 0x3F800000;
        p->a->w54 = 0x3E99999A;
        v->b13C = 0;
        p->c->w80 = 0x3F800000;
        p->c->w7C = 0x3F800000;
        p->c->w78 = 0x3F800000;
    } else {
        p->a->hCC = 0xA6;
        p->a->w84 = D_004C27FC;
        *(f32 *)&p->a->w34 = D_0043CD18[p->h12];
        p->a->w38 = 0x3F800000;
        p->a->w3C = 0xC14E3D71;
        p->a->w54 = 0x3F800000;
        p->a->w50 = 0x3F800000;
        if (p->h36 < 4) {
            v->b13C = 1;
            *(V3 *)&v->w34 = *(V3 *)&p->a->w34;
            v->w38 = 0;
        } else {
            v->b13C = 0;
        }
        p->c->w80 = 0x3F4CCCCD;
        p->c->w7C = 0x3F4CCCCD;
        p->c->w78 = 0x3F4CCCCD;
    }
}

void func_0012C470(G *p) {
    s16 r;

    r = func_0012B8D0(p->h38, p->h12);
    switch (r) {
    case 0:
        if (p->h14[r] != -1) {
            if (p->h10 != 0) {
                p->p4[0x23] = 1;
            } else {
                p->p4[0x23] = 2;
            }
        }
        break;
    case 1:
    case 2:
        if (p->h14[r] != -1) {
            p->p4[0x23] = 0;
        }
        break;
    case 3:
        if (p->h14[r] != -1) {
            p->p4[0x23] = 8;
        }
        break;
    case 4:
        if (p->h14[0] == -1 && p->h14[1] == -1 && p->h14[2] == -1 && p->h14[3] == -1) {
            p->p4[0x23] = 6;
        } else {
            p->p4[0x23] = 7;
        }
        break;
    }
    func_0012B920((P *)p);
}
