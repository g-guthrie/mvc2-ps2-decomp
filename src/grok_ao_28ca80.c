typedef unsigned char u8;
typedef signed int s32;
typedef float f32;

extern u8 D_00455FF0[];
extern void func_0028D810(u8 *, u8 *);
extern void func_001E3210(u8 *, s32);
extern void func_001E2490(s32, s32);
extern void func_001757E0(u8 *, s32, s32);
extern void func_0028CBE0(u8 *);
extern void func_0028CB70(u8 *);

void residual_0028CA80(u8 *p)
{
    p[7]++;
    p[0x2C2] = 0xFF;
    func_0028D810(p, D_00455FF0);
    func_001E3210(p, 0x2B);
    func_001E2490(6, 0x48);
    if (*(f32 *)(p + 0x38) > *(f32 *)(p + 0x430)) {
        p[7] = 2;
        if (!p[0x1E6])
            *(s32 *)(p + 0x5C) = 0x40200000;
        else
            *(s32 *)(p + 0x5C) = 0xC0200000;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x60) = 0x40892492;
        *(s32 *)(p + 0x6C) = 0xBF4DB6DB;
        func_001757E0(p, 0x16, 6);
        func_0028CBE0(p);
    } else {
        func_001757E0(p, 0x16, 5);
        func_0028CB70(p);
    }
}
