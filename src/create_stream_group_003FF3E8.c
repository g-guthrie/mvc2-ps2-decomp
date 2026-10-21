#include "stream_group_types.h"
#include "runtime_stream_query.h"
/* Allocate a 0x9C-byte stream group, initialize its engine and register
 * the position/availability callback. The two stream slots at 0x0C precede
 * the request spans beginning at 0x1C, as consumed by func_003FF810. */
extern s32 func_0040FCD0(void *),func_0040FCD8(void *),func_0040FCE0(void *);
extern void *func_003F7C38(s32,s32,s32,s32);
extern void func_003FF3B0(void *);
void *func_003FF3E8(void *resource,s32 count,void **streams){
 s32 slot,i,position,half,tail;StreamGroup *scan;StreamGroup *p;void *first=streams[0];void *engine;
 slot=0;scan=D_00484100;
 for(;slot<16;slot++,scan++){if(!scan->active)break;}
 if(slot==16)return 0;
 p=&D_00484100[slot];
 position=func_0040FCD0(first);
 half=func_0040FCD8(first)/2;
 tail=func_0040FCE0(first)/2;
 engine=func_003F7C38(count,position,half,half+tail);
 p->engine=engine;
 if(!engine)return 0;
 func_003F80F8(engine,func_003FF810,p);
 p->resource=resource;p->stream_count=count;
 i=0;if(count>0){do{p->streams[i]=streams[i];i++;}while(i<count);}
 p->lifecycle=0;func_003FF3B0(p);
 p->callback_48=0;p->callback_argument_4c=0;p->callback_50=0;p->callback_argument_54=0;p->active=1;
 return p;
}
