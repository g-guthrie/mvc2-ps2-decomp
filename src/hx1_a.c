typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004F1FC8[];
extern f32 D_004F1FD4[];
extern s32 fptosi(f32);

void func_003C2F10(u8 *a)
{
    s16 *s = (s16 *)(a + 0xD0);
    u32 t;

    *(f32 *)(a + 0x34) = 320.0f + D_004F1FC8[0];
    if (a[0x21] == 0) {
        *(f32 *)(a + 0x34) += 213.33333f;
    } else {
        *(f32 *)(a + 0x34) -= 213.33333f;
    }
    s[1] = fptosi(D_004F1FD4[0] - 154.2857f);
    s[0] = fptosi((f32)s[0] + *(f32 *)(a + 0x60));
    *(f32 *)(a + 0x38) = (f32)(s[0] + s[1]);
    if (!((f32)s[0] < 137.14285f)) {
        s[0] = 0x9A;
        *(f32 *)(a + 0x38) = (f32)(s[0] + s[1]);
        t = a[5];
        a[5] = t + 1;
    }
}
