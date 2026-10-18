typedef float f32;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_002C6740(u8 *p) {
    extern s8 func_00175700();
    extern void func_001843A0();
    extern void func_001CEA00();
    switch (p[0x1FC]) {
    case 0:
        if (func_00175700(p) < 0) func_001843A0(p);
        break;
    case 1:
        if (func_00175700(p) < 0) {
            func_001843A0(p);
        } else if (*(s8 *)(p + 0x151) != 0) {
            p[0x151] = 0;
            func_001CEA00(p, 0);
        }
        break;
    case 2:
        if (func_00175700(p) < 0) func_001843A0(p);
        break;
    }
}
