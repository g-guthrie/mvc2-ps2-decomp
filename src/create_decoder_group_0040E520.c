/* Allocate decoder resources, remote state and per-input bindings.
 * The two failure paths intentionally retain separate cleanup counters. */
typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef struct Input Input;
typedef struct {u8 pad[0x24];s32 (*size)(Input *,s32);} InputVtable;
struct Input {InputVtable *vtable;};
typedef struct {s8 used;u8 pad_01[3];void *resource;void *interface;void *stream;unsigned int streamOffset,streamSize;} Resource;
typedef struct RuntimeBinding RuntimeBinding;
typedef struct {
 s8 active;u8 pad[3];s32 count;Resource *resources[2];void *bindings[2];Input *inputs[2];s32 remote;
 u8 flags24[4];s32 field28,field2C,field30,field34; s32 offsets[2],counts[2];u8 flag48,flag49,flag4A,flag4B;s32 field4C,total,maximum;
} DecoderGroup;
extern DecoderGroup D_0048FD38[8];
extern void *func_0011D8F8(void *,s32,unsigned int);
extern Resource *func_0040DF28(void);
extern void func_0040DFA0(Resource *);
extern RuntimeBinding *func_00408DB0(void *,void *);
extern void func_00408EA0(void *);
extern s32 func_00409708(s32,s32 *,s32,s32 *,s32);
extern s32 func_0011EB60(const char *,...);
extern char D_004BE778[],D_004BE7A0[],D_004BE7C8[];
void *func_0040E520(Input **inputs,s32 count){
 DecoderGroup *p; s32 i,args[4],response,total;
 p=D_0048FD38;
 for(i=0;i<8;i++){p=&D_0048FD38[i];if(!p->active)break;}
 if(i==8)return 0;
 func_0011D8F8(p,0,0x58);p->count=count;
 for(i=0;i<count;i++){
  p->resources[i]=func_0040DF28();
  if(!p->resources[i]){s32 j;
   func_0011EB60(D_004BE778);
   for(j=0;j<count;j++)if(p->resources[j])func_0040DFA0(p->resources[j]);
   return 0;
  }
 }
 args[0]=count;args[1]=0;
 for(i=0;i<count;i++)args[i+2]=(s32)p->resources[i]->resource;
 p->remote=func_00409708(8,args,4,&response,1);
 if(!p->remote){func_0011EB60(D_004BE7A0);return 0;}
 for(i=0;i<count;i++){
  p->bindings[i]=func_00408DB0(inputs[i],p->resources[i]->interface);
  if(!p->bindings[i]){s32 j;
   func_0011EB60(D_004BE7C8);
   for(j=0;j<count;j++){
    if(p->bindings[j])func_00408EA0(p->bindings[j]);
    if(p->remote){args[0]=p->remote;func_00409708(9,args,1,0,0);}
    if(p->resources[j])func_0040DFA0(p->resources[j]);
   }
   return 0;
  }
 }
 for(i=0;i<count;i++)p->inputs[i]=inputs[i];
 p->flags24[0]=0;p->flags24[1]=0;p->flags24[2]=count;p->flags24[3]=count;
 p->field30=0;p->field34=0;p->flag4B=0;p->flag4A=0;
 for(i=0;i<count;i++){p->offsets[i]=0;p->counts[i]=0;}
 p->flag48=0;p->flag49=1;p->field4C=0;
 total=inputs[0]->vtable->size(inputs[0],1);
 total+=inputs[0]->vtable->size(inputs[0],0);
 p->total=total;p->maximum=0x4000;p->active=1;return p;
}
