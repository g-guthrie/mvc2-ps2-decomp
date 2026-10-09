#include "runtime_message_callback.h"

extern RuntimeMessageCallback D_00488314;
extern void *D_00488318;

void func_004098A8(s32 auxiliary, const char *message)
{
    if (D_00488314 != 0)
        D_00488314(D_00488318, message, auxiliary);
}
