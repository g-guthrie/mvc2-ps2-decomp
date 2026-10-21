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
typedef struct {u8 prefix[0x1C];s16 timer,count;} ActorTimer;
extern void func_003DAA40(u8 *);
extern int func_00175700(u8 *);
extern int func_001757E0(u8 *,int,int);
extern void func_001CCF40(u8 *,s32);
extern void func_0015E630(u8 *);
typedef struct {u8 prefix[0x34]; f32 x,y,z;u8 middle[0x1C];f32 vx,vy,vz,ax,ay;} ActorMotion;

void func_001CCF60(u8 *p,u8 *q) {
 ActorMotion *motion=(ActorMotion *)p;
 ActorTimer *timer=(ActorTimer *)p;
 u32 state=p[4];
 if(state==0) {
  p[4]=state+1;
        *(ActorState *)(p+0xEC)=*(ActorState *)(q+0xEC);
        p[0x13C]=1;
        p[2]=q[2];p[1]=q[1];
        *(f32 *)(p+0x50)=*(f32 *)(q+0x50);
        *(f32 *)(p+0x54)=*(f32 *)(q+0x54);
        p[0x1B7]=q[0x1B7];p[0x1B8]=q[0x1B8];
        *(s8 *)(p+0x30)=*(s8 *)(q+0x30);
        *(V3 *)(p+0x50)=*(V3 *)(q+0x50);
        *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
  motion->ay=0;
  motion->ax=0;
  motion->vx=0.2083333283662796f;
  motion->vy=-1.0714285373687744f;
  if(*(s16 *)(p+0x140)) motion->vx=-motion->vx;
  func_001CCF40(p,17);
  timer->timer=16;timer->count=11;
 } else {
  if(*(s32 *)(p+0xD0)!=*(u16 *)(q+0x168)) {func_003DAA40(p);return;}
  {
  s16 remaining=timer->timer;--remaining;timer->timer=remaining;
  if(remaining<=0) {
   s16 count;
   timer->timer=16;
   count=timer->count;--count;timer->count=count;
   if(count<=0) {func_003DAA40(p);return;}
   func_001CCF40(p,(u8)timer->count);
  }
  }
  motion->x+=motion->vx;
  motion->vx+=motion->ax;
  motion->y+=motion->vy;
  motion->vy+=motion->ay;
  func_00175700(p);
 }
}

void func_001CD130(u8 *p,u8 *q) {
 ActorMotion *motion=(ActorMotion *)p;
 ActorTimer *timer=(ActorTimer *)p;
 u32 state=p[4];
 if(state==0) {
  f32 offset;
  p[4]=state+1;
        *(ActorState *)(p+0xEC)=*(ActorState *)(q+0xEC);
        p[0x13C]=1;
        p[2]=q[2];p[1]=q[1];
        *(f32 *)(p+0x50)=*(f32 *)(q+0x50);
        *(f32 *)(p+0x54)=*(f32 *)(q+0x54);
        p[0x1B7]=q[0x1B7];p[0x1B8]=q[0x1B8];
        *(s8 *)(p+0x30)=*(s8 *)(q+0x30);
        *(V3 *)(p+0x50)=*(V3 *)(q+0x50);
        *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
  p[0x24]=12;
  offset=80.0f;
  motion->vx=0;motion->vy=0;motion->ax=0;motion->ay=0;
  motion->vx=11.666666030883789f;
  if(*(s16 *)(p+0x140)) {offset=-offset;motion->vx=-motion->vx;}
  motion->x=*(f32 *)(q+0x34)+offset;
  motion->y=*(f32 *)(q+0x38)-12.857142448425293f;
  func_001757E0(p,18,4);
  p[0]=1;func_0015E630(p);
 } else {
  if(p[5]==0) {
   func_00175700(p);
   if(*(s8 *)(p+0x151)) {p[0x151]=0;p[5]++;timer->timer=28;}
  } else {
   s16 remaining;
   motion->x+=motion->vx;motion->vx+=motion->ax;
   remaining=timer->timer;--remaining;timer->timer=remaining;
   if(remaining<0) p[4]++;
   else func_00175700(p);
  }
 }
}

