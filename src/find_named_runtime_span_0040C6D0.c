/* Locate a named directory entry and copy its offset/length pair. */
#include "runtime_span_types.h"
extern struct {s32 unknown0,unknown4,span_count,name_length;} D_004895C0;
extern int func_0040C0E0(char *,char *);
void func_0040C6D0(int *output,char *name,u8 *bytes,int count){
 int i;
 struct RuntimeSpan *spans=(struct RuntimeSpan *)bytes;
 for(i=0;i<count;i++){
  if(func_0040C0E0(name,(char *)(bytes+(D_004895C0.span_count*8+(D_004895C0.name_length+1)*i)))==0){
   output[0]=spans[i].start;output[1]=spans[i].length;return;
  }
 }
 output[0]=0;output[1]=0;
}
