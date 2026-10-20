#include "sony29_kernel_semaphore_calls.h"
#include "sony29_fileio_descriptor_types.h"
/* Complete native file-service descriptor and bounded-buffer RPCs. */
#include "sony29_fileio_path_requests.h"
typedef unsigned int u32;
typedef unsigned char u8;
typedef SonyEeSemaParams SemaParams;
extern u8 D_004C5500[],D_004C6C00[];
extern int D_004382FC,D_004C6140;
extern int func_00107BC0(void);
extern void func_00107AE8(void);
extern int func_00103DE0(SemaParams *),func_00103DF0(int),func_00103E20(int);
extern int func_00106E68(void *,int,int,void *,int,void *,int,void(*)(void*),void *);
extern void func_00106578(void *,int);


typedef SonyFileDescriptor Descriptor;
extern Descriptor *func_00107670(unsigned int);
typedef SonyFileDescriptorRequest DescriptorRequest;
int func_001098C0(unsigned int descriptor,int value)
{
 DescriptorRequest *request=(DescriptorRequest *)D_004C5500;
 Descriptor *entry=func_00107670(descriptor);
 SemaParams sema;
 int semaphore,accepted,result;
 func_00107AB8(11);
 if(!D_004382FC){func_00107AE8();return -1;}
 if(!entry||!entry->active){func_00107AE8();return -9;}
 request->handle=entry->handle;request->value=value;
 sema.max_count=1;sema.init_count=0;sema.option=0;
 semaphore=func_00103DE0(&sema);
 request->semaphore=semaphore;request->completion=&result;request->completion_size=4;
 if(func_00106E68(D_004C6C00,11,0,D_004C5500,32,&D_004C6140,4,0,0)<0){
  /* Native failure path waits here rather than deleting this semaphore. */
  func_00103E20(semaphore);func_00107AE8();return -11;
 }
 accepted=*(int *)((u32)&D_004C6140|0x20000000u);
 func_00107AE8();
 if(!accepted){func_00103DF0(semaphore);return -11;}
 func_00103E20(semaphore);func_00103DF0(semaphore);return result;
}

typedef struct {int semaphore;int *completion;int completion_size;char path[1024];u8 payload[1024];int value;u32 input_size;void *output;u32 output_size;} BufferRequest;
int func_0010A668(const char *path,int value,const u8 *input,u32 input_size,void *output,u32 output_size)
{
 BufferRequest *request;
 SemaParams sema;
 int length,semaphore,accepted,result;
 func_00107AB8(23);
 request=(BufferRequest *)D_004C5500;
 if(!D_004382FC)func_00107BC0();
 for(length=0;length<1024&&(request->path[length]=path[length]);length++);
 if(length==1024)request->path[1023]=0;
 if(input_size>1024||output_size>1024){func_00107AE8();return -22;}
 for(length=0;length<input_size;length++)request->payload[length]=input[length];
 request->input_size=input_size;request->value=value;
 sema.max_count=1;sema.init_count=0;sema.option=0;
 semaphore=func_00103DE0(&sema);
 request->output_size=output_size;
 request->completion=&result;request->completion_size=4;request->output=output;request->semaphore=semaphore;
 func_00106578(D_004C5500,2076);
 if(func_00106E68(D_004C6C00,23,0,D_004C5500,2076,&D_004C6140,4,0,0)<0){
  func_00103DF0(semaphore);func_00107AE8();return -11;
 }
 accepted=*(int *)((u32)&D_004C6140|0x20000000u);
 func_00107AE8();
 if(!accepted){func_00103DF0(semaphore);return -11;}
 func_00103E20(semaphore);func_00103DF0(semaphore);return result;
}
