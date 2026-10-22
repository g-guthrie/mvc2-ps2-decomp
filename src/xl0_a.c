typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

extern s8 D_004F2036[];
extern s32 D_004C25A4;
extern f32 D_004C25A0;
extern f32 D_004C259C;
extern f32 D_004C2598;
extern f32 D_004C9F00[];
extern f32 D_004C9F04[];
extern f32 D_004C9F08[];
extern f32 D_004C9F20[];
extern f32 D_004C9F24[];
extern f32 D_004C9F28[];
extern f32 D_004F2004[];
extern f32 D_004F2008[];
extern f32 D_004F200C[];
extern f32 D_004F1F4C[];
extern f32 D_004F1F50[];
extern f32 D_004F1F54[];
extern f32 D_004F1F94[];
extern f32 D_004F1F98[];
extern f32 D_004F1F9C[];

#define ANGF(x) ((s32)(0.5 + 65536.0 * (f64)(x) / 360.0))
#define ANG(x) ((s32)((u32)ANGF(x) & 0xFFFFu))
#define ANGU(x) ((u16)ANGF(x))

void func_00124660(s32 a0, s32 a1)
{
    extern f32 func_00417500(s32);
    extern f32 func_00417440(s32);
    s32 c;
    f32 f20;
    f32 r;

    if (D_004F2036[0] == 0) {
        D_004F2036[0] = 1;
        D_004C9F20[0] += D_004C9F00[0] * (f32)D_004C25A4;
        D_004C9F24[0] += D_004C9F04[0] * (f32)D_004C25A4;
        D_004C9F28[0] += D_004C9F08[0] * (f32)D_004C25A4;
        D_004C25A4 = 0;
        D_004C9F00[0] = (D_004F2004[0] - D_004C9F20[0]) / (f32)a1;
        D_004C9F04[0] = (D_004F2008[0] - D_004C9F24[0]) / (f32)a1;
        D_004C9F08[0] = (D_004F200C[0] - D_004C9F28[0]) / (f32)a1;
    }
    c = D_004C25A4;
    if (c < a1 - 1) {
        D_004C25A0 = D_004F1F4C[0] - D_004F1F94[0];
        D_004C259C = D_004F1F50[0] - D_004F1F98[0];
        D_004C2598 = D_004F1F54[0] - D_004F1F9C[0];
        r = func_00417500(ANGU(D_004C9F20[0] + D_004C9F00[0] * (f32)c));
        f20 = D_004C259C * r;
        f20 = D_004F1F98[0] + f20;
        r = func_00417440(ANGU(D_004C9F20[0] + D_004C9F00[0] * (f32)c));
        D_004F1F50[0] = f20 - D_004C2598 * r;
        r = func_00417440(ANGU(D_004C9F20[0] + D_004C9F00[0] * (f32)D_004C25A4));
        f20 = D_004C259C * r;
        f20 = D_004F1F9C[0] + f20;
        r = func_00417500(ANGU(D_004C9F20[0] + D_004C9F00[0] * (f32)D_004C25A4));
        D_004F1F54[0] = f20 + D_004C2598 * r;
        D_004C25A0 = D_004F1F4C[0] - D_004F1F94[0];
        D_004C259C = D_004F1F50[0] - D_004F1F98[0];
        D_004C2598 = D_004F1F54[0] - D_004F1F9C[0];
        r = func_00417500(ANGU(D_004C9F24[0] + D_004C9F04[0] * (f32)D_004C25A4));
        f20 = D_004C25A0 * r;
        f20 = D_004F1F94[0] + f20;
        r = func_00417440(ANGU(D_004C9F24[0] + D_004C9F04[0] * (f32)D_004C25A4));
        D_004F1F4C[0] = f20 - D_004C2598 * r;
        r = func_00417440(ANGU(D_004C9F24[0] + D_004C9F04[0] * (f32)D_004C25A4));
        f20 = D_004C259C * r;
        f20 = D_004F1F9C[0] - f20;
        r = func_00417500(ANGU(D_004C9F24[0] + D_004C9F04[0] * (f32)D_004C25A4));
        D_004F1F54[0] = f20 + D_004C2598 * r;
        D_004C25A0 = D_004F1F4C[0] - D_004F1F94[0];
        D_004C259C = D_004F1F50[0] - D_004F1F98[0];
        D_004C2598 = D_004F1F54[0] - D_004F1F9C[0];
        r = func_00417500(ANGU(D_004C9F28[0] + D_004C9F08[0] * (f32)D_004C25A4));
        f20 = D_004C259C * r;
        f20 = D_004F1F50[0] + f20;
        r = func_00417440(ANGU(D_004C9F28[0] + D_004C9F08[0] * (f32)D_004C25A4));
        D_004F1F50[0] = f20 + D_004C25A0 * r;
        r = func_00417500(ANGU(D_004C9F28[0] + D_004C9F08[0] * (f32)D_004C25A4));
        f20 = D_004C25A0 * r;
        f20 = D_004F1F4C[0] + f20;
        r = func_00417440(ANGU(D_004C9F28[0] + D_004C9F08[0] * (f32)D_004C25A4));
        D_004F1F4C[0] = f20 - D_004C259C * r;
        D_004C25A4 = D_004C25A4 + 1;
    } else {
        D_004F2036[0] = 2;
        D_004C25A4 = a1;
        D_004C25A0 = D_004F1F4C[0] - D_004F1F94[0];
        D_004C259C = D_004F1F50[0] - D_004F1F98[0];
        D_004C2598 = D_004F1F54[0] - D_004F1F9C[0];
        r = func_00417500(ANGU(D_004C9F20[0] + D_004C9F00[0] * (f32)*(s32 *)&D_004C25A4));
        f20 = D_004C259C * r;
        f20 = D_004F1F98[0] + f20;
        r = func_00417440(ANGU(D_004C9F20[0] + D_004C9F00[0] * (f32)D_004C25A4));
        D_004F1F50[0] = f20 - D_004C2598 * r;
        r = func_00417440(ANGU(D_004C9F20[0] + D_004C9F00[0] * (f32)D_004C25A4));
        f20 = D_004C259C * r;
        f20 = D_004F1F9C[0] + f20;
        r = func_00417500(ANGU(D_004C9F20[0] + D_004C9F00[0] * (f32)D_004C25A4));
        D_004F1F54[0] = f20 + D_004C2598 * r;
        D_004C25A0 = D_004F1F4C[0] - D_004F1F94[0];
        D_004C259C = D_004F1F50[0] - D_004F1F98[0];
        D_004C2598 = D_004F1F54[0] - D_004F1F9C[0];
        r = func_00417500(ANGU(D_004C9F24[0] + D_004C9F04[0] * (f32)D_004C25A4));
        f20 = D_004C25A0 * r;
        f20 = D_004F1F94[0] + f20;
        r = func_00417440(ANGU(D_004C9F24[0] + D_004C9F04[0] * (f32)D_004C25A4));
        D_004F1F4C[0] = f20 - D_004C2598 * r;
        r = func_00417440(ANGU(D_004C9F24[0] + D_004C9F04[0] * (f32)D_004C25A4));
        f20 = D_004C259C * r;
        f20 = D_004F1F9C[0] - f20;
        r = func_00417500(ANGU(D_004C9F24[0] + D_004C9F04[0] * (f32)D_004C25A4));
        D_004F1F54[0] = f20 + D_004C2598 * r;
        D_004C25A0 = D_004F1F4C[0] - D_004F1F94[0];
        D_004C259C = D_004F1F50[0] - D_004F1F98[0];
        D_004C2598 = D_004F1F54[0] - D_004F1F9C[0];
        r = func_00417500(ANGU(D_004C9F28[0] + D_004C9F08[0] * (f32)D_004C25A4));
        f20 = D_004C259C * r;
        f20 = D_004F1F50[0] + f20;
        r = func_00417440(ANGU(D_004C9F28[0] + D_004C9F08[0] * (f32)D_004C25A4));
        D_004F1F50[0] = f20 + D_004C25A0 * r;
        r = func_00417500(ANGU(D_004C9F28[0] + D_004C9F08[0] * (f32)D_004C25A4));
        f20 = D_004C25A0 * r;
        f20 = D_004F1F4C[0] + f20;
        r = func_00417440(ANGU(D_004C9F28[0] + D_004C9F08[0] * (f32)D_004C25A4));
        D_004F1F4C[0] = f20 - D_004C259C * r;
    }
}
