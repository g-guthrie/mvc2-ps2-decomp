typedef unsigned char u8;
typedef signed int s32;

extern volatile s32 D_00633E18;
extern volatile s32 D_00633E20;
extern volatile s32 D_00633E28;
extern volatile u8 D_00633E30[512];

#pragma padloop on
void func_00422CC0(void)
{
    s32 index;
    s32 offset;

    D_00633E18 = 0;
    D_00633E28 = 0;
    D_00633E20 = 0;

    index = 63;
    offset = 504;
    do {
        *(volatile s32 *)(D_00633E30 + offset) = -1;
        index--;
        offset -= 8;
    } while (index >= 0);
}
