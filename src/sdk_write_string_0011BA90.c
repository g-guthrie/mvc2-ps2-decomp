#include "sdk_file_types.h"
typedef unsigned int u32;
typedef struct SdkIoVector { const void *base; u32 length; } SdkIoVector;
typedef struct SdkIoRequest { SdkIoVector *vectors; int count; u32 residual; } SdkIoRequest;
extern u32 func_0011FFA0(const char *);
extern int func_0011C458(SdkFile *, SdkIoRequest *);
int func_0011BA90(const char *text, SdkFile *file)
{
 SdkIoRequest request;
 SdkIoVector vector;
 vector.base = text;
 vector.length = request.residual = func_0011FFA0(text);
 request.vectors = &vector;
 request.count = 1;
 return func_0011C458(file, &request);
}
