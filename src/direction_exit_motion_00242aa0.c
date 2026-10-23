/* Update direction-dependent movement and its work-context transition. */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef struct {
 u8 pad0[6],phase,subphase,pad8[0x14];s16 timer;u8 pad1E[3],variant,aim,pad23[0x11];
 float x,y;u8 pad3C[0x20];float vx,vy;u8 pad64[4];float ax,ay;
 u8 pad70[0xD0];s16 facing;u8 pad142[0xE];s8 marker,pause,frameRemaining;u8 pad153[8],signal,pad15C[0x56];s8 hit;
 u8 pad1B3[2],category,pad1B6,kind,pad1B8[3],scriptMode,pad1BC[4];unsigned short flags;u8 pad1C2[2];u8 *collisionTarget;u8 pad1C8[0x10];int status;
 u8 pad1DC[0xA],direction,pad1E7[0x15],selection,pad1FD[0xC];s8 flag209;u8 pad20A[3],air;unsigned short inputFlags;u8 pad210;s8 edge;u8 pad212[0xE];u8 *target;u8 pad224[0x92],special,pad2B7;float distance;u8 pad2BC[0x14];u8 *savedTarget;u8 pad2D4[0x68],motionCount,pad33D[0x21];unsigned short buttons;u8 pad360[0xA8];const u8 *script;u8 collisionMode,pad40D[0x1B];unsigned int hitFlags;u8 pad42C[4];float ground;u8 pad434[0x105];s8 automatic;
} ActorView;
extern int func_00175700(u8 *),func_00175910(u8 *,int,int,int);
extern void func_002413C0(u8 *,float *);
void func_00242AA0(u8 *actor,u8 *context)
{
 ActorView *p=(ActorView*)actor;
 int edge=p->edge;
 if(edge&&!((s8)edge&(1u<<p->direction)))goto transition;
 p->flag209=0;func_00175700(actor);func_002413C0(actor,(float*)context);
 if(p->subphase==0) {
  if(p->marker)return;
  p->subphase++;p->vx=-5.416666507720947265625f;p->ax=-1.25f;
  p->vy=-6.428571224212646484375f;p->ay=-0.9375f;
  if(p->direction) {p->vx=-p->vx;p->ax=-p->ax;}
 }
 {float acceleration=p->ax;float velocity=p->vx;
  velocity+=acceleration;p->vx=velocity;p->x+=velocity;
 }
 p->y+=p->vy;
 if((p->edge&(1u<<(p->direction^1)))||!((1u<<p->aim)&0xFF00000Fu))goto transition;
 return;
transition:
 *(s8*)(context+0x20)=-1;p->phase++;p->subphase=0;p->frameRemaining=1;
 p->vx=-10.0f;p->ax=0;p->vy=12.85714244842529296875f;p->ay=-0.9375f;
 if(p->direction) {p->vx=-p->vx;p->ax=-p->ax;}
 func_00175910(actor,20,3,4);
}
