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
