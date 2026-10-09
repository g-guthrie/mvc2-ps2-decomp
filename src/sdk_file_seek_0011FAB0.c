#include "sdk_file_types.h"

extern long long func_0011C9B8(void *, int, long long, int);

long long func_0011FAB0(void *cookie, long long offset, int origin)
{
    SdkFile *file = cookie;
    long long result = func_0011C9B8(file->context, file->descriptor, offset, origin);
    if (result == -1)
        file->flags &= 0xEFFF;
    else {
        file->position = (int)result;
        file->flags |= 0x1000;
    }
    return result;
}
