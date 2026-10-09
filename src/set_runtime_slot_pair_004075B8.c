#include "runtime_message_callback.h"

extern RuntimeMessageCallback D_004872E4;
extern void *D_004872E8;

void func_004075B8(RuntimeMessageCallback callback, void *context)
{
    if (callback == 0) {
        D_004872E4 = 0;
        D_004872E8 = 0;
    } else {
        D_004872E4 = callback;
        D_004872E8 = context;
    }
}
