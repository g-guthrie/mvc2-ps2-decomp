typedef signed char s8;
typedef signed int s32;

extern void func_00406688(s8 *a, s8 *b, s8 *c);
extern s32 func_00406440(s8 *a, s8 *b);
extern void func_00405DC8(char *s);
extern char D_004BCC88[];
extern char D_004BCCE0[];
extern char D_004BCD08[];

s32 func_00406C10(s8 *path, s32 arg)
{
    s8 buf[0x130];
    s8 buf2[0x130];
    s32 obj;
    s32 (*fn)(s8 *, s32);
    if (path == 0) {
        func_00405DC8(D_004BCC88);
        return 0;
    }
    func_00406688(buf, buf2, path);
    if (buf2[0] == 0) {
        func_00405DC8(D_004BCC88);
        return 0;
    }
    obj = func_00406440(buf, buf2);
    if (obj == 0)
        func_00405DC8(D_004BCCE0);
    fn = *(s32(**)(s8 *, s32))(obj + 0x5C);
    if (fn == 0) {
        func_00405DC8(D_004BCD08);
        return 0;
    }
    return fn(buf2, arg);
}
