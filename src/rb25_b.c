typedef signed short s16;
typedef signed int s32;
extern s16 D_004F25A0[];
extern s16 D_004F2B58[];
extern s16 D_004F3110[];
extern s16 D_004F36C8[];
extern s16 D_004F3C80[];
extern s16 D_004F4238[];
extern s16 D_004F4430[];
extern s16 D_004F4444[];
#define CP(D, S) { s32 i; s16 *d; s16 *s; s = S; d = D; i = 5; do { s16 a = *s++; s16 b = *s++; *d++ = a; *d++ = b; i--; } while (i > 0); }

void func_00128740(void)
{
    extern void func_001288A0(s32);
    func_001288A0(0);
    func_001288A0(1);
    CP(D_004F3110, D_004F25A0);
    CP(D_004F36C8, D_004F2B58);
    CP(D_004F3C80, D_004F25A0);
    CP(D_004F4238, D_004F2B58);
    CP(D_004F4430, D_004F25A0);
    CP(D_004F4444, D_004F2B58);
}
