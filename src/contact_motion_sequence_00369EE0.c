typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef struct {u8 prefix[0x1c];s16 timer,repeat;u8 gap20[0x14];f32 x,y,z;u8 gap40[8];u32 angle;u8 gap4c[4];f32 scaleX,scaleY;u8 gap58[4];f32 vx,vy,vz,ax,ay;u8 gap70[0xd0];s16 facing;} Motion;
extern int func_00175700(u8 *);
extern int func_001757E0(u8 *,int,int);
extern void func_001E3710(u8 *,s32);
#define OWNER(p) (*(u8 **)((p)+0x18))

extern int func_0036A5F0(u8 **);
extern void func_001AD1E0(u8 *,int,int);
extern void func_0036A620(u8 *);
extern void func_001549B0(u8 *,f32 *);
extern void func_00191480(u8 *,u8 *,s32);
extern void func_00178F20(void *,void *);
extern void func_0018FDB0(u8 *);
extern u8 *D_004C2988 __attribute__((section(".sdata")));
void func_00369EE0(u8 *p) {
 u8 *owner=OWNER(p),*target=*(u8 **)(p+0x1dc);Motion *m=(Motion *)p;f32 offset[3];s16 countBefore;
 owner[0x1fe]=1;
 if(func_0036A5F0((u8 **)p)){p[5]=15;return;}
 if((s8)func_00175700(p)<0){p[5]++;func_001757E0(p,23,29);D_004C2988[0xb]=2;m->timer=45;return;}
 if(p[0x15b]){p[0x15b]=0;func_001AD1E0(p,12,0);}
 func_0036A620(p);
 if(((s8 *)p)[0x151]==0)return;
 m->x+=m->vx;m->vx+=m->ax;m->y+=m->vy;m->vy+=m->ay;
 if(--m->repeat!=0)return;
 countBefore=m->timer;if(countBefore<0)return;
 if(countBefore==0){
  m->timer=countBefore-1;*(u8 **)(target+0x1c8)=owner;target[0x20a]=15;target[0x1b5]=68;
  offset[0]=-213.3333282470703f;offset[1]=188.57142639160156f;offset[2]=0;
  func_001549B0(p,offset);func_001E3710(p,6);func_00191480(target,owner,1);
  ((Motion *)target)->x=m->x;p[6]=0;p[0x21]=3;func_0036A620(p);return;
 }else{
  p[6]=0;m->timer--;m->repeat=3;p[0x21]=3;func_00178F20(p,target);target[0x1b5]=67;func_0018FDB0(p);
  offset[0]=-213.3333282470703f;offset[2]=0;offset[1]=188.57142639160156f;
  func_001549B0(p,offset);func_001E3710(p,6);func_00191480(target,owner,1);func_001757E0(target,13,5);
 }
}
