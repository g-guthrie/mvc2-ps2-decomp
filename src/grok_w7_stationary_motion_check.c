typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_001843A0(u8 *);

void func_002E5B10(u8 *p)
{
    u8 *state = p + 0x2B8;
    if (state[0] != 0) goto animation_check;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    return;

animation_check:
    if ((s8)func_00175700(p) < 0)
        func_001843A0(p);
}
