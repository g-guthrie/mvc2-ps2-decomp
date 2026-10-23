/* Search the three native target slots and advance or restore the default action. */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef struct {u8 mode,pad1,tag,pad3,selected;s8 ready;u8 pad6[2];} SearchWork;
typedef struct {
 u8 pad0[6],phase,pad7[0x15];s16 timer;u8 pad1E[3],variant,pad22[0x12];
 float x,y;u8 pad3C[0x20];float vx,vy;u8 pad64[4];float ax,ay;
 u8 pad70[0xD0];s16 facing;u8 pad142[0xF];s8 pause;u8 pad152[9],signal,pad15C[0x56];s8 hit;
 u8 pad1B3[2],category,pad1B6,kind,pad1B8[8];unsigned short flags;u8 pad1C2[2];u8 *collisionTarget;u8 pad1C8[0x10];int status;
 u8 pad1DC[0xA],direction,pad1E7[0x26],air,pad20E[0x12];u8 *target;u8 pad224[0x94];SearchWork state;u8 pad2C0[0x10];u8 *savedTarget;u8 pad2D4[0x67],motionPending,motionCount,pad33D[0x21];unsigned short buttons;u8 pad360[0xAC],collisionMode,collisionPending,pad40E[0x1A];unsigned int hitFlags;u8 pad42C[4];float ground;u8 pad434[0x105];s8 automatic;
} ActorView;
extern u8 *func_00319410(u8,u8);
extern int func_00175700(u8 *),func_001757E0(u8 *,int,int);
extern void func_001843A0(u8 *);
void func_00319480(u8 *actor)
{
 u8 *target;
 ActorView *p=(ActorView*)actor;
 SearchWork *state;
 p->collisionMode=2;p->motionCount=5;
 if((s8)func_00175700(actor)>=0)return;
 state=&p->state;
 if(!p->state.ready)goto none;
 p->phase++;state->selected=0;
 if((target=func_00319410(p->target[2],0))!=0)goto have;
 if((target=func_00319410(p->target[2],1))!=0)goto have;
 if((target=func_00319410(p->target[2],2))==0)goto none;
have:
 if(target[0x425])goto none;
 {
  float zero;
  p->vx=(*(float*)(target+0x34)-p->x)/32.0f;p->ax=0;
  zero=0;p->facing=p->vx<zero?0:1;
 }
 p->direction=*(s8*)(actor+0x140);p->state.tag=31;p->state.mode=57;
 func_001757E0(actor,0,2);return;
none:
 p->collisionPending=0;p->collisionMode=0;p->motionPending=0;p->motionCount=0;
 func_001843A0(actor);
}
