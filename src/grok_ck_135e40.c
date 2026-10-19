typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;

extern s32 func_0016D130(u8 *);
extern void func_001E3CE0(u8 *);
extern void func_00135F10(u8 *);
extern float D_0043EDB0[];
extern u32 D_0043ED70[];
extern u8 D_0043EDF0[];

void residual_00135E40(u8 *p)
{
    if (func_0016D130(p))
        return;
    p[4]++;
    p[0x13C] = 1;
    *(s16 *)(p + 0x1C) = 0x3C;
    *(float *)(p + 0x34) = -D_0043EDB0[p[0x20]] / 2.0f;
    *(u32 *)(p + 0x38) = 0xC0C80000;
    *(u32 *)(p + 0x3C) = 0;
    *(u32 *)(p + 0xD8) = D_0043ED70[p[0x20]];
    *(u32 *)(p + 0xDC) = 0;
    if (D_0043EDF0[p[0x20]])
        func_001E3CE0(p);
    func_00135F10(p);
}
