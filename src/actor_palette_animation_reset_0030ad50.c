#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern u8 *D_004C28DC __attribute__((section(".sdata")));
extern void func_00186A20(u8*),func_00176160(u8*,int,int,int),func_00183D10(u8*);
extern void func_00185490(u8*),func_0018C4B0(u8*,int);
extern int func_001757E0(u8*,int,int);
#define SET(action) do{p[0x1B5]=(action);p[0x1B2]=*(u16*)(p+0x1C0)=0;*(u32*)(p+0x1D8)=0;{u32 a=p[2]*2;a+=(u32)D_004C2794;a+=0x7C;++*(s16*)a;}}while(0)
void func_0030AD50(u8 *p)
{
 if(p[0x269]==6){p[0x404]=255;p[0x405]=16;}
 ++p[6];func_00185490(p);
 *(float*)(p+0x5C)=0;*(float*)(p+0x60)=0;*(float*)(p+0x68)=0;*(float*)(p+0x6C)=0;
 SET(0);*(s16*)(p+0x1C)=112;D_004C28DC[0]=0;*(float*)(p+0x60)=3.2142856121063232f;func_00186A20(p);
 if(p[0x25]&1){func_00176160(p,1,32,1);func_00176160(p,2,33,1);}
 else{func_00176160(p,1,35,1);func_00176160(p,2,36,1);}
 func_00183D10(p);func_001757E0(p,22,4);
}
