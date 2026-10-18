typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_0016A1F0(void *p, s32 a);
extern s32 func_0016A130(void *p, s32 a, s32 b);
s32 func_00169310(u8 *p, s32 n) {
    u8 *q = *(u8 **)(p + 0x220);
    if (n > 3) {
        return 0;
    }
    if (p[0x215] != 0 || p[0x20D] == 2 || q[0x1E4] != 10) {
        return func_0016A1F0(p, 10);
    }
    return func_0016A130(p, 10, 3);
}
