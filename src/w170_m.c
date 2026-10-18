typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } GM;
extern GM *D_004C2794;
extern u16 D_004D18DC[];
extern u8 D_004D18DB[];

void func_00354C70(u8 *p, u8 *q) {
    extern s32 func_00175700();
    extern void func_001E7F60();
    s8 r;
    s16 t;
    if ((D_004D18DC[0] & (1 << D_004D18DB[0])) == 0) {
        if (q[5] != 0 || q[0x1E4] != 0x1D) {
            p[4] = 2;
            p[0x13C] = 0;
            *(s16 *)(q + 0x1E) = 1;
            return;
        }
        p[0x151] = 0;
        r = func_00175700(p);
        if (r >= 0) {
            u8 v = p[0x15B];
            if (v != 0) {
                p[0x1B5] = v;
                p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
                *(u32 *)(p + 0x1D8) = 0;
                D_004C2794->f7c[p[2]]++;
                p[0x15B] = 0;
            }
        } else {
            t = *(s16 *)(p + 0x1C) - 1;
            *(s16 *)(p + 0x1C) = t;
            if (t == 0) {
                p[4] = 2;
                p[0x13C] = 0;
                *(s16 *)(q + 0x1E) = 1;
                return;
            }
        }
        func_001E7F60(p);
    }
}

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } GM2;
void func_00211740(u8 *p) {
    extern s32 func_00175700();
    extern void func_001843A0();
    extern void func_001855D0();
    extern void func_001757E0();
    extern void func_001E3710();
    s8 r;
    switch (p[0x1FC]) {
    case 0:
    case 1:
        r = func_00175700(p);
        if (r < 0) func_001843A0(p);
        break;
    case 2:
        r = func_00175700(p);
        if (r < 0) {
            func_001843A0(p);
        } else if (*(s8 *)(p + 0x151) != 0) {
            if (((*(u16 *)(p + 0x362) | *(u16 *)(p + 0x366)) & 0x20) != 0) {
                func_001855D0(p);
                *(u16 *)(p + 0x366) = 0;
                p[0x1B5] = 0x1B;
                p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
                *(u32 *)(p + 0x1D8) = 0;
                D_004C2794->f7c[p[2]]++;
                func_001757E0(p, 8, 4);
                func_001E3710(p, 0x16);
            }
        }
        break;
    default:
        break;
    }
}

extern u8 D_004BFF28[4];
extern u8 D_004BFF2C[4];
extern u8 D_004BFF30[4];
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } GM3;
void func_0021D6A0(u8 *p) {
    extern void func_001E3710();
    extern void func_001E3210();
    extern void func_001757E0();
    u8 v;
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 6;
        func_001E3710(p, 0x14);
        func_001E3210(p, 3);
        *(u8 **)(p + 0x408) = D_004BFF28;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 7;
        func_001E3710(p, 0x15);
        func_001E3210(p, 4);
        *(u8 **)(p + 0x408) = D_004BFF2C;
        p[0x1BB] = 1;
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 8;
        func_001E3210(p, 0x20);
        func_001E3710(p, 0x16);
        *(u8 **)(p + 0x408) = D_004BFF30;
        p[0x1BB] = 2;
        break;
    default:
        break;
    }
    v = *(volatile u8 *)(p + 0x1B5);
    p[0x1B5] = v;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 9, p[0x168]);
}

typedef struct { u8 p0[0x34]; f32 f34, f38; u8 p3c[0x20]; f32 f5c, f60; u8 p64[4]; f32 f68, f6c; u8 p70[0x3C0]; f32 f430; } SM4;
void func_00241DE0(u8 *p, u8 *q) {
    extern void func_00175700();
    extern void func_001A3A10();
    extern void func_00183d50();
    extern void func_001757E0();
    SM4 *r = (SM4 *)p;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x209] = 2;
    func_00175700(p);
    if (p[0x15B] != 0) {
        u8 v = p[0x15B];
        p[0x1B5] = v;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        p[0x15B] = 0;
    }
    r->f34 += r->f5c;
    r->f5c += r->f68;
    r->f38 += r->f60;
    r->f60 += r->f6c;
    if (r->f38 < r->f430) {
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        p[6]++;
        p[7] = 0;
        r->f38 = r->f430;
        p[0x20D] = 1;
        q[3] = 0;
        func_001A3A10(p, 1, 0);
        func_00183d50(p);
        func_001757E0(p, 0x16, 3);
    }
}
