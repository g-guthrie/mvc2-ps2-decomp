#include "sdk_file_types.h"

extern int func_00119E80(void *, int);
int func_0011FB18(void *cookie)
{
 SdkFile *file = cookie;
 return func_00119E80(file->context, file->descriptor);
}
