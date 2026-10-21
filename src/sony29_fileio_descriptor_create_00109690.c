#include "sony29_fileio_descriptor_types.h"
#include "sony29_fileio_path_requests.h"
#include "sony29_kernel_semaphore_calls.h"
extern int D_004382FC,D_00438308;
extern int func_00107BC0(void);
extern void func_00107AE8(void);
int func_00109690(const char *path) {
 SonyFileDescriptor *entry;
 int result;
 func_00107AB8(9);
 if(!D_004382FC)func_00107BC0();
 func_00107AE8();
 entry=func_001075E8();
 if(!entry)return -19;
 result=func_00108F48(path,9);
 if(result<0) {
  func_00103E20(D_00438308);
  entry->active=0;
  func_00103E00(D_00438308);
  return result;
 }
 func_00103E20(D_00438308);
 entry->handle=result;
 result=entry-D_004C6A00;
 func_00103E00(D_00438308);
 return result;
}
