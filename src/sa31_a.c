typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[4]; s8 b4; u8 pad1; s8 b6; } G150;
typedef struct { u16 a; u16 b; } T150;
typedef struct Q150 {
    u8 pad0[0x18];
    struct Q150 *f18;
    u8 pad1[0x1E - 0x1C];
    s16 h1E;
    u8 pad2[0x23 - 0x20];
    u8 b23;
    u8 pad3[0x74 - 0x24];
    f32 f74;
    u8 pad4[0x84 - 0x78];
    s32 f84;
    u8 pad5[0xCC - 0x88];
    s16 hCC;
    u8 pad6[0x13C - 0xCE];
    s8 b13C;
} Q150;

extern G150 *D_004C2840;
extern s32 D_004C27FC;
extern s16 D_00444360[];
extern s16 D_00444362[];
extern T150 D_004CB010[];

static void func_0014E770(u8 *p) {
    u8 *q = *(u8 **)(p + 24);
    if (*(s32 *)(q + 220) != 0) {
        if (q[4] == 1) {
            *(s16 *)(p + 30) = *(s16 *)(q + 30);
        } else {
            *(s16 *)(p + 30) = *(s16 *)(q + 30);
        }
    }
}

void func_001509D0(Q150 *p) {
    s32 a;
    s32 d;
    s32 r;
    s32 v;
    s32 n;
    d = D_00444360[p->b23];
    func_0014E770((u8 *)p);
    p->b13C = p->f18->b13C;
    p->f74 = p->f18->f74;
    a = D_004CB010[D_004C2840->b6 + p->h1E].a;
    v = a;
    if (d != 0) {
        v = (u16)((a & 0xFFFF) / (s16)d);
    }
    r = (u16)((u16)v % 10);
    n = p->b23;
    if (n > 1) {
        if ((a & 0xFFFF) / D_00444362[n] == 0) {
            if (r == 0) {
                p->b13C = 0;
            }
        }
    }
    p->hCC = ((r << 16) >> 16) + 0x25;
    p->f84 = D_004C27FC;
}

extern u8 D_004D18A0[];
extern s8 D_004F1F41[];
extern s8 D_004F1F42[];
extern u8 D_004F2039[];
extern u8 *D_004C25D0;
extern u8 *D_004C25D4;

s32 func_00126530(void) {
    s32 a;
    u8 *x;
    u8 *y;
    s32 c;
    s32 t;
    s32 r;
    if (D_004D18A0[0] < 4) {
        return 0;
    }
    a = D_004F1F41[0];
    if (a == 1) goto L568;
    if (D_004F1F42[0] != 1) goto L5C4;
L568:
    if (a == 8) goto L5C4;
    if (D_004F1F42[0] == 8) goto L5C4;
    if (D_004F2039[0] == 0) goto L5A8;
    if (D_004C25D0[5] != 3) goto L5C4;
    return 1;
L5A8:
    if (D_004C25D4[5] != 3) goto L5C4;
    return 1;
L5C4:
    x = D_004C25D4;
    y = D_004C25D0;
    c = x[5];
    if (c != y[5]) {
        return 0;
    }
    if (a == 2 || D_004F1F42[0] == 2) {
        return 0;
    }
    if (c != 0) {
        return 1;
    }
    if (x[1] == 0x1A) {
        return y[0x1E4] < 0x15;
    }
    if (y[1] == 0x1A) {
        return x[0x1E4] < 0x15;
    }
    t = x[0x1E4];
    if (t >= 0x15 && t != 0x20) {
        return 0;
    }
    if ((r = (y[0x1E4] < 0x15)) == 0) {
        if (t == 0x20) {
            goto ret1;
        }
        return 0;
    }
ret1:
    return 1;
}
