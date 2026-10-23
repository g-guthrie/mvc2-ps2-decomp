/* Airborne input selection, horizontal movement, and landing. */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef struct {
 u8 pad0[6],phase,pad7[0x15];s16 timer;u8 pad1E[0x16];
 float x,y;u8 pad3C[0x20];float vx,vy;u8 pad64[4];float ax,ay;
 u8 pad70[0x19D],air,pad20E[4],aiInput,pad213[0x141];
 unsigned short buttons;u8 pad356[0xDA];float ground;u8 pad434[0x105];s8 automatic;
} ActorView;
extern int func_00175700(u8 *),func_001757E0(u8 *,int,int);
extern void func_00183D50(u8 *);
void func_002C8C20(u8 *actor,void *context_unused)
{
 ActorView *p=(ActorView*)actor;
 float *vx,*vy,*ax,*ay;
 if(!(p->y-p->ground<=137.142852783203125f)&&p->vy<0.0f) {
  int automatic=p->automatic;
  if((automatic&&p->aiInput)||(!automatic&&(p->buttons&0x300))) {p->phase++;p->timer=10;return;}
 }
 vx=&p->vx;ax=&p->ax;vy=&p->vy;ay=&p->ay;
 p->x+=p->vx;p->vx+=p->ax;
 p->y+=p->vy;p->vy+=p->ay;
 func_00175700(actor);
 if(!(p->y<=p->ground)) {
  if(!p->automatic) {
   unsigned int buttons=p->buttons;
   if(buttons&0x800) {p->vx=-5;return;}
   if(buttons&0x400) {p->vx=5;return;}
  }
 } else {
  p->phase=8;p->y=p->ground;p->air=1;
  *vx=0;*vy=0;*ax=0;*ay=0;func_00183D50(actor);func_001757E0(actor,21,12);
 }
}
