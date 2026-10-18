typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 D_004C0AFC[1];
extern s32 D_004C0B00[1];
extern s32 D_004C0B04[1];
typedef struct { u8 pad[0x7C]; s16 h7c[1]; } G1;
extern G1 *D_004C2794;
extern s32 D_004BFF28[1];
extern s32 D_004BFF2C[1];
extern s32 D_004BFF30[1];

void func_0029BEB0(u8 *a) {
    extern void func_0038F440();
    extern void func_001E3710(u8 *, u8);
    extern void func_001757E0(u8 *, s32, s32);
    u8 s0 = a[0x1FC];
    u16 s1 = s0 + 9;
    switch (s0) {
    case 0:
        *(s32 **)(a + 0x408) = D_004C0AFC;
        a[0x1BB] = 0;
        break;
    case 1:
        *(s32 **)(a + 0x408) = D_004C0B00;
        a[0x1BB] = 1;
        break;
    case 2:
        *(s32 **)(a + 0x408) = D_004C0B04;
        a[0x1BB] = 2;
        if (*(u16 *)(a + 0x20E) & 0x400) {
            s0 = 3;
            s1 = 0x14;
            func_0038F440(a, 1);
        }
        break;
    }
    func_001E3710(a, a[0x1FC] + 0x14);
    a[0x1B5] = s1;
    a[0x1B2] = *(u16 *)(a + 0x1C0) = 0;
    *(s32 *)(a + 0x1D8) = 0;
    D_004C2794->h7c[a[2]]++;
    func_001757E0(a, 0xA, s0 & 0xFF);
}

void func_003118B0(u8 *a) {
    extern void func_00175700();
    extern void func_001DD8A0(u8 *, s32, s32);
    extern void func_001843A0();
    func_00175700(a);
    if ((*(s8 *)(a + 0x151) & 2) != 0) {
        a[0x151] = *(s8 *)(a + 0x151) & ~2;
        func_001DD8A0(a, 9, 0);
    }
    if ((*(s8 *)(a + 0x151) & 4) != 0) {
        a[0x151] = *(s8 *)(a + 0x151) & ~4;
        func_001DD8A0(a, 9, 1);
    }
    if ((*(s8 *)(a + 0x151) & 8) != 0) {
        a[0x151] = *(s8 *)(a + 0x151) & ~8;
        a[0x1B5] = 0x17;
        a[0x1B2] = *(u16 *)(a + 0x1C0) = 0;
        *(s32 *)(a + 0x1D8) = 0;
        D_004C2794->h7c[a[2]]++;
    }
    if (!(*(f32 *)(a + 0x430) < *(f32 *)(a + 0x38))) {
        *(f32 *)(a + 0x38) = *(f32 *)(a + 0x430);
        *(s32 *)(a + 0x5C) = 0;
        *(s32 *)(a + 0x60) = 0;
        *(s32 *)(a + 0x68) = 0;
        *(s32 *)(a + 0x6C) = 0;
        func_001843A0(a);
    }
}

void func_0021D580(u8 *a) {
    extern void func_001E3710();
    extern void func_001E3210();
    extern void func_001757E0();
    switch (a[0x1FC]) {
    case 0:
        a[0x168] = 0;
        a[0x1B5] = 0;
        func_001E3710(a, 0x14);
        func_001E3210(a, 3);
        *(s32 **)(a + 0x408) = D_004BFF28;
        a[0x1BB] = 0;
        break;
    case 1:
        a[0x168] = 1;
        a[0x1B5] = 1;
        func_001E3710(a, 0x15);
        func_001E3210(a, 4);
        *(s32 **)(a + 0x408) = D_004BFF2C;
        a[0x1BB] = 1;
        break;
    case 2:
        a[0x168] = 2;
        a[0x1B5] = 2;
        func_001E3210(a, 0x20);
        func_001E3710(a, 0x16);
        *(s32 **)(a + 0x408) = D_004BFF30;
        a[0x1BB] = 2;
        break;
    }
    a[0x1B5] = *(volatile u8 *)(a + 0x1B5);
    a[0x1B2] = *(u16 *)(a + 0x1C0) = 0;
    *(s32 *)(a + 0x1D8) = 0;
    D_004C2794->h7c[a[2]]++;
    func_001757E0(a, 7, a[0x168]);
}

void func_002B97C0(u8 *a) {
    extern void func_001861B0();
    extern void func_001757E0();
    extern void func_001E3710();
    extern void func_0018C4B0();
    extern void func_00183D90();
    extern void func_001863F0();
    extern s8 func_00175700();
    extern void func_001843A0();
    if (a[6] == 0) {
        u32 t;
        func_001861B0(a);
        t = a[6];
        a[6] = t + 1;
        a[0x20D] = 0;
        func_001757E0(a, 0x14, 3);
        a[0x1B5] = 0x5F;
        a[0x1B2] = *(u16 *)(a + 0x1C0) = 0;
        *(s32 *)(a + 0x1D8) = 0;
        D_004C2794->h7c[a[2]]++;
        func_001E3710(a, 0x16);
        func_0018C4B0(a, 5);
    }
    if (a[0x213] == 3) func_00183D90(a);
    *(f32 *)(a + 0x34) += *(f32 *)(a + 0x5C);
    *(f32 *)(a + 0x5C) += *(f32 *)(a + 0x68);
    *(f32 *)(a + 0x38) += *(f32 *)(a + 0x60);
    *(f32 *)(a + 0x60) += *(f32 *)(a + 0x6C);
    func_001863F0(a);
    if (func_00175700(a) < 0) func_001843A0(a);
}
