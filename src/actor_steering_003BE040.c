typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;
typedef struct {f32 x,y,z;} V3;
typedef struct {u8 prefix[0x34];f32 x,y;} ActorPosition;
typedef struct {u8 prefix[0x5c];f32 vx,vy;u8 unknown64[4];f32 ax,ay;} ActorMotion;
typedef struct {u8 prefix[0x1c];s16 timer,rotation;} ActorClock;
extern int func_001748C0(u8 *,u8 *);
extern void func_00174910(u8 *,int);
extern void func_003BE2C0(u8 *,u8 *);
void func_003BE040(u8 *p,void *context)
{
 u8 *q=(u8 *)context;
 ActorPosition *position=(ActorPosition *)p;
 ActorMotion *motion=(ActorMotion *)p;
 ActorClock *clock=(ActorClock *)p;
 s16 timer;
 position->x+=motion->vx;
 motion->vx+=motion->ax;
 position->y+=motion->vy;
 motion->vy+=motion->ay;
 timer=clock->timer-1;
 clock->timer=timer;
 if(timer==0)p[5]++;
 if(*(u32 *)(p+0xd4)==0) {
  s16 rotation=clock->rotation+0x4000;
  clock->rotation=rotation;
  if(rotation==0) {
   V3 target=*(V3 *)(*(u8 **)(q+0x220)+0x34);
   u8 direction;
   int angle;
   target.y+=137.142852783203125f;
   angle=func_001748C0(p+0x34,(u8 *)&target)&0xff;
   direction=angle>>3;
   if(direction!=p[0x22]) {
    p[0x22]++;
    if(((p[0x22]-direction)&31)<16)p[0x22]-=2;
    p[0x22]&=31;
    func_00174910(p,0x2bc);
   }
  }
 }
 func_003BE2C0(p,q);
}
