typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s8 D_004F2034[];
extern s32 D_004C25BC;
extern f32 D_004F1FEC[], D_004F1FF0[], D_004F1FF4[];
extern f32 D_004C9F50[], D_004C9F54[], D_004C9F58[];
extern f32 D_004F201C[], D_004F2020[], D_004F2024[];
extern f32 D_004F1F4C[], D_004F1F50[], D_004F1F54[];

void func_001237E0(s32 a0, s32 n)
{
    f32 d;
    f32 r;
    if (D_004F2034[0] == 0) {
        D_004F2034[0] = 1;
        D_004C25BC = 0;
        if ((d = D_004F1FEC[0] - D_004C9F50[0])) r = d / (f32)n; else r = 0.0f;
        D_004F201C[0] = r;
        if ((d = D_004F1FF0[0] - D_004C9F54[0])) r = d / (f32)n; else r = 0.0f;
        D_004F2020[0] = r;
        if ((d = D_004F1FF4[0] - D_004C9F58[0])) r = d / (f32)n; else r = 0.0f;
        D_004F2024[0] = r;
    }
    if (D_004C25BC < n - 1) {
        D_004C25BC = D_004C25BC + 1;
        D_004F1F4C[0] = D_004C9F50[0] + D_004F201C[0];
        D_004F1F50[0] = D_004C9F54[0] + D_004F2020[0];
        D_004F1F54[0] = D_004C9F58[0] + D_004F2024[0];
        D_004C9F50[0] = D_004F1F4C[0];
        D_004C9F54[0] = D_004F1F50[0];
        D_004C9F58[0] = D_004F1F54[0];
    } else {
        D_004F2034[0] = 2;
        D_004F1F4C[0] = D_004F1FEC[0];
        D_004F1F50[0] = D_004F1FF0[0];
        D_004F1F54[0] = D_004F1FF4[0];
        D_004C9F50[0] = D_004F1F4C[0];
        D_004C9F54[0] = D_004F1F50[0];
        D_004C9F58[0] = D_004F1F54[0];
    }
}
