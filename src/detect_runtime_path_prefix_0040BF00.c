typedef unsigned char u8;
typedef signed int s32;
typedef unsigned int u32;

extern const char D_004BE120[];
extern void *func_0011D8F8(void *destination, s32 value, u32 size);
extern s32 func_0011FD40(const char *path, const char *filter);

s32 func_0040BF00(const u8 *path)
{
    u8 prefix[6];

    func_0011D8F8(prefix, 0, 6);
    __builtin_memcpy(prefix, path, 4);
    prefix[5] = 0;
    return func_0011FD40((const char *)prefix, D_004BE120) == 0;
}

/* Follows func_0040BF00 in this unit: EE GCC 2.96 treats calls to functions
   it has already compiled as non-throwing, which lets reorg fill the bnez
   slot with retail's lui a1. */
typedef signed char s8;
extern s32 func_0040BE90();
extern void func_0011FE88();
extern void func_0011FC10();
extern s32 func_0011FFA0();
extern s8 D_004896E0[];
extern s8 D_004895D8[];
extern s8 D_004BE128[];

void func_0040BF58(s8 *src, s8 *dst)
{
    s32 i, n;
    s32 c;

    *dst = 0;
    if (func_0040BE90(src, dst) == 0)
        func_0011FE88(dst, D_004896E0);
    if (func_0040BF00((const u8 *)dst) == 1) {
        func_0011FC10(dst, D_004895D8);
        c = D_004895D8[func_0011FFA0(D_004895D8) - 1];
        if (c != 0x5C && c != 0x2F && c != 0) {
            c = *src;
            if (c != 0x5C && c != 0x2F)
                func_0011FC10(dst, D_004BE128);
        }
    }
    func_0011FC10(dst, src);
    n = func_0011FFA0(dst);
    for (i = 0; i < n; i++) {
        if (dst[i] == 0x5C)
            dst[i] = 0x2F;
    }
}
