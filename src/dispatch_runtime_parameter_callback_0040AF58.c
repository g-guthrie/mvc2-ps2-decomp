#include "runtime_message_callback.h"

extern RuntimeMessageCallback D_004891AC;
extern void *D_004891B0;

void func_0040AF58(s32 auxiliary, const char *message)
{
    if (D_004891AC != 0)
        D_004891AC(D_004891B0, message, auxiliary);
}
