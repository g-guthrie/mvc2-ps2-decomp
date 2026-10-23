/* Handle the rise animation, native motion, and descending transition. */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef struct {
 u8 pad0[6],phase,pad7[0x15];s16 timer;u8 pad1E[3],variant,pad22[0x12];
 float x,y;u8 pad3C[0x20];float vx,vy;u8 pad64[4];float ax,ay;
 u8 pad70[0xD0];s16 facing;u8 pad142[0xF];s8 pause;u8 pad152[9],signal,pad15C[0x56];s8 hit;
 u8 pad1B3[2],category,pad1B6,kind,pad1B8[8];unsigned short flags;u8 pad1C2[2];u8 *collisionTarget;u8 pad1C8[0x10];int status;
 u8 pad1DC[0xA],direction,pad1E7[0x26],air,pad20E[0x12];u8 *target;u8 pad224[0x94];float distance;u8 pad2BC[0x14];u8 *savedTarget;u8 pad2D4[0x68],motionCount,pad33D[0x21];unsigned short buttons;u8 pad360[0xAC],collisionMode,pad40D[0x1B];unsigned int hitFlags;u8 pad42C[4];float ground;u8 pad434[0x105];s8 automatic;
} ActorView;
typedef struct {u8 prefix[0x7C];s16 count[];} CounterView;
extern CounterView *D_004C2794 __attribute__((section(".sdata")));
extern const float D_004C0C58[] __attribute__((section(".sdata")));
extern int func_00175700(u8 *),func_001757E0(u8 *,int,int);
/* Complete native motion helper, independently checked at its own address. */
static float func_002ADC20(u8 *actor)
{
 float old=*(float*)(actor+0x5C);
 *(float*)(actor+0x34)+=old;*(float*)(actor+0x5C)+=*(float*)(actor+0x68);
 *(float*)(actor+0x38)+=*(float*)(actor+0x60);*(float*)(actor+0x60)+=*(float*)(actor+0x6C);
 return *(float*)(actor+0x5C)*old;
}
void func_002AF510(u8 *actor)
{
 ActorView *p=(ActorView*)actor;
 func_00175700(actor);
 if(p->signal) {
  p->category=p->signal;p->hit=p->flags=0;p->status=0;
  D_004C2794->count[actor[2]]++;p->signal=0;
 }
 if(p->pause) {
  p->pause=0;p->vy=D_004C0C58[p->kind];p->ay=-0.803571403026580810546875f;
  p->vx/=2.0f;p->y+=10.0f;
 }
 {
  float distance=func_002ADC20(actor);
  float zero=0.0f;
  if(distance<zero) {p->vx=zero;p->ax=zero;}
 }
 {
  float zero=0.0f;
  if(p->vy<zero) {
   p->phase++;p->vx=zero;p->ax=zero;p->vy=-2.142857074737548828125f;
   func_001757E0(actor,21,(u8)(p->kind+8));
  }
 }
}
