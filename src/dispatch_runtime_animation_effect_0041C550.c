typedef unsigned char u8;
typedef signed int s32;

extern s32 func_003299D0(void);
extern void func_0041C5B0(u8 *state, u8 *owner);
extern void (*D_0043CD0C)(u8 *state, u8 *owner);

void func_0041C550(u8 *state, u8 *owner)
{
    if (func_003299D0() != 0)
        return;

    D_0043CD0C = func_0041C5B0;
    D_0043CD0C(state, owner);
}
