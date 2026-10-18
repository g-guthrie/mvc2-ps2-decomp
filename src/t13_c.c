typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u16 D_004D18DC[];
extern u8 D_004D18DB[];

void func_003B3650(u8 *a, u8 *b) {
    extern void func_003B3860(); extern void (*D_004C1FE8[2])(void*,void*);
    if (b[0x169] != 0x16) { u32 u = a[4]; a[4] = u + 1; func_003B3860(a); return; }
    if (b[5] != 0) { u32 u = a[4]; a[4] = u + 1; func_003B3860(a); return; }
    *(s8 *)(a + 0x24) = *(s8*)(b + 0x24);
    if ((D_004D18DC[0] & (1 << D_004D18DB[0])) == 0) D_004C1FE8[a[5]](a,b);
}

extern u8 *D_004C2840;
extern s8 D_004F8010[];
extern s8 D_004F8014[];

void func_00146440(u8 *p) {
    u32 v;
    if (p[0x21] != 0) {
        if (p[0x20] == *(s8 *)(D_004C2840 + 0x4C)) {
            p[0x13C] = 0;
        } else {
            p[0x13C] = 1;
        }
    }
    if (p[0x20] == 1) {
        if (D_004F8010[0] == 0 || D_004F8014[0] == 0) {
            v = 0x3F19999A;
            *(u32 *)(p + 0x80) = v;
            *(u32 *)(p + 0x7C) = v;
            *(u32 *)(p + 0x78) = v;
        } else {
            v = 0x3F800000;
            *(u32 *)(p + 0x80) = v;
            *(u32 *)(p + 0x7C) = v;
            *(u32 *)(p + 0x78) = v;
        }
    }
}

extern void (*D_004BFAC0[2])(void *, void *);

void func_001DABF0(u8 *a, u8 *b) {
    u32 t;
    *(s8 *)(a + 0x24) = *(s8 *)(b + 0x24);
    if (a[0x22] == 0) {
        if (b[5] == 0 && b[0x1E4] == 0x15 && b[0x1FD] == 0) goto call;
        t = a[4];
        a[4] = t + 1;
        a[0x13C] = 0;
        return;
    } else {
        if (b[5] == 1 && b[0x1E4] == 0x1E) goto call;
        t = a[4];
        a[4] = t + 1;
        a[0x13C] = 0;
        return;
    }
call:
    D_004BFAC0[a[5]](a, b);
}

extern u8 *D_004C2794;

void func_002FDD90(u8 *p) {
    extern void func_00175C00(void *, s32);
    extern void func_001757E0(void *, s32, s32);
    u8 *e;
    s16 v;
    u32 t;
    func_00175C00(p, 0);
    t = p[6];
    p[6] = t + 1;
    p[0x20D] = 2;
    *(u32 *)(p + 0x5C) = 0xC1F00000;
    if (p[0x1E6] != 0) {
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
    }
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0xBE892492;
    *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    p[0x1B5] = 0x35;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    e = (u8 *)((p[2] << 1) + (u32)D_004C2794);
    v = *(s16 *)(e + 0x7C) + 1;
    *(s16 *)(e + 0x7C) = v;
    func_001757E0(p, 0x14, 0);
}

extern u8 D_004F20B0[];

void func_00190070(void) {
    u8 *a = D_004C2794;
    if (a[6] == 0) {
        if (a[0] == 4) {
            u8 *b = D_004C2840;
            if (*(s8 *)(b + 0x53) == 0) {
                if (*(s8 *)(b + 0x57) == 0) {
                    s32 i;
                    u8 *e;
                    s32 off;
                    i = 0;
                    off = 0;
                    do {
                        e = D_004F20B0 + off;
                        if (e[0] == 0) {
                            if (*(s16 *)(e + 0x434) < *(s16 *)(e + 0x438)) {
                                if (*(s16 *)(e + 0x2B4) == 0) {
                                    s16 v = *(s16 *)(e + 0x43A) - 1;
                                    *(s16 *)(e + 0x43A) = v;
                                    if (v < 0) {
                                        *(s16 *)(e + 0x43A) = 50;
                                        *(s16 *)(e + 0x434) = *(s16 *)(e + 0x434) + 1;
                                    }
                                }
                            }
                        }
                        off += 0x5B8;
                        i++;
                    } while (i < 6);
                }
            }
        }
    }
}
