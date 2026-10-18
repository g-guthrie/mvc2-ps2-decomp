typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 t7c[1]; } G1;
extern G1 *D_004C2794;

void func_00264FC0(u8 *p)
{
    extern void func_00175700();
    extern s32 func_0018AB10();
    extern void func_001757E0();
    s16 v;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    func_00175700(p);
    if (p[0x15B] != 0) {
        p[0x15B] = 0;
        p[0x1B5] = 0x33;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->t7c[p[2]]++;
    }
    v = *(s16 *)(p + 0x1E);
    if (v > 0) {
        *(s16 *)(p + 0x1E) = v - 1;
        if (func_0018AB10(p) != 0) {
            *(s16 *)(p + 0x1C) += 2;
        }
    }
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v < 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x168] = 3;
        if (p[0x20D] == 2) p[0x168] = 5;
        func_001757E0(p, 0x15, p[0x168]);
    }
}
