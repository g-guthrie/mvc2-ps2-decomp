typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 p0; s8 f1; s8 f2; u8 p3[5]; s16 f8; } G0;
void func_003D2130(void) {
    extern G0 *D_004C2840;
    extern s32 func_0012E560();
    extern void func_001E4150();
    extern void func_003298B0();
    extern void func_00144460();
    D_004C2840->f8 = D_004C2840->f8 - 1;
    if (D_004C2840->f8 == 0) {
        if (func_0012E560() == 0) {
            D_004C2840->f8 = D_004C2840->f8 + 1;
            return;
        }
        D_004C2840->f1 = D_004C2840->f1 + 1;
        D_004C2840->f2 = 0;
        func_001E4150();
    }
    if (D_004C2840->f8 == 0x14F)
        func_003298B0(-1, 0x3C, 1);
    if (D_004C2840->f8 == 0xEB) {
        func_003298B0(-1, 0x3C, 0);
        func_00144460();
    }
}

s32 func_0035AED0(u8 *p) {
    extern s16 D_004C27A4;
    extern u8 *func_003DA750();
    extern void func_0035AFA0();
    u8 *o;
    if (D_004C27A4 < 2)
        return 0;
    if ((o = func_003DA750(0, 2, 1)) != 0) {
        *(void **)(o + 0x10) = func_0035AFA0;
        *(s32 *)(o + 0x18) = *(s32 *)(p + 0x18);
        *(u8 **)(o + 0x14) = p;
        o[1] = p[1];
        o[0x20] = 0;
        o[0x21] = 0;
        *(s16 *)(o + 0x26) = 0xB01;
    }
    if ((o = func_003DA750(0, 2, 1)) != 0) {
        *(void **)(o + 0x10) = func_0035AFA0;
        *(s32 *)(o + 0x18) = *(s32 *)(p + 0x18);
        *(u8 **)(o + 0x14) = p;
        o[1] = p[1];
        o[0x20] = 0;
        o[0x21] = 1;
        *(s16 *)(o + 0x26) = 0xB01;
    }
    return 0;
}

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G;
void func_002FA7F0(u8 *p) {
    extern G *D_004C2794;
    extern s8 func_00175700();
    extern void func_001843A0();
    if (func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        *(s8 *)(p + 0x1B5) = 0x1A;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
    }
    if (*(s8 *)(p + 0x150) != 0) {
        p[0x150] = 0;
        *(s8 *)(p + 0x1B5) = 2;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
    }
}

void func_002650D0(u8 *p) {
    extern G *D_004C2794;
    extern s8 func_00175700();
    extern void func_001843A0();
    extern void func_00184540();
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    p[0x1B5] = p[0x1B7];
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    if (func_00175700(p) < 0) {
        if (p[0x20D] == 2)
            func_00184540(p);
        else
            func_001843A0(p);
        return;
    }
    if (*(s8 *)(p + 0x151) != 0)
        p[0x151] = 0;
}

typedef struct { f32 x, y, z; } V3;
void func_0033F3C0(s32 n) {
    extern u8 *func_003DA750();
    extern void func_0033F260();
    extern V3 D_0045F930[];
    extern s32 D_004C283C;
    extern s32 D_004C1940[2];
    u8 *o;
    if ((o = func_003DA750(0, 5, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_0033F260;
        *(s16 *)(o + 0xCC) = n + 1;
        *(s32 *)(o + 0x84) = D_004C283C;
        *(s32 *)(o + 0xD0) = 0x807;
        *(V3 *)(o + 0x34) = D_0045F930[n];
        *(s32 *)(o + 0x44) = D_004C1940[n];
        o[0x20] = n;
    }
}

void func_001E40E0(void) {
    extern s32 D_004C2B50;
    extern void func_001E5F30();
    extern s32 func_00401920();
    extern void func_00401868();
    s32 r;
    func_001E5F30();
    if (D_004C2B50 == 0)
        return;
    r = func_00401920(D_004C2B50);
    if (r == 0 || r == 5)
        return;
    func_00401868(D_004C2B50);
}
