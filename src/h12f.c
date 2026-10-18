typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_0016A1F0(void *p, s32 a);
extern s32 func_0016A130(void *p, s32 a, s32 b);
s32 func_001690F0(u8 *p, s32 n) {
    u32 a, b;
    if (n > 3) return 0;
    if (p[0x215] != 0) return func_0016A1F0(p, 6);
    a = p[0x1E4];
    b = p[0x1E5];
    if (a == b) return 1;
    if (b == 0x13) {
        if (a == 0x12) goto A;
        return func_0016A130(p, 6, 3);
    }
    A:
    return func_0016A1F0(p, 6);
}
