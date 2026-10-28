typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern char D_004BBF18[];

s32 func_00400468(s32 a, s32 b, s32 c)
{
    extern s32 func_00406B50(void *);
    extern s32 func_00406C10(void *, s32);
    extern s32 func_004064E8(s32, s32, s32);
    extern s32 func_00400258(s32, s32, s32, s32);
    extern void func_00400658(s32, s32);
    extern void func_003FB178(char *, s32);
    s32 r, v, w;
    if (b == 0) {
        v = func_00406B50((void *)(u32)a);
    } else {
        v = func_00406C10((void *)(u32)a, b);
    }
    r = func_004064E8(a, b, 0);
    if (r == 0) {
        func_003FB178(D_004BBF18, a);
        return 0;
    }
    w = func_00400258(r, 0, v, c);
    if (w != 0) func_00400658(w, 0);
    return w;
}
