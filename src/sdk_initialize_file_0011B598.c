#include "sdk_file_types.h"
extern int func_0011F9C8(void *, void *, int);
extern int func_0011FA30(void *, const void *, int);
extern long long func_0011FAB0(void *, long long, int);
extern int func_0011FB18(void *);
void func_0011B598(SdkFile *file, int flags, int descriptor, void *context)
{
 file->cursor = 0;
 file->readCount = 0;
 file->writeCount = 0;
 file->flags = flags;
 file->descriptor = descriptor;
 file->buffer = 0;
 file->bufferSize = 0;
 file->lineBufferSize = 0;
 file->cookie = file;
 file->read = func_0011F9C8;
 file->write = func_0011FA30;
 file->seek = func_0011FAB0;
 file->close = func_0011FB18;
 file->context = context;
}
