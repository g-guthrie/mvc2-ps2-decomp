#include "actor_inherited_state.h"
typedef unsigned char u8;typedef signed char s8;typedef unsigned short u16;typedef signed short s16;typedef int s32;typedef float f32;
typedef struct {f32 x,y,z;} V3;typedef struct {u8 pad[0x7c];s16 counts[2];} Game;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_001E7F60(u8 *);extern int func_001757E0(u8 *,int,int);
void func_0035C4C0(u8 *p,void *context){
 u8 *q=context;float offset;
 *(ActorState *)(p+0xec)=*(ActorState *)(q+0xec);
 p[0x13c]=1;p[2]=q[2];p[1]=q[1];
 *(f32 *)(p+0x50)=*(f32 *)(q+0x50);*(f32 *)(p+0x54)=*(f32 *)(q+0x54);
 p[0x1b7]=q[0x1b7];p[0x1b8]=q[0x1b8];*(s8 *)(p+0x30)=*(s8 *)(q+0x30);
 *(V3 *)(p+0x50)=*(V3 *)(q+0x50);*(s8 *)(p+0x24)=*(s8 *)(q+0x24);
 p[4]++;p[0x1b0]=70;p[0x1b1]=64;
 { u8 *side=p+2; offset=-83.33332824707031f;if(q[0x1e6])offset=-offset;
 *(f32 *)(p+0x34)=*(f32 *)(q+0x34)+offset;
 *(f32 *)(p+0x38)=*(f32 *)(q+0x38)+90.0f;
 p[0x1b5]=99;p[0x1b2]=*(u16 *)(p+0x1c0)=0;*(s32 *)(p+0x1d8)=0;
 {int index=*side;Game *game=(Game *)D_004C2794;game->counts[index]=game->counts[index]+1;} }
 func_001E7F60(p);func_001757E0(p,23,23);
}
