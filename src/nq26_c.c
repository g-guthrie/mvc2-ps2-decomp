typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;


typedef struct { s8 a, b; } T2;
extern s8 D_00489020[];
extern s8 D_004BDC30[];

extern void func_0011FC10(s8 *, s8 *);
extern s32 func_0011FFA0(s8 *);

void func_0040AE10(s8 *s) {
    if (s == 0) {
        D_00489020[0] = 0;
        return;
    }
    if (s[0] != '/' && s[0] != '\\') {
        *(T2 *)D_00489020 = *(T2 *)D_004BDC30;
    } else {
        D_00489020[0] = 0;
    }
    func_0011FC10(D_00489020, s);
    {
        s8 c = s[func_0011FFA0(s) - 1];
        if (c == '/' || c == '\\') {
            D_00489020[func_0011FFA0(D_00489020) - 1] = 0;
        }
    }
}
