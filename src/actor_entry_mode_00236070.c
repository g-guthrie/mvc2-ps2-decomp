/* Initialize entry mode and select ground or airborne setup. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct {u8 pad[0x5C];float vx,vy,vz,ax,ay;} Motion;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_00185490(u8 *),func_00183D10(u8 *),func_00186A20(u8 *);
extern int func_001757E0(u8 *,int,int);
void func_00236070(u8 *p,u8 *work)
{
 Motion *motion=(Motion*)p;
 ++p[6];p[7]=0;p[0x20]=1;p[0x22]=28;p[0x209]=2;work[5]=0;
 *(float*)(p+0x5C)=0;*(float*)(p+0x60)=0;*(float*)(p+0x68)=0;*(float*)(p+0x6C)=0;
 motion->vx=2.916666507720947f;motion->ax=0;motion->vy=17.142856597900391f;motion->ay=-1.0714285373687744f;
 if(p[0x1E6]){motion->vx=-motion->vx;motion->ax=-motion->ax;}
 if(p[0x20D]!=2){
  p[0x20]=0;p[0x210]=0;*(float*)(p+0x38)=*(float*)(p+0x430);
  func_00185490(p);func_00183D10(p);func_00186A20(p);
 }
 p[0x1B5]=*(s8*)(p+0x20)*3+60;
 p[0x1B2]=*(u16*)(p+0x1C0)=0;*(u32*)(p+0x1D8)=0;
 {u32 a=p[2]*2;a+=(u32)D_004C2794;a+=0x7C;++*(s16*)a;}
 func_001757E0(p,21,(u8)((p[0x1B7]+11)+p[0x20]*3));
}
