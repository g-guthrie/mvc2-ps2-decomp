typedef signed int s32;

extern s32 D_004C21F0;
extern char D_004BAB80[];
extern char D_004BAB70[];
extern s32 func_00122340(char *, char *, char *);
extern s32 func_0011FFA0(char *);
extern void func_003DCBB0(char *, char *, s32);
extern void func_003DCC70(char *, char *, s32);

s32 func_003ED0D0(char *fmt, ...)
{
    char buf[2056];
    s32 n;
    char *p;
    char *ap;

    ap = (char *)__builtin_next_arg(fmt) - 56;
    n = func_00122340(buf, fmt, ap);
    p = buf + func_0011FFA0(buf);
    p[0] = 13;
    p[1] = 10;
    p[2] = 0;
    if (D_004C21F0) {
        func_003DCBB0(D_004BAB70, D_004BAB80, func_0011FFA0(D_004BAB80));
        D_004C21F0 = 0;
    }
    func_003DCC70(D_004BAB70, buf, func_0011FFA0(buf));
    return 1;
}
