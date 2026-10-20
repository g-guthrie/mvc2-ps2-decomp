#include "sony_deci2_call.h"

/* Native Sony DECI2 registration and channel adapter. */
typedef unsigned char u8;
typedef unsigned int u32;
typedef void (*DeciHandler)(int,int,void *);
extern u8 D_004C3570[];
extern int D_00438250;
extern int func_00105480(void);
extern int func_00105260(const char *,int);
int func_00104E40(unsigned short protocol,void *context,DeciHandler handler)
{
 struct {u32 protocol;void *context;DeciHandler handler;void *buffer;} parameters;
 parameters.protocol=protocol;
 parameters.context=context;
 parameters.handler=handler;
 parameters.buffer=(void *)((u32)D_004C3570|0x20000000);
 return func_00104210(1,&parameters);
}
int func_001043A8(unsigned int channel,const char *text,int length)
{
 if(channel-1<2){
  if(!D_00438250){
   if(!func_00105480())return -1;
   D_00438250=1;
  }
  return func_00105260(text,length);
 }
 return -1;
}
