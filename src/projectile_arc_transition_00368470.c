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
extern void func_001E7F60(u8 *);
extern void func_001E3710(u8 *,s32);
extern u8 *D_004C2794 __attribute__((section(".sdata")));
#define OWNER(p) (*(u8 **)((p)+0x18))
#define RESET_ACTION(p,code) do {u32 counterAddress;(p)[0x1b5]=(code);(p)[0x1b2]=*(u16 *)((p)+0x1c0)=0;*(u32 *)((p)+0x1d8)=0;counterAddress=(p)[2]*2;counterAddress+=(u32)D_004C2794;counterAddress+=0x7c;++*(s16 *)counterAddress;}while(0)

extern s32 func_00417690(f32,f32);
extern void func_001AD1E0(u8 *,int,int);
extern u8 *D_004C2980 __attribute__((section(".sdata")));
void func_00368470(u8 *p) {
 u8 *owner=OWNER(p);Motion *m=(Motion *)p;u32 rotated;
 func_00175700(p);m->x+=m->vx;m->vx+=m->ax;m->y+=m->vy;m->vy+=m->ay;
 m->angle=func_00417690(m->vy,m->vx);
 if(m->facing)rotated=-m->angle;else rotated=(m->angle+0x8000)&0xffff;
 m->angle=rotated;
 m->timer++;
 if(--m->repeat==0){m->repeat=3;func_001AD1E0(p,4,0);}
 if(!(m->y<=*(f32 *)(owner+0x430)) && !((s8 *)p)[0x1b2]){
  if(p[7]==0 && ((s8 *)owner)[0x539]==0){
   u32 mask=owner[0x1b7]?0x100:0x200;
   if(*(u16 *)(owner+0x354)&mask){if(m->timer<60){func_001E7F60(p);return;}}
   else if(m->timer<10){p[7]=1;func_001E7F60(p);return;}
  }else if(m->timer<29){func_001E7F60(p);return;}
 }
 p[5]++;D_004C2980[8]=1;func_001E3710(p,73);
 if(owner[0x269]==3)RESET_ACTION(p,84);else RESET_ACTION(p,55);
 func_001757E0(p,23,21);func_001E7F60(p);
}
