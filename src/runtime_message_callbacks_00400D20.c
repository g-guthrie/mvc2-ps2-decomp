#include "runtime_message_callback.h"

extern void func_003FB128(const char *message);

void func_00400D20(void *context, const char *message, s32 reserved)
{
    func_003FB128(message);
}

void func_00400EF0(void *context, const char *message, s32 reserved)
{
    func_003FB128(message);
}