void func_001CD320(u8 *p,u8 *q) {
 ActorMotion *motion=(ActorMotion *)p;
 u32 state=p[4];
 if(state==0) {
  f32 offset;
  p[4]=state+1;
        *(ActorState *)(p+0xEC)=*(ActorState *)(q+0xEC);
        p[0x13C]=1;
        p[2]=q[2];p[1]=q[1];
        *(f32 *)(p+0x50)=*(f32 *)(q+0x50);
        *(f32 *)(p+0x54)=*(f32 *)(q+0x54);
        p[0x1B7]=q[0x1B7];p[0x1B8]=q[0x1B8];
        *(s8 *)(p+0x30)=*(s8 *)(q+0x30);
        *(V3 *)(p+0x50)=*(V3 *)(q+0x50);
        *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
  p[0x31]=8;
  offset=640.0f;
  motion->vx=0;motion->vy=0;motion->ax=0;motion->ay=0;
  motion->vx=11.666666030883789f;
  if(*(s16 *)(p+0x140)) {offset=-offset;motion->vx=-motion->vx;}
  motion->x=*(f32 *)(q+0x34)-offset;
  motion->y=*(f32 *)(q+0x38);
  func_001757E0(p,19,8);
  p[0]=1;func_0015E630(p);
 } else {
  *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
  if(p[5]==0) {
   f32 distance;
   motion->x+=motion->vx;motion->vx+=motion->ax;
   func_00175700(p);
   distance=*(f32 *)(q+0x34)-motion->x;
   distance=distance<0.0f ? -distance:distance;
   if(distance<160.0f) {p[5]++;*(s16 *)(q+0x2C2)=1;func_001757E0(p,19,9);}
  } else func_00175700(p);
 }
}

extern void func_001E3710(u8 *,int);
void func_001CD520(u8 *p,u8 *q) {
 ActorMotion *motion=(ActorMotion *)p;
 u32 state=p[4];
 if(state==0) {
  f32 offset;
  p[4]=state+1;
        *(ActorState *)(p+0xEC)=*(ActorState *)(q+0xEC);
        p[0x13C]=1;
        p[2]=q[2];p[1]=q[1];
        *(f32 *)(p+0x50)=*(f32 *)(q+0x50);
        *(f32 *)(p+0x54)=*(f32 *)(q+0x54);
        p[0x1B7]=q[0x1B7];p[0x1B8]=q[0x1B8];
        *(s8 *)(p+0x30)=*(s8 *)(q+0x30);
        *(V3 *)(p+0x50)=*(V3 *)(q+0x50);
        *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
  offset=640.0f;
  *(s8 *)(p+0x31)-=8;
  motion->vx=0;motion->vy=0;motion->ax=0;motion->ay=0;
  motion->vx=-11.666666030883789f;
  if(*(s16 *)(p+0x140)) {offset=-offset;motion->vx=-motion->vx;}
  motion->x=*(f32 *)(q+0x34)+offset;
  motion->y=*(f32 *)(q+0x38);
  func_001757E0(p,19,10);
  p[0]=1;func_0015E630(p);
 } else {
  u32 phase;
  *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
  phase=p[5];
  if(phase==0) {
   f32 distance;
   motion->x+=motion->vx;motion->vx+=motion->ax;
   func_00175700(p);
   distance=*(f32 *)(q+0x34)-motion->x;
   distance=distance<0.0f ? -distance:distance;
   if(distance<426.666656494140625f) {
    f32 offset;
    p[5]++;*(s16 *)(q+0x2C4)=1;
    offset=53.333332061767578f;
    motion->ax=0.4166666567325592f;
    if(*(s16 *)(p+0x140)) {offset=-offset;motion->ax=-motion->ax;}
    motion->x-=offset;
    func_001757E0(p,19,11);
    func_001E3710(q,41);
   }
  } else {
   if((u8)phase==1) {
    f32 old=motion->vx;
    motion->x+=old;
    motion->vx+=motion->ax;
    if(motion->vx*old<0.0f) p[5]++;
   }
   func_00175700(p);
  }
 }
}

void func_001CD7D0(u8 *p,u8 *q) {
 ActorMotion *motion=(ActorMotion *)p;
 ActorTimer *timer=(ActorTimer *)p;
 u32 state=p[4];
 if(state==0) {
  p[4]=state+1;
        *(ActorState *)(p+0xEC)=*(ActorState *)(q+0xEC);
        p[0x13C]=1;
        p[2]=q[2];p[1]=q[1];
        *(f32 *)(p+0x50)=*(f32 *)(q+0x50);
        *(f32 *)(p+0x54)=*(f32 *)(q+0x54);
        p[0x1B7]=q[0x1B7];p[0x1B8]=q[0x1B8];
        *(s8 *)(p+0x30)=*(s8 *)(q+0x30);
        *(V3 *)(p+0x50)=*(V3 *)(q+0x50);
        *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
  *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
  *(s8 *)(p+0x31)=-8;
  motion->x=*(f32 *)(q+0x34);
  motion->y=*(f32 *)(q+0x38);
  func_001757E0(p,23,25);
 } else {
  u32 phase;
  *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
  if(((*(s32 *)(p+0xD0)>>8)&31)!=q[0x169]) {p[4]=3;func_003DAA40(p);return;}
  phase=p[5];
  if(phase==0) {
   s32 signal;
   motion->x=*(f32 *)(q+0x34);
   motion->y=*(f32 *)(q+0x38);
   signal=*(s8 *)(q+0x2C6);
   if(signal==2) {func_003DAA40(p);return;}
   if(signal==1) {
    p[5]++;
    motion->vx=-10.0f;motion->ax=0.0f;
    if(*(s16 *)(p+0x140)) motion->vx=-motion->vx;
    timer->timer=32;
   }
   func_00175700(p);
  } else if((u8)phase==1) {
   s16 remaining;
   motion->x+=motion->vx;motion->vx+=motion->ax;
   func_00175700(p);
   remaining=timer->timer;--remaining;timer->timer=remaining;
   if(remaining<=0) {
    p[5]++;
    motion->vx/=4.0f;motion->ax/=4.0f;
    func_001757E0(p,23,26);
   }
  } else {
   motion->x+=motion->vx;motion->vx+=motion->ax;
   if((s8)func_00175700(p)<0) func_003DAA40(p);
  }
 }
}

