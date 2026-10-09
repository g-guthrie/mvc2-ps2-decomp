#include "sdk_file_types.h"

extern int func_0011B480(SdkFile *);
int func_0011F6A0(SdkFile *file)
{
 if ((file->flags &9)==9) return func_0011B480(file);
 return 0;
}
