typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_00448BB0[];
extern void func_00185490(u8 *);
extern void func_001757E0(u8 *, s32, s32);

void residual_0017C360(u8 *p)
{
    p[0x201] = 2;
    jtbl_00448BB0[p[6]](p);
}

void func_0017C390(u8 *p)
{
    p[6]++;
    *(s16 *)(p + 0x1C) = 0x10;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    p[0x20D] = 0;
    func_00185490(p);
    func_001757E0(p, 0x18, 0);
}
