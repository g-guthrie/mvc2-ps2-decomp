#include "stream_group_types.h"
#include "cri_sj_ring_buffer_types.h"
extern s32 func_003F7FC8(u8 *,u16 *,s32);
extern s32 func_003F8120(void *);
extern void func_004104E0(SJCK *,s32,SJCK *,SJCK *);
extern void *memcpy(void *,const void *,u32);
void func_003FF688(StreamGroup *p) {
 SJ_OBJ *resource=(SJ_OBJ *)p->resource;
 u8 *engine=(u8 *)p->engine;
 SJCK chunk,rest;
 s32 parsed,kind;
 resource->vtbl->GetChunk(resource,1,0x1000,&chunk);
 if(chunk.len<16) {resource->vtbl->UngetChunk(resource,1,&chunk);return;}
 parsed=func_003F7FC8(engine,(u16 *)chunk.data,chunk.len);
 if(parsed==0 || chunk.len<parsed){resource->vtbl->UngetChunk(resource,1,&chunk);return;}
 p->result_98=parsed;
 if(func_003F8120(engine)==4)p->mode=1;
 if(func_003F8120(engine)==2)memcpy(p->transfer_buffer,chunk.data,chunk.len<64 ? chunk.len : 64);
 kind=func_003F8120(engine);
 if(kind==10 || kind==20) resource->vtbl->UngetChunk(resource,1,&chunk);
 else {
  func_004104E0(&chunk,parsed,&chunk,&rest);
  resource->vtbl->PutChunk(resource,0,&chunk);
  resource->vtbl->UngetChunk(resource,1,&rest);
 }
 p->lifecycle=2;
}
