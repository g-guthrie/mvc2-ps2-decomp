typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef int s32;

struct BackendState
{
    u8 unknown0;
    u8 unknown1;
    s8 selectedBackend;
    u8 unknown3;
    u8 unknown4;
    u8 unknown5;
    u8 unknown6;
    u8 unknown7;
    s16 frameLimit;
};

extern struct BackendState *D_004C2840;
extern s32 func_003299D0(void);
extern s32 func_003298B0(s32 value, s32 duration, s32 mode);
extern void func_00152990(int value);

void func_00420840(void)
{
    s16 frameLimit;

    if (func_003299D0() == 0)
    {
        frameLimit = --D_004C2840->frameLimit;
        if (frameLimit < 0)
        {
            D_004C2840->selectedBackend++;
            func_003298B0(-16777216, 30, 1);
        }
    }
}

void func_004208B0(void)
{
    if (func_003299D0() == 0)
    {
        func_00152990(0);
        D_004C2840->unknown1 = 13;
        D_004C2840->selectedBackend = 0;
        D_004C2840->unknown3 = 0;
        D_004C2840->unknown4 = 0;
        D_004C2840->unknown5 = 0;
        D_004C2840->unknown6 = 0;
        D_004C2840->unknown7 = 0;
    }
}
