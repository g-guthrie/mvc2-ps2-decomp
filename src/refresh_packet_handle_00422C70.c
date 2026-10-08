typedef signed int s32;

extern volatile s32 D_004C2538;
extern s32 func_00103E20(s32 handle);
extern s32 func_00103E00(s32 handle);
extern void func_00422CC0(void);

void func_00422C70(void)
{
    s32 handle;

    handle = D_004C2538;
    if (handle >= 0)
        func_00103E20(handle);
    func_00422CC0();
    handle = D_004C2538;
    if (handle >= 0)
        func_00103E00(handle);
}