extern void *func_003DA750(void *,s32,s32);
extern int func_00174170(void);
extern void func_001D3E60(u8 *);
extern u8 *D_004C2840;
void func_001D3F00(u8 *p,u8 *q) {
 ActorTimer *timer=(ActorTimer *)p;
 u32 state;
 p[0x13C]=0;
 state=p[4];
 if(state==0) {
  p[4]=state+1;
        *(ActorState *)(p+0xEC)=*(ActorState *)((*(u8 **)(q+0x1DC))+0xEC);
        p[0x13C]=1;
        p[2]=(*(u8 **)(q+0x1DC))[2];p[1]=(*(u8 **)(q+0x1DC))[1];
        *(f32 *)(p+0x50)=*(f32 *)((*(u8 **)(q+0x1DC))+0x50);
        *(f32 *)(p+0x54)=*(f32 *)((*(u8 **)(q+0x1DC))+0x54);
        p[0x1B7]=(*(u8 **)(q+0x1DC))[0x1B7];p[0x1B8]=(*(u8 **)(q+0x1DC))[0x1B8];
        *(s8 *)(p+0x30)=*(s8 *)((*(u8 **)(q+0x1DC))+0x30);
        *(V3 *)(p+0x50)=*(V3 *)((*(u8 **)(q+0x1DC))+0x50);
        *(s8 *)(p+0x24)=*(s8 *)((*(u8 **)(q+0x1DC))+0x24);
  *(f32 *)(p+0x34)=*(f32 *)(*(u8 **)(q+0x1DC)+0x34);
  *(f32 *)(p+0x38)=*(f32 *)(*(u8 **)(q+0x1DC)+0x38);
  timer->count=10;
 } else {
  if(q[0x23E]) {func_003DAA40(p);return;}
  if(q[5]==3 || q[5]==2) {
   if(timer->count) {
    u8 *child;
    if((child=func_003DA750(0,3,0))!=0) {
     *(void (**)(u8 *))(child+0x10)=func_001D3E60;
     child[0x20]=(*(s8 *)(D_004C2840+0x1C)&3)+1;
     child[0x21]=0;
     *(u8 **)(child+0x18)=*(u8 **)(p+0x18);
     child[1]=(*(u8 **)(q+0x1DC))[1];
     *(u16 *)(child+0x26)=0x2C02;
     *(s32 *)(child+0xD0)=(func_00174170()&63)-32;
     *(s32 *)(child+0xD4)=64-(func_00174170()&63);
    }
    timer->count--;
   }
  } else func_003DAA40(p);
 }
}

extern int func_001754A0(u8 *,int,int);
extern int func_00175670(u8 *);
void func_001D4400(u8 *p,u8 *q) {
 ActorTimer *timer=(ActorTimer *)p;
 ActorMotion *motion=(ActorMotion *)p;
 u32 state=p[4];
 if(state==0) {
  p[4]=state+1;
        *(ActorState *)(p+0xEC)=*(ActorState *)((*(u8 **)(q+0x1DC))+0xEC);
        p[0x13C]=1;
        p[2]=(*(u8 **)(q+0x1DC))[2];p[1]=(*(u8 **)(q+0x1DC))[1];
        *(f32 *)(p+0x50)=*(f32 *)((*(u8 **)(q+0x1DC))+0x50);
        *(f32 *)(p+0x54)=*(f32 *)((*(u8 **)(q+0x1DC))+0x54);
        p[0x1B7]=(*(u8 **)(q+0x1DC))[0x1B7];p[0x1B8]=(*(u8 **)(q+0x1DC))[0x1B8];
        *(s8 *)(p+0x30)=*(s8 *)((*(u8 **)(q+0x1DC))+0x30);
        *(V3 *)(p+0x50)=*(V3 *)((*(u8 **)(q+0x1DC))+0x50);
        *(s8 *)(p+0x24)=*(s8 *)((*(u8 **)(q+0x1DC))+0x24);
  func_001754A0(p,27,(u8)((p[0x20]&7)+10));
  timer->timer=30;p[0x13C]=0;
  *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
  *(s8 *)(p+0x31)=-1;
 } else {
  s16 remaining;
  *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
  if(q[0x23E]) {func_003DAA40(p);return;}
  remaining=timer->timer;--remaining;timer->timer=remaining;
  if(remaining<0) {func_003DAA40(p);return;}
  p[0x13C]=1;func_00175670(p);
  motion->x+=motion->vx;motion->vx+=motion->ax;
  motion->y+=motion->vy;motion->vy+=motion->ay;
 }
}

