#include "actor_inherited_state.h"
typedef unsigned char u8;typedef signed char s8;typedef unsigned short u16;typedef signed short s16;typedef unsigned int u32;typedef int s32;typedef float f32;
typedef struct {f32 x,y,z;} V3;
typedef struct {u8 pad[0x7c];s16 counts[2];} Game;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
typedef struct {u8 pad0,kind,team,pad3,phase,pad5[0x1B],choice,savedFacing,pad22[2];s8 layer;u8 pad25[0xB];s8 group;u8 pad31[3];V3 position;u8 pad40[0x10];V3 scale;} Actor;
void func_0035EBA0(u8 *p,u8 *q) {
 extern int func_001757E0(u8 *,int,int);extern void func_001E7F60(u8 *);
 Actor *a=(Actor *)p,*owner=(Actor *)q; u8 *tp;
 *(ActorState *)(p+0xec)=*(ActorState *)(q+0xec);
 p[0x13c]=1;a->team=owner->team;a->kind=owner->kind;
 a->scale.x=owner->scale.x;a->scale.y=owner->scale.y;
 p[0x1b7]=q[0x1b7];p[0x1b8]=q[0x1b8];*(s8 *)(p+0x30)=*(s8 *)(q+0x30);
 a->scale=owner->scale;*(s8 *)(p+0x24)=*(s8 *)(q+0x24);
 a->phase++;
 p[0x1b1]=p[0x1b0]=0x46;
 *(s8 *)(p+0x24)=0xC;p[0x21]=0;
 a->position.x=owner->position.x;
 a->position.y=171.42855834960938f+owner->position.y;
 tp=p+2;
 if (p[0x20]==0) {
  p[0x1b5]=0x37;p[0x1b2]=*(u16 *)(p+0x1c0)=0;*(s32 *)(p+0x1d8)=0;
  { int side=*tp; Game *game=(Game *)D_004C2794; game->counts[side]=game->counts[side]+1; }
 }
 func_001E7F60(p);
 func_001757E0(p,0x17,(u8)(p[0x20]+10));
}
void func_0035F4F0(u8 *p,u8 *q) {
 extern int func_001757E0(u8 *,int,int);extern void func_001E7F60(u8 *);
 Actor *a=(Actor *)p,*owner=(Actor *)q; u8 *r=q+0x2b8;
 *(ActorState *)(p+0xec)=*(ActorState *)(q+0xec);
 p[0x13c]=1;a->team=owner->team;a->kind=owner->kind;
 a->scale.x=owner->scale.x;a->scale.y=owner->scale.y;
 p[0x1b7]=q[0x1b7];p[0x1b8]=q[0x1b8];*(s8 *)(p+0x30)=*(s8 *)(q+0x30);
 a->scale=owner->scale;*(s8 *)(p+0x24)=*(s8 *)(q+0x24);
 a->phase++;
 p[0x1b1]=p[0x1b0]=0x42;
 *(s8 *)(p+0x24)=*(s8 *)(q+0x24);p[0x31]=8;
 a->position.x=owner->position.x+*(f32 *)(r+0xc);
 a->position.y=owner->position.y+*(f32 *)(r+0x10);
 p[0x1b5]=*(s8 *)(p+0x1b7)+0x32;p[0x1b2]=*(u16 *)(p+0x1c0)=0;*(s32 *)(p+0x1d8)=0;
 { int side=p[2]; Game *game=(Game *)D_004C2794; game->counts[side]=game->counts[side]+1; }
 func_001E7F60(p);
 func_001757E0(p,0x17,(u8)(p[0x1b7]+0x27));
}
