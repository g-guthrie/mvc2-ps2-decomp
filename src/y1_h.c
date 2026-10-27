typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
void func_003DCAD0(s32 a, s32 b, s32 c, s32 n)
{
    extern s32 func_0010BB98(const char *, int, const void *);
    extern void func_0011EB60();
    extern u8 D_004BA4F0[];
    s32 i;
    if (n == 0) {
        goto test;
    body:
        asm { nop; nop; nop; nop; nop; nop }
    test:
        asm { nop; nop }
        if (func_0010BB98((const char *)a, b, (const void *)c) < 0) goto body;
        return;
    }
    for (i = 0; i < n; i++) {
        if (func_0010BB98((const char *)a, b, (const void *)c) > 0) return;
    }
    func_0011EB60(D_004BA4F0, a);
}
