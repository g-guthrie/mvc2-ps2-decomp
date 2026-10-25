/* Select fixed-point velocity and acceleration from the native bank. */
#pragma padloop on
typedef unsigned char u8;
typedef struct {u8 pad[0x5C];float vx;u8 pad60[8];float ax;} Motion;
extern int D_0044F940[][2][2],D_0044F944[][2][2];
extern short D_004BFC30[] __attribute__((section(".sdata")));
extern void func_001F0420(u8 *),func_0018C4B0(u8 *,int);
extern int func_001757E0(u8 *,int,int);
void func_001F3EF0(u8 *p)
{
 Motion *motion=(Motion*)p;
 ++p[6];func_001F0420(p);func_0018C4B0(p,12);
 *(short*)(p+0x1C)=D_004BFC30[p[0x1B7]];
 motion->vx=1.6666666269302368f*D_0044F940[p[0x216]>>7][p[0x1B7]][0]/65536.0f;
 motion->ax=1.6666666269302368f*D_0044F944[p[0x216]>>7][p[0x1B7]][0]/65536.0f;
 *(float*)(p+0x60)=9.64285659790039f;
 *(float*)(p+0x6C)=-0.2678571343421936f;
 if(p[0x1E6]==0){motion->vx=-motion->vx;motion->ax=-motion->ax;}
 func_001757E0(p,15,47);
}
