typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;


void func_0030A010(u8 *p) {
    extern void func_0030C470();
    extern void func_003BA230(u8 *, s32, u8);
    extern s8 func_00175700();
    extern void func_00184540();
    u8 i;
    switch (p[0x1FC]) {
    case 2:
        if (*(s8 *)(p + 0x151) != 0) {
            *(s8 *)(p + 0x151) = 0;
            func_0030C470(p);
            for (i = 0; i < 3; i++) {
                func_003BA230(p, 2, i);
            }
        }
        break;
    case 1:
        if (*(s8 *)(p + 0x150) != 0) {
            *(s8 *)(p + 0x150) = 0;
            func_003BA230(p, 8, 0);
        }
        break;
    }
    if (func_00175700(p) < 0) {
        func_00184540(p);
    }
}
