/* Run the counted emission stream with its unsigned header and signed countdown views. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern int func_001757E0(u8 *,int,int);
typedef struct {u8 pad0[4],phase,pad5[0x17];short timer;unsigned short remaining;u8 choice,savedFacing,pad22[2];s8 layer;u8 pad25[0xB];s8 group;u8 pad31[3];V3 position;u8 pad40[0x10];V3 scale;f32 vx,vy,vz,ax,ay;u8 pad70[0xCC],visible,pad13D[3];short facing;u8 pad142[0x75],mode,variant;} Actor;
typedef unsigned short u16;
typedef struct {s32 word[49];} State;
extern u16 D_0044EEA0[];
extern u8 *func_001DF540(u8 *,s32);
extern void func_003DAA40(u8 *);
void func_001DF670(u8 *actor,u8 *parent) {
 Actor *p=(Actor*)actor,*owner=(Actor*)parent;
 if(p->phase==0) {
  u16 *initial;
  ++p->phase;*(State*)(actor+0xEC)=*(State*)(parent+0xEC);
  p->visible=1;actor[2]=parent[2];actor[1]=parent[1];
  p->scale.x=owner->scale.x;p->scale.y=owner->scale.y;
  p->mode=owner->mode;p->variant=owner->variant;p->group=owner->group;
  p->scale=owner->scale;p->layer=owner->layer;p->visible=0;
  initial=D_0044EEA0;
  if((p->remaining=*initial++)==0) {func_003DAA40(actor);return;}
  p->timer=*initial++;*(u16**)(actor+0x14)=initial;
 }
 if(actor[5]==0) {
  if(--p->timer<0) {
   u16 *stream=*(u16**)(actor+0x14);
   func_001DF540(actor,stream[0]);
   p->timer=stream[1];*(u16**)(actor+0x14)=stream+2;
   if(--*(short*)&p->remaining<=0)++actor[5];
  }
 } else p->phase=2;
}
