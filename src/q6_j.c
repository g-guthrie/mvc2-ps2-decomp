typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[16]; } G2794;
extern G2794 *D_004C2794;

void func_0025FE50(u8 *p) {
    extern void func_00175700(u8 *);
    extern void func_001E3210(u8 *, s32);
    extern void func_00176160(u8 *, s32, s32, s32);
    extern void func_0036BFF0(u8 *, s32, s32, s32);
    extern void func_001757E0(u8 *, s32, u8);
    p[0x40C] = 2;
    p[0x33C] = 5;
    if (*(s8 *)(p + 0x153) < 0) {
        *(s16 *)(p + 0x366) = 0;
        p[6] = 2;
        p[0x2C2] = 0;
        *(s16 *)(p + 0x2C4) = 0;
        p[0x1B5] = 0x38;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        func_001E3210(p, 4);
        func_00176160(p, 4, 7, 1);
        func_0036BFF0(p, 10, 0x13, 10);
        func_0036BFF0(p, 9, 0x13, 9);
        func_0036BFF0(p, 11, 0x13, 11);
        func_001757E0(p, 0x16, p[7] + 3);
    } else {
        func_00175700(p);
    }
}
