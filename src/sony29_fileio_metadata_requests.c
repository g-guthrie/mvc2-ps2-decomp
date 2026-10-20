/* Complete native file-service metadata, two-path and bounded-payload RPCs. */
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
extern void *memcpy(void *,const void *,unsigned int);

typedef struct {int semaphore;int *completion;int completion_size;char first[1024],second[1024];} TwoPathRequest;
int func_00109DF8(const char *first,const char *second)
{
 TwoPathRequest *request=(TwoPathRequest *)D_004C5500;
 SemaParams sema;
 int length,semaphore,accepted,result;
 func_00107AB8(17);
 if(!D_004382FC)func_00107BC0();
 for(length=0;length<1024&&(request->first[length]=first[length]);length++);
 if(length==1024)request->first[1023]=0;
 for(length=0;length<1024&&(request->second[length]=second[length]);length++);
 if(length==1024)request->second[1023]=0;
 sema.limit=1;sema.initial=0;sema.option=0;
 semaphore=func_00103DE0(&sema);
 request->completion=&result;request->semaphore=semaphore;request->completion_size=4;
 func_00106578(D_004C5500,2060);
 if(func_00106E68(D_004C6C00,17,0,D_004C5500,2060,&D_004C6140,4,0,0)<0){
  func_00103DF0(semaphore);func_00107AE8();return -11;
 }
 accepted=*(int *)((u32)&D_004C6140|0x20000000u);
 func_00107AE8();
 if(!accepted){func_00103DF0(semaphore);return -11;}
 func_00103E20(semaphore);func_00103DF0(semaphore);return result;
}


typedef struct {int semaphore;int *completion;int completion_size,flags;u8 metadata[64],path[1024];} MetadataRequest;
int func_00109BB8(const char *path,const void *metadata,int flags)
{
 MetadataRequest *request=(MetadataRequest *)D_004C5500;
 SemaParams sema;
 int length,semaphore,accepted,result;
 func_00107AB8(13);
 if(!D_004382FC)func_00107BC0();
 for(length=0;length<1024&&(request->path[length]=path[length]);length++);
 if(length==1024){request->path[1023]=0;length=1023;}
 memcpy(request->metadata,metadata,64);
 request->flags=flags;
 sema.limit=1;sema.initial=0;sema.option=0;
 semaphore=func_00103DE0(&sema);
 request->completion=&result;request->semaphore=semaphore;request->completion_size=4;
 func_00106578(D_004C5500,1104);
 if(func_00106E68(D_004C6C00,13,0,D_004C5500,length+81,&D_004C6140,4,0,0)<0){
  func_00103DF0(semaphore);func_00107AE8();return -11;
 }
 accepted=*(int *)((u32)&D_004C6140|0x20000000u);
 func_00107AE8();
 if(!accepted){func_00103DF0(semaphore);return -11;}
 func_00103E20(semaphore);func_00103DF0(semaphore);return result;
}

typedef struct {int semaphore;int *completion;int completion_size;u32 size;void *buffer;char path[1024];} PathBufferRequest;
int func_0010AA80(const char *path,void *buffer,u32 size)
{
 PathBufferRequest *request=(PathBufferRequest *)D_004C5500;
 SemaParams sema;
 int length,semaphore,accepted,result;
 func_00107AB8(17);
 if(!D_004382FC)func_00107BC0();
 for(length=0;length<1024&&(request->path[length]=path[length]);length++);
 if(length==1024)request->path[1023]=0;
 if(size>=1024)size=1023;
 request->buffer=buffer;request->size=size;
 func_00106578(buffer,size);
 sema.limit=1;sema.initial=0;sema.option=0;
 semaphore=func_00103DE0(&sema);
 request->completion=&result;request->semaphore=semaphore;request->completion_size=4;
 if(func_00106E68(D_004C6C00,25,0,D_004C5500,2060,&D_004C6140,4,0,0)<0){
  func_00103DF0(semaphore);func_00107AE8();return -11;
 }
 accepted=*(int *)((u32)&D_004C6140|0x20000000u);
 func_00107AE8();
 if(!accepted){func_00103DF0(semaphore);return -11;}
 func_00103E20(semaphore);func_00103DF0(semaphore);return result;
}

typedef struct {int semaphore;int *completion;int completion_size;char first[1024],second[1024];u8 payload[1024];int value,size;} PayloadRequest;
int func_0010A1A0(const char *first,const char *second,int value,const u8 *payload,int size)
{
 PayloadRequest *request=(PayloadRequest *)D_004C5500;
 SemaParams sema;
 int length,semaphore,accepted,result;
 func_00107AB8(20);
 if(!D_004382FC)func_00107BC0();
 for(length=0;length<1024&&(request->first[length]=first[length]);length++);
 if(length==1024)request->first[1023]=0;
 for(length=0;length<1024&&(request->second[length]=second[length]);length++);
 if(length==1024)request->second[1023]=0;
 if(size>1024){func_00107AE8();return -7;}
 for(length=0;length<size;length++)request->payload[length]=payload[length];
 request->size=size;request->value=value;
 sema.limit=1;sema.initial=0;sema.option=0;
 semaphore=func_00103DE0(&sema);
 request->completion=&result;request->semaphore=semaphore;request->completion_size=4;
 func_00106578(D_004C5500,3092);
 if(func_00106E68(D_004C6C00,20,0,D_004C5500,3092,&D_004C6140,4,0,0)<0){
  func_00103DF0(semaphore);func_00107AE8();return -11;
 }
 accepted=*(int *)((u32)&D_004C6140|0x20000000u);
 func_00107AE8();
 if(!accepted){func_00103DF0(semaphore);return -11;}
 func_00103E20(semaphore);func_00103DF0(semaphore);return result;
}
