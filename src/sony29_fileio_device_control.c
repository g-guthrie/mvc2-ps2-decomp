/* Complete native file-service descriptor device-control request. */
#include "sony29_fileio_path_requests.h"
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct {int current,limit,initial,waiters;u32 attributes,option;} SemaParams;
extern u8 D_004C5500[],D_004C6C00[];
extern int D_004382FC,D_004C6140;
extern int func_00107BC0(void);
extern void func_00107AE8(void);
extern int func_00103DE0(SemaParams *),func_00103DF0(int),func_00103E20(int);
extern int func_00106E68(void *,int,int,void *,int,void *,int,void(*)(void*),void *);
extern void func_00106578(void *,int);


typedef struct {int handle,active,word8,word12;} Descriptor;
extern Descriptor *func_00107670(unsigned int);
extern void *func_0011D740(void *,const void *,unsigned int);
typedef struct {
 int semaphore;int *completion;int completion_size,handle,operation;
 u8 input[1024];void *output;u32 output_size,input_size;
} DeviceRequest;
int func_00108D68(u32 descriptor,int operation,const void *input,u32 input_size,void *output,u32 output_size)
{
 DeviceRequest *request=(DeviceRequest *)D_004C5500;
 Descriptor *entry=func_00107670(descriptor);
 SemaParams sema;
 int semaphore,accepted,result;
 func_00107AB8(26);
 if(!D_004382FC)func_00107BC0();
 if(!entry||!entry->active){func_00107AE8();return -9;}
 if(input_size>1024||output_size>1024){func_00107AE8();return -22;}
 /* Native NULL-input path zeros this word before the descriptor read;
  * the incoming size is assigned again below. */
 if(!input)request->input_size=0;
 else func_0011D740(request->input,input,input_size);
 request->handle=entry->handle;request->operation=operation;request->input_size=input_size;
 sema.limit=1;sema.initial=0;sema.option=0;
 semaphore=func_00103DE0(&sema);
 request->output_size=output_size;request->completion=&result;request->completion_size=4;
 request->output=output;request->semaphore=semaphore;
 func_00106578(D_004C5500,1056);
 if(func_00106E68(D_004C6C00,26,0,D_004C5500,1056,&D_004C6140,4,0,0)<0){
  func_00103DF0(semaphore);func_00107AE8();return -11;
 }
 accepted=*(int *)((u32)&D_004C6140|0x20000000u);
 func_00107AE8();
 if(!accepted){func_00103DF0(semaphore);return -11;}
 func_00103E20(semaphore);func_00103DF0(semaphore);return result;
}
