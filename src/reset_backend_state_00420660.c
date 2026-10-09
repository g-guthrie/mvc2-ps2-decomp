#include "runtime_backend_types.h"
typedef unsigned char u8;
typedef int s32;


extern struct BackendState *D_004C2840;
extern s32 func_003299D0(void);
extern void func_00152990(int value);

void func_00420660(void)
{
    if (func_003299D0() == 0)
    {
        func_00152990(0);
        D_004C2840->unknown1 = 1;
        D_004C2840->selectedBackend = 0;
        D_004C2840->unknown3 = 0;
        D_004C2840->unknown4 = 0;
        D_004C2840->unknown5 = 0;
        D_004C2840->unknown6 = 0;
        D_004C2840->unknown7 = 0;
    }
}
