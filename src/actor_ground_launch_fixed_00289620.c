/* Initialize the fixed-point ground launch or dispatch the airborne variant. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct {u8 pad[0x5C];float vx,vy,vz,ax,ay;} Motion;
extern int D_004568B0[][2],D_004568B4[][2];
extern s8 D_004C0978[][2] __attribute__((section(".sdata")));
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_00289AE0(u8 *),func_00185490(u8 *),func_00175C00(u8 *,int),func_0018C4B0(u8 *,int),func_00289800(u8 *);
extern int func_001757E0(u8 *,int,int);
void func_00289620(u8 *p)
{
 Motion *motion=(Motion*)p;
 if(p[0x20D]==2){++p[6];func_00289AE0(p);return;}
 ++p[7];func_00185490(p);func_00175C00(p,0);
 *(float*)(p+0x5C)=0;*(float*)(p+0x60)=0;*(float*)(p+0x68)=0;*(float*)(p+0x6C)=0;
 *(float*)(p+0x38)=*(float*)(p+0x430);p[0x210]=0;p[0x20D]=0;func_0018C4B0(p,5);
 if(!p[0x1E6]){
  motion->vx=1.6666666269302368f*D_004568B0[p[0x1B7]][0]/65536.0f;motion->ax=0.7291666269302368f;
 }else{
  motion->vx=-(1.6666666269302368f*D_004568B0[p[0x1B7]][0]/65536.0f);motion->ax=-0.7291666269302368f;
 }
 motion->vy=2.142857074737549f*D_004568B4[p[0x1B7]][0]/65536.0f;motion->ay=-0.9375f;
 p[0x1B5]=D_004C0978[p[0x1B7]][0];p[0x1B2]=*(u16*)(p+0x1C0)=0;*(u32*)(p+0x1D8)=0;
 {u32 a=p[2]*2;a+=(u32)D_004C2794;a+=0x7C;++*(s16*)a;}
 func_001757E0(p,21,(u8)(p[0x1B7]+3));func_00289800(p);
}
