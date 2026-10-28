typedef unsigned char u8;
typedef signed int s32;
extern s32 D_004C21F0;
extern char D_004BAB70[], D_004BAB80[];
s32 func_003ED0D0(char *fmt, ...)
{
    extern s32 func_00122340(char *, const char *, char *);
    extern s32 func_0011FFA0(char *);
    extern s32 func_003DCBB0(char *, const void *, s32);
    extern s32 func_003DCC70(const char *, const void *, s32);
    char buf[0x800];
    char *ap;
    char *p;
    ap = ((char *)__builtin_next_arg(fmt) - (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8));
    func_00122340(buf, fmt, ap);
    p = buf + func_0011FFA0(buf);
    p[0] = 13;
    p[1] = 10;
    p[2] = 0;
    if (D_004C21F0 != 0) {
        func_003DCBB0(D_004BAB70, D_004BAB80, func_0011FFA0(D_004BAB80));
        D_004C21F0 = 0;
    }
    func_003DCC70(D_004BAB70, buf, func_0011FFA0(buf));
    return 1;
}