extern void *func_003DA750(void *,s32,s32);
extern void func_001D0580(u8 *);
extern int func_00175910(u8 *,int,int,int);
void func_001D0850(u8 *p,u8 *q) {
 u32 state=p[4];
 if(state==0) {
  p[4]=state+1;p[0x151]=0;p[5]=0;
        *(ActorState *)(p+0xEC)=*(ActorState *)(q+0xEC);
        p[0x13C]=1;
        p[2]=q[2];p[1]=q[1];
        *(f32 *)(p+0x50)=*(f32 *)(q+0x50);
        *(f32 *)(p+0x54)=*(f32 *)(q+0x54);
        p[0x1B7]=q[0x1B7];p[0x1B8]=q[0x1B8];
        *(s8 *)(p+0x30)=*(s8 *)(q+0x30);
        *(V3 *)(p+0x50)=*(V3 *)(q+0x50);
        *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
  p[0x13C]=0;*(s8 *)(p+0x31)=-1;
 }
 if(p[5]==0) {
  if(q[0x169]==21) {
   s32 flags;
   *(f32 *)(p+0x34)=*(f32 *)(q+0x34);
   *(f32 *)(p+0x38)=*(f32 *)(q+0x38);
   *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
   flags=*(s8 *)(q+0x151);
   if(flags&128) {
    s32 frame=(s8)(flags&127);
    if(frame) {
     if(*(s8 *)(p+0x151)!=(s8)frame) {
      p[0x13C]=1;
      func_00175910(p,23,3,(s8)frame);
      if(*(s8 *)(p+0x150)) {
       u8 *child;
       p[0x150]=0;
       child=func_003DA750(p,3,2);
       if(child) {
        *(void (**)(u8 *))(child+0x10)=func_001D0580;
        child[0x20]=3;child[0x21]=0;
        *(u8 **)(child+0x18)=q;
        child[1]=q[1];
        *(f32 *)(child+0x34)=*(f32 *)(q+0x34);
        *(f32 *)(child+0x38)=*(f32 *)(q+0x38);
        *(u16 *)(child+0x26)=0x2900;
       }
      }
     }
    } else {
     p[5]++;
     if((s8)func_00175700(p)<0) func_003DAA40(p);
    }
   }
  } else func_003DAA40(p);
 } else if((s8)func_00175700(p)<0) func_003DAA40(p);
}

extern u8 *D_004C2840;
extern u8 D_004D18E4 __attribute__((section(".bss")));
void func_001E0090(u8 *p) {
 ActorTimer *timer=(ActorTimer *)p;
 s32 state=p[4];
 u8 *q=*(u8 **)(p+0x18);
 if(state>=2) func_003DAA40(p);
 else {
  if(state==0) {
   p[4]=state+1;
        *(ActorState *)(p+0xEC)=*(ActorState *)(q+0xEC);
        p[0x13C]=1;
        p[2]=q[2];p[1]=q[1];
        *(f32 *)(p+0x50)=*(f32 *)(q+0x50);
        *(f32 *)(p+0x54)=*(f32 *)(q+0x54);
        p[0x1B7]=q[0x1B7];p[0x1B8]=q[0x1B8];
        *(s8 *)(p+0x30)=*(s8 *)(q+0x30);
        *(V3 *)(p+0x50)=*(V3 *)(q+0x50);
        *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
   if(*(s8 *)(D_004C2840+3)==4) {func_003DAA40(p);return;}
   *(f32 *)(p+0x34)=*(f32 *)(q+0x34);
   *(f32 *)(p+0x38)=*(f32 *)(q+0x38);
   timer->timer=0;
   *(s8 *)(p+0x31)-=1;
  }
  p[0x13C]=0;
  *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
  if(*(s8 *)(q+0x13C)) {
   u32 animation;
   *(f32 *)(p+0x34)=*(f32 *)(q+0x34);
   *(f32 *)(p+0x38)=*(f32 *)(q+0x38);
   *(s16 *)(p+0x140)=*(s16 *)(q+0x140);
   animation=(u16)*(s8 *)(q+0x161);
   if(animation) {
    p[0x13C]=1;
    if(timer->timer!=(u16)animation) {
     timer->timer=animation;
     func_001757E0(p,23,(u8)animation);
    } else if(!D_004D18E4) func_00175700(p);
   } else timer->timer=animation;
  } else p[0x13C]=0;
 }
 *(s8 *)(p+0x24)=*(s8 *)(q+0x24)+*(s8 *)(p+0x31);
 if(7<*(s8 *)(p+0x24)) p[0x24]=7;
 if(*(s8 *)(p+0x24)<0) p[0x24]=0;
}

