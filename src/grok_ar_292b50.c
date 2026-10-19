typedef unsigned char u8;
typedef signed int s32;
typedef float f32;

extern u8 D_004572B0[];
extern void func_00294B20(u8 *, u8 *);
extern int func_001757E0(u8 *, s32, s32);
extern void func_00292C90(u8 *);
extern void func_00292C20(u8 *);

void func_00292B50(u8 *p)
{
    p[7]++;
    p[0x215] = 0;
    p[0x2C2] = 0xFF;
    func_00294B20(p, D_004572B0);
    if (*(f32 *)(p + 0x38) > *(f32 *)(p + 0x430)) {
        p[7] = 2;
        if (!p[0x1E6])
            *(s32 *)(p + 0x5C) = 0x40200000;
        else
            *(s32 *)(p + 0x5C) = 0xC0200000;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x60) = 0x40892492;
        *(s32 *)(p + 0x6C) = 0xBF4DB6DB;
        func_001757E0(p, 0x16, 0x1A);
        func_00292C90(p);
    } else {
        func_001757E0(p, 0x16, 0x19);
        func_00292C20(p);
    }
}
