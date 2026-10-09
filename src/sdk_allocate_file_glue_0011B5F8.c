#include "sdk_file_types.h"
typedef unsigned int u32;
typedef struct SdkFileGlue { struct SdkFileGlue *next; int count; SdkFile *files; } SdkFileGlue;
extern void *func_0011CE68(void *context, u32 size);
extern void *func_0011D8F8(void *dest, int value, u32 size);
SdkFileGlue *func_0011B5F8(void *context, int count)
{
 u32 bytes = (u32)count * sizeof(SdkFile);
 SdkFileGlue *glue = func_0011CE68(context, sizeof(SdkFileGlue) + bytes);
 if (glue == 0) return 0;
 {
  glue->count = count;
  glue->next = 0;
  glue->files = (SdkFile *)(glue + 1);
  func_0011D8F8(glue->files, 0, bytes);
 }
 return glue;
}
