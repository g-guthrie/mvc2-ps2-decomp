typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

/* MW 3.0: ./try30.sh SRC "-O3 -Op -fp off -sdatathreshold 8"
   Statics are the real contiguous predecessors of func_0033C530 only. */
typedef struct DB {
    u8 _p0[0x4];
    u8 b4;
    u8 _p1[0x17];
    s16 h1c;
    u8 _p2[0x22];
    u32 w40;
    u32 w44;
    u32 w48;
    u8 _p3[0x10];
    f32 f5c;
    f32 f60;
    f32 f64;
} DB;

extern f32 D_00583C48[];
extern f32 D_00583C4C[];
extern f32 D_00583C50[];



typedef struct { f32 x, y, z; } V3;
extern s32 D_004C283C;
extern u8 *func_003DA750(s32, s32, s32);
extern V3 D_004B7FE8;
extern f32 D_004B7FF8[];
extern f32 D_004B7FFC[];
extern f32 D_004B8000[];
extern V3 D_0045F988;
extern f32 D_0045F998[];
extern f32 D_0045F99C[];
extern f32 D_0045F9A0[];
extern V3 D_0045ECF8;
extern f32 D_0045ED08[];
extern f32 D_0045ED0C[];
extern f32 D_0045ED10[];

extern f32 D_0045ECD0[3];
extern f32 func_00417440(u32);
extern f32 func_00417500(u32);
extern void func_0033C250();

/* Real contiguous address-order predecessors of func_0033C530
   (retail 0x0033C300, 0x0033C470, 0x0033C520; matched globally in
   src/scene_orbit_0033C300.c, src/t10_g.c, src/simple_leaves.c).
   Each is verified exact at its own address under this file's flags. */
typedef struct { u8 _p[0x1C]; s16 h1c; } SO;
static void func_0033C300(u8 *p) {
    u32 angle;
    SO *sa = (SO *)p;
    if (*(s16 *)(p + 0x1C) >= 300)
        sa->h1c = 180;
    angle = (u32)(int)(0.5 + 65536.0 * (double)((s32)*(s16 *)(p + 0x1C) + 90) / 360.0) & 0xFFFFu;
    *(u32 *)(p + 0x44) = angle;
    angle = (u32)(int)(0.5 + 65536.0 * (double)((s32)*(s16 *)(p + 0x1C)) / 360.0) & 0xFFFFu;
    *(f32 *)(p + 0x34) = D_0045ECD0[0] + 850.0f * func_00417440(angle);
    angle = (u32)(int)(0.5 + 65536.0 * (double)((s32)*(s16 *)(p + 0x1C)) / 360.0) & 0xFFFFu;
    *(f32 *)(p + 0x3C) = D_0045ECD0[2] + 850.0f * func_00417500(angle);
    *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 1;
}

static void func_0033C470(void) {
    u8 *o;
    s32 i;
    if ((o = func_003DA750(0, 6, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_0033C300;
        *(s16 *)(o + 0xCC) = 0x1C;
        *(s32 *)(o + 0x84) = D_004C283C;
        *(V3 *)(o + 0x34) = *(V3 *)D_0045ECD0;
        *(s32 *)(o + 0xD0) = 0x805;
        i = 0;
        do {
            func_0033C250(o, i);
            i++;
        } while (i < 2);
    }
}

static void func_0033C520(void) {}

static void (*keep_0033C470)(void) = func_0033C470;

void func_0033C530(void) {
    u8 *o;
    double k;
    extern void func_0033C7A0();
    if ((o = func_003DA750(0, 6, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_0033C520;
        *(s16 *)(o + 0xCC) = 30;
        *(s32 *)(o + 0x84) = D_004C283C;
        *(s32 *)(o + 0xD0) = 0x80F;
        *(V3 *)(o + 0x34) = D_0045ECF8;
        k = 65536.0;
        *(s32 *)(o + 0x40) = (u32)(s32)(0.5 + (k *= D_0045ED08[0]) / 360.0) & 0xFFFF;
        k = 65536.0;
        *(s32 *)(o + 0x44) = (u32)(s32)(0.5 + (k *= D_0045ED0C[0]) / 360.0) & 0xFFFF;
        k = 65536.0;
        *(s32 *)(o + 0x48) = (u32)(s32)(0.5 + (k *= D_0045ED10[0]) / 360.0) & 0xFFFF;
        func_0033C7A0(o, 0);
        func_0033C7A0(o, 1);
        func_0033C7A0(o, 2);
    }
}

void func_00337BA0(void) {
    u8 *o;
    double k;
    extern void func_00337990();
    extern void func_00337850();
    extern void func_00337900();
    extern void func_00337660();
    if ((o = func_003DA750(0, 6, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_00337990;
        *(s16 *)(o + 0xCC) = 20;
        *(s32 *)(o + 0x84) = D_004C283C;
        *(s32 *)(o + 0xD0) = 0x801;
        *(V3 *)(o + 0x34) = D_004B7FE8;
        k = 65536.0;
        *(s32 *)(o + 0x40) = (u32)(s32)(0.5 + (k *= D_004B7FF8[0]) / 360.0) & 0xFFFF;
        k = 65536.0;
        *(s32 *)(o + 0x44) = (u32)(s32)(0.5 + (k *= D_004B7FFC[0]) / 360.0) & 0xFFFF;
        k = 65536.0;
        *(s32 *)(o + 0x48) = (u32)(s32)(0.5 + (k *= D_004B8000[0]) / 360.0) & 0xFFFF;
        func_00337850(o);
        func_00337900(o);
        func_00337660(o);
    }
}

void func_0033FA90(void) {
    u8 *o;
    double k;
    extern void func_0033FC20();
    extern void func_0033FCD0();
    if ((o = func_003DA750(0, 6, 0)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_0033FC20;
        *(s16 *)(o + 0xCC) = 5;
        *(s32 *)(o + 0x84) = D_004C283C;
        *(s32 *)(o + 0xD0) = 0x805;
        *(V3 *)(o + 0x34) = D_0045F988;
        k = 65536.0;
        *(s32 *)(o + 0x40) = (u32)(s32)(0.5 + (k *= D_0045F998[0]) / 360.0) & 0xFFFF;
        k = 65536.0;
        *(s32 *)(o + 0x44) = (u32)(s32)(0.5 + (k *= D_0045F99C[0]) / 360.0) & 0xFFFF;
        k = 65536.0;
        *(s32 *)(o + 0x48) = (u32)(s32)(0.5 + (k *= D_0045F9A0[0]) / 360.0) & 0xFFFF;
        func_0033FCD0(o);
    }
}
