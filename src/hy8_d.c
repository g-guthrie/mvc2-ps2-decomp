typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 s7C[8]; } H8G;
extern H8G *D_004C2794;

void func_001FF390(u8 *p)
{
    extern s8 func_00175700();
    extern void func_001757E0(u8 *, s32, s32, s32);
    extern void func_00186A20(u8 *);
    u32 t;
    if (func_00175700(p) < 0) {
        t = p[7] + 1;
        p[7] = t;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0xC0892492;
        *(u32 *)(p + 0x6C) = 0xBF892492;
        func_001757E0(p, 0x15, 9, t);
    }
    if (*(s8 *)(p + 0x151) != 0) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        if (p[0x20D] != 2) func_00186A20(p);
    }
    if (p[0x15B] != 0) {
        if (p[0x269] == 3) {
            p[0x1B5] = (s8)p[0x15B] + 0x31;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(u32 *)(p + 0x1D8) = 0;
            D_004C2794->s7C[p[2]]++;
        } else {
            p[0x1B5] = (s8)p[0x15B] + 0x31;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(u32 *)(p + 0x1D8) = 0;
            D_004C2794->s7C[p[2]]++;
        }
        p[0x15B] = 0;
    }
}
