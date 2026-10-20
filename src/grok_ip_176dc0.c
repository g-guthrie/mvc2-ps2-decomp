typedef unsigned char u8;
typedef signed int s32;
typedef float f32;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_004BF4C0[2];
extern void func_00176E20(u8 *);

void func_00176DC0(u8 *p)
{
    p[0x201] = 2;
    p[0x1B1] = 0;
    jtbl_004BF4C0[p[6]](p);
}

void func_00176DF0(u8 *p)
{
    p[6]++;
    *(f32 *)(p + 0x5C) = *(f32 *)(p + 0x22C);
    *(f32 *)(p + 0x60) = *(f32 *)(p + 0x230);
    *(s32 *)(p + 0x68) = 0;
    func_00176E20(p);
}
