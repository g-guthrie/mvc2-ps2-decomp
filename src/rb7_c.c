typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern char D_004AB1B0[];
extern char D_004AB1C0[];
extern void func_00105E80();
extern void func_00106628();
extern void func_001067C8();
extern s32 func_0010BEF8();

s32 func_0010C098(char *s)
{
    char buf[0x50];
    char *d;
    char *a;
    char *t;
    char *b;
    u32 n;

    t = s;
    a = D_004AB1B0;
    while (*s) s++;
    b = t - 11;
    n = s - b;
    if (n >= 0x51) {
        func_00105E80(D_004AB1C0, t);
        return 0;
    }
    func_00106628(0);
    func_001067C8();
    d = buf;
    while (*a) {
        *d++ = *a++;
    }
    while (*t) {
        *d++ = *t++;
    }
    *d = 0;
    return func_0010BEF8(buf, 0);
}
