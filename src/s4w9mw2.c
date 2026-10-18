typedef signed int s32;
extern s32 D_00633694;
extern s32 D_006336B4;
extern s32 D_00633690;
extern s32 func_00110FD8(s32);
s32 func_00419C60(s32 p){
    s32 i;
    if (D_00633694 != 0) return -1;
    i = 0;
    do {
        if (func_00110FD8(p) == 0) {
            D_006336B4 = p;
            D_00633694 = 10;
            if (D_00633690 == 0) D_00633690 = 5;
            return 0;
        }
        i++;
    } while (i < 5);
    return -1;
}
