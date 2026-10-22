typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[8]; } G_002DEED0;
extern G_002DEED0 *D_004C2794;

void func_002DEED0(u8 *p)
{
    s16 v;
    extern void func_00175700();
    extern void func_001D1EB0(u8 *);
    extern void func_001D2730(u8 *, s32, s32);
    extern void func_001757E0(u8 *, s32, s32);
    p[0x40C] = 2;
    p[0x33C] = 5;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        *(u32 *)(p + 0x5C) = 0xC22D5555;
        *(u32 *)(p + 0x68) = 0;
        if (p[0x1E6] != 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        }
        p[0x1B5] = 0x38;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]] += 1;
        func_001D1EB0(p);
        func_001D2730(p, 0, 0);
        func_001D2730(p, 0, 1);
        func_001D2730(p, 1, 0);
        func_001D2730(p, 1, 1);
    }
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        { u32 t = p[6]; p[6] = t + 1; }
        p[7] = 0;
        *(u32 *)(p + 0x5C) = 0xC0D55555;
        *(u32 *)(p + 0x68) = 0x3E555555;
        if (p[0x1E6] != 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        }
        func_001757E0(p, 0x16, 8);
    }
}
