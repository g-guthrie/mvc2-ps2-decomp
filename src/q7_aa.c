typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


void func_002C6820(u8 *p) {
    extern s8 func_00175700();
    extern void func_001843A0();
    extern void func_001E3210();
    extern void func_001CEA00();
    u8 *s = p + 0x2B8;
    switch (p[0x1FC]) {
    case 0:
        if (func_00175700(p) < 0) {
            func_001843A0(p);
        }
        break;
    case 1:
        if (func_00175700(p) < 0) {
            func_001843A0(p);
        } else if (*(s8 *)(p + 0x151) != 0) {
            p[0x151] = 0;
            func_001CEA00(p, 2);
        }
        break;
    case 2:
        if (func_00175700(p) < 0) {
            func_001843A0(p);
        } else {
            if (s[2] == 0 && *(s8 *)(p + 0x1B2) != 0) {
                s[2] = 1;
                func_001E3210(p, 3);
            }
            if (*(s8 *)(p + 0x151) != 0) {
                p[0x151] = 0;
                func_001CEA00(p, 3);
            }
        }
        break;
    }
}
