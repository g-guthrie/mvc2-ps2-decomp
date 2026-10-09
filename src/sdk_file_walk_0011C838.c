#include "sdk_file_types.h"

typedef struct Glue { struct Glue *next; int count; SdkFile *files; } Glue;
int func_0011C838(void *context, int (*callback)(SdkFile *))
{
 Glue *glue;
 SdkFile *file;
 int remaining;
 int result = 0;
 for (glue = (Glue *)((u8 *)context + 0x1D8); glue; glue = glue->next) {
  for (file = glue->files, remaining = glue->count; --remaining >= 0; ++file) {
   if ((s16)file->flags != 0) result |= callback(file);
  }
 }
 return result;
}
