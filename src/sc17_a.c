typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern s16 D_00633720[8][8];
s32 func_0041CEE0(s32 *px, s32 *py, s32 dx, s32 dy, s32 cx, s32 cy) {
    extern void func_001E3CE0(s32);
    s32 x = *px;
    s32 y = *py;
    s32 flags = 0;
    s32 n, m;
    n = 8;
    do {
        m = 8;
        do {
            x += dx;
            if (dx != 0) {
                if (x < 0 || x > 7) { y += cy; flags |= 1; }
            }
            y += dy;
            if (dy != 0) {
                if (y < 0 || y > 7) { x += cx; flags |= 1; }
            }
            x = (x + 8) % 8;
            y = (y + 8) % 8;
            if ((D_00633720[x][y] & 0xFFC0) == 0) {
                if (*px != x || *py != y) {
                    func_001E3CE0(1);
                    *px = x;
                    *py = y;
                }
                return flags;
            }
            m--;
        } while (m >= 0);
        n--;
    } while (n > 0);
    return flags;
}
