typedef unsigned char u8;
typedef signed short s16;
typedef float f32;
typedef struct { f32 x,y; } PositionDelta;
typedef struct { f32 vx,ax,vy,ay; } MotionPreset;
typedef struct {u8 prefix[0x34]; f32 x,y;} ActorPosition;
typedef struct {u8 prefix[0x5c];f32 vx,vy;u8 unknown64[4];f32 ax,ay;} ActorMotion;
extern PositionDelta D_004747E0[];
extern MotionPreset D_004748A0[];
void func_003BD2E0(u8 *p)
{
 u8 *owner=*(u8 **)(p+0x18);
 ActorPosition *position=(ActorPosition *)p;
 ActorMotion *motion=(ActorMotion *)p;
 f32 xdelta=D_004747E0[p[0x20]*5+p[0x21]].x;
 f32 ax,vx;
 if(owner[0x1e6]==0)xdelta=-xdelta;
 position->x+=xdelta;
 position->y+=D_004747E0[p[0x20]*5+p[0x21]].y;
 motion->vy=D_004748A0[p[0x20]*5+p[0x21]].vy;
 motion->ay=D_004748A0[p[0x20]*5+p[0x21]].ay;
 vx=D_004748A0[p[0x20]*5+p[0x21]].vx;
 ax=D_004748A0[p[0x20]*5+p[0x21]].ax;
 if(*(s16 *)(owner+0x140)==0) {vx=-vx;ax=-ax;}
 motion->vx=vx;
 motion->ax=ax;
}
