typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern void func_001757E0(u8 *, s32, s32);
extern void func_0028D910(u8 *, s32);
extern s32 func_001C13F0(u8 *, s32);
extern void func_00288140(u8 *);

void residual_00288040(u8 *p)
{
    p[6]++;
    p[0x13C] = 1;
    *(s16 *)(p + 0x1C) = 0x10;
    *(f32 *)(p + 0x38) = 426.6666564941406f + *(f32 *)(p + 0x430);
    *(s32 *)(p + 0x60) = 0xC1892492;
    *(s32 *)(p + 0x6C) = 0xBF4DB6DB;
    func_001757E0(p, 0x12, 0);
    func_0028D910(p, 0);
    func_001C13F0(p, 1);
    func_001C13F0(p, 2);
    func_001C13F0(p, 3);
    func_001C13F0(p, 4);
    func_001C13F0(p, 5);
    func_001C13F0(p, 6);
    func_001C13F0(p, 7);
    func_001C13F0(p, 8);
    *(s32 *)(p + 0x14) = func_001C13F0(p, 0);
    func_00288140(p);
}
