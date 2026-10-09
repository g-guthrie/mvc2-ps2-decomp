#include "sdk_file_types.h"

extern long long func_0011F640(int *, int, void *, int);
int func_0011F9C8(void *cookie, void *buffer, int count)
{
    SdkFile *file = cookie;
    int result = func_0011F640(file->context, file->descriptor, buffer, count);
    if (result >= 0)
        file->position += result;
    else
        file->flags &= 0xEFFF;
    return result;
}
