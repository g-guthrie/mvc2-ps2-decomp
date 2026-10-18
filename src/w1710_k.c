typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
typedef struct { s32 x[49]; } B9;
extern u8 D_004C1D10[4];
void func_0037DA90(u8 *p, u8 *q) {
    extern void func_0037D9F0();
    extern void func_001757E0();
    extern void func_0037DBC0();
    *(B9 *)(p + 0xEC) = *(B9 *)(q + 0xEC);
    p[0x13C] = 1;
    p[2] = q[2];
    p[1] = q[1];
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
    p[0x1B7] = q[0x1B7];
    p[0x1B8] = q[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(q + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    { u32 t = p[4]; p[4] = t + 1; }
    p[0x13C] = 1;
    func_0037D9F0(p, q);
    func_001757E0(p, 0x17, D_004C1D10[p[0x23]]);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    *(s8 *)(p + 0x31) = -1;
    if (p[0x23] >= 4) *(u32 *)(p + 0x118) = 0x3ECCCCCD;
    func_0037DBC0(p, q);
}

typedef struct { u8 pad0[0x7C]; s16 h7c[1]; } G12;
extern G12 *D_004C2794;
void func_001EA110(u8 *p) {
    extern s8 func_00175700();
    extern void func_001843A0();
    f32 c;
    switch (p[0x1FC]) {
    case 0:
    case 1:
        if (func_00175700(p) < 0) func_001843A0(p);
        break;
    case 2:
        if (func_00175700(p) < 0) {
            func_001843A0(p);
        } else if (p[6] != 0) {
            if (*(s8 *)(p + 0x151) != 0) {
                p[0x151] = 0;
                *(u8 *)(p + 0x1B5) = 0x13;
                ((u8 *)p)[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
                *(s32 *)(p + 0x1D8) = 0;
                D_004C2794->h7c[p[2]]++;
            }
            if (*(s8 *)(p + 0x150) != 0) {
                if (p[0x1E6] != 0) c = 3.3333332538604736f; else c = -3.3333332538604736f;
                *(f32 *)(p + 0x34) += c;
            }
        }
        break;
    }
}

void func_002701E0(u8 *p) {
    extern void func_001861B0();
    extern void func_0018C4B0();
    extern void func_001757E0();
    extern void func_001E3710();
    extern void func_00183D90();
    extern void func_001863F0();
    extern s8 func_00175700();
    extern void func_001843A0();
    if (p[6] == 0) {
        u32 t;
        func_001861B0(p);
        t = p[6];
        p[6] = t + 1;
        func_0018C4B0(p, 5);
        p[0x1B5] = 0x12;
        p[0x20D] = 1;
        func_001757E0(p, 0x14, 2);
        t = p[0x1B5];
        p[0x1B5] = t;
        ((u8 *)p)[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->h7c[p[2]]++;
        func_001E3710(p, 0x15);
    }
    if (p[0x213] == 3) func_00183D90(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_001863F0(p);
    if (func_00175700(p) < 0) func_001843A0(p);
}
