typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef struct {f32 x,y,z;} V3;
typedef struct {u8 prefix[0x14];u8 *link,*owner;s16 timer,repeat;u8 kind,phase,frame,slot;s8 mode;u8 gap25[0xf];f32 x,y,z;u8 gap40[8];u32 angle;s16 originX,originY;f32 scaleX,scaleY,scaleZ,vx,vy,vz,ax,ay;u8 gap70[0xcc];s8 active;u8 gap13d[3];s16 facing;u8 gap142[0xf];s8 animPhase;} Motion;
extern int func_00174170(void);
extern int func_00175700(u8 *);
extern int func_001757E0(u8 *,int,int);
extern void func_001E7F60(u8 *);
extern void func_001E3710(u8 *,int);
extern void func_001E3210(u8 *,int);
#define OWNER(p) (*(u8 **)((p)+0x18))
#define LINK(p) (*(u8 **)((p)+0x14))
#define COPY_FIELDS(p) do {(p)[0x13c]=1;(p)[2]=OWNER(p)[2];(p)[1]=OWNER(p)[1];*(f32 *)((p)+0x50)=*(f32 *)(OWNER(p)+0x50);*(f32 *)((p)+0x54)=*(f32 *)(OWNER(p)+0x54);(p)[0x1b7]=OWNER(p)[0x1b7];(p)[0x1b8]=OWNER(p)[0x1b8];((s8 *)(p))[0x30]=((s8 *)OWNER(p))[0x30];*(V3 *)((p)+0x50)=*(V3 *)(OWNER(p)+0x50);((Motion *)(p))->mode=((Motion *)OWNER(p))->mode;}while(0)

extern f32 D_00463B80[];
extern u8 D_00463BB0[];
extern void func_0036F120(u8 *,u8 *,s32 *);
extern void func_0036F4A0(u8 *,u8 *,s32 *);
extern void func_0036F560(u8 *,u8 *,s32 *);
extern void func_0036C0B0(u8 *,s32,s32);
void func_0036EF10(u8 *p,u8 *context,s32 *contact) {
 f32 *offsets=D_00463B80;u8 *target=*(u8 **)(context+0x220);Motion *m=(Motion *)p;u8 *owner;s8 *phase=&((Motion *)m->owner)->animPhase;f32 offset;
 if(*phase==11){*phase=0;p[5]++;func_0036F120(p,context,contact);return;}
 if(((s8 *)p)[0x1b2]<0){
  func_0036F4A0(p,context,contact);func_0036F560(p,context,contact);
  if(*contact){
   m->owner[0x23]=((s8 *)p)[0x23]+1;p[5]++;func_001757E0(p,23,(u8)(D_00463BB0[target[1]]+37));func_0036F120(p,context,contact);return;
  }
  func_001E3210(p,35);
 }
 owner=m->owner;
 if(((s8 *)owner)[0x151]>0){
  m->x=*(f32 *)(owner+0x34);m->y=*(f32 *)(m->owner+0x38);m->z=*(f32 *)(m->owner+0x3c);
  m->x+=*(s16 *)(m->owner+0x140)?159:-159;m->y+=165.0f;
  owner=m->owner;
  if(*(s16 *)(owner+0x140))offset=offsets[((s8 *)owner)[0x151]];else offset=-offsets[((s8 *)owner)[0x151]];
  m->x+=offset;
  p[0x23]=((s8 *)m->owner)[0x151]-1;
  if(((s8 *)m->owner)[0x151]>0)func_0036C0B0(p,7,p[0x23]);
  m->owner[0x151]=0;
 }
 func_001E7F60(p);
}
