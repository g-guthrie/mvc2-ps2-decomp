#include "runtime_backend_types.h"
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef int s32;


extern struct BackendState *D_004C2840;
extern s32 func_003299D0(void);
extern void func_003298B0(s32 value, s32 duration, s32 mode);

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
