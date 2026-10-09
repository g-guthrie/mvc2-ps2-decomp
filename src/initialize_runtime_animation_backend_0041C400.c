typedef signed int s32;

extern s32 func_00131660(void);
extern void func_001E3CE0(s32 mode);
extern s32 func_003298B0(s32 color, s32 duration, s32 mode);
extern void func_0041C460(void);

void func_0041C400(void)
{
    if (func_00131660() != 0)
        func_001E3CE0(2);
    else
        func_001E3CE0(3);

    func_003298B0(-16777216, 10, 1);
    *(void (**)(void))0x0043CD0C = func_0041C460;
}
