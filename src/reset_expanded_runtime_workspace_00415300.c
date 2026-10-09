typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;

extern volatile s32 D_004C28A0;
extern u8 D_0056EE70[0xF700];
extern void func_0011D8F8(void *destination, s32 value, u32 bytes);

void func_00415300(void)
{
    D_004C28A0 = 0;
    func_0011D8F8(D_0056EE70, 0, 0xF700);
}
