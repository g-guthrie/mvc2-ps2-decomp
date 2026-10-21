typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef struct {u8 prefix[0x14];u8 *link,*owner;s16 timer,repeat;u8 kind,phase,frame,slot;s8 mode;u8 gap25[0xf];f32 x,y,z;u8 gap40[8];u32 angle;s16 originX,originY;f32 scaleX,scaleY,scaleZ,vx,vy,vz,ax,ay;u8 gap70[0x60];s32 remaining;u8 gapd4[0x44];f32 intensity;u8 gap11c[0x20];s8 active;u8 gap13d[3];s16 facing;u8 gap142[0xf];s8 animPhase;} Motion;
extern int func_001757E0(u8 *,int,int);
#define OWNER(p) (*(u8 **)((p)+0x18))

extern u8 *D_004C297C __attribute__((section(".sdata")));
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern f32 D_00463960[],D_00463964[],D_00463968[],D_0046396C[];
extern void func_00368FB0(u8 *);
extern s32 func_00417690(f32,f32);
#define RESET_ACTION(p,code) do {u32 counterAddress;(p)[0x1b5]=(code);(p)[0x1b2]=*(u16 *)((p)+0x1c0)=0;*(u32 *)((p)+0x1d8)=0;counterAddress=(p)[2]*2;counterAddress+=(u32)D_004C2794;counterAddress+=0x7c;++*(s16 *)counterAddress;}while(0)
void func_00368160(u8 *p) {
 u8 *owner=OWNER(p);Motion *m=(Motion *)p;f32 value;u32 angle;
 if(*(u16 *)D_004C297C!=*(u16 *)(owner+0x168)){func_00368FB0(p);return;}
 if(((s8 *)owner)[0x539])p[7]=1;
 else if((!*(u16 *)(owner+0x354))&(owner[0x1b7]?0x100:0x200))p[7]=1;
 if(((s8 *)owner)[0x151]){
  p[5]++;p[0x13c]=1;p[0x24]=11;p[0x1b0]=68;p[0x1b1]=68;
  if(owner[0x269]==3)RESET_ACTION(p,83);else RESET_ACTION(p,54);
  if(m->facing)value=D_00463960[p[0x1b7]*4];else value=-D_00463960[p[0x1b7]*4];m->vx=value;
  if(m->facing)value=D_00463964[p[0x1b7]*4];else value=-D_00463964[p[0x1b7]*4];m->ax=value;
  m->vy=D_00463968[p[0x1b7]*4];m->ay=D_0046396C[p[0x1b7]*4];m->angle=func_00417690(m->vy,m->vx);
  if(m->facing)angle=-m->angle;else angle=(m->angle+0x7fff+1)&0xffff;m->angle=angle;
  if(p[0x1b7]==0){
   m->x=*(f32 *)(OWNER(p)+0x34)+(m->facing?93.3333282470703125f:-93.3333282470703125f);
   m->y=192.8571319580078125f+*(f32 *)(OWNER(p)+0x38);
  }else{
   m->x=*(f32 *)(OWNER(p)+0x34)+(m->facing?26.6666660308837890625f:-26.6666660308837890625f);
   m->y=237.8571319580078125f+*(f32 *)(OWNER(p)+0x38);
  }
  m->timer=0;m->repeat=2;func_001757E0(p,23,20);
 }
}
