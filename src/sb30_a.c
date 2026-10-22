typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_001FD6B0(u8 *p) {
    extern s8 func_00175700();
    extern void func_001843A0();
    extern void func_001FD510();
    extern void func_001FD5B0();
    extern void func_001FD670();
    switch (p[0x1FC]) {
    case 0:
    case 1:
        if (func_00175700(p) < 0) func_001843A0(p);
        break;
    case 2:
        if (p[6] == 0) {
            if (func_00175700(p) < 0) func_001843A0(p);
        } else {
            switch (p[7]) {
            case 0:
                func_001FD510(p);
                break;
            case 1:
                func_001FD5B0(p);
                break;
            case 2:
                func_001FD670(p);
                break;
            }
        }
        break;
    }
}
