/* Initialize mode-dependent launch velocity and the associated action and animation. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct {u8 pad[0x5C];float vx,vy,vz,ax,ay;} Motion;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_00185490(u8 *),func_00183D10(u8 *);
extern int func_001757E0(u8 *,int,int);
void func_00235D20(u8 *p)
{
 Motion *motion=(Motion*)p;
 int action,event;
 ++p[6];
 if(p[0x20D]!=2){
  p[0x20D]=0;*(float*)(p+0x38)=*(float*)(p+0x430);p[0x210]=0;
  func_00185490(p);func_00183D10(p);action=54;event=7;
 }else{
  ++*(s8*)(p+0x1E8);
  motion->vx=1.6666666269302368f;motion->ax=0;
  motion->vy=12.857142448425293f;motion->ay=-0.6696428060531616f;
  *(s16*)(p+0x140)=p[0x1E6];
  if(*(s16*)(p+0x140)){motion->vx=-motion->vx;motion->ax=-motion->ax;}
  action=57;event=9;
 }
 p[0x1B5]=action+*(s8*)(p+0x1B7);
 p[0x1B2]=*(u16*)(p+0x1C0)=0;*(u32*)(p+0x1D8)=0;
 {u32 a=p[2]*2;a+=(u32)D_004C2794;a+=0x7C;++*(s16*)a;}
 func_001757E0(p,21,(u8)(event+p[0x1B7]));
}
