#include "actor_inherited_state.h"
typedef unsigned char u8;typedef signed char s8;typedef unsigned short u16;typedef signed short s16;typedef unsigned int u32;typedef int s32;typedef float f32;
typedef struct {f32 x,y,z;} V3;
typedef struct {u8 pad0,kind,team,pad3,phase,pad5[0x17];s16 h1c;u8 pad1e[6];s8 layer;u8 pad25[0xB];s8 group;s8 b31;u8 pad32[2];V3 position;u8 pad40[0x10];V3 scale;f32 f5c;f32 f60;u8 pad64[8];f32 f6c;} Actor;
extern s16 D_00463240[];
extern s16 D_00463242[];
extern s16 D_00463244[];
void residual_0035CCC0(u8 *p,u8 *q) {
 extern s32 func_00174170(void);
 extern int func_001757E0(u8 *,int,int);
 extern void func_0035CF70(u8 *,u8 *);
 Actor *a=(Actor *)p,*owner=(Actor *)q;
 s16 d;
 s32 r;
 a->phase++;
 *(ActorState *)(p+0xec)=*(ActorState *)(q+0xec);
 p[0x13c]=1;a->team=owner->team;a->kind=owner->kind;
 a->scale.x=owner->scale.x;a->scale.y=owner->scale.y;
 p[0x1b7]=q[0x1b7];p[0x1b8]=q[0x1b8];*(s8 *)(p+0x30)=*(s8 *)(q+0x30);
 a->scale=owner->scale;*(s8 *)(p+0x24)=*(s8 *)(q+0x24);
 a->b31=-1;
 p[0x13c]=0;
 a->position.x=owner->position.x;
 a->position.y=owner->position.y;
 a->position.z=owner->position.z;
 d=func_00174170()&0x7F;
 a->position.x+=1.6666666269302368f*(f32)(64-d);
 d=func_00174170()&0x7F;
 a->position.y+=2.142857074737549f*(f32)(64-d);
 switch (q[0x20]) {
 case 0: d=-0x6A; break;
 case 1: d=0x6A; break;
 }
 if (q[0x1e6]!=0) d=-d;
 a->position.x+=(f32)d;
 r=(func_00174170()&0xF)*3;
 a->f5c=1.6666666269302368f*(f32)(D_00463240[r]<<8)/65536.0f;
 a->f60=2.142857074737549f*(f32)(D_00463242[r]<<8)/65536.0f;
 a->f6c=2.142857074737549f*(f32)(D_00463244[r]<<8)/65536.0f;
 a->h1c=(func_00174170()&0xF)+1;
 func_001757E0(p,0x17,(u8)((func_00174170()&7)+0xB));
 func_0035CF70(p,q);
}
