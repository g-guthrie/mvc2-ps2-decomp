typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* Metrowerks 3.0: ./try30.sh src/w190_g.c "-O3 -Op -sdatathreshold 8" */

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G2794;
extern G2794 *D_004C2794;
extern void func_00175C00(u8 *, s32);
extern void func_00185490(u8 *);
extern void func_001861B0(u8 *);
extern void func_00183D10(u8 *);
extern void func_001757E0(u8 *, s32, u8);

void func_00212F40(u8 *p) {
    u8 k;
    u32 t;
    if (p[0x269] == 6) {
        p[0x404] = 0xFF;
        p[0x405] = 0x10;
    }
    t = p[6];
    p[6] = t + 1;
    func_00175C00(p, 0);
    func_00185490(p);
    if (p[0x20D] == 2) {
        *(f32 *)(p + 0x5C) /= 16.0f;
        *(f32 *)(p + 0x60) /= 8.0f;
        *(f32 *)(p + 0x6C) /= 64.0f;
        *(s32 *)(p + 0x68) = 0;
        k = 9;
    } else {
        func_001861B0(p);
        func_00183D10(p);
        p[0x20D] = 0;
        k = 0;
        if (p[0x269] == 5 || p[0x269] == 4) k = 8;
    }
    p[0x1B5] = 0x38;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 0x16, k);
}


