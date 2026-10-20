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

void func_00178010(u8 *p)
{
    p[6]++;
    *(f32 *)(p + 0x5C) = *(f32 *)(p + 0x22C);
    *(f32 *)(p + 0x60) = *(f32 *)(p + 0x230);
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x6C) = 0xBFBC9249;
    *(s16 *)(p + 0x1E) = 0;
    func_00178050(p);
}
