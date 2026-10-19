/* Locate a named directory entry and copy its descriptor/length pair. */
#include "runtime_directory_types.h"
extern int func_0040C0E0(char *,char *);
void func_0040C6D0(int *output,char *name,unsigned char *bytes,int count){
 int i;
 RuntimeDirectoryEntry *spans=(RuntimeDirectoryEntry *)bytes;
 for(i=0;i<count;i++){
  if(func_0040C0E0(name,(char *)(bytes+(D_004895C0.span_count*8+(D_004895C0.name_length+1)*i)))==0){
   output[0]=spans[i].descriptor;output[1]=spans[i].length;return;
  }
 }
 output[0]=0;output[1]=0;
}

extern RuntimeDirectory D_00489000;
extern int func_0040A578(char *,char *);
void func_0040A9C8(int *output,char *name,unsigned char *bytes,int count){
 int i;
 RuntimeDirectoryEntry *spans=(RuntimeDirectoryEntry *)bytes;
 for(i=0;i<count;i++){
  if(func_0040A578(name,(char *)(bytes+(D_00489000.span_count*8+(D_00489000.name_length+1)*i)))==0){
   output[0]=spans[i].descriptor;output[1]=spans[i].length;return;
  }
 }
 output[0]=0;output[1]=0;
}
