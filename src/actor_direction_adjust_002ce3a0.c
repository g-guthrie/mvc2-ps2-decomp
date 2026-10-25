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
void func_002CE3A0(u8 *p)
{
 float delta;
 ++p[6];func_00185490(p);func_0018C4B0(p,5);SET((s8)p[0x1B7]+61);
 delta=p[0x1B7]?4.166666507720947f:2.5f;
 if(p[0x1E6]){if(*(float*)(p+0x5C)<0.0)delta=-delta;}
 else{delta=-delta;if(*(float*)(p+0x5C)>0.0)delta=-delta;}
 *(float*)(p+0x5C)+=delta;*(float*)(p+0x68)=0;*(s16*)(p+0x1C)=p[0x1B7]*2+1;
 func_001757E0(p,21,8);
}
