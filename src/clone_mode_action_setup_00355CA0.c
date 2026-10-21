#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef struct {f32 x,y,z;} V3;
typedef struct {u8 prefix[0x7c];s16 counters[];} CounterState;
typedef struct {u8 prefix[0x24];s8 mode;u8 gap25[0xf];f32 x,y,z;u8 gap40[8];u32 angle;s16 originX,originY;f32 scaleX,scaleY,scaleZ,vx,vy,vz,ax,ay;} Motion;
extern int func_001757E0(u8 *,int,int);
extern u8 *D_004C2794 __attribute__((section(".sdata")));
#define OWNER(p) (*(u8 **)((p)+0x18))
#define COPY_FIELDS(p) do { (p)[0x13c]=1;(p)[2]=OWNER(p)[2];(p)[1]=OWNER(p)[1];*(f32 *)((p)+0x50)=*(f32 *)(OWNER(p)+0x50);*(f32 *)((p)+0x54)=*(f32 *)(OWNER(p)+0x54);(p)[0x1b7]=OWNER(p)[0x1b7];(p)[0x1b8]=OWNER(p)[0x1b8];((s8 *)(p))[0x30]=((s8 *)OWNER(p))[0x30];*(V3 *)((p)+0x50)=*(V3 *)(OWNER(p)+0x50);((Motion *)(p))->mode=((Motion *)OWNER(p))->mode;}while(0)
#define RESET_ACTION(p,code) do {u32 counterAddress;(p)[0x1b5]=(code);(p)[0x1b2]=*(u16 *)((p)+0x1c0)=0;*(u32 *)((p)+0x1d8)=0;counterAddress=(p)[2]*2;counterAddress+=(u32)D_004C2794;counterAddress+=0x7c;++*(s16 *)counterAddress;}while(0)
#define RESET_PLAYER(p,code,player) do {CounterState *counterState;(p)[0x1b5]=(code);(p)[0x1b2]=*(u16 *)((p)+0x1c0)=0;*(u32 *)((p)+0x1d8)=0;counterState=(CounterState *)D_004C2794;counterState->counters[*(player)]++;}while(0)

extern u8 D_004C1AA0[] __attribute__((section(".sdata")));
extern u8 D_004C1A98[] __attribute__((section(".sdata")));
void func_00355CA0(u8 *p) {
 u8 *owner;u8 *player;s32 count;s32 *d,*s;Motion *m=(Motion *)p;
 p[4]++;d=(s32 *)(p+0xec);count=49;owner=OWNER(p);s=(s32 *)(owner+0xec);
 do{*d=*s;count--;s++;d++;}while(count>0);
 COPY_FIELDS(p);
 p[0x13c]=1;m->x=*(f32 *)(OWNER(p)+0x34);m->y=*(f32 *)(OWNER(p)+0x38);
 m->vx=0;m->vy=0;m->ax=0;m->ay=0;player=p+2;
 switch(p[0x20]) {
 case 0:
  m->mode=((s8 *)owner)[0x24];((s8 *)p)[0x31]=-1;p[0x1b0]=5;p[0x1b1]=68;
  RESET_PLAYER(p,D_004C1AA0[p[0x20]],player);RESET_ACTION(owner,D_004C1AA0[p[0x20]]);break;
 case 2:
  p[0x1b0]=5;p[0x1b1]=68;if(owner[0x2b8]){p[0x1b0]=0;p[0x1b1]=0;}
  m->mode=((s8 *)owner)[0x24];((s8 *)p)[0x31]=-1;
  RESET_PLAYER(p,D_004C1AA0[p[0x20]],player);RESET_ACTION(owner,D_004C1AA0[p[0x20]]);break;
 case 4:m->mode=7;p[0x1b0]=0;p[0x1b1]=0;break;
 case 6:
  m->mode=11;p[0x1b0]=68;p[0x1b1]=68;
  RESET_PLAYER(p,D_004C1AA0[p[0x20]],player);RESET_ACTION(owner,D_004C1AA0[p[0x20]]);
  m->vx=*(s16 *)(p+0x140) ? 5.0f : -5.0f;
  m->vy=-15.0f;break;
 default:
  m->mode=0;p[0x1b0]=5;p[0x1b1]=68;
  RESET_PLAYER(p,D_004C1AA0[p[0x20]],player);RESET_ACTION(owner,D_004C1AA0[p[0x20]]);break;
 }
 func_001757E0(p,23,D_004C1A98[p[0x20]]);
}
