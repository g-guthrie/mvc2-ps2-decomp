typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern s16 D_00633720[8][8];
s32 func_0041D070(s32 *px, s32 *py, s32 dx, s32 dy) {
    extern s32 func_003299D0(s32 *, s32 *, s32, s32);
    extern void func_001E3CE0(s32);
    s32 x = *px;
    s32 y = *py;
    s32 flags = 0;
    s32 n;
    if (func_003299D0(px, py, dx, dy) != 0) return 0;
    n = 8;
    do {
        x += dx;
        if (dx != 0) {
            if (x < 0 || x > 7) flags |= 1;
        }
        y += dy;
        if (dy != 0) {
            if (y < 0 || y > 7) flags |= 1;
        }
        x = (x + 8) % 8;
        y = (y + 8) % 8;
        if ((D_00633720[x][y] & 0xC0) == 0) {
            if (*px != x || *py != y) {
                func_001E3CE0(1);
                *px = x;
                *py = y;
            }
            return flags;
        }
        n--;
    } while (n > 0);
    return flags;
}
