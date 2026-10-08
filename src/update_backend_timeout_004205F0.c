typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef int s32;

struct BackendState
{
    u8 unknown0[2];
    s8 selectedBackend;
    u8 unknown3[5];
    s16 frameLimit;
};

extern struct BackendState *D_004C2840;
extern s32 func_003299D0(void);
extern s32 func_003298B0(s32 value, s32 duration, s32 mode);

void func_004205F0(void)
{
    s16 frameLimit;

    if (func_003299D0() == 0)
    {
        frameLimit = --D_004C2840->frameLimit;
        if (frameLimit < 0)
        {
            D_004C2840->selectedBackend++;
            func_003298B0(-1, 30, 1);
        }
    }
}
