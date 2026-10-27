typedef unsigned char u8;
typedef signed int s32;

extern s32 func_003299D0(void);
extern void func_0041C5B0(s32 state, s32 owner);
extern void (*D_0043CD0C)(s32 state, s32 owner);

void func_0041C550(s32 state, s32 owner)
{
    if (func_003299D0() != 0)
        return;

    D_0043CD0C = func_0041C5B0;
    D_0043CD0C(state, owner);
}
