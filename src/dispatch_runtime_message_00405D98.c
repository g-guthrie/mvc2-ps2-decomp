#include "runtime_message_callback.h"

extern RuntimeMessageCallback D_004872E4;
extern void *D_004872E8;

void func_00405D98(void *unused_pointer, const char *message, s32 reserved)
{
    /* 00405DC8 passes &D_004872E8 in A0, the message in A1, and zero in A2. */
    if (D_004872E4 != 0)
        D_004872E4(D_004872E8, message, reserved);
}
