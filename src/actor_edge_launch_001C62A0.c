#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef struct {f32 x,y,z;} V3;
#include "actor_inherited_state.h"
typedef struct {u8 prefix[0x1C];s16 timer,count;} ActorTimer;
extern void func_003DAA40(u8 *);
extern int func_00175700(u8 *);
extern int func_001757E0(u8 *,int,int);
extern void func_001CCF40(u8 *,s32);
extern void func_0015E630(u8 *);
typedef struct {u8 prefix[0x34]; f32 x,y,z;u8 middle[0x1C];f32 vx,vy,vz,ax,ay;} ActorMotion;

extern f32 D_004F1FC8 __attribute__((section(".bss")));
extern f32 D_004F1FCC __attribute__((section(".bss")));
extern void func_001C63B0(u8 *,u8 *);
void func_001C62A0(u8 *p,void *q) {
 ActorMotion *motion=(ActorMotion *)p;
 s16 facing;
 p[7]++;
 p[0x14C]=32;p[0x14D]=32;p[0x14E]=32;p[0x14F]=32;
 facing=*(s16 *)((u8 *)q+0x140);
 *(s16 *)(p+0x140)=facing;
 if(facing==0) {
  motion->x=80.0f+D_004F1FCC;
  motion->vx=-6.666666507720947f;
 } else {
  motion->x=D_004F1FC8-80.0f;
  motion->vx=6.666666507720947f;
 }
 motion->y=68.57142639160156f+*(f32 *)((u8 *)q+0x430);
 motion->ax=0;motion->vy=2.142857074737549f;motion->ay=-0.8035714030265808f;
 func_001757E0(p,25,16);
 p[0]=1;func_0015E630(p);
 func_001C63B0(p,q);
}
