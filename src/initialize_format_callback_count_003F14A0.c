typedef unsigned char u8;
typedef signed int s32;

extern s32 D_004C2B04;
extern void func_003F14C0(u8 *object, s32 index);

s32 func_003F14A0(u8 *object, s32 index)
{
    D_004C2B04 = 0;
    func_003F14C0(object, index);
    return D_004C2B04;
}
