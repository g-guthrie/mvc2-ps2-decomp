typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;
typedef double f64;
typedef unsigned long long u64;

typedef struct { s8 b0; u8 pad1[9]; s16 hA; u8 padC[4]; f32 f10; f32 f14; } S7F50;
extern S7F50 D_004F7F50;
extern f32 D_004F7FD0[];
extern f32 D_004F7FD4[];
extern f32 D_00477210[];
extern f32 D_00477220[];
extern f32 D_00477230[];
extern f32 D_00477240[];
extern f32 D_00477214[];
extern f32 D_00477224[];
extern f32 D_00477234[];
extern f32 D_00477244[];
extern f32 D_00477250[];
extern f32 D_00477260[];
extern f32 D_00477270[];
extern f32 D_00477280[];
extern f32 D_00477254[];
extern f32 D_00477264[];
extern f32 D_00477274[];
extern f32 D_00477284[];
extern void (*D_004C2A48)(void);
extern void func_003D3A90(void);

extern f64 func_00119058(f32);
extern f64 func_00119510(f64, f64);
extern f64 func_00119568(f64, f64);
extern f32 dptofp(f64);

void func_003D3750(void)
{
    S7F50 *s;
    f32 sc;
    f32 g;
    f64 t;
    extern void func_00123090(void);
    extern void func_00417AE0(s32, f32 *);

    s = &D_004F7F50;
    if (s->b0 != 0) {
        func_00123090();
        D_004C2A48 = func_003D3A90;
        sc = (f32)(11 - s->hA) / 10.0f;
        t = func_00119568(316.0, func_00119058(s->f10 * sc));
        D_00477210[0] = D_00477230[0] = dptofp(func_00119510(func_00119058(g = D_004F7FD0[0]), t));
        t = func_00119510(324.0, func_00119058(s->f10 * sc));
        D_00477220[0] = D_00477240[0] = dptofp(func_00119510(func_00119058(g), t));
        t = func_00119568(236.0, func_00119058(s->f14 * sc));
        D_00477214[0] = D_00477224[0] = dptofp(func_00119510(func_00119058(g = D_004F7FD4[0]), t));
        t = func_00119510(244.0, func_00119058(s->f14 * sc));
        D_00477234[0] = D_00477244[0] = dptofp(func_00119510(func_00119058(g), t));
        func_00417AE0(4, D_00477210);
        { extern f64 func_00119568(u64, f64); t = func_00119568(0x4074000000000000ULL, func_00119058(s->f10 * sc)); }
        D_00477250[0] = D_00477270[0] = dptofp(func_00119510(func_00119058(g = D_004F7FD0[0]), t));
        t = func_00119510(320.0, func_00119058(s->f10 * sc));
        D_00477260[0] = D_00477280[0] = dptofp(func_00119510(func_00119058(g), t));
        { extern f64 func_00119568(u64, f64); t = func_00119568(0x406E000000000000ULL, func_00119058(s->f14 * sc)); }
        D_00477254[0] = D_00477264[0] = dptofp(func_00119510(func_00119058(g = D_004F7FD4[0]), t));
        t = func_00119510(240.0, func_00119058(s->f14 * sc));
        D_00477274[0] = D_00477284[0] = dptofp(func_00119510(func_00119058(g), t));
        func_00417AE0(4, D_00477250);
    }
}
