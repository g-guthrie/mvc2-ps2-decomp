#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef struct {u8 prefix[0x34];f32 x,y,z;u8 gap40[8];u32 angle;s16 originX,originY;f32 scaleX,scaleY,scaleZ,vx,vy,vz,ax,ay;} Motion;
extern int func_00175700(u8 *);
extern int func_001757E0(u8 *,int,int);
extern void func_001E7F60(u8 *);
extern void func_001E3210(u8 *,int);
#define OWNER(p) (*(u8 **)((p)+0x18))
#define LINK(p) (*(u8 **)((p)+0x14))

extern u8 *D_004C2974 __attribute__((section(".sdata")));
extern u8 *D_004C2978 __attribute__((section(".sdata")));
extern int func_00185980(u8 *);
extern void func_00185870(u8 *,u8 *);
extern void func_00182C30(u8 *,int);
extern void func_00179160(void *,void *);
extern void func_0018D9A0(u8 *);
extern int func_00174470(u8 *);
extern void func_00367140(u8 *);
extern void func_003671D0(u8 *,u8 *);
extern void func_003670F0(u8 *);
extern void func_00367F60(u8 *);
void func_003663E0(u8 *p) {
 Motion *m=(Motion *)p;u8 *target;
 func_00175700(p);m->x+=m->vx;m->vx+=m->ax;
 if(D_004C2974[0xe]){D_004C2974[6]=1;D_004C2974[7]=((s8 *)p)[0x140]^1;func_001E3210(p,48);func_00367140(p);return;}
 if(*(s16 *)(p+0x1c)<0){D_004C2974[6]=1;func_001E3210(p,48);func_00367140(p);return;}
 if(((s8 *)D_004C2974)[0xf]){p[0x1b0]=0;p[0x1b1]=0;LINK(p)[0x1b0]=0;LINK(p)[0x1b1]=0;}
 if(((s8 *)p)[0x1b2]) {
  target=*(u8 **)(p+0x1c4);
  if(func_00185980(p)==0){D_004C2974[6]=1;func_00367140(p);return;}
  p[5]=1;p[0x24]=0;OWNER(p)[0x20b]=195;func_00185870(p,target);
  target[0x20a]=6;*(s16 *)(p+0x1e)=128;func_00182C30(target,30);func_001757E0(p,15,6);
  ((Motion *)target)->vx=0;((Motion *)target)->vy=0;((Motion *)target)->ax=0;((Motion *)target)->ay=0;
  if(target[0x20d]==2)((Motion *)target)->y=*(f32 *)(target+0x430);
  {u8 *effect=*(u8 **)(p+0x1dc);
   if(*(u32 *)(effect+0x42c)&0x04000000)((Motion *)effect)->y=128.57142639160156f+*(f32 *)(OWNER(p)+0x430);
   else if(*(u32 *)(effect+0x428)&0x20000000)((Motion *)effect)->y=68.57142639160156f+*(f32 *)(OWNER(p)+0x430);
  }
  func_00179160(p,target);func_003671D0(p,target);return;
 }
 if(((s8 *)p)[0x1b3] || ((s8 *)LINK(p))[0x1b3]) {
  if(((s8 *)p)[0x1b3])target=*(u8 **)(p+0x1c8);else target=*(u8 **)(LINK(p)+0x1c8);
  func_0018D9A0(p);func_001E3210(p,44);D_004C2974[7]=((s8 *)target)[0x140];
  if(target[2]!=p[2] || target[1]!=17) {
   if(--D_004C2974[5]<=0 || (target[3]==1 && *(u16 *)(target+0x26)==0x1101)) {D_004C2974[6]=1;func_001E3210(p,48);}
   else {func_003670F0(p);return;}
  }
  p[7]=2;func_00367140(p);return;
 }
 if(func_00174470(p)==0){D_004C2978[2]=0;func_00367F60(p);return;}
 if(--*(s16 *)(D_004C2974+0xc)==0){*(s16 *)(D_004C2974+0xc)=180;func_001E3210(p,49);}
 func_001E7F60(p);
}
