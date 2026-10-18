typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2840;
extern s32 D_004D17B8[], D_004D17BC[];
void func_0012FB90(s32 flag)
{
    extern void func_00131340();
    s32 v = ((s8 *)D_004C2840)[0x4C];
    switch (v) {
    case 0:
        func_00131340(-0x64);
        if (((s8 *)D_004C2840)[0x88] == 3) func_00131340(-0x64);
        break;
    case 1:
    case 7:
        func_00131340(-0x64);
        break;
    case 5:
    case 2:
        break;
    }
    if (flag) {
        D_004D17B8[0] = 0;
        D_004D17BC[0] = 0;
    }
}
