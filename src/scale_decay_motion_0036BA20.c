typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef struct {f32 x,y,z;} V3;
typedef struct {u8 prefix[0x14];u8 *link,*owner;s16 timer,repeat;u8 kind,phase,frame,slot;s8 mode;u8 gap25[0xf];f32 x,y,z;u8 gap40[8];u32 angle;s16 originX,originY;f32 scaleX,scaleY,scaleZ,vx,vy,vz,ax,ay;u8 gap70[0x60];s32 remaining;u8 gapd4[0x44];f32 intensity;u8 gap11c[0x20];s8 active;u8 gap13d[3];s16 facing;u8 gap142[0xf];s8 animPhase;} Motion;
extern int func_00175700(u8 *);

void func_0036BA20(u8 *p) {
 Motion *m=(Motion *)p;
 func_00175700(p);
 m->scaleX-=(f32)(0.06+0.02*m->timer);
 if(m->scaleX<0.01){p[5]++;m->timer=8;m->scaleX=0.04f;m->ay=-0.1f;}
 m->timer++;m->x+=m->vx;m->vx+=m->ax;m->scaleY+=m->vy;m->vy+=m->ay;
 if(m->scaleY<0.01)m->scaleY=0.01f;
}
