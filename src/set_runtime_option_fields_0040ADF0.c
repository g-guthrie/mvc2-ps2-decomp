typedef unsigned char u8;
typedef signed int s32;

extern u8 D_00489010[3];
extern s32 D_00489014;

void func_0040ADF0(s32 first, s32 second, s32 third, s32 word)
{
    D_00489014 = word;
    D_00489010[0] = first;
    D_00489010[1] = second;
    D_00489010[2] = third;
}
