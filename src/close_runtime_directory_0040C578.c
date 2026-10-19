/* Close all active directory descriptors and report the result. */
#include "runtime_directory_types.h"

typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;
extern s32 D_004895D4;
extern char D_004BE1C0[],D_004BE1E8[],D_004BE208[];
extern void func_0040BF58(char *,char *);
extern s32 func_00108118(s32);
extern s32 func_0011EB60(const char *,...);
extern void func_0040C798(void);
s32 func_0040C578(void){
 char name[256];u8 *base;u32 count,i;s32 successes=0;
 base=D_004895C0.entries;
 if(!base)return 0;
 count=D_004895C0.count;
 for(i=0;i<count;i++){
  char *entry_name=(char *)(base+(D_004895C0.span_count*8+(D_004895C0.name_length+1)*i));
  func_0040BF58(entry_name,name);
  if(*entry_name){
   if(func_00108118(((RuntimeDirectoryEntry *)base)[i].descriptor)<0){
    if(D_004895D4!=2)func_0011EB60(D_004BE1C0,name);
   }else{
    successes++;
    if(D_004895D4!=2)func_0011EB60(D_004BE1E8,name);
   }
  }
 }
 if(D_004895D4!=2)func_0011EB60(D_004BE208,successes);
 func_0040C798();return 1;
}
