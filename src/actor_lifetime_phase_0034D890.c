#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef struct {u8 prefix[5];u8 state;u8 gap06[0x12];u8 *owner;s16 delay,angle;u8 mode;u8 gap21;s8 phase;u8 gap23[0x39];f32 vx,vy;u8 gap64[4];f32 ax,ay;u8 gap70[0xcc];u8 active;u8 gap13D[0x75];s8 hit,ground,flash;} SceneActor;
typedef struct {f32 x,y;u8 b8;} G40;
extern G40 *D_004C2940 __attribute__((section(".sdata")));
extern u8 *D_004C2840 __attribute__((section(".sdata")));
extern int func_001757E0(u8 *,int,int);
extern void func_0034DC70(u8 *);
extern void func_0034DC30(u8 *);
extern void func_0034DD60(u8 *,u8);
extern void func_001E7F60(u8 *);
void func_0034D890(u8 *p) {
 SceneActor *a=(SceneActor *)p;
 if(*(s16 *)(a->owner+0x434)==0 || --a->delay==0) {
  a->state++;
  if(a->mode)a->delay=0;
  a->vx=0.0f;a->ax=0.0f;
  a->vy=-4.285714149475098f;
  a->ay=-0.4017857015132904f;
  func_001757E0(p,23,3);
 } else {
  if(a->ground)a->ground=0;
  if(--a->angle==0) {a->angle=2;a->phase=(a->phase+1)&31;}
  func_0034DC70(p);func_0034DC30(p);
  if(a->flash && --a->flash==0)a->hit=0;
 }
 if(((u8 *)D_004C2940)[9]==0) {
  if(a->owner[5]==0 && (*(u16 *)(a->owner+0x35c)&0x300)) {
   func_0034DD60(p,0);
   ((u8 *)D_004C2940)[9]=22;
   ((u8 *)D_004C2940)[9]--;
  }
 } else ((u8 *)D_004C2940)[9]--;
 {u8 count=((u8 *)D_004C2940)[10];
  s32 next=count-1;
  u8 *life=(u8 *)D_004C2940+10;
  if(count==0) {
   a->active=1;func_001E7F60(p);
  } else {
   *life=next;
   a->active=(*(u32 *)(D_004C2840+0x1c)&1)?1:0;
  }
 }
}
