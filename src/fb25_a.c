typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G2794;
extern G2794 *D_004C2794;

void func_002AA4B0(u8 *p, u8 *q)
{
    f32 *a5c, *a60, *a68, *a6c;
    extern void func_001843A0(u8 *);
    extern void func_00175700(u8 *);
    extern void func_00183d50(u8 *);
    extern void func_001757E0(u8 *, s32, s32);

    p[0x40C] = 2;
    p[0x33C] = 5;
    if ((*(u8 **)(p + 0x220))[1] != q[1]) {
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        func_001843A0(p);
        return;
    }
    if (p[7] == 0) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        func_00175700(p);
        if (*(s8 *)(p + 0x151) != 0) {
            u32 t = p[7];
            p[7] = t + 1;
            p[0x151] = 0;
            *(f32 *)(p + 0x5C) /= 4.0f;
            *(u32 *)(p + 0x60) = 0x41892492;
            *(u32 *)(p + 0x6C) = 0xC0092492;
        }
        if (p[0x15B] != 0) {
            p[0x1B5] = p[0x15B];
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(u32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
            p[0x15B] = 0;
        }
    } else {
        a5c = (f32 *)(p + 0x5C);
        a68 = (f32 *)(p + 0x68);
        a60 = (f32 *)(p + 0x60);
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        a6c = (f32 *)(p + 0x6C);
        if (*(s8 *)(p + 0x151) == 0) {
            func_00175700(p);
        }
        if (p[0x15B] != 0) {
            p[0x1B5] = p[0x15B];
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(u32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
            p[0x15B] = 0;
        }
        if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
            p[6]++;
            *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
            p[0x20D] = 0;
            p[0x40D] = 0;
            p[0x40C] = 0;
            p[0x33B] = 0;
            p[0x33C] = 0;
            *a5c = 0;
            *a60 = 0;
            *a68 = 0;
            *a6c = 0;
            func_00183d50(p);
            func_001757E0(p, 1, 3);
        }
    }
}