extern int func_001754A0(u8 *,int,int);
extern int func_00175670(u8 *);
extern void func_00175580(u8 *,int,int,int);
extern void func_003C9850(u8 *,u8 *);
void func_001E0280(u8 *p) {
 ActorMotion *motion=(ActorMotion *)p;
 s32 state=p[4];
 u8 *q=*(u8 **)(p+0x18);
 if(1<state || *(s32 *)(p+0xD0)!=*(u16 *)(q+0x168)) {func_003DAA40(p);return;}
 if(state==0) {
  p[4]=state+1;
        *(ActorState *)(p+0xEC)=*(ActorState *)(q+0xEC);
        p[0x13C]=1;
        p[2]=q[2];p[1]=q[1];
        *(f32 *)(p+0x50)=*(f32 *)(q+0x50);
        *(f32 *)(p+0x54)=*(f32 *)(q+0x54);
        p[0x1B7]=q[0x1B7];p[0x1B8]=q[0x1B8];
        *(s8 *)(p+0x30)=*(s8 *)(q+0x30);
        *(V3 *)(p+0x50)=*(V3 *)(q+0x50);
        *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
  motion->vy=342.85711669921875f;
  motion->vx=13.333333015441895f;
  if(*(s16 *)(p+0x140)) motion->vx=-motion->vx;
  motion->x=*(f32 *)(q+0x34)+motion->vx;
  motion->y=*(f32 *)(q+0x38)+motion->vy;
  *(s8 *)(p+0x31)=-8;
  func_001754A0(p,27,0);
 } else {
  if(p[5]==0) {
   motion->x=*(f32 *)(q+0x34)+motion->vx;
   motion->y=*(f32 *)(q+0x38)+motion->vy;
   *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
   *(s8 *)(p+0x31)=-8;
   if((s8)func_00175670(p)<0) {p[5]++;p[0x22]=0;func_00175580(p,27,1,0);}
  } else {
   s32 frame=*(s8 *)(q+0x151);
   if(frame>=0) {
    if(p[0x22]!=frame) {p[0x22]=frame;func_00175580(p,27,1,p[0x22]);func_003C9850(p,q);}
    motion->x=*(f32 *)(q+0x34)+motion->vx;
    motion->y=*(f32 *)(q+0x38)+motion->vy;
   } else {p[0x13C]=0;p[4]++;p[5]=0;}
  }
 }
}

extern int func_00174170(void);
extern void func_001E3B70(u8 *,int);
extern f32 D_0044EF20[8],D_0044EF40[8];
void func_001E0540(u8 *p) {
 u8 *q=*(u8 **)(p+0x18);
 u8 *r=*(u8 **)(q+0x1C8);
 s32 state=p[4];
 if(state>=2) func_003DAA40(p);
 else {
  if(state==0) {
   p[4]=state+1;p[5]=0;
        *(ActorState *)(p+0xEC)=*(ActorState *)(r+0xEC);
        p[0x13C]=1;
        p[2]=r[2];p[1]=r[1];
        *(f32 *)(p+0x50)=*(f32 *)(r+0x50);
        *(f32 *)(p+0x54)=*(f32 *)(r+0x54);
        p[0x1B7]=r[0x1B7];p[0x1B8]=r[0x1B8];
        *(s8 *)(p+0x30)=*(s8 *)(r+0x30);
        *(V3 *)(p+0x50)=*(V3 *)(r+0x50);
        *(s8 *)(p+0x24)=*(s8 *)(r+0x24);
   func_001757E0(p,25,4);
   *(s8 *)(p+0x24)=*(s8 *)(r+0x24);
   *(s8 *)(p+0x31)=-8;
  }
  *(s8 *)(p+0x24)=*(s8 *)(r+0x24);
  func_00175700(p);
  if(*(s8 *)(p+0x151)) func_001E3B70(r,4);
  if(q[5]!=2 || q[0x20A]!=19 || 1<q[6]) p[4]++;
  else if(p[5]==0) {
   f32 offset=D_0044EF20[func_00174170()&7];
   if(*(s16 *)(q+0x140)) offset=-offset;
   *(f32 *)(p+0x34)=*(f32 *)(q+0x34)+offset;
   *(f32 *)(p+0x38)=*(f32 *)(q+0x38)+D_0044EF40[func_00174170()&7];
   p[5]++;
  }
 }
 *(s8 *)(p+0x24)=*(s8 *)(q+0x24)+*(s8 *)(p+0x31);
 if(7<*(s8 *)(p+0x24)) p[0x24]=7;
 if(*(s8 *)(p+0x24)<0) p[0x24]=0;
}

