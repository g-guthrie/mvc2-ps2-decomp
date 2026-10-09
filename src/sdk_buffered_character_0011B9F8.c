#include "sdk_file_types.h"
extern int func_001223F0(int character, SdkFile *file);
int func_0011B9F8(int character, SdkFile *file)
{
 return --file->writeCount < 0 ?
  (file->writeCount >= file->lineBufferSize ?
   ((*file->cursor = character, *file->cursor) != '\n' ? *file->cursor++ : func_001223F0('\n', file)) :
   func_001223F0(character, file)) :
  (*file->cursor = character, *file->cursor++);
}
