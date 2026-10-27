typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

struct PW;
extern s32 func_001E81C0(u8 *, struct PW *, int);

s32 func_001E8110(u8 *a, u8 *b, s32 c)
{
    s32 t = b[0x20D];
    if (t == 3) {
        return 0;
    }
    if (b[5] == 2) {
        return 0;
    }
    if (a[0x20D] == 2) {
        if (t != 2) {
            return 0;
        }
    } else {
        if (t == 2) {
            return 0;
        }
        if (!(*(f32 *)(b + 0x38) < 32.14285659790039f + *(f32 *)(b + 0x430))) {
            return 0;
        }
    }
    return func_001E81C0(a, (struct PW *)b, c);
}
