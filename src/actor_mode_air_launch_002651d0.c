/* Select the launch animation and mode-specific motion before resetting the frame. */
#pragma padloop on
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct {u8 pad[0x5C];float vx,vy,vz,ax,ay;} Motion;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_00185490(u8 *),func_0018C4B0(u8 *,int),func_00186A20(u8 *),func_00183D10(u8 *),func_00175C00(u8 *,int);
extern int func_001757E0(u8 *,int,int);
void func_002651D0(u8 *p)
{
 Motion *motion=(Motion*)p;
 ++p[6];func_00185490(p);func_0018C4B0(p,5);*(s16*)(p+0x1C)=0;
 p[0x1B5]=54;p[0x1B2]=*(u16*)(p+0x1C0)=0;*(u32*)(p+0x1D8)=0;
 {u32 a=p[2]*2;a+=(u32)D_004C2794;a+=0x7C;++*(s16*)a;}
 if(p[0x20D]==2){++p[6];p[0x168]=p[0x1B7]?27:11;func_001757E0(p,21,p[0x168]);}
 else{func_00186A20(p);p[0x168]=p[0x1B7]?26:10;func_001757E0(p,21,p[0x168]);func_00183D10(p);}
 *(float*)(p+0x5C)=0;*(float*)(p+0x60)=0;*(float*)(p+0x68)=0;*(float*)(p+0x6C)=0;
 if(p[0x1B7]==0){
  float speed;
  motion->vy=20.357141494750977f;motion->ay=-0.9040178060531616f;
  speed=-3.3333332538604736f;
  if(*(s16*)(p+0x140))speed=-speed;
  motion->vx=speed;
 }else{
  float speed;
  motion->vy=34.285713195800781f;motion->ay=-1.3392856121063232f;
  speed=-4.5833330154418945f;
  if(*(s16*)(p+0x140))speed=-speed;
  motion->vx=speed;
 }
 func_00175C00(p,0);
}
