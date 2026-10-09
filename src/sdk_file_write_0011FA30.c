#include "sdk_file_types.h"

extern long long func_0011C9B8(void *, int, long long, int);
extern long long func_00122500(int *, int, const void *, int);
int func_0011FA30(void *cookie, const void *buffer, int count)
{
 SdkFile *file = cookie;
 if (file->flags & 0x100)
  func_0011C9B8(file->context, file->descriptor, 0, 2);
 file->flags &= 0xEFFF;
 return (int)func_00122500(file->context, file->descriptor, buffer, count);
}
