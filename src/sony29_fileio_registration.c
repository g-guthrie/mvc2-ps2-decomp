/* Native file-service completion-hook replacement and descriptor reservation. */
#include "sony29_fileio_path_requests.h"
typedef void (*Completion)(void *);
typedef struct {Completion function;void *argument;} CompletionHook;
typedef struct {int handle,active,word8,word12;} Descriptor;
extern CompletionHook D_004C6C80;
extern Descriptor D_004C6A00[32];
extern int D_004382FC,D_00438308;
extern int func_00107BC0(void),func_0010CA20(void),func_00103E20(int),func_00103E00(int);
extern void func_0010CA68(void),func_00107AE8(void),func_00107588(void);
Completion func_00107AF8(Completion function,void *argument)
{
 CompletionHook *hook=&D_004C6C80;
 Completion old;
 int interrupts;
 func_00107AB8(27);
 if(!D_004382FC)func_00107BC0();
 interrupts=func_0010CA20();
 old=hook->function;
 hook->argument=argument;hook->function=function;
 if(interrupts)func_0010CA68();
 func_00107AE8();return old;
}
Descriptor *func_001075E8(void)
{
 Descriptor *entry;
 func_00107588();
 func_00103E20(D_00438308);
 for(entry=D_004C6A00;entry<D_004C6A00+32;entry++){
  if(!entry->active){
   entry->active=0x10000000;
   func_00103E00(D_00438308);return entry;
  }
 }
 func_00103E00(D_00438308);return 0;
}
