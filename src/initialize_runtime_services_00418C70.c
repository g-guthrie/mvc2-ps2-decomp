typedef unsigned char u8;
typedef signed int s32;

extern u8 D_004BEF00[];
extern u8 D_004BEF20[];
extern void func_003DCAD0(void *object, s32 mode, s32 value, s32 flags);

s32 func_00418C70(void)
{
    func_003DCAD0(D_004BEF00, 0, 0, 0);
    func_003DCAD0(D_004BEF20, 0, 0, 0);
    return 1;
}
