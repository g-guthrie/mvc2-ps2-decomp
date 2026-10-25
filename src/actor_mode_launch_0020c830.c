/* Initialize the mode-dependent launch and its opposing horizontal acceleration. */
#pragma padloop on
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern float D_004508B0[][2],D_004508B4[][2];
extern int func_001757E0(u8 *,int,int);
extern void func_0020C980(u8 *,u8 *);
void func_0020C830(u8 *p,u8 *work)
{
 float speed,accel;
 ++p[7];
 p[0x1B5]=p[0x1B7]?66:64;
 p[0x1B2]=*(u16*)(p+0x1C0)=0;
 *(u32*)(p+0x1D8)=0;
 {u32 a=p[2]*2;a+=(u32)D_004C2794;a+=0x7C;++*(s16*)a;}
 work[9]=1;
 if(p[0x1E6])speed=D_004508B0[p[0x1B7]][0];
 else speed=-D_004508B0[p[0x1B7]][0];
 *(float*)(p+0x5C)=speed;
 if(p[0x1E6])accel=-D_004508B4[p[0x1B7]][0];
 else accel=D_004508B4[p[0x1B7]][0];
 *(float*)(p+0x68)=accel;
 *(float*)(p+0x60)=-19.28571319580078f;
 *(float*)(p+0x6C)=-0.2678571343421936f;
 func_001757E0(p,20,(u8)(p[0x1B7]*2+10));
 func_0020C980(p,work);
}
