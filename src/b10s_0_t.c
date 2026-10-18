typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern void func_003FB510(s32, s32, s32, s32, s32);
extern void func_003F9630(void);
extern void func_003F9660(void);
extern s32 func_003FC978(void);
extern s32 func_003FCB20(s32, s32, s32);
extern void func_003FCCF0(s32);
s32 func_003FCBC0(s32 a, s32 b) {
    s32 r;
    func_003FB510(2, 0, a, b, -1);
    func_003F9630();
    r = func_003FC978();
    if (r != 0) {
        if (func_003FCB20(r, a, b) < 0) {
            func_003F9660();
            func_003FCCF0(r);
            func_003F9630();
            r = 0;
        }
    }
    func_003F9660();
    func_003FB510(2, 1, a, b, -1);
    return r;
}
