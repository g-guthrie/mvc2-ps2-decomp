typedef signed char s8;
typedef signed int s32;

extern void func_00406688(s8 *a, s8 *b, s8 *c);
extern s32 func_00406440(s8 *a, s8 *b);
extern void func_00405DC8(char *s);
extern char D_004BCBF0[];
extern char D_004BCC40[];
extern char D_004BCC68[];

s32 func_00406B50(s8 *path)
{
    s8 buf[0x130];
    s8 buf2[0x130];
    s32 obj;
    s32 (*fn)(s8 *);
    if (path == 0) {
        func_00405DC8(D_004BCBF0);
        return 0;
    }
    func_00406688(buf, buf2, path);
    if (buf2[0] == 0) {
        func_00405DC8(D_004BCBF0);
        return 0;
    }
    obj = func_00406440(buf, buf2);
    if (obj == 0) {
        func_00405DC8(D_004BCC40);
        fn = 0;
    } else {
        fn = *(s32(**)(s8 *))(obj + 8);
    }
    if (fn == 0) {
        func_00405DC8(D_004BCC68);
        return 0;
    }
    return fn(buf2);
}
