typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C29A8;
void func_00383F40(u8 *p) {
    extern void func_001757E0();
    extern s32 func_00174470();
    extern void func_003859F0();
    extern void func_00175700();
    extern void func_001E7F60();
    u32 t;
    p[0x13C] = 1;
    if (*(s8 *)(p + 0x1B2) != 0 || *(s8 *)(p + 0x1B3) != 0) {
        t = p[4];
        p[4] = t + 1;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        *D_004C29A8 = 0;
        func_001757E0(p, 0x14, 1);
        return;
    }
    if (func_00174470() == 0) {
        *D_004C29A8 = 0;
        func_003859F0(p);
        return;
    }
    p[0x24] = 0;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_001E7F60(p);
}

typedef struct { f32 x, y, z; } V3_33F560;
extern V3_33F560 D_0045F950[];
extern s32 D_004C1948[2];
extern s32 D_004C283C;
void func_0033F560(s32 idx) {
    extern u8 *func_003DA750();
    extern void func_0033F470();
    extern void func_0033F720();
    u8 *o;
    if ((o = func_003DA750(0, 6, 0)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = (void *)func_0033F470;
        *(s16 *)(o + 0xCC) = 3;
        *(s32 *)(o + 0x84) = D_004C283C;
        *(s32 *)(o + 0xD0) = 0x807;
        *(V3_33F560 *)(o + 0x34) = D_0045F950[idx];
        *(s32 *)(o + 0x44) = D_004C1948[idx];
        *(s16 *)(o + 0x1C) = idx * 180;
        func_0033F720(o);
    }
}

typedef struct { u8 pad[0x7C]; s16 tab[1]; } G_310C90;
extern G_310C90 *D_004C2794;
void func_00310C90(u8 *p) {
    extern void func_00175700();
    extern void func_001DD8A0();
    extern void func_001843A0();
    s32 t;
    func_00175700(p);
    t = *(s8 *)(p + 0x151);
    if (t & 2) {
        p[0x151] = t & ~2;
        func_001DD8A0(p, 9, 8);
    }
    t = *(s8 *)(p + 0x151);
    if (t & 4) {
        p[0x151] = t & ~4;
        func_001DD8A0(p, 9, 9);
    }
    t = *(s8 *)(p + 0x151);
    if (t & 8) {
        p[0x151] = t & ~8;
        p[0x1B5] = 0x19;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->tab[p[2]]++;
    }
    if (!(*(f32 *)(p + 0x430) < *(f32 *)(p + 0x38))) {
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        func_001843A0(p);
    }
}
