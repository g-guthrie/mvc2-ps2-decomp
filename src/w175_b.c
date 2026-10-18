typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
extern V3 D_004B18F0;
extern s32 D_004C282C;
extern void func_0013E070();
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G;
extern G *D_004C2794;
extern s32 D_004C1338[2];
extern s32 D_004C133C[2];
extern s32 D_004C1340[2];
typedef struct { u8 p0[0x34]; f32 f34; f32 f38; u8 p1[0x20]; f32 f5c; f32 f60; u8 p2[4]; f32 f68; f32 f6c; } A_00274DA0;
extern s32 D_004BFCD4[2];
extern s32 D_004BFCD8[2];
extern s32 D_004BFCDC[2];
typedef struct { u8 p0[2]; u8 b2; u8 p0b[3]; u8 b6; u8 p1[0x2D]; f32 f34; f32 f38; u8 p2[0x20]; f32 f5c; f32 f60; u8 p3[4]; f32 f68; f32 f6c; } A_002BBB90;
typedef struct { u8 p0[3]; s8 b3; s8 b4; u8 p1[2]; u8 b7; u8 p2[2]; s16 hA; s16 hC; s16 hE; u8 p3[0x79]; s8 b89; u8 p4[4]; s8 b8E; } S_00128510;
extern S_00128510 *D_004C2840;
extern s16 D_004F2584[];
extern s16 D_004F2586[];
extern s16 D_004F2B3C[];
extern s32 D_004C00D8[2];
extern s32 D_004C00DC[2];
extern s32 D_004C00E0[2];

void func_0013DFB0(s32 a, V3 *src)
{
    extern u8 *func_003DA750(s32, s32, s32);
    u8 *o;
    V3 v;
    v = *src;
    if ((o = func_003DA750(0, 6, 1)) != 0) {
        o[0x13C] = 1;
        o[0x20] = a;
        *(void **)(o + 0x10) = func_0013E070;
        *(s16 *)(o + 0xCC) = a + 0x13;
        *(s32 *)(o + 0x84) = D_004C282C;
        *(V3 *)(o + 0x50) = D_004B18F0;
        *(V3 *)(o + 0x34) = v;
        *(s32 *)(o + 0xD0) = 0x811;
        *(s16 *)(o + 0x1C) = 0;
    }
}

