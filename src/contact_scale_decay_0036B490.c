typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef struct {f32 x,y,z;} V3;
typedef struct {u8 prefix[0x14];u8 *link,*owner;s16 timer,repeat;u8 kind,phase,frame,slot;s8 mode;u8 gap25[0xf];f32 x,y,z;u8 gap40[8];u32 angle;s16 originX,originY;f32 scaleX,scaleY,scaleZ,vx,vy,vz,ax,ay;u8 gap70[0xa8];f32 intensity;u8 gap11c[0x20];s8 active;u8 gap13d[3];s16 facing;u8 gap142[0xf];s8 animPhase;} Motion;
extern int func_00174170(void);
extern int func_00175700(u8 *);
extern int func_001757E0(u8 *,int,int);
extern void func_001E7F60(u8 *);
extern void func_001E3710(u8 *,int);
extern void func_001E3210(u8 *,int);
#define OWNER(p) (*(u8 **)((p)+0x18))
#define LINK(p) (*(u8 **)((p)+0x14))
#define COPY_FIELDS(p) do {(p)[0x13c]=1;(p)[2]=OWNER(p)[2];(p)[1]=OWNER(p)[1];*(f32 *)((p)+0x50)=*(f32 *)(OWNER(p)+0x50);*(f32 *)((p)+0x54)=*(f32 *)(OWNER(p)+0x54);(p)[0x1b7]=OWNER(p)[0x1b7];(p)[0x1b8]=OWNER(p)[0x1b8];((s8 *)(p))[0x30]=((s8 *)OWNER(p))[0x30];*(V3 *)((p)+0x50)=*(V3 *)(OWNER(p)+0x50);((Motion *)(p))->mode=((Motion *)OWNER(p))->mode;}while(0)

extern void func_00131AB0(u8 *,s16 *,s32);
void func_0036B490(u8 *p,u8 *context) {
 s16 *counter=(s16 *)(context+0x2b8);Motion *m=(Motion *)p;s16 timer;u8 *target;
 func_00175700(p);m->repeat=1;m->angle+=0x4000;if(m->angle==0xf000)m->angle=0;
 m->scaleX/=1.66666663f;m->scaleY/=2.14285707f;m->ay+=m->ax;m->scaleX+=m->ay;m->scaleY+=m->ay;m->intensity+=m->ax;
 if((double)m->scaleX>1.440000034332276){m->scaleX=1.44f;m->scaleY=1.12f;}
 if(!(m->intensity<=1.0f))m->intensity=1.0f;
 timer=m->timer;m->timer=timer-1;
 if(!timer){p[5]++;m->timer=35;m->angle=0;m->ay=2.0f;m->ax=0.01f;}
 else if(!(((s8 *)p)[0x1b2]&1)){
  if(((s8 *)p)[0x1b2]){target=*(u8 **)(p+0x1c4);if(!target[3]&&!target[0x425]&&*(s16 *)(target+0x434)){*counter=600;func_00131AB0(context,counter,6);}}
  func_001E7F60(p);
 }
}
