typedef signed int s32;
typedef signed char s8;
extern s32 D_004C2450;
extern char D_004BD908[];
extern s32 func_0011F938(char *, char *, s32);
s32 func_004091A8(s32 a, char *buf, s32 n) {
    s32 i, r;
    for (i = 0; i < n; i++) buf[i] = 0xAA;
    r = func_0011F938(buf, D_004BD908, D_004C2450);
    D_004C2450++;
    return r;
}
