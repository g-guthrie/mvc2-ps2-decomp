typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;
typedef struct {u8 prefix[0x34];f32 x,y;} ActorPosition;
typedef struct {u8 prefix[0x5c];f32 vx,vy;u8 unknown64[4];f32 ax,ay;} ActorMotion;
typedef struct {u8 prefix[0x1c];s16 timer;} ActorTimer;
extern u8 D_004D18DB;
extern u16 D_004D18DC;
extern s16 D_004C2170[] __attribute__((section(".sdata")));
extern int func_00175700(u8 *);
extern int func_00174240(u8 *);
void func_003C8BD0(u8 *p)
{
 ActorPosition *position=(ActorPosition *)p;
 ActorMotion *motion=(ActorMotion *)p;
 ActorTimer *clock=(ActorTimer *)p;
 if(!(D_004D18DC & (1u<<D_004D18DB))) {
  s16 timer;
  func_00175700(p);
  position->x+=motion->vx;
  motion->vx+=motion->ax;
  position->y+=motion->vy;
  motion->vy+=motion->ay;
  timer=clock->timer-1;
  clock->timer=timer;
  if(timer<0) {
   p[6]++;
   clock->timer=D_004C2170[p[0x20]];
   *(s16 *)(p+0x1e)=1;
   return;
  }
 }
 if(func_00174240(p))p[0x13c]=1;
 else p[0x13c]=0;
}
