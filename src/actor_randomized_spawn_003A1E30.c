#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
#include "actor_inherited_state.h"

typedef struct { u8 prefix[0x24]; s8 palette; } ActorPalette;
extern int func_00174170(void);
extern int func_001757E0(u8 *,int,int);
extern void func_003DAA40(u8 *);
extern void (*D_00472B30[])(u8 *,u8 *);
void func_003A1E30(u8 *p)
{
 ActorPalette *palette=(ActorPalette *)p;
 u8 *q=*(u8 **)(p+0x18);
 if(p[4]>=2) {
  if(p[0x20]==0)q[0x2c4]=0;
  func_003DAA40(p);
 } else if(p[4]==0) {
  s16 r;
  p[4]++;
  *(ActorState *)(p+0xec)=*(ActorState *)(q+0xec);
    p[0x13C] = 1;
        p[2] = q[2];
    p[1] = q[1];
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
    p[0x1B7] = q[0x1B7];
    p[0x1B8] = q[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(q + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);


  p[0x1b0]=0x42;
  p[0x1b1]=0x42;
  *(f32 *)(p+0x34)=13.333333015441895f+*(f32 *)(q+0x34);
  *(f32 *)(p+0x38)=171.428558349609375f+*(f32 *)(q+0x38);
  r=(func_00174170()&31)+32;
  if(r&1)r=-r;
  *(f32 *)(p+0x34)+=1.6666666269302368f*(f32)r;
  r=func_00174170()&31;
  if(r&1)r=-r;
  *(f32 *)(p+0x38)+=2.142857074737549f*(f32)r;
  p[0x14c]=p[0x14d]=p[0x14e]=p[0x14f]=48;
  p[0x1b2]=0;
  if((p[0x21]=func_00174170()&3)!=0)((s8 *)p)[0x31]=-7;
  else ((s8 *)p)[0x31]=7;
  func_001757E0(p,0x15,7);
 } else {
  D_00472B30[p[5]](p,q);
 }
 palette->palette=((ActorPalette *)q)->palette+((s8 *)p)[0x31];
 { int value=palette->palette;
   if(value>7)palette->palette=7;
   value=palette->palette;
   if(value<0)palette->palette=0; }
}
