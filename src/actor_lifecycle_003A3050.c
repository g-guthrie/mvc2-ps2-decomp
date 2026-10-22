#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
#include "actor_inherited_state.h"

typedef struct { u8 prefix[0x24]; s8 palette; } ActorPalette;
typedef struct {u8 prefix[0xd0];s32 timer;} ActorTimer;
typedef struct {u8 prefix[0x7c];s16 count[2];} GameState;
extern GameState *D_004C2794 __attribute__((section(".sdata")));
typedef struct {f32 x,y;} PositionOffset;
extern PositionOffset D_00472B80[];
extern const u32 jtbl_00472BB0[];
extern int func_001757E0(u8 *,int,int);
extern int func_00175700(u8 *);
extern int func_00174470(const void *);
extern void func_003DAA40(u8 *);
extern void func_003A3880(u8 *,u8 *);
extern void func_001D36E0(u8 *,u8);
void func_003A3050(u8 *p)
{
 ActorTimer *timer=(ActorTimer *)p;
 ActorPalette *palette=(ActorPalette *)p;
 u8 *q=*(u8 **)(p+0x18);
 switch(p[4]) {
 case 0:
 p[4]++;
  *(ActorState *)(p+0xec)=*(ActorState *)(q+0xec);
    p[0x13C] = 1;
        p[2] = q[2];
    p[1] = q[1];
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
    p[0x1B7] = q[0x1B7];
    p[0x1B8] = q[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(q + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
 ((s8 *)p)[0x31]=-8;
 p[0x1b3]=0;
 *(float *)(p+0x5c)=0.0f;
 *(float *)(p+0x60)=0.0f;
 *(float *)(p+0x68)=0.0f;
 *(float *)(p+0x6c)=0.0f;
 p[0x14c]=p[0x14d]=p[0x14e]=p[0x14f]=32;
 p[0x13c]=1;
 timer->timer=80;
 {u8 *team=p+2;
 if(q[0x20d]==2) {
 p[0x1b5]=59;
 p[0x1b2]=*(u16 *)(p+0x1c0)=0;
 *(u32 *)(p+0x1d8)=0;
 D_004C2794->count[team[0]]++;
 } else {
 p[0x1b5]=51;
 p[0x1b2]=*(u16 *)(p+0x1c0)=0;
 *(u32 *)(p+0x1d8)=0;
 D_004C2794->count[team[0]]++;
 }}
 p[0x1b0]=64; p[0x1b1]=64;
 *(u16 *)(p+0x1c0)|=0x200;
 {int index=p[0x20];
 float x=D_00472B80[index].x;
 *(float *)(p+0x38)=*(float *)(q+0x38)+D_00472B80[index].y;
 if(*(s16 *)(p+0x140)!=0)x=-x;
 *(float *)(p+0x34)=*(float *)(q+0x34)+x;}
 func_001D36E0(p,2);
 func_001757E0(p,21,2);
 case 1:
 ((s8 *)p)[0x24]=((s8 *)q)[0x24];
 ((void (*)(u8 *,u8 *))jtbl_00472BB0[p[5]])(p,q);
 if(timer->timer==0) {
 if(!func_00174470(p))func_003A3880(p,q);
 } else --timer->timer;
 break;
 case 2:
 if((s8)func_00175700(p)>=0)break;
 case 3:
 default:func_003DAA40(p);break;
 }
 palette->palette=((ActorPalette *)q)->palette+((s8 *)p)[0x31];
 {int value=palette->palette;
 if(value>7)palette->palette=7;
 value=palette->palette;
 if(value<0)palette->palette=0;}
}
