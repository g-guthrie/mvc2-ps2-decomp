typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef struct {u8 prefix[0x14];u8 *link,*owner;s16 timer,repeat;u8 kind,phase,frame,slot;s8 mode;u8 gap25[0xf];f32 x,y,z;u8 gap40[8];u32 angle;s16 originX,originY;f32 scaleX,scaleY,scaleZ,vx,vy,vz,ax,ay;u8 gap70[0xd0];s16 facing;} Motion;
extern int func_00175700(u8 *);
extern int func_001757E0(u8 *,int,int);
extern void func_001E7F60(u8 *);
#define OWNER(p) (*(u8 **)((p)+0x18))
#define LINK(p) (*(u8 **)((p)+0x14))

typedef struct {u8 active,life;} OwnerControl;
extern void func_00358860(u8 *);
extern void func_00358890(u8 *,u8 *);
extern s16 D_00462DD0[][2];
void func_00358620(u8 *p) {
 Motion *m=(Motion *)p;u8 *owner=m->owner,*current;OwnerControl *control=(OwnerControl *)(owner+0x2b8);f32 offset;s8 result;
 if(p[5]==0){
  if(((s8 *)p)[0x1b2]){
   p[6]++;p[0x1b2]=0;
   if(--control->life<=0){p[5]++;p[0x13c]=1;func_001757E0(p,20,4);}
  }
  if(control->active==0){p[4]++;func_00358860(p);return;}
  if(m->owner[0x15b]){
   p[0x13c]=1;m->x=*(f32 *)(m->owner+0x34);m->y=*(f32 *)(m->owner+0x38);
   current=m->owner;offset=1.6666666269302368f*D_00462DD0[current[0x15b]][0];if(*(s16 *)(current+0x140))offset=-offset;
   m->x+=offset;m->y-=2.142857074737549f*D_00462DD0[m->owner[0x15b]][1];
  }else p[0x13c]=0;
  current=m->owner;
  if(*(u16 *)(current+0x168)!=m->timer){p[4]++;func_00358860(p);return;}
  if(((s8 *)p)[0x13c] && p[6]==0){
   if(m->repeat==0){if(current[0x15f]){func_00358890(p,owner);func_001E7F60(p);}}
   else m->repeat--;
  }
 }else{
  result=(s8)func_00175700(p);if(result<0){p[4]++;func_00358860(p);}
 }
}
