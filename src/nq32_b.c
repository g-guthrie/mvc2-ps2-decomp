typedef signed int s32;
extern s32 D_004C2208;
extern char D_004BAC38[], D_004BAC48[], D_004BAC50[];

void func_003F12C0(const char *fmt, ...)
{
    extern s32 func_0011B9D0(char *, char *);
    extern void func_0011B380(s32);
    extern s32 func_00122340(char *, const char *, char *);
    extern void func_0011BA90(char *, s32);
    extern void func_0011B9F8(s32, s32);
    char buf[0x800];
    s32 h;
    char *ap;
    if (D_004C2208 != 0) {
        D_004C2208 = 0;
        func_0011B380(func_0011B9D0(D_004BAC38, D_004BAC48));
    }
    h = func_0011B9D0(D_004BAC38, D_004BAC50);
    ap = ((char *)__builtin_next_arg(fmt) - (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8));
    func_00122340(buf, (const char *)(s32)fmt, ap);
    func_0011BA90(buf, h);
    func_0011B9F8(10, h);
    func_0011B380(h);
}
