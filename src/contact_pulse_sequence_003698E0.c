typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef struct {u8 prefix[0x1c];s16 timer,repeat;u8 kind,phase,frame,slot;s8 mode;u8 gap25[0xf];f32 x,y,z;u8 gap40[8];u32 angle;s16 originX,originY;f32 scaleX,scaleY,scaleZ,vx,vy,vz,ax,ay;u8 gap70[0xd0];s16 facing;} Motion;
extern int func_00175700(u8 *);
extern int func_001757E0(u8 *,int,int);
extern void func_001E3710(u8 *,int);
#define OWNER(p) (*(u8 **)((p)+0x18))
#define LINK(p) (*(u8 **)((p)+0x14))

extern int func_0036A5F0(u8 **);
extern void func_001AD1E0(u8 *,int,int);
extern void func_0036A620(u8 *);
extern void func_00178F20(void *,void *);
extern void func_0018FDB0(u8 *);
extern void func_001549B0(u8 *,f32 *);
extern void func_00191480(u8 *,u8 *,int);
void func_003698E0(u8 *p) {
 u8 *owner=OWNER(p),*target=*(u8 **)(p+0x1dc);Motion *m=(Motion *)p;f32 offset[3];s8 result;
 owner[0x1fe]=1;
 if(func_0036A5F0((u8 **)p)){p[5]=15;return;}
 result=(s8)func_00175700(p);if(result<0){p[5]++;return;}
 if(p[0x15b]){p[0x15b]=0;func_001AD1E0(p,12,0);}
 func_0036A620(p);
 if(((s8 *)p)[0x151]==0)return;
 m->x+=m->vx;m->vx+=m->ax;m->y+=m->vy;m->vy+=m->ay;
 if(--m->repeat!=0)return;
 if(m->timer==0)return;
 p[6]=0;m->timer--;m->repeat=3;p[0x21]=1;
 func_00178F20(p,target);target[0x1b5]=67;func_0018FDB0(p);
 offset[0]=-213.3333282470703f;offset[2]=0;offset[1]=188.57142639160156f;
 func_001549B0(p,offset);func_001E3710(p,6);func_00191480(target,owner,1);func_001757E0(target,13,5);func_0036A620(p);
}
