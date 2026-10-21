#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef struct {u8 prefix[0x140];s16 facing;u8 gap142[0x73];u8 action;u8 gap1b6[0x27a];f32 ground;} OwnerGroundState;
typedef struct {u8 prefix[0x1c];s16 timer,repeat;u8 gap20[0x14];f32 x,y,z;u8 gap40[8];u32 angle;u8 gap4c[4];f32 scaleX,scaleY;u8 gap58[4];f32 vx,vy,vz,ax,ay;u8 gap70[0xd0];s16 facing;} Motion;
extern void func_001E7F60(u8 *);
extern u8 *D_004C2794 __attribute__((section(".sdata")));
#define OWNER(p) (*(u8 **)((p)+0x18))
#define RESET_ACTION(p,code) do {u32 counterAddress;(p)[0x1b5]=(code);(p)[0x1b2]=*(u16 *)((p)+0x1c0)=0;*(u32 *)((p)+0x1d8)=0;counterAddress=(p)[2]*2;counterAddress+=(u32)D_004C2794;counterAddress+=0x7c;++*(s16 *)counterAddress;}while(0)

struct PP;struct RR;
extern void func_003532F0(struct PP *,u8 *,struct RR *,u8 *);
extern void func_00353430(u8 *,u8 *);
extern int func_003535B0(u8 *);
extern void func_00353670(u8 *,u8 *,u8 *);
extern void func_00353650(u8 *,u8 *,u8 *);
extern u8 D_00462AD0[];
void func_00352C90(u8 *p,u8 *context) {
 u8 *source=*(u8 **)(context+0xc);OwnerGroundState *owner=(OwnerGroundState *)OWNER(p);u8 *previous,*sourceContext=source+0x88;Motion *m=(Motion *)p;
 if(source[4]!=1){p[4]=2;p[0x13c]=0;return;}
 previous=*(u8 **)(p+8);if(previous[0x8b]){p[4]=2;p[0x13c]=0;context[3]=255;return;}
 if(!sourceContext[0xb] || ((s8 *)sourceContext)[7]==0)p[0x20]++;
 context[2]=sourceContext[2];m->facing=owner->facing;p[0x22]=previous[0x22];((s8 *)p)[0x24]=((s8 *)source)[0x24];((s8 *)p)[0x31]=((s8 *)source)[0x31]-2;
 func_003532F0((struct PP *)p,context,(struct RR *)previous,sourceContext);func_00353430(p,context);
 if(m->y<=owner->ground) {
  p[0x22]=D_00462AD0[p[0x22]];*(f32 *)(sourceContext+0x10)=m->x;*(f32 *)(sourceContext+0x14)=owner->ground;sourceContext[0x2a]=255;
  if(!sourceContext[6])sourceContext[6]=30;
  if(sourceContext[0xb]){p[4]=2;p[0x13c]=0;return;}
  func_003532F0((struct PP *)p,context,(struct RR *)previous,sourceContext);m->y-=34.28571319580078f;func_00353430(p,context);
 }
 if(p[0x22]<8)m->facing^=1;
 if(func_003535B0(p)==0){p[4]=2;p[0x13c]=0;return;}
 if(((s8 *)p)[0x1b2]){func_00353670(p,context,sourceContext);p[0x13c]=1;return;}
 if(((s8 *)p)[0x1b3]){p[0x1b3]=0;func_00353650(p,context,sourceContext);p[0x13c]=1;return;}
 if(!sourceContext[0xb]){
  if(context[4]==0){p[0x1b0]=0;if(context[3]){if(((s8 *)sourceContext)[7]){p[0x13c]=1;return;}p[0x1b0]=66;}}
  {u8 action=owner->action;if(context[0x29]){context[9]=(((s8 *)context)[9]+1)&1;action+=context[9];}RESET_ACTION(p,action);func_001E7F60(p);}
 }
 p[0x13c]=1;
}
