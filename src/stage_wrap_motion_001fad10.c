/* Context-matched motion, landing, and stage-edge wrap transitions. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef struct {
 u8 pad0[6],phase,pad7[0x15];s16 timer;u8 pad1E[3],variant,pad22[0x12];
 float x,y;u8 pad3C[0x20];float vx,vy;u8 pad64[4];float ax,ay;
 u8 pad70[0xD0];s16 facing;u8 pad142[0x19],signal,pad15C[0x56];s8 hit;
 u8 pad1B3[2],category,pad1B6[0xA];unsigned short flags;u8 pad1C2[0x16];int status;
 u8 pad1DC[0xA],direction,pad1E7[0x26],air,pad20E[0x12];u8 *target;u8 pad224[0x118],motionCount,pad33D[0xCF],collisionMode,pad40D[0x23];float ground;
} ActorView;
typedef struct {u8 pad[0x7C];s16 counters[];} SharedCounters;
extern SharedCounters *D_004C2794 __attribute__((section(".sdata")));
extern float D_004F1FC8,D_004F1FCC;
extern int func_00175700(u8 *),func_001757E0(u8 *,int,int);
extern void func_00184540(u8 *),func_00183D50(u8 *);
void func_001FAD10(u8 *actor,void *context)
{
 u8 *target;
 ActorView *p=(ActorView*)actor;
 u8 *work=context;
 p->collisionMode=2;p->motionCount=5;target=p->target;
 if(target[1]!=work[1]) {
  p->vx=0;p->vy=0;p->ax=0;p->ay=0;
  func_00184540(actor);return;
 }
 if(p->variant==1) {
  float *vx,*vy,*ax,*ay;
  func_00175700(actor);
  vx=&p->vx;ax=&p->ax;vy=&p->vy;ay=&p->ay;
  p->x+=p->vx;p->vx+=p->ax;
  p->y+=p->vy;p->vy+=p->ay;
  if(p->y<p->ground) {
   p->y=p->ground;p->phase=4;*vx=0;*vy=0;*ax=0;*ay=0;p->air=0;
   func_00183D50(actor);func_001757E0(actor,1,3);
  }
 } else {
  if((s8)func_00175700(actor)<0) {
   p->vx/=4.0f;p->vy=17.142856597900390625f;
   p->ay=-2.142857074737548828125f;p->phase=7;return;
  }
  p->x+=p->vx;p->vx+=p->ax;
  p->y+=p->vy;p->vy+=p->ay;
  if(!(D_004F1FC8-26.6666660308837890625f<=p->x))p->x=D_004F1FC8-80.0f;
  {float right=26.6666660308837890625f+D_004F1FCC;
   if(right<p->x)p->x=80.0f+D_004F1FC8;
  }
  if(p->variant!=1) {
   float offset=p->direction?100.0f:-100.0f;
   *(float*)(target+0x34)=p->x+offset;
  }
  if(p->signal) {
   p->category=p->signal;p->hit=p->flags=0;p->status=0;
   D_004C2794->counters[((u8*)p)[2]]++;p->signal=0;
  }
 }
}
