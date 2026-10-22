typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G3d;
extern G3d *D_004C2794;

void func_002FAC50(u8 *p)
{
    extern s8 func_00175700(u8 *);
    extern void func_00175C00(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00176160(u8 *, s32, s32, s32);
    f32 *q1;
    f32 *q2;
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    q1 = (f32 *)(p + 0x5C);
    q2 = (f32 *)(p + 0x68);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    if (func_00175700(p) < 0) {
        t = p[6];
        p[6] = t + 1;
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        func_00175C00(p, 0);
        *(u32 *)q1 = 0;
        *(u32 *)q2 = 0;
        func_001757E0(p, 0x16, 0xA);
        return;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        func_00176160(p, 0, *(s8 *)(p + 0x150), 2);
        switch (*(s8 *)(p + 0x151)) {
        case 1:
            p[0x1B5] = 0x38;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(u32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
            break;
        case 2:
            p[0x1B5] = 0x39;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(u32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
            break;
        case 3:
            p[0x1B5] = 0x3A;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(u32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
            break;
        }
        p[0x151] = 0;
    }
}
