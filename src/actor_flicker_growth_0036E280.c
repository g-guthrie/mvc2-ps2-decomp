#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef struct {f32 x,y,z;} V3;
typedef struct {u8 prefix[0x34];f32 x,y,z;u8 gap40[0x10];f32 scaleX,scaleY;u8 gap58[4];f32 vx,vy,vz,ax,ay;u8 gap70[0xa8];f32 fade;} Motion;
extern int func_00175700(u8 *);
extern int func_001757E0(u8 *,int,int);
extern void func_001E7F60(u8 *);
extern void func_001E3710(u8 *,s32);
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern u8 *D_004C2840 __attribute__((section(".sdata")));
#define RESET_ACTION(p,code) do {u32 counterAddress; (p)[0x1b5]=(code);(p)[0x1b2]=*(u16 *)((p)+0x1c0)=0;*(u32 *)((p)+0x1d8)=0;counterAddress=(p)[2]*2;counterAddress+=(u32)D_004C2794;counterAddress+=0x7c;++*(s16 *)counterAddress;}while(0)

extern void func_0036C0B0(u8 *,s32,s32);
void func_0036E280(u8 *p) {
 Motion *m=(Motion *)p;
 if(((s8 *)p)[0x151]==1) {func_00175700(p);return;}
 if(*(s32 *)(D_004C2840+0x1c)%14==0 && p[0x23]<4) {
  p[0x1b0]=66;p[0x1b1]=66;RESET_ACTION(p,63);
 }
 func_00175700(p);
 m->scaleY+=0.20000000298023224f;
 if(!(m->scaleY<1.0f)) {p[5]++;func_0036C0B0(p,3,0);}
 m->scaleX=1.0f;
 if((*(u32 *)(D_004C2840+0x1c)&1)==0)m->scaleX=0.800000011920929f;
 func_001E7F60(p);
}
