#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_001861B0(u8*),func_001863F0(u8*),func_00183D90(u8*),func_00183D10(u8*),func_002F1D90(u8*),func_002F1DF0(u8*),func_001E3210(u8*,int),func_003A82E0(u8*,int),func_001D6B50(u8*,int),func_001266A0(u8*,int,int);
extern int func_00175700(u8*);
extern void func_00185490(u8*),func_0018C4B0(u8*,int);
extern int func_001757E0(u8*,int,int);
#define SET(action) do{p[0x1B5]=(action);p[0x1B2]=*(u16*)(p+0x1C0)=0;*(u32*)(p+0x1D8)=0;{u32 a=p[2]*2;a+=(u32)D_004C2794;a+=0x7C;++*(s16*)a;}}while(0)
extern float D_004F1FC8,D_004F1FCC;
void func_002EFD00(u8 *p)
{
 if(p[0x269]==6){p[0x404]=255;p[0x405]=16;}
 p[0x209]=2;++p[6];func_00185490(p);p[0x20D]=2;*(float*)(p+0x38)=*(float*)(p+0x430);SET(64);
 func_00183D10(p);func_001266A0(p,1,0);
 *(float*)(p+0x5C)=((D_004F1FC8+D_004F1FCC)/2.0f-*(float*)(p+0x34))/16.0f;
 *(float*)(p+0x68)=0;*(float*)(p+0x60)=8.571428298950195f;*(float*)(p+0x6C)=-0.8035714030265808f;*(s16*)(p+0x1C)=16;
 func_001E3210(p,3);func_001757E0(p,22,1);
}
