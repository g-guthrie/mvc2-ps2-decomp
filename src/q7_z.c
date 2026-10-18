typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


void func_00218140(u8 *p) {
    extern s32 func_003D92F0();
    extern void func_001843A0();
    extern s8 func_00175700();
    extern void func_0019B110();
    extern void func_001757E0();
    if (p[0x1E4] == 0x16 && func_003D92F0(p) != 0) {
        func_001843A0(p);
        return;
    }
    switch (p[0x20]) {
    case 0:
    case 2:
    case 4:
        if (p[0x21] == 0) {
            func_00175700(p);
            if (*(s8 *)(p + 0x151) != 0) {
                f32 v;
                p[0x151] = 0;
                v = (f32)*(s8 *)(p + 0x150);
                if (p[0x1E6] != 0) v = -v;
                *(f32 *)(p + 0x34) += v;
            }
        } else {
            if (func_00175700(p) >= 0) {
                if (*(s8 *)(p + 0x151) != 0) {
                    p[0x151] = 0;
                    func_0019B110(p, 6);
                }
            } else {
                p[0x20] = 4;
                func_001757E0(p, 0, 0);
            }
        }
        break;
    case 1:
    case 3:
        func_00175700(p);
        break;
    }
}
