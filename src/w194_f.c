typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern s32 D_00633690;
extern s32 D_00633694;
extern s32 D_0063369C;
extern s32 D_006336A0;
extern s32 D_006336A4;
extern s32 func_00111480(s32, s32, s32);

s32 func_00419DF0(s32 a, s32 b, s32 c) {
    s32 i;
    if (D_00633694 != 0) return -1;
    if (a >= 2) return -1;
    if (b > 0) return -1;
    i = 0;
    do {
        if (func_00111480(a, b, c) == 0) {
            D_0063369C = a;
            D_00633694 = 0x12;
            D_006336A0 = b;
            D_006336A4 = c;
            if (D_00633690 == 0) {
                D_00633690 = 5;
            }
            return 0;
        }
        i++;
    } while (i < 5);
    return -1;
}
