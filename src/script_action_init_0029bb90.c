/* Select the native script and action, including the alternate launch path. */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef struct {
 u8 pad0[6],phase,pad7[0x15];s16 timer;u8 pad1E[3],variant,pad22[0x12];
 float x,y;u8 pad3C[0x20];float vx,vy;u8 pad64[4];float ax,ay;
 u8 pad70[0xD0];s16 facing;u8 pad142[0xF];s8 pause;u8 pad152[9],signal,pad15C[0x56];s8 hit;
 u8 pad1B3[2],category,pad1B6,kind,pad1B8[3],scriptMode,pad1BC[4];unsigned short flags;u8 pad1C2[2];u8 *collisionTarget;u8 pad1C8[0x10];int status;
 u8 pad1DC[0xA],direction,pad1E7[0x15],selection,pad1FD[0x10],air;unsigned short inputFlags;u8 pad210[0x10];u8 *target;u8 pad224[0x92],special,pad2B7;float distance;u8 pad2BC[0x14];u8 *savedTarget;u8 pad2D4[0x68],motionCount,pad33D[0x21];unsigned short buttons;u8 pad360[0xA8];const u8 *script;u8 collisionMode,pad40D[0x1B];unsigned int hitFlags;u8 pad42C[4];float ground;u8 pad434[0x105];s8 automatic;
} ActorView;
typedef struct {u8 prefix[0x7C];s16 count[];} CounterView;
extern CounterView *D_004C2794 __attribute__((section(".sdata")));
extern const u8 D_004C0AF0[] __attribute__((section(".sdata")));
extern const u8 D_004C0AF4[] __attribute__((section(".sdata")));
extern const u8 D_004C0AF8[] __attribute__((section(".sdata")));
extern void func_001E3710(u8 *,u8);
extern int func_001757E0(u8 *,int,int);
void func_0029BB90(u8 *actor)
{
 ActorView *p=(ActorView*)actor;
 func_001E3710(actor,(u8)(p->selection+20));
 switch(p->selection) {
 case 0:p->script=D_004C0AF0;p->scriptMode=0;p->special=1;break;
 case 1:p->script=D_004C0AF4;p->scriptMode=1;break;
 case 2:
  p->script=D_004C0AF8;p->scriptMode=2;
  if(p->inputFlags&0xC00) {
   p->script=0;p->phase=1;p->category=18;p->hit=p->flags=0;p->status=0;
   D_004C2794->count[actor[2]]++;func_001757E0(actor,7,6);return;
  }
  break;
 }
 p->category=p->selection;p->hit=p->flags=0;p->status=0;
 D_004C2794->count[actor[2]]++;func_001757E0(actor,7,p->selection);
}
