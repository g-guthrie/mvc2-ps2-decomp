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

extern u8 *D_004C2794 __attribute__((section(".sdata")));
#define RESET_ACTION(p,code) do {u32 counterAddress; (p)[0x1b5]=(code);(p)[0x1b2]=*(u16 *)((p)+0x1c0)=0;*(u32 *)((p)+0x1d8)=0;counterAddress=(p)[2]*2;counterAddress+=(u32)D_004C2794;counterAddress+=0x7c;++*(s16 *)counterAddress;}while(0)
void func_0035FDF0(u8 *p,u8 *context) {
 Motion *m=(Motion *)p;f32 contextX;s16 ownDistance,targetDistance,timer;u8 *target;
 func_00175700(p);
 if(!((s8 *)p)[0x151])p[0x24]=10;else p[0x24]=13;
 func_001E7F60(p);
 if(!(m->timer&7)){
  contextX=*(f32 *)(context+0x34);target=*(u8 **)(context+0x220);
  ownDistance=contextX-m->x;if(ownDistance<0)ownDistance=-ownDistance;
  targetDistance=contextX-*(f32 *)(target+0x34);if(targetDistance<0)targetDistance=-targetDistance;
  if(ownDistance<targetDistance){RESET_ACTION(p,58);*(u16 *)(p+0x1c0)|=16;}else RESET_ACTION(p,58);
 }
 timer=m->timer;m->timer=timer-1;
 if(!timer){RESET_ACTION(p,59);p[4]++;}
}
