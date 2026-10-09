typedef signed char s8;
typedef signed int s32;

extern s8 D_004872F1;
extern s32 func_004087A0(void);
extern s32 func_004087B8(void);

s32 func_00408808(void)
{
    s8 mode = D_004872F1;
    if (mode == 1)
        return (s32)((unsigned int)func_004087A0() * 2u);
    if (mode == 2)
        return func_004087B8();
    return 0;
}
