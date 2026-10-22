/* sb20_d: Sony 2.9: ./trysony29.sh src/sb20_d.c 0 O2 */
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

typedef struct {int semaphore;int *completion;int completion_size;char first[1024],second[1024];u8 payload[1024];int size;} PayloadOnlyRequest;
int func_001092E0(const char *first,const char *second,const u8 *payload,int size)
{
 PayloadOnlyRequest *request=(PayloadOnlyRequest *)D_004C5500;
 SemaParams sema;
 int length,semaphore,accepted,result;
 func_00107AB8(14);
 if(!D_004382FC)func_00107BC0();
 for(length=0;length<1024&&(request->first[length]=first[length]);length++);
 if(length==1024)request->first[1023]=0;
 if(!second)request->second[0]=0;
 else{
  for(length=0;length<1024&&(request->second[length]=second[length]);length++);
  if(length==1024)request->second[1023]=0;
 }
 if(size>1024){func_00107AE8();return -7;}
 for(length=0;length<size;length++)request->payload[length]=payload[length];
 request->size=size;
 sema.limit=1;sema.initial=0;sema.option=0;
 semaphore=func_00103DE0(&sema);
 request->completion=&result;request->semaphore=semaphore;request->completion_size=4;
 func_00106578(D_004C5500,3088);
 if(func_00106E68(D_004C6C00,14,0,D_004C5500,3088,&D_004C6140,4,0,0)<0){
  func_00103DF0(semaphore);func_00107AE8();return -11;
 }
 accepted=*(int *)((u32)&D_004C6140|0x20000000u);
 func_00107AE8();
 if(!accepted){func_00103DF0(semaphore);return -11;}
 func_00103E20(semaphore);func_00103DF0(semaphore);return result;
}
