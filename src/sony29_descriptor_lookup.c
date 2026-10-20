#include "sony29_kernel_semaphore_calls.h"
#include "sony29_fileio_descriptor_types.h"
/* Native IOP descriptor lookup, semaphore ownership and completion requests. */
typedef unsigned char u8;
typedef unsigned int u32;
typedef SonyEeSemaParams SemaParams;
typedef SonyFileDescriptor Descriptor;
extern int D_00438308,D_0043830C;
extern int func_00103DE0(SemaParams *);
extern int func_00103E20(int);
extern int func_00103E00(int);
void func_00107588(void)
{
 SemaParams params;
 if(D_00438308==-1){
  params.init_count=1;
  params.max_count=1;
  params.option=0;
  D_00438308=func_00103DE0(&params);
  D_0043830C=func_00103DE0(&params);
 }
}
Descriptor *func_00107670(unsigned int descriptor)
{
 Descriptor *result;
 func_00107588();
 func_00103E20(D_00438308);
 if(descriptor>=32){func_00103E00(D_00438308);return 0;}
 result=&D_004C6A00[descriptor];
 func_00103E00(D_00438308);
 return result;
}
