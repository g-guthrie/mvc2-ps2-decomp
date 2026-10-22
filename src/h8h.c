typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

extern u8 *func_003DA750();
extern void func_00344B70(u8 *);
extern s32 D_004C283C;
extern V3 D_00460DD0[];
extern void func_00170DF0(u32);
void func_00344D80(void) {
    u8 *o = func_003DA750(0, 6, 0);
    if (o) {
        o[0x13C] = 0;
        *(void **)(o + 0x10) = (void *)func_00344B70;
        *(s16 *)(o + 0xCC) = 10;
        *(s32 *)(o + 0x84) = D_004C283C;
        *(s32 *)(o + 0xD0) = 0xD09;
        *(V3 *)(o + 0x34) = D_00460DD0[0];
        func_00170DF0((u32)*(s32 *)(o + 0x84));
    }
}

extern s8 func_00175700();
extern void func_001843A0();
extern u8 *D_004C2794;
void func_002048D0(u8 *p) {
    if (func_00175700(p) < 0) func_001843A0(p);
    if (*(s8 *)(p + 0x151)) {
        p[0x151] = 0;
        p[0x1B5] = 7;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        ((s16 *)(D_004C2794 + 0x7C))[p[2]] += 1;
    }
}

extern s32 func_003DAA40();
extern s16 D_00444C20[];
extern f32 D_00444C40[];
extern s32 D_004C2838;
s32 func_00156B50(u8 *p) {
    s16 i = *(s16 *)(p + 0x1C);
    if (i >= 7) return func_003DAA40(p, i);
    *(s16 *)(p + 0xCC) = D_00444C20[i * 2];
    *(s32 *)(p + 0x84) = D_004C2838;
    {
        f32 v = D_00444C40[*(s16 *)(p + 0x1C)];
        *(f32 *)(p + 0x78) = v;
        *(f32 *)(p + 0x7C) = v;
        *(f32 *)(p + 0x80) = *(f32 *)(p + 0x78);
    }
    *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 1;
}
