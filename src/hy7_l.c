typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef struct { s32 w; s8 name[12]; } HY7N;
extern HY7N D_0062FB48[];

s32 func_00406050(s8 *x, s32 (*fn)()) {
    extern void func_004061C0();
    extern s32 func_00406128();
    extern s32 func_0011FFA0();
    extern void memcpy();
    s32 r;
    s32 i;
    HY7N *e;
    s8 *dst;
    func_004061C0(x);
    r = fn();
    i = 0;
    if (func_00406128(x) == 0) {
        while (i < 32 && D_0062FB48[i].name[0] != 0) i++;
        if (i == 32) return 0;
        e = &D_0062FB48[i];
        dst = D_0062FB48[0].name + i * 16;
        e->w = r;
        memcpy(dst, x, func_0011FFA0(x) + 1);
    }
    return r;
}
