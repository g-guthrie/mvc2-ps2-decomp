typedef signed int s32;

extern s32 D_004895D0;

void func_0040CA70(s32 mode)
{
    if (mode == 0)
        goto use_default;
    if (mode != 1)
        goto use_default;

    D_004895D0 = mode;
    return;

use_default:
    D_004895D0 = 0x8001;
}
