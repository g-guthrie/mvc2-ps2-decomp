/* Native file-service path request and reply-semaphore ownership. */
#include "sony29_fileio_path_requests.h"
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct {int current,limit,initial,waiters;u32 attributes,option;} SemaParams;
typedef struct {int semaphore;int *completion;int completion_size;char path[1024];} PathRequest;
extern u8 D_004C5500[],D_004C6C00[];
extern int D_004382FC,D_004C6140;
extern int func_00107BC0(void);
extern void func_00107AE8(void);
extern int func_00103DE0(SemaParams *),func_00103DF0(int),func_00103E20(int);
extern int func_00106E68(void *,int,int,void *,int,void *,int,void(*)(void*),void *);
int func_00108F48(const char *path,int operation)
{
 PathRequest *request=(PathRequest *)D_004C5500;
 SemaParams sema;
 int length,semaphore,accepted,result;
 func_00107AB8(operation);
 if(!D_004382FC)func_00107BC0();
 for(length=0;length<1024&&(request->path[length]=path[length]);length++);
 if(length==1024){request->path[1023]=0;length=1023;}
 sema.limit=1;sema.initial=0;sema.option=0;
 semaphore=func_00103DE0(&sema);
 request->completion=&result;request->semaphore=semaphore;request->completion_size=4;
 if(func_00106E68(D_004C6C00,operation,0,D_004C5500,length+13,&D_004C6140,4,0,0)<0){
  func_00103DF0(semaphore);func_00107AE8();return -11;
 }
 accepted=*(int *)((u32)&D_004C6140|0x20000000u);
 func_00107AE8();
 if(!accepted){func_00103DF0(semaphore);return -11;}
 func_00103E20(semaphore);func_00103DF0(semaphore);return result;
}

typedef struct {int semaphore;int *completion;int completion_size,mode;char path[1024];} ModePathRequest;
int func_00109110(const char *path,int mode)
{
 ModePathRequest *request=(ModePathRequest *)D_004C5500;
 SemaParams sema;
 int length,semaphore,accepted,result;
 func_00107AB8(7);
 if(!D_004382FC)func_00107BC0();
 for(length=0;length<1024&&(request->path[length]=path[length]);length++);
 if(length==1024){request->path[1023]=0;length=1023;}
 request->mode=mode;
 sema.limit=1;sema.initial=0;sema.option=0;
 semaphore=func_00103DE0(&sema);
 request->completion=&result;request->semaphore=semaphore;request->completion_size=4;
 if(func_00106E68(D_004C6C00,7,0,D_004C5500,length+17,&D_004C6140,4,0,0)<0){
  func_00103DF0(semaphore);func_00107AE8();return -11;
 }
 accepted=*(int *)((u32)&D_004C6140|0x20000000u);
 func_00107AE8();
 if(!accepted){func_00103DF0(semaphore);return -11;}
 func_00103E20(semaphore);func_00103DF0(semaphore);return result;
}

typedef struct {int semaphore;int *completion;int completion_size,mode;u8 path[1024];} UnsignedModePathRequest;
int func_00109A18(const char *path,int mode)
{
 UnsignedModePathRequest *request=(UnsignedModePathRequest *)D_004C5500;
 SemaParams sema;
 int length,semaphore,accepted,result;
 func_00107AB8(12);
 if(!D_004382FC)func_00107BC0();
 for(length=0;length<1024&&(request->path[length]=path[length]);length++);
 if(length==1024){request->path[1023]=0;length=1023;}
 request->mode=mode;
 sema.limit=1;sema.initial=0;sema.option=0;
 semaphore=func_00103DE0(&sema);
 request->completion=&result;request->semaphore=semaphore;request->completion_size=4;
 if(func_00106E68(D_004C6C00,12,0,D_004C5500,length+17,&D_004C6140,4,0,0)<0){
  func_00103DF0(semaphore);func_00107AE8();return -11;
 }
 accepted=*(int *)((u32)&D_004C6140|0x20000000u);
 func_00107AE8();
 if(!accepted){func_00103DF0(semaphore);return -11;}
 func_00103E20(semaphore);func_00103DF0(semaphore);return result;
}

typedef struct {int semaphore;int *completion;int completion_size,value;} ScalarRequest;
int func_00109550(int value)
{
 ScalarRequest *request=(ScalarRequest *)D_004C5500;
 SemaParams sema;
 int semaphore,accepted,result;
 func_00107AB8(15);
 if(!D_004382FC)func_00107BC0();
 request->value=value;
 sema.limit=1;sema.initial=0;sema.option=0;
 semaphore=func_00103DE0(&sema);
 request->semaphore=semaphore;request->completion=&result;request->completion_size=4;
 if(func_00106E68(D_004C6C00,15,0,D_004C5500,16,&D_004C6140,4,0,0)<0){
  func_00103DF0(semaphore);func_00107AE8();return -1;
 }
 accepted=*(int *)((u32)&D_004C6140|0x20000000u);
 func_00107AE8();
 if(!accepted){func_00103DF0(semaphore);return -1;}
 func_00103E20(semaphore);func_00103DF0(semaphore);return result;
}

typedef struct {int semaphore;int *completion;int completion_size,word12,value;char path[1024];} ExtendedPathRequest;
int func_0010A008(const char *path,int value)
{
 ExtendedPathRequest *request=(ExtendedPathRequest *)D_004C5500;
 SemaParams sema;
 int length,semaphore,accepted,result;
 func_00107AB8(19);
 if(!D_004382FC)func_00107BC0();
 for(length=0;length<1024&&(request->path[length]=path[length]);length++);
 if(length==1024)request->path[1023]=0;
 request->value=value;
 sema.limit=1;sema.initial=0;sema.option=0;
 semaphore=func_00103DE0(&sema);
 request->completion=&result;request->semaphore=semaphore;request->completion_size=4;
 if(func_00106E68(D_004C6C00,19,0,D_004C5500,1044,&D_004C6140,4,0,0)<0){
  func_00103DF0(semaphore);func_00107AE8();return -11;
 }
 accepted=*(int *)((u32)&D_004C6140|0x20000000u);
 func_00107AE8();
 if(!accepted){func_00103DF0(semaphore);return -11;}
 func_00103E20(semaphore);func_00103DF0(semaphore);return result;
}

typedef struct {int semaphore;int *completion;int completion_size;char first[1024],second[1024];} TwoPathRequest;
int func_0010A8A0(const char *first,const char *second)
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
 if(func_00106E68(D_004C6C00,24,0,D_004C5500,2060,&D_004C6140,4,0,0)<0){
  func_00103DF0(semaphore);func_00107AE8();return -11;
 }
 accepted=*(int *)((u32)&D_004C6140|0x20000000u);
 func_00107AE8();
 if(!accepted){func_00103DF0(semaphore);return -11;}
 func_00103E20(semaphore);func_00103DF0(semaphore);return result;
}

/* These five existing entry points forward the callee's signed result. */
int func_001090F0(const char *path){return func_00108F48(path,6);}
int func_001092C0(const char *path){return func_00108F48(path,8);}
int func_00109670(const char *path){return func_00108F48(path,16);}
int func_00109FE8(const char *path){return func_00108F48(path,18);}
int func_0010A410(const char *path){return func_00108F48(path,21);}
