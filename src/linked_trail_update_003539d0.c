/* Maintain the linked trail, its native work fields, and spawned callbacks. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct {float x,y,z;} Vec3;
typedef void (*ActorCallback)(u8 *);
typedef struct {
 s8 active;u8 phase,flag;s8 spawnCountdown;u8 *parent;
 s16 rotation[3];s8 cooldown;u8 tail;
} TrailWork;
typedef struct {
 u8 pad0[2],team,pad3,phase,pad5[0xB];ActorCallback callback;u8 pad14[4];u8 *owner;s16 timer;
 u8 pad1E[6];s8 layer;u8 pad25[0xF];Vec3 position;u8 pad40[0x48];TrailWork state;
 u8 pad98[0xA4],visible,pad13D[3];s16 facing;u8 pad142[0x6E],color,pad1B1,hit,pad1B3[2],category,pad1B6[0xA];
 u16 flags;u8 pad1C2[0x16];u32 status;
} TrailActor;

typedef struct {u8 prefix[0x7C];s16 count[];} CounterView;
extern u16 D_004D18DC;
extern u8 D_004D18DB;
extern CounterView *D_004C2794 __attribute__((section(".sdata")));
extern u8 *D_004C2840 __attribute__((section(".sdata")));
extern void *func_003DA750(void *,int,int);
extern int func_00175910(u8 *,int,int,int);
void func_003539D0(u8 *actor)
{
 u8 *owner;
 TrailWork *state;
 u8 *spawned;
 TrailActor *p=(TrailActor*)actor;
 int animation;
 owner=p->owner;state=&p->state;
 animation=*(u16*)(owner+0x168);
 if(animation!=0x1600&&animation!=0x1608&&animation!=0x1609) {
  p->phase=2;p->visible=0;return;
 }
 {
  int active=*(s8*)(owner+0x2B9);
  state->active=active;
  if(active<0) {p->phase=2;p->visible=0;return;}
 }
 if(D_004D18DC&(1<<D_004D18DB))return;
 { s8 cooldown=state->cooldown;
 if(cooldown) {
  cooldown--;state->cooldown=cooldown;
  if(cooldown<=0) {
   state->rotation[0]=0;state->rotation[1]=0;state->rotation[2]=0;
  }
 }
 }
 if((spawned=func_003DA750(actor,1,2))!=0) {
  TrailWork *childState=(TrailWork*)(spawned+0x88);
  u8 *child;
  *(ActorCallback*)(spawned+0x10)=p->callback;
  *(u8**)(spawned+0x18)=p->owner;
  spawned[0x20]=1;spawned[0x21]=1;
  spawned[0x8A]=0;spawned[0x89]=0;
  *(s16*)(spawned+0x92)=0;*(s16*)(spawned+0x94)=0;
  *(u8**)(spawned+0x8C)=actor;
  { s8 index=state->spawnCountdown-1;
    state->spawnCountdown=index;
    if(index<0) {state->spawnCountdown=5;childState->flag=255;}
  }
  child=func_003DA750(0,1,1);
  if(child) {
   *(ActorCallback*)(child+0x10)=p->callback;
   *(u8**)(child+0x18)=p->owner;
   *(u8**)(child+0x14)=spawned;child[0x20]=1;child[0x21]=2;
  }
 }
 { s16 timer=p->timer-1;
 p->timer=timer;
 if(timer<0) {
  p->timer=4;p->color=66;
  p->category=owner[0x1B5];p->hit=p->flags=0;p->status=0;
  D_004C2794->count[p->team]++;
 }
 }
 p->position=*(Vec3*)(owner+0x34);
 {
  float x=-93.3333282470703125f;
  float y;
  if(owner[0x20D]==2)x=-65.0f;
  if(p->facing)x=-x;
  p->position.x+=x;
  y=192.8571319580078125f;
  if(owner[0x20D]==2)y=229.28570556640625f;
  p->position.y+=y;
 }
 p->layer=*(s8*)(owner+0x24);
 func_00175910(actor,22,2,(*(u32*)(D_004C2840+0x1C)&1)*19);
 p->visible=1;
}
