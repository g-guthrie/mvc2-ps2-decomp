typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef struct {f32 x,y,z;} V3;
typedef struct {u8 prefix[0x14];u8 *link,*owner;s16 timer,repeat;u8 kind,phase,frame,slot;s8 mode;u8 gap25[0xf];f32 x,y,z;u8 gap40[8];u32 angle;s16 originX,originY;f32 scaleX,scaleY,scaleZ,vx,vy,vz,ax,ay;u8 gap70[0x60];s32 remaining;u8 gapd4[0x44];f32 intensity;u8 gap11c[0x20];s8 active;u8 gap13d[3];s16 facing;u8 gap142[0xf];s8 animPhase;} Motion;
extern int func_00174170(void);
extern int func_00175700(u8 *);
extern int func_001757E0(u8 *,int,int);
extern void func_001E7F60(u8 *);
extern void func_001E3710(u8 *,int);
extern void func_001E3210(u8 *,int);
#define OWNER(p) (*(u8 **)((p)+0x18))
#define LINK(p) (*(u8 **)((p)+0x14))
#define COPY_FIELDS(p) do {(p)[0x13c]=1;(p)[2]=OWNER(p)[2];(p)[1]=OWNER(p)[1];*(f32 *)((p)+0x50)=*(f32 *)(OWNER(p)+0x50);*(f32 *)((p)+0x54)=*(f32 *)(OWNER(p)+0x54);(p)[0x1b7]=OWNER(p)[0x1b7];(p)[0x1b8]=OWNER(p)[0x1b8];((s8 *)(p))[0x30]=((s8 *)OWNER(p))[0x30];*(V3 *)((p)+0x50)=*(V3 *)(OWNER(p)+0x50);((Motion *)(p))->mode=((Motion *)OWNER(p))->mode;}while(0)

extern void func_00355AE0(u8 *);
extern void func_00355B60(u8 *);
extern void func_00355B10(u8 *);
void func_00355930(u8 *p) {
 u8 *owner;Motion *m=(Motion *)p;
 p[0x24]=((s8 *)OWNER(p))[0x24];
 m->timer--;if(*(s16 *)(p+0x1c)<=0){
  m->timer=3;
  if(m->facing&1)p[0x22]+=2;else p[0x22]-=2;p[0x22]&=31;
  owner=OWNER(p);
  if(*(u16 *)(owner+0x168)==0x1510||owner[0x1e4]!=29){m->remaining=17;p[4]++;}
  func_00355AE0(p);
  if(!(p[0x22]&3)){
   if(m->remaining!=17)m->remaining=(s32)((u32)m->remaining-1u);
   m->repeat++;if(*(s16 *)(p+0x1e)>8)m->repeat=8;
   *(s32 *)(p+0xdc)=*(s16 *)(p+0x1e);func_00355B60(p);func_001E7F60(p);return;
  }
 }
 func_00355B10(p);func_001E7F60(p);
}