typedef struct {f32 x,bottom; s8 first_tick,repeat_tick;u8 animation,unknown0B;} DropConfig;
extern DropConfig D_0044EEC0[];
typedef struct { u16 count, first_code; } DropSequence;
extern DropSequence D_0044EF10[];
extern int func_00174170(void);
extern u8 *func_001DF540(u8 *,s32);
void func_001DF7F0(u8 *p,u8 *q) {
 ActorMotion *motion=(ActorMotion *)p;
 ActorTimer *timer=(ActorTimer *)p;
 DropConfig *config=&D_0044EEC0[p[0x21]];
 u32 state=p[4];
 if(state==0) {
  f32 x;
  p[4]=state+1;
        *(ActorState *)(p+0xEC)=*(ActorState *)(q+0xEC);
        p[0x13C]=1;
        p[2]=q[2];p[1]=q[1];
        *(f32 *)(p+0x50)=*(f32 *)(q+0x50);
        *(f32 *)(p+0x54)=*(f32 *)(q+0x54);
        p[0x1B7]=q[0x1B7];p[0x1B8]=q[0x1B8];
        *(s8 *)(p+0x30)=*(s8 *)(q+0x30);
        *(V3 *)(p+0x50)=*(V3 *)(q+0x50);
        *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
  *(s8 *)(p+0x31)=-8;
  motion->vx=0;motion->vy=0;motion->ax=0;motion->ay=0;
  motion->vy=-34.28571319580078f;motion->ay=-1.0714285373687744f;
  func_001757E0(p,18,config->animation);
  func_001DF540(p,(u16)(p[0x21]|0x200));
  timer->timer=config->first_tick;timer->count=config->repeat_tick;
  x=*(s16 *)(p+0x140) ? -config->x : config->x;
  motion->x=*(f32 *)(q+0x34)+x;
  motion->y=617.142822265625f+*(f32 *)(q+0x38);
 }
 *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
 if(p[5]==0) {
  s16 remaining=timer->timer;
  --remaining;timer->timer=remaining;
  if(remaining<0) {
   timer->timer=timer->count;
   if(func_00174170()&1) func_001DF540(p,0x500);
  }
  motion->x+=motion->vx;motion->vx+=motion->ax;
  motion->y+=motion->vy;motion->vy+=motion->ay;
  {
  f32 bottom=config->bottom;
  f32 y=motion->y;
  if(!(bottom<=y)) {
   u32 index,count,code;
   motion->y=bottom;p[5]++;
   index=0;
   count=D_0044EF10[p[0x21]].count;code=D_0044EF10[p[0x21]].first_code;
   for(; (u16)index<(u16)count; code=(u16)(code+1),index=(u16)(index+1)) func_001DF540(p,code);
  }
  }
 } else if((s8)func_00175700(p)<0) func_003DAA40(p);
}

extern int func_001754A0(u8 *,int,int);
extern void func_001C4890(s32,u8);
extern void func_001C4B00(u8 *);
extern u8 D_004BFA38[3], D_004BFA3B[3];
void func_001C4920(u8 *p) {
 ActorMotion *motion=(ActorMotion *)p;
 ActorTimer *timer=(ActorTimer *)p;
 u8 *q,*owner;
 u32 state=p[4];
 p[4]=state+1;*(u16 *)(p+0x26)=0xC054;timer->timer=300;
 q=*(u8 **)(p+0x18);
        *(ActorState *)(p+0xEC)=*(ActorState *)(q+0xEC);
        p[0x13C]=1;
        p[2]=q[2];p[1]=q[1];
        *(f32 *)(p+0x50)=*(f32 *)(q+0x50);
        *(f32 *)(p+0x54)=*(f32 *)(q+0x54);
        p[0x1B7]=q[0x1B7];p[0x1B8]=q[0x1B8];
        *(s8 *)(p+0x30)=*(s8 *)(q+0x30);
        *(V3 *)(p+0x50)=*(V3 *)(q+0x50);
        *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
 p[0x24]=9;
 p[0x14C]=12;p[0x14D]=12;p[0x14E]=12;p[0x14F]=12;
 *(s16 *)(p+0x140)=0;
 owner=*(u8 **)(p+0x14);
 if(!*(s16 *)(owner+0x140)) {
  motion->x=-3.3333332538604736f+*(f32 *)(owner+0x34);
  motion->vx=-2.5f;
 } else {
  motion->x=*(f32 *)(owner+0x34)-(-3.3333332538604736f);
  motion->vx=2.5f;
 }
 motion->ax=0;
 motion->y=57.857139587402344f+*(f32 *)(owner+0x38);
 motion->vy=12.857142448425293f;motion->ay=-0.5357142686843872f;
 if(q[1]==28) p[0x168]=D_004BFA38[p[0x20]];
 else p[0x168]=D_004BFA3B[p[0x20]];
 func_001754A0(p,27,p[0x168]);
 func_001C4890((s32)p,3);func_001C4890((s32)p,4);func_001C4B00(p);
}

