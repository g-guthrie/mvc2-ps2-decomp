typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef float f32;

extern s32 func_00333950();
void func_003338C0(u8 *p) {
    u32 t;
    *(u32 *)(p + 0x44) = (u16)((u32)(s32)(0.5 + 65536.0 * *(f32 *)(p + 0x50) / 360.0));
    if (func_00333950(p) != 0) {
        p[5] = 1;
        t = p[6];
        p[6] = t + 1;
    }
}

