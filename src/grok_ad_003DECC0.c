typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

extern void *func_003DD160(s32, s32);
extern void func_003DC2F0(u32, void *);
extern u8 D_0062BBA0[];

s32 func_003DECC0(u32 *src)
{
    u32 n = (*src & 0x7FFF) + 1;
    u32 *dst;
    u32 i;
    u32 words;
    dst = func_003DD160(n << 4, 0x10);
    *src |= 0x80000000;
    src[2] = 0x13000000;
    src[3] = 0x51000000 | (n - 1);
    words = n << 2;
    for (i = 0; i < words; i++)
        dst[i] = src[i];
    func_003DC2F0(((u32)dst & 0x0FFFFFFF) | 0x30000000, D_0062BBA0);
    return 1;
}
