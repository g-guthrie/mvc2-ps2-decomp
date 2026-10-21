#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef struct {f32 x,y,z;} V3;
#include "actor_inherited_state.h"

extern void func_001D8A00(u8 *);
extern int func_00175580(u8 *,int,int,int);
typedef struct {s16 frame,x,y,flags;} CycleFrame;
extern const CycleFrame D_0044E700[2][9];
typedef struct {u8 prefix[0x1C];s16 timer,count;} ActorTimer;
typedef struct {u8 prefix[0x34];f32 x,y,z;} ActorPosition;
void func_001D8700(u8 *p) {
 ActorPosition *position=(ActorPosition *)p;
 u8 *q=*(u8 **)(p+0x18);
 const CycleFrame *record;
 p[0x13C]=0;
 if(q[0x1E4]!=21 || (q[6]!=9 && q[6]!=10)) {func_001D8A00(p);return;}
 *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
 *(V3 *)(p+0x34)=*(V3 *)(q+0x34);
 record=&D_0044E700[p[0x20]][((ActorTimer *)p)->timer];
 ((ActorTimer *)p)->timer=(((ActorTimer *)p)->timer+1)%9;
 if(record->frame>0) {
  f32 dx;
  func_00175580(p,27,10,record->frame);
  dx=1.6666666269302368f*record->x;
  if(*(s16 *)(q+0x140)) dx=-dx;
  position->x+=dx;
  position->y+=2.142857074737549f*record->y;
  if(q[0x20D]==2) position->y+=34.28571319580078f;
  if(record->flags&1) *(s16 *)(p+0x140)^=1;
  if(record->flags&2) *(f32 *)(p+0x54)=-*(f32 *)(p+0x54);
  p[0x13C]=1;
 }
}
