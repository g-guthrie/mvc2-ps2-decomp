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
extern int func_00175910(u8 *,int,int,int);
extern int func_00174170(void);
extern u8 *D_004C2794 __attribute__((section(".sdata")));
#define OWNER(p) (*(u8 **)((p)+0x18))
#define COPY_FIELDS(p) do { (p)[0x13c]=1;(p)[2]=OWNER(p)[2];(p)[1]=OWNER(p)[1];*(f32 *)((p)+0x50)=*(f32 *)(OWNER(p)+0x50);*(f32 *)((p)+0x54)=*(f32 *)(OWNER(p)+0x54);(p)[0x1b7]=OWNER(p)[0x1b7];(p)[0x1b8]=OWNER(p)[0x1b8];((s8 *)(p))[0x30]=((s8 *)OWNER(p))[0x30];*(V3 *)((p)+0x50)=*(V3 *)(OWNER(p)+0x50);((Motion *)(p))->mode=((Motion *)OWNER(p))->mode;}while(0)
#define RESET_PLAYER(p,code,player) do {CounterState *counterState;(p)[0x1b5]=(code);(p)[0x1b2]=*(u16 *)((p)+0x1c0)=0;*(u32 *)((p)+0x1d8)=0;counterState=(CounterState *)D_004C2794;counterState->counters[*(player)]++;}while(0)

extern s16 D_00462C00[][2];
extern f32 D_00462C10[1] __attribute__((section(".rodata")));
extern f32 D_00462C30[];
void func_003564A0(u8 *p) {
 Motion *m=(Motion *)p;u8 *player;s32 count;s32 *d,*s;u32 index;f32 x,y;
 p[4]++;
 if(p[0x20]==0){p[0x13c]=0;*(s16 *)(p+0x1e)=3;return;}
 d=(s32 *)(p+0xec);count=49;s=(s32 *)(OWNER(p)+0xec);
 do{*d=*s;count--;s++;d++;}while(count>0);
 COPY_FIELDS(p);
 p[0x13c]=1;p[0x24]=11;m->x=*(f32 *)(OWNER(p)+0x34);m->y=*(f32 *)(OWNER(p)+0x38);*(s16 *)(p+0x1e)=35;
 player=p+2;
 if((!(u32)func_00174170())&3){p[0x1b0]=0;p[0x1b1]=0;p[0x21]=1;}
 else {
  u8 action=57;
  if(((u32)func_00174170()&3)==0)action=56;
  RESET_PLAYER(p,action,player);p[0x21]=0;p[0x1b0]=68;p[0x1b1]=68;
 }
 m->x=*(f32 *)(OWNER(p)+0x34);m->y=*(f32 *)(OWNER(p)+0x38);
 index=(u32)func_00174170()&3;
 x=1.6666666269302368f*D_00462C00[index][0];y=D_00462C10[0];
 if(!*(s16 *)(p+0x140)){x=-x;y=-y;}
 m->x+=x;m->y+=2.142857074737549f*D_00462C00[index][1];m->vx=y;
 m->vy=D_00462C30[(u32)func_00174170()&7];m->ax=0;m->ay=0;
 p[0x21]=func_00174170()&7;
 func_00175910(p,22,4,(u32)func_00174170()%3);
}
