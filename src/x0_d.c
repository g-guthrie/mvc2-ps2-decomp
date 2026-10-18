typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V15F3D0;
typedef struct { u8 pad[0x7C]; s16 f7c[16]; } G306280;
extern s16 D_004B3D90[];
extern s32 D_004C2838;
extern u8 *D_004C2840;
extern s32 D_004C2B50;
extern s32 D_004BFAE4;
extern s32 D_004B6A70[];
extern G306280 *D_004C2794;

void func_0015F3D0(u8 *p, s8 idx) {
    extern u8 *func_003DA750();
    extern void func_0015F020();
    s16 *tab;
    s32 i;
    s32 j;
    u8 *o;
    j = 0;
    i = 0;
    tab = D_004B3D90;
    do {
        if ((o = func_003DA750(0, 8, 1)) == 0) return;
        o[0x13C] = 0;
        *(void **)(o + 0x10) = func_0015F020;
        *(s32 *)(o + 0xD0) = 0x11;
        *(V15F3D0 *)(o + 0x34) = *(V15F3D0 *)(p + 0x34);
        *(s16 *)(o + 0xCC) = tab[idx];
        *(s32 *)(o + 0x84) = D_004C2838;
        *(u8 **)(o + 0x18) = p;
        o[0x23] = i;
        *(s16 *)(o + 0x1E) = j;
        i++;
        o[0x20] = idx;
        j += 2;
    } while (i < 3);
}

void func_001E3F50(s8 i) {
    extern void func_00401868();
    extern void func_004026B0();
    extern void func_00402C20();
    u8 *g = D_004C2840;
    if (*(s8 *)(g + 0x43) == 0) {
        if (*(s32 *)(g + 0x14) == 0x40) return;
    }
    if (D_004C2B50 == 0) return;
    func_00401868(D_004C2B50);
    func_004026B0(D_004C2B50, 1);
    D_004BFAE4 = D_004B6A70[i];
    func_00402C20(D_004C2B50, 0, D_004BFAE4);
}

void func_00306280(u8 *p) {
    extern s8 func_00175700();
    extern void func_001843A0();
    s32 v;
    switch (p[0x1FC]) {
    case 0:
        if (func_00175700(p) < 0) func_001843A0(p);
        break;
    case 1:
    case 2:
        v = *(s8 *)(p + 0x151);
        if (v != 0) {
            p[0x1B5] = v;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
            p[0x151] = 0;
        }
        if (func_00175700(p) < 0) func_001843A0(p);
        break;
    default:
        break;
    }
}
