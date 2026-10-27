typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 a[1]; } G7C;

void func_00387940(u8 *p, u8 *q) {
    extern G7C *D_004C2794;
    extern void func_00175700();
    extern void func_001E7F60(u8 *);
    u8 *r;
    s16 v;
    r = q + 0x2B8;
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        p[4]++;
        r[6] = 0;
        return;
    }
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        *(s8 *)(p + 0x151) = 0;
        p[0x1B5] = 0x3A;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->a[p[2]]++;
    }
    func_001E7F60(p);
}

void func_00273EE0(u8 *p) {
    extern G7C *D_004C2794;
    extern u8 D_004C0780[4], D_004C0784[4], D_004C0788[4];
    extern void func_001757E0(u8 *, s32, s32);
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 0;
        *(u8 **)(p + 0x408) = D_004C0780;
        p[0x1BB] = 0;
        p[0x2B6] = 1;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 1;
        *(u8 **)(p + 0x408) = D_004C0784;
        p[0x1BB] = 1;
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 2;
        *(u8 **)(p + 0x408) = D_004C0788;
        p[0x1BB] = 2;
        break;
    }
    p[0x1B5] = *(volatile u8 *)(p + 0x1B5);
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->a[p[2]]++;
    func_001757E0(p, 7, p[0x168]);
}

void func_003C0020(u8 *p, u8 *q) {
    extern u8 *D_004C2840;
    extern void (*D_00475BF0[])(u8 *, u8 *);
    extern void func_00176160(u8 *, s32, s32, s32);
    extern void func_003C0540(u8 *, u8 *);
    *(s32 *)(q + 0x2CC) = 4;
    if (*(s32 *)(p + 0xD0) == *(u16 *)(q + 0x168) && q[0x425] == 0 && q[0x1E4] == 0x1D) {
        func_00176160(q, 1, ((*(s32 *)(D_004C2840 + 0x1C) & 2) >> 1) + 0xB, 1);
        D_00475BF0[p[5]](p, q);
    } else {
        func_003C0540(p, q);
    }
}

typedef struct { f32 x, y, z; } V3;

void func_00354F80(u8 *p, void *owner) {
    u8 *q = owner;
    extern u16 D_004D18DC[];
    extern u8 D_004D18DB[];
    extern G7C *D_004C2794;
    extern void func_001E7F60(u8 *);
    u8 *t = *(u8 **)(p + 0x14);
    if ((D_004D18DC[0] & (1 << D_004D18DB[0])) == 0) {
        if (q[5] != 0 || q[0x1E4] != 0x1D) {
            p[4] = 2;
            p[0x13C] = 0;
        } else if (*(s16 *)(q + 0x1E) == 0) {
            if (*(s8 *)(t + 0x151) != 0) {
                p[0x1B5] = p[0x15B];
                p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
                *(u32 *)(p + 0x1D8) = 0;
                D_004C2794->a[p[2]]++;
                func_001E7F60(p);
            }
        } else {
            p[4] = 2;
            p[0x13C] = 0;
        }
    }
}

void func_00298000(u8 *p) {
    extern G7C *D_004C2794;
    extern void func_00185490(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    if (p[0x269] == 6) {
        p[0x404] = 0xFF;
        p[0x405] = 0x10;
    }
    p[6]++;
    func_00185490(p);
    *(f32 *)(p + 0x5C) /= 16.0f;
    *(f32 *)(p + 0x60) /= 16.0f;
    *(f32 *)(p + 0x6C) /= 64.0f;
    *(u32 *)(p + 0x68) = 0;
    p[0x1B5] = 0x57;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->a[p[2]]++;
    func_001757E0(p, 0x16, 3);
}
