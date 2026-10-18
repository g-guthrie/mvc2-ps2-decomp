typedef float f32;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;


extern u32 D_004D18A0[][3];

typedef struct { f32 x, y, z; } V3_47;
extern V3_47 D_00442AA0;
typedef struct { f32 x, y, z, w; } V4_47;
extern V4_47 D_004439B0;
extern void *func_003DA750();
extern u8 residual_001487B0[];

void func_00147AB0(u8 a, u8 b) {
    u8 *o;
    if ((o = func_003DA750(0, 15, 0)) != 0) {
        o[0x13C] = 0;
        *(u32 *)(o + 0x10) = (u32)residual_001487B0;
        o[0x23] = a;
        o[0x20] = b;
        *(V3_47 *)(o + 0x50) = D_00442AA0;
        *(u32 *)(o + 0xD8) = 0;
        *(V4_47 *)(o + 0x74) = D_004439B0;
    }
}

s32 func_002C73B0(u8 *p, u8 *q) {
    extern s8 func_00175700();
    extern void func_001757E0();
    extern void func_00175C00();
    p[0x13C] = 1;
    if (func_00175700(p) < 0) {
        u32 t = p[6];
        p[6] = t + 1;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        *(u32 *)(p + 0x60) = 0xBFF00000;
        func_001757E0(p, 0x12, 1);
        return;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        q[4] = 0;
        func_00175C00(p, 0);
    }
}

void func_002665D0(u8 *p) {
    extern s8 func_00175700();
    extern void func_001757E0();
    extern void func_00183d50();
    f32 *a = (f32 *)(p + 0x5C);
    f32 *b = (f32 *)(p + 0x68);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    if (func_00175700(p) < 0) {
        u32 t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        func_001757E0(p, 0x16, 0xB);
        func_00183d50(p);
        *(u32 *)a = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)b = 0;
        *(u32 *)(p + 0x6C) = 0;
    }
}

void func_0021B340(u8 *p) {
    extern s8 func_00175700();
    extern void func_001843A0();
    extern void func_001E3210();
    extern void func_0019B110();
    extern void func_00183920();
    f32 v[4];
    if (func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    if (*(s8 *)(p + 0x151) & 1) {
        s32 t = *(s8 *)(p + 0x151);
        p[0x151] = t ^ 1;
        func_001E3210(p, 0x20);
        func_0019B110(p, 1);
    }
    if (*(s8 *)(p + 0x151) & 2) {
        s32 t = *(s8 *)(p + 0x151);
        p[0x151] = t ^ 2;
        *(u32 *)&v[0] = 0xC2D55555;
        *(u32 *)&v[1] = 0x42CDB6DB;
        func_00183920(p, v);
    }
}
