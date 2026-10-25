#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern float D_004F1F4C;
extern void func_00183D10(u8*),func_001266A0(u8*,int,int),func_002D3230(u8*);
extern void func_00185490(u8*),func_0018C4B0(u8*,int);
extern int func_001757E0(u8*,int,int);
#define SET(action) do{p[0x1B5]=(action);p[0x1B2]=*(u16*)(p+0x1C0)=0;*(u32*)(p+0x1D8)=0;{u32 a=p[2]*2;a+=(u32)D_004C2794;a+=0x7C;++*(s16*)a;}}while(0)
void func_002D4BE0(u8 *p)
{
 float target;
 if(p[0x269]==6){p[0x404]=255;p[0x405]=16;}
 ++p[6];func_00183D10(p);func_001266A0(p,1,13);func_002D3230(p);SET(72);
 if(p[0x1FD]!=14)p[0x1E6]^=1;
 *(s16*)(p+0x140)=p[0x1E6];*(float*)(p+0x60)=8.571428298950195f;*(float*)(p+0x6C)=-0.2678571343421936f;
 if(p[0x1E6])target=746.6666870117188f+D_004F1F4C;else target=D_004F1F4C-746.6666870117188f;
 target-=*(float*)(p+0x34);
 *(float*)(p+0x5C)=target/53.33333206176758f;
 *(float*)(p+0x68)=0;*(s16*)(p+0x1C)=33;
 if(p[0x1FD]==14){func_001757E0(p,22,6);return;}
 func_001757E0(p,22,15);
}
