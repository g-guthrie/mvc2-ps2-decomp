typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern char D_004BE2F8[], D_004BE348[];
extern void func_0040D5A0(const char *, ...);

s32 func_0040D1D8(u8 *p, s32 idx) {
    s32 n;
    if (p == 0) {
        func_0040D5A0(D_004BE2F8);
        goto fail;
    }
    if (idx < 0 || idx >= *(s32 *)(p + 0x24)) {
        func_0040D5A0(D_004BE348);
        goto fail;
    }
    n = (*(s32 *)(p + 0x20) + idx) % 16;
    return *(s32 *)(p + n * 64 + 0x38);
fail:
    return -1;
}
