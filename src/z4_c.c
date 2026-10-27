typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[0x7C]; s16 f7c[1]; } G4;

typedef struct { f32 x, y, z; } V3;
extern G4 *D_004C2794;
extern u8 *D_004C2840;
extern void (*D_004522D0[])(u8 *, u8 *);
typedef struct { s16 pad0; s16 pad2; s16 f4; s16 f6; s16 f8; s16 fa; } S1800;
extern S1800 D_004D1800[];
extern s16 D_004D1806[];
extern u8 *D_00446A60[];
extern s16 D_004F25D2[];
extern s16 D_004F2B8A[];
extern u16 D_004F4480[];
extern u16 D_004F4494[];

void func_00235270(u8 *p, u8 *q)
{
    extern s32 func_003D92F0(u8 *);
    extern void func_00126400();
    extern void func_001843A0(u8 *);
    extern void func_00175700(u8 *);
    if (func_003D92F0(p)) {
        if (p[0x21] != 0) {
            func_00126400();
            q[0x39] = 1;
        }
        func_001843A0(p);
        return;
    }
    switch (p[0x20]) {
    case 0:
        if (p[0x21] != 0) {
            D_004522D0[p[7]](p, q);
            break;
        }
    default:
    case 2:
    case 4:
    case 1:
    case 3:
        func_00175700(p);
        break;
    }
}

void func_00229800(u8 *p)
{
    extern s32 func_00175700(u8 *);
    extern s32 func_00185980(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    u32 *a, *c;
    p[0x40C] = 2;
    p[0x33C] = 5;
    c = (u32 *)(p + 0x68);
    a = (u32 *)(p + 0x5C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if ((s8)func_00175700(p) < 0) {
        if (func_00185980(p) != 0) {
            u32 t = p[6];
            p[6] = t + 1;
            *a = 0;
            *c = 0;
            *(u32 *)(p + 0x60) = 0x42092492;
            *(u32 *)(p + 0x6C) = 0;
            *(s16 *)(p + 0x1C) = 0x12;
            func_001757E0(p, 0x16, 4);
            return;
        }
        p[6] = 6;
        func_001757E0(p, 0x16, 2);
    }
}
