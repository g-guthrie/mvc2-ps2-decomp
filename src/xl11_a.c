typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

/* MW 3.0.3: ./try.sh src/xl11_a.c "-O3 -Op -fp off -sdatathreshold 8" */
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

static void func_00338670(DB *p)
{
    p->h1c = p->h1c + 1;
    if (p->h1c > 150) {
        p->b4 = 0;
        p->h1c = 0;
        return;
    }
    p->w40 = (u32)(s32)(0.5 + 65536.0 * (f64)p->f5c / 360.0) & 0xFFFF;
    p->w44 = (u32)(s32)(0.5 + 65536.0 * (f64)p->f60 / 360.0) & 0xFFFF;
    p->w48 = (u32)(s32)(0.5 + 65536.0 * (f64)p->f64 / 360.0) & 0xFFFF;
    p->w40 += (u32)(s32)(0.5 + 65536.0 * (f64)(D_00583C48[0] * (f32)p->h1c) / 360.0) & 0xFFFF;
    p->w44 += (u32)(s32)(0.5 + 65536.0 * (f64)(D_00583C4C[0] * (f32)p->h1c) / 360.0) & 0xFFFF;
    p->w48 += (u32)(s32)(0.5 + 65536.0 * (f64)(D_00583C50[0] * (f32)p->h1c) / 360.0) & 0xFFFF;
}


typedef struct XA {
    u8 _p0[0x1C];
    s16 h1c;
    s16 h1e;
    u8 _p1[0x14];
    f32 f34;
    f32 f38;
    f32 f3c;
    u32 w40;
    u32 w44;
    u32 w48;
} XA;

extern f32 D_0045FB88[], D_0045FB8C[], D_0045FB90[], D_0045FB94[], D_0045FB98[], D_0045FB9C[];
extern f32 D_0045FBA0[], D_0045FBA4[], D_0045FBA8[], D_0045FBAC[], D_0045FBB0[], D_0045FBB4[];
extern f32 D_0045FBB8[], D_0045FBBC[], D_0045FBC0[], D_0045FBC4[], D_0045FBC8[], D_0045FBCC[];
extern f32 D_0045FBD0[], D_0045FBD4[];
extern u8 D_004C27D0[1];
extern f64 func_00119058(f32);
extern f64 func_001195D0(f64, f64);
extern f64 func_00119858(f64, f64);
extern f64 func_00119510(f64, f64);
extern s32 func_00119BC0(f64);
extern void func_0032FEB0(f32, f32 *, f32 *, f32 *);

void func_003413B0(XA *p)
{
    f32 v38[3];
    f32 v48[3];
    f32 c0, c1, c2;
    extern void func_00416AE0(s32);
    extern void func_004171E0();
    extern void func_00417350(s32);
    extern void func_004172E0(s32);
    extern void func_00417270(s32);
    extern void func_00417E30(f32 *, f32 *);
    extern void func_00416CC0(s32);
    s32 i = p->h1e;

    func_0032FEB0((f32)p->h1c / (D_0045FBBC[i * 7] - D_0045FBA0[i * 7]), &c0, &c1, &c2);
    i = p->h1e;
    p->w40 = -((u32)(s32)(0.5 + 65536.0 * (f64)(c0 * D_0045FB94[i * 7] + c1 * D_0045FBB0[i * 7] + c2 * D_0045FBCC[i * 7]) / 360.0) & 0xFFFF);
    p->w44 = -((u32)(s32)(0.5 + 65536.0 * (f64)(c0 * D_0045FB98[i * 7] + c1 * D_0045FBB4[i * 7] + c2 * D_0045FBD0[i * 7]) / 360.0) & 0xFFFF);
    p->w48 = -((u32)(s32)(0.5 + 65536.0 * (f64)(c0 * D_0045FB9C[i * 7] + c1 * D_0045FBB8[i * 7] + c2 * D_0045FBD4[i * 7]) / 360.0) & 0xFFFF);
    v38[0] = c0 * D_0045FB88[i * 7] + c1 * D_0045FBA4[i * 7] + c2 * D_0045FBC0[i * 7];
    v38[1] = c0 * D_0045FB8C[i * 7] + c1 * D_0045FBA8[i * 7] + c2 * D_0045FBC4[i * 7];
    v38[2] = c0 * D_0045FB90[i * 7] + c1 * D_0045FBAC[i * 7] + c2 * D_0045FBC8[i * 7];
    func_00416AE0(0);
    func_004171E0();
    func_00417350(p->w40);
    func_004172E0(p->w44);
    func_00417270(p->w48);
    func_00417E30(v38, v48);
    func_00416CC0(1);
    p->f34 = -v48[0];
    p->f38 = -v48[1];
    p->f3c = -v48[2];
    if (D_004C27D0[0] == 7) {
        p->h1c = p->h1c + 1;
    } else {
        p->h1c = p->h1c + 2;
    }
    i = p->h1e;
    if (!((f32)p->h1c < D_0045FBBC[i * 7] - D_0045FBA0[i * 7])) {
        p->h1c = 0;
        p->h1e = p->h1e + 1;
        if ((u32)(p->h1e + 2) >= 0x59) {
            p->h1e = 1;
        }
    }
}
