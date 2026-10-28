/* residual_003660F0: MW 3.0 "-O3 -Op -fp off -sdatathreshold 8", exact when compiled in the same mwccps2 run after src/owner_entry_motion_00365870.c (warm-up: nearest preceding double-arithmetic function func_00365870). */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;
typedef struct { f32 x, y, z; } V3;
typedef struct { s32 w[0x31]; } Bq;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } Gq;
extern Gq *D_004C2794;
extern u8 *D_004C2974;
extern u8 *D_004C2978;
extern f32 D_004F1F4C[];
extern f64 func_00119058(f32);
extern f64 func_00119510(f64, f64);
extern f32 dptofp(f64);

#define PAR (*(u8 **)(o + 0x18))

void residual_003660F0(u8 *o) {
    extern void func_00365FC0(u8 *);
    extern void func_001E3210(u8 *, s32);
    extern void func_003670B0(u8 *);
    u32 t;
    f32 g;
    f64 r;
    f64 k;
    t = o[4];
    o[4] = t + 1;
    *(Bq *)(o + 0xEC) = *(Bq *)(PAR + 0xEC);
    o[0x13C] = 1;
    o[2] = PAR[2];
    o[1] = PAR[1];
    *(f32 *)(o + 0x50) = *(f32 *)(PAR + 0x50);
    *(f32 *)(o + 0x54) = *(f32 *)(PAR + 0x54);
    o[0x1B7] = PAR[0x1B7];
    o[0x1B8] = PAR[0x1B8];
    *(s8 *)(o + 0x30) = *(s8 *)(PAR + 0x30);
    *(V3 *)(o + 0x50) = *(V3 *)(PAR + 0x50);
    *(s8 *)(o + 0x24) = *(s8 *)(PAR + 0x24);
    o[0x24] = 0xC;
    D_004C2978[2] = 1;
    o[0x1B5] = 0x32;
    o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
    *(s32 *)(o + 0x1D8) = 0;
    { s32 x = o[2]; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    o[0x1B0] = 0x46;
    o[0x1B1] = 0x44;
    *(u16 *)(o + 0x1C0) |= 0x200;
    o[0x14E] = 0x40;
    o[0x14F] = 0x40;
    if (PAR[0x1E6] != 0) {
        g = D_004F1F4C[0];
        r = (f64)(g - 320.0f - 106.66666412353516f);
    } else {
        g = D_004F1F4C[0];
        k = 320.0;
        r = k + (f64)g;
        r = 106.66666412353516 + r;
    }
    *(f32 *)(o + 0x34) = (f32)r;
    *(f32 *)(o + 0x38) = *(f32 *)D_004C2974 = 17.14285659790039f + *(f32 *)(PAR + 0x430);
    *(s16 *)(o + 0x1C) = 0x258;
    D_004C2974[4] = 0;
    D_004C2974[5] = 1;
    D_004C2974[6] = 0;
    *(s16 *)(D_004C2974 + 0xC) = 0xB4;
    D_004C2974[0xF] = 0;
    func_00365FC0(o);
    func_001E3210(o, 0x30);
    func_003670B0(o);
}
