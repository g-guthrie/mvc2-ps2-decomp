typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern s32 D_00633694;
extern s32 D_006336B4;
extern s32 D_006336C0;
extern s32 D_006336C4;
extern s32 D_00633690;
extern s32 func_001104B8(s32, s32, s32);

s32 func_00419AC0(s32 a, s32 b, s32 c)
{
    s32 i;
    if (D_00633694 != 0) {
        return -1;
    }
    i = 0;
    do {
        if (func_001104B8(a, b, c) == 0) {
            D_006336B4 = a;
            D_006336C0 = b;
            D_006336C4 = c;
            D_00633694 = 5;
            if (D_00633690 == 0) {
                D_00633690 = 5;
            }
            return 0;
        }
        i++;
    } while (i < 5);
    return -1;
}