void func_002F7630(u8 *a)
{
    extern void func_002FA020(void);
    extern void func_001E3710(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    u8 v;
    if (a[0x2CE] != 0) {
        func_002FA020();
        return;
    }
    switch (a[0x1FC]) {
    case 0:
        a[0x168] = 0;
        a[0x1B5] = 0;
        *(void **)(a + 0x408) = D_004C1338;
        a[0x1BB] = 0;
        func_001E3710(a, 0x14);
        break;
    case 1:
        a[0x168] = 1;
        a[0x1B5] = 1;
        *(void **)(a + 0x408) = D_004C133C;
        a[0x1BB] = 1;
        func_001E3710(a, 0x15);
        break;
    case 2:
        a[0x168] = 2;
        a[0x1B5] = 2;
        *(void **)(a + 0x408) = D_004C1340;
        a[0x1BB] = 2;
        break;
    default:
        break;
    }
    v = *(volatile u8 *)(a + 0x1B5);
    a[0x1B5] = v;
    a[0x1B2] = *(u16 *)(a + 0x1C0) = 0;
    *(s32 *)(a + 0x1D8) = 0;
    D_004C2794->f7c[a[2]]++;
    func_001757E0(a, 7, a[0x168]);
}

void func_00274DA0(A_00274DA0 *p)
{
    extern void func_001861B0(A_00274DA0 *);
    extern void func_001757E0(A_00274DA0 *, s32, s32);
    extern void func_001E3710(A_00274DA0 *, s32);
    extern void func_0018C4B0(A_00274DA0 *, s32);
    extern void func_00183D90(A_00274DA0 *);
    extern void func_001863F0(A_00274DA0 *);
    extern s8 func_00175700(A_00274DA0 *);
    extern void func_001843A0(A_00274DA0 *);
    u8 *a = (u8 *)p;
    u8 v;
    if (a[6] == 0) {
        func_001861B0(p);
        a[6]++;
        if (a[0x212] == 0) {
            a[0x1B5] = 0x35;
            a[0x20D] = 0;
            func_001757E0(p, 0x14, 5);
        }
        v = *(volatile u8 *)(a + 0x1B5);
        a[0x1B5] = v;
        a[0x1B2] = *(u16 *)(a + 0x1C0) = 0;
        *(s32 *)(a + 0x1D8) = 0;
        D_004C2794->f7c[a[2]]++;
        func_001E3710(p, 0x15);
        func_0018C4B0(p, 5);
    }
    if (a[0x213] == 3) func_00183D90(p);
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    func_001863F0(p);
    if (func_00175700(p) < 0) func_001843A0(p);
}

void func_001FCCF0(u8 *a)
{
    extern void func_001E3710(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    u8 v;
    switch (a[0x1FC]) {
    case 0:
        a[0x168] = 0;
        a[0x1B5] = 3;
        func_001E3710(a, 0x14);
        *(void **)(a + 0x408) = D_004BFCD4;
        a[0x1BB] = 0;
        break;
    case 1:
        a[0x168] = 1;
        a[0x1B5] = 4;
        func_001E3710(a, 0x15);
        *(void **)(a + 0x408) = D_004BFCD8;
        a[0x1BB] = 1;
        break;
    case 2:
        if (*(u16 *)(a + 0x20E) & 0x800) {
            a[6]++;
            a[7] = 0;
            a[0x168] = 3;
            a[0x1B5] = 0x13;
        } else {
            a[0x168] = 2;
            a[0x1B5] = 5;
        }
        func_001E3710(a, 0x16);
        *(void **)(a + 0x408) = D_004BFCDC;
        a[0x1BB] = 2;
        break;
    default:
        break;
    }
    v = *(volatile u8 *)(a + 0x1B5);
    a[0x1B5] = v;
    a[0x1B2] = *(u16 *)(a + 0x1C0) = 0;
    *(s32 *)(a + 0x1D8) = 0;
    D_004C2794->f7c[a[2]]++;
    func_001757E0(a, 8, a[0x168]);
}

void func_002BBB90(A_002BBB90 *p)
{
    extern void func_00175700(A_002BBB90 *);
    extern void func_001757E0(A_002BBB90 *, s32, s32, s32);
    u8 *a = (u8 *)p;
    f32 *t0, *t1;
    u32 n;
    a[0x40C] = 2;
    a[0x33C] = 5;
    func_00175700(p);
    if (a[0x15B] != 0) {
        a[0x15B] = 0;
        a[0x1B5] = 0x40;
        a[0x1B2] = *(u16 *)(a + 0x1C0) = 0;
        *(s32 *)(a + 0x1D8) = 0;
        D_004C2794->f7c[a[2]]++;
    }
    t0 = &p->f60; t1 = &p->f6c;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (p->f38 <= *(f32 *)(a + 0x430)) {
        n = a[6];
        n = n + 1;
        a[6] = n;
        p->f38 = *(f32 *)(a + 0x430);
        a[0x20D] = 0;
        *(s32 *)t0 = 0;
        *(s32 *)t1 = 0;
        a[0x1B5] = 0x41;
        a[0x1B2] = *(u16 *)(a + 0x1C0) = 0;
        *(s32 *)(a + 0x1D8) = 0;
        D_004C2794->f7c[a[2]]++;
        func_001757E0(p, 0x15, 0x10, n);
    }
}

void func_00128510(void)
{
    extern void func_0016F0D0(void);
    extern void func_001E3CE0(s32);
    s8 v;
    s32 x;
    s32 idx;
    func_0016F0D0();
    if (D_004C2840->b89 != 0) {
        D_004C2840->b3 = 3;
        D_004C2840->hA = 0xB4;
        func_001E3CE0(0x41);
        D_004C2840->b7 = 2;
    } else {
        x = D_004C2840->b8E;
        if (x == 0) {
            D_004C2840->b3 = D_004C2840->b3 + 1;
            D_004C2840->hC = 0;
            D_004C2840->hE = 0;
        } else {
            v = x;
            idx = v - 1;
            if (v == 3) {
                idx = (D_004F2584[0] > D_004F2B3C[0]) ? 0 : 1;
            }
            D_004C2840->hC = *(s16 *)((u8 *)D_004F2584 + idx * 0x5B8) - 1;
            D_004C2840->hE = *(s16 *)((u8 *)D_004F2586 + idx * 0x5B8) - 1;
            if (D_004C2840->hC < 0) D_004C2840->hC = 0;
        }
        if (D_004C2840->hC == 0 && D_004C2840->b4 == 0) {
            D_004C2840->b4++;
            func_001E3CE0(0x3E);
        }
    }
}

void func_0022D0D0(u8 *a)
{
    extern void func_001E3710(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    u8 *b;
    u8 v;
    b = a + 0x2B8;
    switch (a[0x1FC]) {
    case 0:
        a[0x168] = 0;
        a[0x1B5] = 0;
        func_001E3710(a, 0x14);
        *(void **)(a + 0x408) = D_004C00D8;
        a[0x1BB] = 0;
        a[0x2B6] = 1;
        break;
    case 1:
        a[0x168] = 1;
        if (b[0xE] != 0) a[0x1B5] = 1;
        else a[0x1B5] = 0x12;
        func_001E3710(a, 0x15);
        *(void **)(a + 0x408) = D_004C00DC;
        a[0x1BB] = 1;
        break;
    case 2:
        if (b[0xE] != 0) {
            a[0x168] = 2;
            a[0x1B5] = 2;
        } else {
            a[0x168] = 4;
            a[0x1B5] = 0x13;
        }
        func_001E3710(a, 0x16);
        *(void **)(a + 0x408) = D_004C00E0;
        a[0x1BB] = 2;
        break;
    default:
        break;
    }
    v = *(volatile u8 *)(a + 0x1B5);
    a[0x1B5] = v;
    a[0x1B2] = *(u16 *)(a + 0x1C0) = 0;
    *(s32 *)(a + 0x1D8) = 0;
    D_004C2794->f7c[a[2]]++;
    func_001757E0(a, 7, a[0x168]);
}
