#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef float f32;
typedef struct {u8 prefix[0x1c];s16 timer,repeat;} ActorTimers;
extern void func_003563E0(u8 *);
extern void func_003568E0(u8 *);
extern int func_001757E0(u8 *,int,int);
extern void func_001E7F60(u8 *);
void func_00356770(u8 *p) {
 ActorTimers *timers=(ActorTimers *)p;
 if(p[0x20]==0) {
  u8 *owner;
  if(--timers->repeat<=0) {timers->repeat=3;func_003563E0(p);}
  owner=*(u8 **)(p+0x18);
  if(owner[6]>=4) {p[4]++;func_003568E0(p);return;}
  if(*(u16 *)(owner+0x168)!=*(s16 *)(p+0x1c)) {p[4]++;func_003568E0(p);}
 } else {
  if(((s8 *)p)[0x1b2] || ((s8 *)p)[0x1b3] || --timers->repeat<=0) {
   p[4]++;func_001757E0(p,22,5);func_003568E0(p);
  } else {
   *(f32 *)(p+0x34)+=*(f32 *)(p+0x5c);
   *(f32 *)(p+0x5c)+=*(f32 *)(p+0x68);
   *(f32 *)(p+0x38)+=*(f32 *)(p+0x60);
   *(f32 *)(p+0x60)+=*(f32 *)(p+0x6c);
   p[0x21]=(((s8 *)p)[0x21]+1)&7;
   if(p[0x21]==0)func_001E7F60(p);
  }
 }
}
