/* Preserve the marker assignment and clear, then snap at the native boundary. */
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
extern int func_00175700(u8 *),func_001757E0(u8 *,int,int);
void func_002645D0(u8 *actor)
{
 float *bound;
 ActorView *p=(ActorView*)actor;
 bound=&p->distance;
 p->x+=p->vx;p->vx+=p->ax;p->y+=p->vy;p->vy+=p->ay;
 func_00175700(actor);
 /* Retail assigns the marker before testing and clearing it. */
 if((p->pause=2))p->pause=0;
 if(actor[2]==0) {
  if(p->x<=*bound) {
   p->phase++;p->x=*bound;p->y+=68.5714263916015625f;
   func_001757E0(actor,1,1);return;
  }
 } else if(!(p->x<*bound)) {
  p->phase++;p->x=*bound;p->y+=68.5714263916015625f;
  func_001757E0(actor,1,1);
 }
}
