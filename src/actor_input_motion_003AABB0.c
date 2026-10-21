#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef int s32;
typedef float f32;
typedef struct {u8 prefix[0x366];u16 pressed;} OwnerInput;
typedef struct {u8 prefix[0x68];f32 divisor;} ActorDivisor;
typedef struct {u8 prefix[8];s16 timer;u8 unknown[5];s8 count;} Control;
extern void func_003AB180(u8 *,u8 *);
extern void func_003AADA0(u8 *,u8 *);
extern void func_003AD2D0(u8 *,u8 *);
extern void func_003AA3C0(s32,f32 *);
void func_003AABB0(u8 *p,u8 *q)
{
 u8 *owner=*(u8 **)(p+0x18);
 OwnerInput *input=(OwnerInput *)owner;
 ActorDivisor *motion=(ActorDivisor *)p;
 Control *control=(Control *)q;
 f32 delta[2];
 if(((s8 *)owner)[0x1b2] || ((s8 *)p)[0x1b2]) {
  func_003AB180(p,q);return;
 }
 input->pressed|=*(s16 *)(owner+0x362)&0x360;
 if(control->count>7) {
  u16 pressed=input->pressed;
  u16 mask=0x320;
  input->pressed=0;
  if(owner[0x20d]==2)mask|=0x40;
  if(pressed&mask) {func_003AADA0(p,q);return;}
 }
 if(*(f32 *)(owner+0x430)>*(f32 *)(p+0x38)) {
  func_003AD2D0(p,q);return;
 }
 func_003AA3C0(p[0x22],delta);
 delta[0]/=motion->divisor;
 delta[1]/=motion->divisor;
 *(f32 *)(p+0x5c)+=delta[0];
 *(f32 *)(p+0x60)+=delta[1];
 *(f32 *)(p+0x34)=*(f32 *)(q+0x10)+*(f32 *)(p+0x5c);
 *(f32 *)(p+0x38)=*(f32 *)(q+0x14)+*(f32 *)(p+0x60);
 p[0x13c]=1;q[0x34]=1;
 if(--control->timer<=0) {
  control->timer=8;
  motion->divisor*=2.0f;
  if(motion->divisor>32.0f) {
   owner[6]=3;p[5]=2;
   control->timer=0xe00;
   *(s16 *)(q+10)=p[0x22];
   q[0x33]=0;
  }
 }
 q[15]=0;
}

typedef struct {u8 prefix[0x1c];s16 timer;} ActorTimer;
typedef struct {u8 prefix[0x34];f32 x,y;} ActorPosition;
extern void func_003AB400(u8 *,void *);
extern void func_003AC580(u8 *,u8 *);
extern void func_003AADA0(u8 *,u8 *);
extern void func_003ACCC0(u8 *,u8 *,u8 *,u8 *);
extern void func_001823C0(u8 *);
void func_003AB270(u8 *p,u8 *q)
{
 u8 *owner=*(u8 **)(p+0x18);
 ActorPosition *position=(ActorPosition *)p;
 ActorTimer *timer=(ActorTimer *)p;
 u8 *target;
 owner[0x201]=3; owner[0x206]=3;
 if(owner[6]==6) {func_003AB400(p,q);return;}
 if(owner[6]==9 || owner[6]==10) {func_003AC580(p,q);return;}
 target=*(u8 **)(owner+0x1dc);
 if(target[5]!=2) {owner[6]=2;func_003AADA0(p,q);return;}
 if(--timer->timer<=0) {target[0x20a]=7;owner[6]=2;func_003AADA0(p,q);return;}
 *(f32 *)(p+0x34)=*(f32 *)(p+0x5c)+*(f32 *)(q+0x10);
 position->y=*(f32 *)(p+0x60)+*(f32 *)(q+0x14);
 *(f32 *)(q+0x2c)=*(f32 *)(p+0x34);
 {f32 dy=position->y-(137.14285278320312f+*(f32 *)(owner+0x430));
 if(dy<0.0f) {
 *(f32 *)(owner+0x38)-=dy;
 position->y-=dy;
 }}
 func_003ACCC0(p,q,*(u8 **)(q+0x28),owner);
 *(f32 *)(owner+0x34)+=*(f32 *)(p+0x34)-*(f32 *)(q+0x2c);
 func_001823C0(owner);
 p[0x13c]=1;q[0x34]=1;q[15]=0;
}
