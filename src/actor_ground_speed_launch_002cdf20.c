#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_00183D10(u8*),func_00186A20(u8*);
extern void func_00185490(u8*),func_0018C4B0(u8*,int);
extern int func_001757E0(u8*,int,int);
#define SET(action) do{p[0x1B5]=(action);p[0x1B2]=*(u16*)(p+0x1C0)=0;*(u32*)(p+0x1D8)=0;{u32 a=p[2]*2;a+=(u32)D_004C2794;a+=0x7C;++*(s16*)a;}}while(0)
void func_002CDF20(u8 *p)
{
 float vx;
 ++p[6];func_00185490(p);func_00183D10(p);func_0018C4B0(p,10);
 *(float*)(p+0x38)=*(float*)(p+0x430);SET((s8)p[0x1B7]+58);func_00186A20(p);
 *(float*)(p+0x68)=0;*(float*)(p+0x6C)=0;
 vx=p[0x1B7]?13.333333015441895f:8.333333015441895f;
 *(float*)(p+0x60)=p[0x1B7]?8.571428298950195f:2.6785712242126465f;
 *(float*)(p+0x5C)=p[0x1E6]?vx:-vx;
 func_001757E0(p,21,4);
}