typedef struct {u8 prefix[0x50];V3 scale;u8 gap5C[12];V3 previous;u8 gap74[20];f32 stepX,stepY;} ActorScale;
extern int func_001754A0(u8 *,int,int);
extern void func_001C05B0(u8 *);
void func_001C03B0(u8 *p) {
 ActorScale *scale=(ActorScale *)p;
 ActorMotion *motion=(ActorMotion *)p;
 u32 state=p[4];
 p[4]=state+1;
        *(ActorState *)(p+0xEC)=*(ActorState *)((*(u8 **)(p+0x18))+0xEC);
        p[0x13C]=1;
        p[2]=(*(u8 **)(p+0x18))[2];p[1]=(*(u8 **)(p+0x18))[1];
        *(f32 *)(p+0x50)=*(f32 *)((*(u8 **)(p+0x18))+0x50);
        *(f32 *)(p+0x54)=*(f32 *)((*(u8 **)(p+0x18))+0x54);
        p[0x1B7]=(*(u8 **)(p+0x18))[0x1B7];p[0x1B8]=(*(u8 **)(p+0x18))[0x1B8];
        *(s8 *)(p+0x30)=*(s8 *)((*(u8 **)(p+0x18))+0x30);
        *(V3 *)(p+0x50)=*(V3 *)((*(u8 **)(p+0x18))+0x50);
        *(s8 *)(p+0x24)=*(s8 *)((*(u8 **)(p+0x18))+0x24);
 p[0x24]=0;func_001754A0(p,27,4);
 {
 f32 dx;
 *(V3 *)(p+0x34)=*(V3 *)(*(u8 **)(p+0x18)+0x34);
 dx=-40.0f;
 if(*(s16 *)(p+0x140)) dx=-dx;
 motion->x+=dx*scale->scale.x;
 motion->y+=205.7142791748047f*scale->scale.y;
 scale->previous=scale->scale;
 scale->scale.x*=0.4000000059604645f;
 scale->scale.y*=0.4000000059604645f;
 scale->stepX=(1.5f*scale->previous.x-scale->scale.x)/20.0f;
 scale->stepY=(1.5f*scale->previous.y-scale->scale.y)/20.0f;
 }
 *(s16 *)(p+0x1E)=20;*(s16 *)(p+0x1C)=30;
 *(s32 *)(p+0x48)=0;*(s16 *)(p+0x1C)=240;
 func_001C05B0(p);
}

extern f32 D_004F1F50 __attribute__((section(".bss")));
void func_001CC8C0(u8 *p) {
 ActorMotion *motion=(ActorMotion *)p;
 u32 state=p[4];
 p[4]=state+1;
        *(ActorState *)(p+0xEC)=*(ActorState *)((*(u8 **)(p+0x18))+0xEC);
        p[0x13C]=1;
        p[2]=(*(u8 **)(p+0x18))[2];p[1]=(*(u8 **)(p+0x18))[1];
        *(f32 *)(p+0x50)=*(f32 *)((*(u8 **)(p+0x18))+0x50);
        *(f32 *)(p+0x54)=*(f32 *)((*(u8 **)(p+0x18))+0x54);
        p[0x1B7]=(*(u8 **)(p+0x18))[0x1B7];p[0x1B8]=(*(u8 **)(p+0x18))[0x1B8];
        *(s8 *)(p+0x30)=*(s8 *)((*(u8 **)(p+0x18))+0x30);
        *(V3 *)(p+0x50)=*(V3 *)((*(u8 **)(p+0x18))+0x50);
        *(s8 *)(p+0x24)=*(s8 *)((*(u8 **)(p+0x18))+0x24);
 p[0x24]=11;
 {
 u8 *q=*(u8 **)(p+0x18);
 f32 x=*(f32 *)(q+0x34);
 motion->x=x+(*(s16 *)(p+0x140) ? 80.0f : -80.0f);
 }
 motion->y=548.5714111328125f+D_004F1F50;
 motion->vx=0;motion->vy=0;motion->ax=0;motion->ay=0;
 motion->vy=-4.285714149475098f;motion->ay=-0.8035714030265808f;
 func_0015E630(p);p[0]=1;
 func_001757E0(p,23,(u8)(p[0x21]+62));
}

