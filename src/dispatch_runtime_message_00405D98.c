typedef signed int s32;
#include "runtime_message_callback.h"

extern RuntimeMessageCallback D_004872E4;
extern void *D_004872E8;

void func_00405D98(void *context_slot, const char *message, s32 reserved)
{
    if (D_004872E4 != 0)
        D_004872E4(D_004872E8, message);
}
