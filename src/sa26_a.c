typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u32 func_0011FFA0(char *s);

void func_00409AE0(char *s) {
    u32 n = func_0011FFA0(s);
    u32 i;
    for (i = 0; i < n; i++) {
        if (s[i] == '/') {
            s[i] = '\\';
        }
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] -= 0x20;
        }
    }
}

extern u8 D_006300C0[];
extern s32 D_00489000;
extern s32 D_00489018;
extern u8 D_004BDCF0[];
extern u8 D_004BDD18[];

s32 func_0040ACA0(u8 *a, u8 *b, s32 c) {
    extern void func_0011D8F8(u8 *, s32, s32);
    extern void func_0040AA90(void);
    extern s32 func_0040A740(u8 *, u8 *);
    extern void func_0011EB60(u8 *, u8 *);
    extern void func_004098A8(s32, u8 *);
    extern s32 func_0040A610(u8 *, u8 *, s32, s32);
    extern s32 func_0040A838(u8 *, s32);
    s32 r;
    s32 t;
    register s32 d __asm__("$2");
    func_0011D8F8(D_006300C0, 0, 0x1000);
    d = D_00489000;
    if (d == 0) {
        func_0040AA90();
    }
    if (a == 0 || b == 0 || c == 0) {
        func_0040AA90();
        return 0;
    }
    r = func_0040A740(a, D_006300C0);
    if (r == 0) {
        if (D_00489018 != 2) {
            func_0011EB60(D_004BDCF0, a);
        }
        func_004098A8(0, D_004BDD18);
        return 0;
    }
    t = func_0040A838(b, func_0040A610(b, D_006300C0, c / 137, 0x81));
    return t * 137;
}
