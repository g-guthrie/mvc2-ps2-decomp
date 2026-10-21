#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef struct {f32 x,y,z;} V3;
#include "actor_inherited_state.h"
struct Object;
extern void func_003DAA40(struct Object *);
extern void func_001CB5A0(u8 *,int,int);
extern void func_0015E630(u8 *);
extern const u32 jtbl_0044DA80[16];
/* Every native table call supplies child and its actual owner. */
typedef void (*OwnerState)(u8 *,u8 *);
typedef struct {u8 prefix[0xd0];s32 state;} ActorOwnerCache;
void func_001CAF00(u8 *p) {
 ActorOwnerCache *cache=(ActorOwnerCache *)p;
 u8 *q=*(u8 **)(p+0x18);
 if(p[4]>=2) {func_003DAA40((struct Object *)p);return;}
 if(p[4]==0) {
  p[0]=1;p[4]++;
  *(ActorState *)(p+0xec)=*(ActorState *)(q+0xec);
  p[0x13c]=1;p[2]=q[2];p[1]=q[1];
  *(f32 *)(p+0x50)=*(f32 *)(q+0x50);
  *(f32 *)(p+0x54)=*(f32 *)(q+0x54);
  p[0x1b7]=q[0x1b7];p[0x1b8]=q[0x1b8];
  *(s8 *)(p+0x30)=*(s8 *)(q+0x30);
  *(V3 *)(p+0x50)=*(V3 *)(q+0x50);
  *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
  p[0x24]=12;
  *(f32 *)(p+0x34)=*(f32 *)(q+0x34);
  *(f32 *)(p+0x38)=*(f32 *)(q+0x38);
  *(s16 *)(p+0x140)=*(s16 *)(q+0x140);
  cache->state=0;p[5]=0;
  func_001CB5A0(p,27,80);func_0015E630(p);
 } else {
  s32 index;
  u32 address;
  if(q[0] && ((s8 *)q)[0x13c]) {
   p[0x13c]=1;p[0]=1;
   if(q[0x15f]!=cache->state) {
    cache->state=q[0x15f];p[5]=0;((s8 *)p)[0x151]=-1;
   }
  } else {p[0]=0;p[0x13c]=0;}
  index=cache->state>>1;
  address=jtbl_0044DA80[index];
  ((OwnerState)address)(p,q);
 }
}
