typedef signed int s32;
typedef unsigned char u8;

extern volatile u8 D_004D0B60[];
extern volatile u8 D_004D0A60[];
extern void func_0041FD10(s32 address);
extern void func_0041FD20(volatile u8 *buffer);

void func_00420310(void)
{
    func_0041FD10((s32)D_004D0B60);
    func_0041FD20(D_004D0A60);
}
