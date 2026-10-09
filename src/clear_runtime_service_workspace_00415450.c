typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

extern s32 D_004C2894;
extern s32 D_004C2898;
extern s32 D_004C289C;
extern u8 D_004F9170[0x24900];
extern u8 D_004F8470[0xD00];
extern u8 D_0051DA70[0x51400];

extern void *func_0011D8F8(void *destination, s32 value, u32 bytes);

void func_00415450(void)
{
    D_004C289C = 0;
    func_0011D8F8(D_0051DA70, 0, sizeof(D_0051DA70));
    D_004C2898 = 0;
    func_0011D8F8(D_004F9170, -1, sizeof(D_004F9170));
    D_004C2894 = 0;
    func_0011D8F8(D_004F8470, 0, sizeof(D_004F8470));
}
