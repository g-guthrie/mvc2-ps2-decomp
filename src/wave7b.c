typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;


extern u8 *D_004C25D4;
extern u8 *D_004C2794;
extern s8 *D_004C2840;
extern s8 *D_004C299C;
extern u8 D_004C00C4[8];
extern void (*D_004C21C8[2])(void);
extern void (*D_004C1C98[2])(u8 *);
extern void (*D_004BFAB4[2])(u8 *, u8 *);
extern u8 D_0043CC08[];
extern void func_00186A60(u8 *, s32);
extern void func_0016D190(void);
extern void func_003D7310(void *);
extern void func_00152790(void);
extern void func_00152720(void);
extern void func_00169C30(u8 *);
extern void func_0018C4B0(u8 *, s32);
extern void func_003DA6F0(s32);
extern s32 func_0032C180(s32);
extern void func_003DAA40(u8 *);

void func_0022C7D0(u8 *p) {
    u8 v;
    s32 c;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    v = D_004C00C4[*(s8 *)(p + 0x4DD)];
    c = *(s32 *)(p + 0x2BC);
    if (c == 0x27) v = 0x1C;
    if (c == 7) v = 0x1B;
    p[0x1FD] = v;
    func_00186A60(p, 0x1D);
}

void func_003D21F0(void) {
    D_004C21C8[D_004C2840[2]]();
    func_0016D190();
    func_003D7310(func_00152790);
}

void func_00169BE0(u8 *p) {
    s8 *g = D_004C2840;
    if (g[0x2E] != 0 || (g[0x88] & (1 << p[2])) == 0) {
        p[0x45F] = 0;
        p[0x4BD] = 0;
        func_00169C30(p);
    }
}

void func_00327C20(void) {
    if (D_004C2840[0xAE] != 0) {
        u8 *a = D_004C2794;
        if (a[6] == 0) {
            func_0018C4B0(*(u8 **)(a + 0x18), 4);
            func_0018C4B0(*(u8 **)(D_004C2794 + 0x24), 4);
        }
    }
}

void func_00127590(void) {
    (*(void (**)(void))(D_0043CC08 + D_004C2840[4] * 4))();
    func_003DA6F0(6);
    func_003DA6F0(0xD);
    func_003D7310(func_00152720);
}

void func_001D9BF0(u8 *p, u8 *q) {
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    if (*(u16 *)(q + 0x168) != *(u16 *)(p + 0xD0)) {
        p[4] += 1;
    } else {
        D_004BFAB4[p[5]](p, q);
    }
}

void func_0032C390(void) {
    if (func_0032C180(0) == 0) {
        *(s16 *)(D_004C2840 + 8) -= 1;
        if (*(s16 *)(D_004C2840 + 8) <= 0) {
            D_004C2840[4] += 1;
            D_004C2840[5] = 0;
        }
    }
}

void func_00139E80(u8 *p) {
    u8 a = p[4];
    switch (a) {
    case 0:
        if (D_004C2840[7] != 0) {
            p[4] = a + 1;
            p[0x13C] = 0;
        }
        break;
    case 1:
        func_003DAA40(p);
        break;
    }
}
