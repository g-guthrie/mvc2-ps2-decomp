#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef struct {u8 direction;s8 target;} ControlPrefix;
typedef struct {u8 current;s8 wait;u8 phase,flags,kind;s8 remaining;u8 cooldown;s8 timer;u8 reload;s8 toggle;u8 quota,special;u8 *source;f32 x,y;u8 gap18[0x11];u8 variation,impact;s8 stepWait,stepIndex;} SequenceContext;
typedef struct {u8 prefix[0x1c];s16 timer,repeat;u8 gap20[0x14];f32 x,y,z;u8 gap40[8];u32 angle;u8 gap4c[4];f32 scaleX,scaleY;u8 gap58[4];f32 vx,vy,vz,ax,ay;u8 gap70[0xd0];s16 facing;} Motion;
extern void func_001E7F60(u8 *);
extern u8 *D_004C2794 __attribute__((section(".sdata")));
#define OWNER(p) (*(u8 **)((p)+0x18))
#define RESET_ACTION(p,code) do {u32 counterAddress;(p)[0x1b5]=(code);(p)[0x1b2]=*(u16 *)((p)+0x1c0)=0;*(u32 *)((p)+0x1d8)=0;counterAddress=(p)[2]*2;counterAddress+=(u32)D_004C2794;counterAddress+=0x7c;++*(s16 *)counterAddress;}while(0)

extern void *func_003DA750(void *,s32,s32);
extern u16 D_004D18DC __attribute__((section(".bss")));
extern u8 D_004D18DB __attribute__((section(".bss")));
extern void func_00353690(u8 *,s8 *,s8 *);
extern void func_00353140(u8 *,u8 *,u8 *);
extern void func_00353430(u8 *,u8 *);
void func_00352990(u8 *p,u8 *context) {
 u8 *owner=OWNER(p);ControlPrefix *control=(ControlPrefix *)(owner+0x2b8);SequenceContext *state=(SequenceContext *)context;Motion *m=(Motion *)p;
 if(owner[0x2bc]==0){p[4]=2;p[0x13c]=0;return;}
 if(D_004D18DC&(1u<<D_004D18DB))return;
 if(state->special)state->current=control->target;
 if(state->current!=control->target) {
  if(--state->wait<0){state->wait=1;if(state->current<control->target)state->current+=16;else state->current-=16;}
 }
 if(state->cooldown)state->cooldown--;
 state->impact=0;state->phase^=2;
 func_00353690(p,(s8 *)context+0x2b,(s8 *)context+0x2c);
 m->facing=*(s16 *)(owner+0x140);p[0x22]=control->direction;if(p[0x22]<8)m->facing^=1;
 if(--state->timer<=0) {
  if(state->timer<0)state->timer=state->reload;
  if(state->timer==0 && (!state->special || state->quota)) {
   u8 *child,*childContext;
   if(state->quota)state->quota--;
   child=(u8 *)func_003DA750(p,1,2);
   if(child){
    *(void **)(child+0x10)=*(void **)(p+0x10);child[0x20]=1;*(u8 **)(child+0x18)=OWNER(p);*(u16 *)(child+0x26)=0x601;
    childContext=child+0x88;*(u8 **)(child+0x94)=p;child[0x8b]=0;child[0xb1]=state->variation;child[0x8c]=0;
    if(--state->remaining<0){state->remaining=2;childContext[4]=255;if(state->special){p[0x1b0]=66;p[0x1b1]=66;}}
   }
  }
 }
 if(--m->timer<0) {
  m->timer=10;
  if(state->special==0 && owner[0x169]!=15){u8 action=owner[0x1b5];if(state->variation){state->toggle=(state->toggle+1)&1;action+=state->toggle;}RESET_ACTION(p,action);func_001E7F60(p);}
 }
 func_00353140(p,context,owner);func_00353430(p,context);p[0x13c]=1;
}
