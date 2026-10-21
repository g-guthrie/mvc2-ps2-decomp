typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef struct {u8 prefix[0x14];u8 *link,*owner;s16 timer,repeat;u8 kind,phase,frame,slot;s8 mode;u8 gap25[0xf];f32 x,y,z;u8 gap40[8];u32 angle;s16 originX,originY;f32 scaleX,scaleY,scaleZ,vx,vy,vz,ax,ay;u8 gap70[0xd0];s16 facing;} Motion;

extern int func_0036F5A0(u8 *,u8 *,s32 *);
#define SNAP_OFFSET(dx,dy) do {m->x=*(f32 *)(owner+0x34);m->y=*(f32 *)(m->owner+0x38);m->z=*(f32 *)(m->owner+0x3c);m->x+=*(s16 *)(m->owner+0x140)?(dx):-(dx);m->y+=(dy);}while(0)
void func_0036F240(u8 *p,u8 *context,s32 *contact) {
 Motion *m=(Motion *)p;u8 *owner=m->owner;
 if(((s8 *)owner)[0x153]<0){p[5]++;func_0036F5A0(p,context,contact);return;}
 if(((s8 *)owner)[0x151]==1)SNAP_OFFSET(136,165.0f);
 owner=m->owner;
 if(((s8 *)owner)[0x151]==2)SNAP_OFFSET(106,146.0f);
 owner=m->owner;
 if(((s8 *)owner)[0x151]==3)SNAP_OFFSET(106,151.0f);
 owner=m->owner;
 if(((s8 *)owner)[0x151]==4)SNAP_OFFSET(48,202.0f);
 func_0036F5A0(p,context,contact);
}
