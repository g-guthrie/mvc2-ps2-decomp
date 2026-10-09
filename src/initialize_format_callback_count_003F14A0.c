typedef signed int s32;

extern s32 D_004C2B04;
extern void func_003F14C0(void *object);

s32 func_003F14A0(void *object)
{
    D_004C2B04 = 0;
    func_003F14C0(object);
    return D_004C2B04;
}
