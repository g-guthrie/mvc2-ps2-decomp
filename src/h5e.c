typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern double func_00119058(float);
extern s32 func_003333C0(u8 *);
void func_00333330(u8 *p) {
    *(s32 *)(p + 0x40) = (u16)((u32)(s32)(0.5 + 65536.0 * func_00119058(*(f32 *)(p + 0x50)) / 360.0));
    if (func_003333C0(p) != 0) {
        u32 t;
        p[5] = 1;
        t = p[6];
        p[6] = t + 1;
    }
}
