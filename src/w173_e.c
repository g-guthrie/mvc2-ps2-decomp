typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

#define Q (*(u8 **)(p + 0x1DC))

void func_002222F0(u8 *p)
{
    extern s8 func_00175700(u8 *);
    extern void func_00184540(u8 *);
    extern void func_00126400(void);
    if (*(s8 *)(p + 0x151) <= 0) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    }
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (func_00175700(p) < 0) {
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        func_00184540(p);
        return;
    }
    if (*(s8 *)(p + 0x151) < 0) {
        p[0x151] = 0;
        *(u32 *)(Q + 0x1C8) = (u32)p;
        Q[0x20A] = 1;
        Q[0x1E6] = *(s8 *)(p + 0x1E6) ^ 1;
        Q[0x1B5] = 0x20;
        Q[0x20D] = 2;
        *(u32 *)(p + 0x5C) = 0;
        func_00126400();
    }
}
