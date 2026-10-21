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

extern int func_0019FC30(u8 *,s32);
extern int func_00182D30(u8 *);
extern void func_001843A0(u8 *);
extern void func_001845F0(u8 *);
void func_0035BC20(u8 *p,u8 *context) {
 u8 *flags=context+0x2b8;u8 *link;u32 slot;Motion *m=(Motion *)p;
 if(*(u8 **)(*(u8 **)(p+0x1e0)+0x1e0)!=p){p[4]=2;m->timer=0;func_001E3210(p,35);func_0019FC30(p,p[0x22]);return;}
 func_00175700(p);link=LINK(p);slot=p[0x23];link[0x1ff]=2;*(V3 *)(p+0x34)=*(V3 *)(link+0x34);
 if(((s8 *)link)[0x1b3]){
  if(link[5]!=3){p[0x152]=1;func_00175700(p);}else{m->timer=0;flags[slot+1]|=0x80;}
 }
 link[0x13c]=0;
 if(func_00182D30(link)){p[0x152]=1;m->timer-=p[0x1b7]*4+3;}
 if(--m->timer<0){
  p[5]++;flags[slot+1]&=0xfd;
  if(!*(s16 *)(link+0x434))link[0x20a]=7;
  else{
   link[0x20a]=0;
   if(!(flags[slot+1]&0x80)){
    if(p[0x1b7])link[0x203]=8;
    if(link[0x20d]!=2)func_001843A0(link);else func_001845F0(link);
   }
  }
  func_001E3210(p,35);func_0019FC30(p,p[0x22]);
 }
}
