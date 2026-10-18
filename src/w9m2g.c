typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2840;
extern s32 func_0012FD70(s32 x);
s32 func_0012FFD0(s32 x) {
    s32 r = (s8)func_0012FD70(x);
    if (r != (s8)x) {
        if (r != 7) {
            D_004C2840[2] = r;
            D_004C2840[4] = 0;
            D_004C2840[3] = 0;
            return 1;
        }
    }
    return 0;
}
