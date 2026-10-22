typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* MW 3.0: ./try30.sh src/sa4_a.c "-O3 -sdatathreshold 0" */

void func_001FDAE0(u8 *p) {
    extern void func_001FD910();
    extern void func_001FD950();
    extern s8 func_00175700(u8 *);
    extern void func_00184540(u8 *);
    extern s32 func_001864a0(u8 *);
    extern void func_001865B0(u8 *);
    if (p[0x1FC] == 2) {
        switch (p[6]) {
        case 1:
            func_001FD910();
            if (func_001864a0(p) != 0) {
                func_001865B0(p);
                return;
            }
            break;
        case 2:
            func_001FD950();
            break;
        default:
            if (func_00175700(p) < 0) {
                func_00184540(p);
            }
            if (func_001864a0(p) != 0) {
                func_001865B0(p);
            }
            break;
        }
    } else {
        if (func_00175700(p) < 0) {
            func_00184540(p);
        }
        if (func_001864a0(p) != 0) {
            func_001865B0(p);
        }
    }
}
