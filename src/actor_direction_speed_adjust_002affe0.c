#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern float D_004C0C70[] __attribute__((section(".sdata")));
extern u16 D_004C0C78[] __attribute__((section(".sdata")));
extern void func_00185490(u8*),func_0018C4B0(u8*,int);
extern int func_001757E0(u8*,int,int);
#define SET(action) do{p[0x1B5]=(action);p[0x1B2]=*(u16*)(p+0x1C0)=0;*(u32*)(p+0x1D8)=0;{u32 a=p[2]*2;a+=(u32)D_004C2794;a+=0x7C;++*(s16*)a;}}while(0)
void func_002AFFE0(u8 *p)
{
 float delta;
 ++p[6];SET((s8)p[0x1B7]*2+90);func_0018C4B0(p,4);func_00185490(p);
 *(u16*)(p+0x1C)=D_004C0C78[p[0x1B7]];delta=D_004C0C70[p[0x1B7]];
 if(p[0x1E6]){delta=-delta;if(*(float*)(p+0x5C)<0)delta=-delta;}
 else if(*(float*)(p+0x5C)>0)delta=-delta;
 *(float*)(p+0x5C)+=delta;*(float*)(p+0x68)=0;
 func_001757E0(p,21,(u8)(p[0x1B7]+25));
}
