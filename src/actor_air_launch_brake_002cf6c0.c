#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern u8 *D_004C2794 __attribute__((section(".sdata")));

extern void func_00185490(u8*),func_0018C4B0(u8*,int);
extern int func_001757E0(u8*,int,int);
#define SET(action) do{p[0x1B5]=(action);p[0x1B2]=*(u16*)(p+0x1C0)=0;*(u32*)(p+0x1D8)=0;{u32 a=p[2]*2;a+=(u32)D_004C2794;a+=0x7C;++*(s16*)a;}}while(0)
void func_002CF6C0(u8 *p)
{
 float vx;
 ++p[6];func_00185490(p);func_0018C4B0(p,10);
 vx=p[0x1B7]?16.66666603088379f:13.333333015441895f;
 *(float*)(p+0x5C)=p[0x1E6]?vx:-vx;
 *(float*)(p+0x68)=p[0x1E6]?-0.625f:0.625f;
 *(float*)(p+0x60)=p[0x1B7]?34.28571319580078f:21.428569793701172f;
 *(float*)(p+0x6C)=-1.0714285373687744f;SET(80);
 func_001757E0(p,21,(u8)(p[0x1B7]+21));
}
