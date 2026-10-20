/* Complete native kernel argument-vector preparation for LoadExecPS2/ExecOSD. */
#include "sony29_exec_arguments.h"
typedef struct {int number;void *handler;} KernelHook;
extern char *D_004386A0;
extern KernelHook D_00439158;
extern void func_0010CEA8(int,void *);
extern int func_0010CE68(void *,const void *,int);
extern unsigned int func_0011FFA0(const char *);
char *func_0010CEB8(const char *filename,int argc,char *const *argv)
{
 char *table=D_004386A0;
 char *text=table+64;
 char *first=text;
 int length;
 func_0010CEA8(D_00439158.number,D_00439158.handler);
 if(argc>15)argc=15;
 func_0010CE68(table,&text,sizeof(text));table+=4;
 length=func_0011FFA0(filename)+1;
 func_0010CE68(text,filename,length);text+=length;
 if(argc>0){
  char *const *cursor=argv;
  do{
   func_0010CE68(table,&text,sizeof(text));table+=4;
   argc--;
   length=func_0011FFA0(*cursor)+1;
   func_0010CE68(text,*cursor++,length);text+=length;
  }while(argc);
 }
 return first;
}
