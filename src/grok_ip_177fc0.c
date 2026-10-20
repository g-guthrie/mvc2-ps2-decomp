typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;
typedef void (*DispatchFn)(u8 *);

extern u8 D_004D18A0;
extern DispatchFn jtbl_00448970[];
extern void func_00178050(u8 *);

void func_00177FC0(u8 *p)
{
    if (D_004D18A0 < 5 && p[0x1F0] != 0 && p[0x24C] != 0)
        p[0x201] = 2;
    jtbl_00448970[p[6]](p);
}