extern int func_001754A0(u8 *,int,int);
extern u8 D_0044DB40[];
extern f32 D_0044DB80[],D_0044DBA0[];
extern s16 D_0044DC90[];
void func_001CC280(u8 *p) {
 ActorMotion *motion=(ActorMotion *)p;
 u8 *owner=*(u8 **)(*(u8 **)(p+0x18)+0x1DC);
 u32 state=p[4];
 p[4]=state+1;
        *(ActorState *)(p+0xEC)=*(ActorState *)((*(u8 **)(p+0x18))+0xEC);
        p[0x13C]=1;
        p[2]=(*(u8 **)(p+0x18))[2];p[1]=(*(u8 **)(p+0x18))[1];
        *(f32 *)(p+0x50)=*(f32 *)((*(u8 **)(p+0x18))+0x50);
        *(f32 *)(p+0x54)=*(f32 *)((*(u8 **)(p+0x18))+0x54);
        p[0x1B7]=(*(u8 **)(p+0x18))[0x1B7];p[0x1B8]=(*(u8 **)(p+0x18))[0x1B8];
        *(s8 *)(p+0x30)=*(s8 *)((*(u8 **)(p+0x18))+0x30);
        *(V3 *)(p+0x50)=*(V3 *)((*(u8 **)(p+0x18))+0x50);
        *(s8 *)(p+0x24)=*(s8 *)((*(u8 **)(p+0x18))+0x24);
 p[0x24]=10;*(s8 *)(p+0x31)=-1;
 {
 u32 index=D_0044DB40[owner[1]];
 f32 offset;
 if(*(s16 *)(p+0x140)) offset=D_0044DB80[(u8)index];
 else offset=-D_0044DB80[(u8)index];
 motion->x=offset;
 }
 motion->x+=*(f32 *)(owner+0x34);
 motion->y=*(f32 *)(owner+0x38)+D_0044DBA0[owner[1]];
 *(s16 *)(p+0x1E)=0;
 *(s16 *)(p+0x1C)=D_0044DC90[*(s16 *)(p+0x1E)];
 p[0x22]=8;func_001754A0(p,27,8);
}

extern int func_00174170(void);
extern int func_001754A0(u8 *,int,int);
extern void func_001DC600(u8 *,void *);
void func_001DC460(u8 *p,void *context) {
 u8 *q=context;
 ActorMotion *motion=(ActorMotion *)p;
 u32 state=p[4];
 p[4]=state+1;
        *(ActorState *)(p+0xEC)=*(ActorState *)(q+0xEC);
        p[0x13C]=1;
        p[2]=q[2];p[1]=q[1];
        *(f32 *)(p+0x50)=*(f32 *)(q+0x50);
        *(f32 *)(p+0x54)=*(f32 *)(q+0x54);
        p[0x1B7]=q[0x1B7];p[0x1B8]=q[0x1B8];
        *(s8 *)(p+0x30)=*(s8 *)(q+0x30);
        *(V3 *)(p+0x50)=*(V3 *)(q+0x50);
        *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
 p[0x24]=8;
 motion->vx=0;motion->vy=0;motion->ax=0;motion->ay=0;
 motion->vx=(1.6666666269302368f*(((func_00174170()&255)-128)*128))/65536.0f;
 motion->vy=(2.142857074737549f*(((func_00174170()&255)+96)*1024))/65536.0f;
 motion->ay=-0.4017857015132904f;
 func_001754A0(p,27,(u8)((func_00174170()&3)+9));
 func_001DC600(p,q);
}

typedef struct {s16 x,y;} EmissionOffset;
typedef struct {s32 vx,ax,vy,ay;} FixedMotion;
extern EmissionOffset D_0044E000[4];
extern FixedMotion D_0044E010;
void func_001D1C10(u8 *p) {
 ActorMotion *motion=(ActorMotion *)p;
 u32 state=p[4];
 u8 *q=*(u8 **)(p+0x14);
 p[4]=state+1;
        *(ActorState *)(p+0xEC)=*(ActorState *)(q+0xEC);
        p[0x13C]=1;
        p[2]=q[2];p[1]=q[1];
        *(f32 *)(p+0x50)=*(f32 *)(q+0x50);
        *(f32 *)(p+0x54)=*(f32 *)(q+0x54);
        p[0x1B7]=q[0x1B7];p[0x1B8]=q[0x1B8];
        *(s8 *)(p+0x30)=*(s8 *)(q+0x30);
        *(V3 *)(p+0x50)=*(V3 *)(q+0x50);
        *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
 p[0x24]=0;
 *(s16 *)(p+0x140)=*(s16 *)(q+0x140);
 p[0x14C]=16;p[0x14D]=16;p[0x14E]=16;p[0x14F]=16;
 *(V3 *)(p+0x34)=*(V3 *)(q+0x34);
 {
 s32 dx=D_0044E000[p[0x20]].x;
 s32 dy=D_0044E000[p[0x20]].y;
 motion->vx=(1.6666666269302368f*D_0044E010.vx)/65536.0f;
 motion->ax=(1.6666666269302368f*D_0044E010.ax)/65536.0f;
 motion->vy=(2.142857074737549f*D_0044E010.vy)/65536.0f;
 motion->ay=(2.142857074737549f*D_0044E010.ay)/65536.0f;
 if(*(s16 *)(p+0x140)) {dx=-dx;motion->vx=-motion->vx;motion->ax=-motion->ax;}
 motion->x+=1.6666666269302368f*dx;
 motion->y+=2.142857074737549f*dy;
 }
 func_001757E0(p,23,10);
}
