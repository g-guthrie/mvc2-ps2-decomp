typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern s32 D_004BEDA0[];
extern s32 D_00633694, D_006336B4, D_00633690;
extern s32 func_00110298(s32);
s32 func_00419950(s32 a) {
    s32 i;
    if (D_00633694 != 0) return -1;
    i = 0;
    do {
        if (func_00110298(a) == 0) {
            D_006336B4 = a; D_00633694 = 3;
            if (D_00633690 == 0) D_00633690 = 5;
            return 0;
        }
        i++;
    } while (i < 5);
    return -1;
}
