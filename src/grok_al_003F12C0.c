typedef signed int s32;

extern s32 D_004C2208;
extern char D_004BAC38[];
extern char D_004BAC48[];
extern char D_004BAC50[];
extern s32 func_0011B9D0(char *, char *);
extern void func_0011B380(s32);
extern void func_00122340(char *, char *, char *);
extern void func_0011BA90(char *, s32);
extern void func_0011B9F8(s32, s32);

void func_003F12C0(char *fmt, ...)
{
    char buf[2048];
    s32 f;
    char *ap;

    if (D_004C2208 != 0) {
        f = func_0011B9D0(D_004BAC38, D_004BAC48);
        D_004C2208 = 0;
        func_0011B380(f);
    }
    f = func_0011B9D0(D_004BAC38, D_004BAC50);
    ap = (char *)__builtin_next_arg(fmt) - 56;
    func_00122340(buf, fmt, ap);
    func_0011BA90(buf, f);
    func_0011B9F8(10, f);
    func_0011B380(f);
}
