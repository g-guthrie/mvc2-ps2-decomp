typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef float f32;
typedef int s32;
typedef unsigned int u32;
typedef struct { u8 pad[0x7C]; s16 h7C[8]; } G;
extern G *D_004C2794;
void func_002B07B0(u8 *p) {
    extern s32 func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    f32 *z;
    u8 *q;
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    if ((s8)func_00175700(p) < 0) {
        t = p[6];
        p[6] = t + 1;
        func_001757E0(p, 0x16, 6);
        return;
    }
    if (p[0x15B] != 0) {
        p[0x1B5] = p[0x15B];
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->h7C[p[2]]++;
        p[0x15B] = 0;
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        if ((*(s32 *)(p + 0x428) & 0x7000000) == 0) {
            q = *(u8 **)(p + 0x2D0);
            z = (f32 *)(p + 0x2B8);
            if (*(s16 *)(q + 0x434) != 0) {
                *(f32 *)(q + 0x34) = *(f32 *)(p + 0x34) - *z;
            }
        }
    }
}
