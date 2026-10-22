typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

extern s8 D_004F2037[];
extern s32 D_004C25B4;
extern f32 D_004C25AC;
extern f32 D_004C25A8;
extern f32 D_004C25B0;
extern f32 D_004C9F10[];
extern f32 D_004C9F14[];
extern f32 D_004C9F18[];
extern f32 D_004C9F30[];
extern f32 D_004C9F34[];
extern f32 D_004C9F38[];
extern f32 D_004F2010[];
extern f32 D_004F2014[];
extern f32 D_004F2018[];
extern f32 D_004F1F4C[];
extern f32 D_004F1F50[];
extern f32 D_004F1F54[];
extern f32 D_004F1F94[];
extern f32 D_004F1F98[];
extern f32 D_004F1F9C[];
extern s32 D_004F1FC4[];

#define ANGF(x) ((s32)(0.5 + 65536.0 * (f64)(x) / 360.0))
#define ANG(x) ((s32)((u32)ANGF(x) & 0xFFFFu))
#define ANGU(x) ((u16)ANGF(x))

void func_00123BE0(s32 a0, s32 a1)
{
    extern f32 func_00417500(s32);
    extern f32 func_00417440(s32);
    s32 c;
    f32 f20;
    f32 r;

    if (D_004F2037[0] == 0) {
        D_004F2037[0] = 1;
        D_004C9F30[0] += D_004C9F10[0] * (f32)D_004C25B4;
        D_004C9F34[0] += D_004C9F14[0] * (f32)D_004C25B4;
        D_004C25B4 = 0;
        D_004C9F10[0] = (D_004F2010[0] - D_004C9F30[0]) / (f32)a1;
        D_004C9F14[0] = (D_004F2014[0] - D_004C9F34[0]) / (f32)a1;
        D_004C9F18[0] = (D_004F2018[0] - D_004C9F38[0]) / (f32)a1;
    }
    c = D_004C25B4;
    if (c < a1 - 1) {
        D_004C25AC = D_004F1F98[0] - D_004F1F50[0];
        D_004C25A8 = D_004F1F9C[0] - D_004F1F54[0];
        r = func_00417500(ANGU(D_004C9F30[0] + (f32)c * D_004C9F10[0]));
        f20 = D_004C25AC * r;
        f20 = D_004F1F50[0] + f20;
        r = func_00417440(ANGU(D_004C9F30[0] + (f32)c * D_004C9F10[0]));
        D_004F1F98[0] = f20 - D_004C25A8 * r;
        r = func_00417440(ANGU(D_004C9F30[0] + (f32)D_004C25B4 * D_004C9F10[0]));
        f20 = D_004C25AC * r;
        f20 = D_004F1F54[0] + f20;
        r = func_00417500(ANGU(D_004C9F30[0] + (f32)D_004C25B4 * D_004C9F10[0]));
        D_004F1F9C[0] = f20 + D_004C25A8 * r;
        D_004C25B0 = D_004F1F94[0] - D_004F1F4C[0];
        D_004C25A8 = D_004F1F9C[0] - D_004F1F54[0];
        r = func_00417500(ANGU(D_004C9F34[0] + (f32)D_004C25B4 * D_004C9F14[0]));
        f20 = D_004C25B0 * r;
        f20 = D_004F1F4C[0] + f20;
        r = func_00417440(ANGU(D_004C9F34[0] + (f32)D_004C25B4 * D_004C9F14[0]));
        D_004F1F94[0] = f20 + D_004C25A8 * r;
        r = func_00417440(ANGU(D_004C9F34[0] + (f32)D_004C25B4 * D_004C9F14[0]));
        f20 = D_004C25B0 * r;
        f20 = D_004F1F54[0] - f20;
        r = func_00417500(ANGU(D_004C9F34[0] + (f32)D_004C25B4 * D_004C9F14[0]));
        D_004F1F9C[0] = f20 + D_004C25A8 * r;
        D_004C9F38[0] = D_004C9F38[0] + D_004C9F18[0];
        D_004F1FC4[0] = ANGU(D_004C9F38[0]);
        D_004C25B4 = D_004C25B4 + 1;
    } else {
        D_004F2037[0] = 2;
        D_004C9F38[0] = D_004F2018[0];
        D_004F1FC4[0] = ANG(D_004C9F38[0]);
        D_004C25AC = D_004F1F98[0] - D_004F1F50[0];
        D_004C25A8 = D_004F1F9C[0] - D_004F1F54[0];
        r = func_00417500(ANG(D_004C9F30[0] + (f32)*(s32 *)&D_004C25B4 * D_004C9F10[0]));
        f20 = D_004C25AC * r;
        f20 = D_004F1F50[0] + f20;
        r = func_00417440(ANGU(D_004C9F30[0] + (f32)c * D_004C9F10[0]));
        D_004F1F98[0] = f20 - D_004C25A8 * r;
        r = func_00417440(ANGU(D_004C9F30[0] + (f32)D_004C25B4 * D_004C9F10[0]));
        f20 = D_004C25AC * r;
        f20 = D_004F1F54[0] + f20;
        r = func_00417500(ANGU(D_004C9F30[0] + (f32)D_004C25B4 * D_004C9F10[0]));
        D_004F1F9C[0] = f20 + D_004C25A8 * r;
        D_004C25B0 = D_004F1F94[0] - D_004F1F4C[0];
        D_004C25A8 = D_004F1F9C[0] - D_004F1F54[0];
        r = func_00417500(ANGU(D_004C9F34[0] + (f32)D_004C25B4 * D_004C9F14[0]));
        f20 = D_004C25B0 * r;
        f20 = D_004F1F4C[0] + f20;
        r = func_00417440(ANGU(D_004C9F34[0] + (f32)D_004C25B4 * D_004C9F14[0]));
        D_004F1F94[0] = f20 + D_004C25A8 * r;
        r = func_00417440(ANGU(D_004C9F34[0] + (f32)D_004C25B4 * D_004C9F14[0]));
        f20 = D_004C25B0 * r;
        f20 = D_004F1F54[0] - f20;
        r = func_00417500(ANGU(D_004C9F34[0] + (f32)D_004C25B4 * D_004C9F14[0]));
        D_004F1F9C[0] = f20 + D_004C25A8 * r;
    }
}
