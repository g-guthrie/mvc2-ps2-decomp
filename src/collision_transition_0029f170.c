/* Ground handling, timed emissions, and collision-status transitions. */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef struct {
 u8 prefix[0x1C];s16 timer,counter;u8 gap20[0x14];
 float x,y,z;u8 gap40[0x1C];float vx,vy;u8 gap64[4];float ax,ay;u8 gap70[0x288];s32 status;
} MotionView;
extern u8 D_004F1F45,D_004F1F46;
extern int func_00175700(u8 *),func_001757E0(u8 *,int,int);
extern void func_00183D50(u8 *),func_00390C40(void *,u8,u8),func_0018FDB0(u8 *),func_00191480(u8 *,u8 *,int);
void func_0029F170(u8 *actor)
{
 u8 *target=*(u8**)(actor+0x1DC);
 float *vx;
 float *vy;
 float *ax;
 float *ay;
 MotionView *p=(MotionView*)actor;
 vx=&p->vx;vy=&p->vy;ax=&p->ax;ay=&p->ay;
 ((u8*)p)[0x1FE]=1;((u8*)p)[0x201]=2;
 p->x+=p->vx;
 p->vx+=p->ax;
 p->y+=p->vy;
 p->vy+=p->ay;
 func_00175700((u8*)p);
 {
  float ground=*(float*)((u8*)p+0x430);
  if(!(ground<=p->y)) {
   p->y=ground;func_00183D50((u8*)p);
   *vx=0;*vy=0;*ax=0;*ay=0;func_001757E0((u8*)p,22,14);
  }
 }
 if(p->counter<=4) {
  s16 timer=p->timer-1;
  p->timer=timer;
  if(timer<0) {
   p->timer=2;func_00390C40(p,0,(u8)p->counter);
   (p->counter)++;
  }
 }
 {
  s32 status=p->status;
  if(status) {
   if(status<0) {
    ((u8*)p)[6]++;((u8*)p)[7]=0;p->timer=32;func_001757E0((u8*)p,22,7);
    D_004F1F45=2;D_004F1F46=1;target[0x20A]=16;target[0x1B5]=74;
   } else {D_004F1F45=1;D_004F1F46=1;target[0x1B5]=71;}
   p->status=0;*(u8**)(target+0x1C8)=(u8*)p;
   func_0018FDB0((u8*)p);func_00191480(target,(u8*)p,1);
  }
 }
}
