typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s8 D_004F2035[];
extern s32 D_004C25B8;
extern f32 D_004F1FF8[];
extern f32 D_004F1FFC[];
extern f32 D_004F2000[];
extern f32 D_004C9F40[];
extern f32 D_004C9F44[];
extern f32 D_004C9F48[];
extern f32 D_004F2028[];
extern f32 D_004F202C[];
extern f32 D_004F2030[];
extern f32 D_004F1F94[];
extern f32 D_004F1F98[];
extern f32 D_004F1F9C[];

void func_001239E0(s32 a0, s32 n) {
    f32 z;
    f32 d;
    f32 r;
    if (D_004F2035[0] == 0) {
        D_004F2035[0] = 1;
        D_004C25B8 = 0;
        z = 0.0f;
        r = z;
        d = D_004F1FF8[0] - D_004C9F40[0];
        if (d != z) { f32 nf = (f32)n; asm { div.s r, d, nf; nop; nop; nop } }
        D_004F2028[0] = r;
        r = z;
        d = D_004F1FFC[0] - D_004C9F44[0];
        if (d != z) { f32 nf = (f32)n; asm { div.s r, d, nf; nop; nop; nop } }
        D_004F202C[0] = r;
        r = z;
        d = D_004F2000[0] - D_004C9F48[0];
        if (d != z) { f32 nf = (f32)n; asm { div.s r, d, nf; nop; nop; nop } }
        D_004F2030[0] = r;
    }
    if (D_004C25B8 < n - 1) {
        D_004C25B8 = D_004C25B8 + 1;
        D_004F1F94[0] = D_004C9F40[0] + D_004F2028[0];
        D_004F1F98[0] = D_004C9F44[0] + D_004F202C[0];
        D_004F1F9C[0] = D_004C9F48[0] + D_004F2030[0];
        D_004C9F40[0] = D_004F1F94[0];
        D_004C9F44[0] = D_004F1F98[0];
        D_004C9F48[0] = D_004F1F9C[0];
    } else {
        D_004F2035[0] = 2;
        D_004F1F94[0] = D_004F1FF8[0];
        D_004F1F98[0] = D_004F1FFC[0];
        D_004F1F9C[0] = D_004F2000[0];
        D_004C9F40[0] = D_004F1F94[0];
        D_004C9F44[0] = D_004F1F98[0];
        D_004C9F48[0] = D_004F1F9C[0];
    }
}
