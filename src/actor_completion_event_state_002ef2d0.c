#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_001861B0(u8*),func_001863F0(u8*),func_00183D90(u8*),func_00183D10(u8*),func_002F1D90(u8*),func_002F1DF0(u8*),func_001E3210(u8*,int),func_003A82E0(u8*,u8*),func_001D6B50(u8*,u8),func_001266A0(u8*,int,int);
extern int func_00175700(u8*);
extern void func_00185490(u8*),func_0018C4B0(u8*,int);
extern int func_001757E0(u8*,int,int);
#define SET(action) do{p[0x1B5]=(action);p[0x1B2]=*(u16*)(p+0x1C0)=0;*(u32*)(p+0x1D8)=0;{u32 a=p[2]*2;a+=(u32)D_004C2794;a+=0x7C;++*(s16*)a;}}while(0)
void func_002EF2D0(u8 *p)
{
 if(!p[6]){
  ++p[6];func_00185490(p);func_00183D10(p);p[0x20D]=0;func_0018C4B0(p,10);
  SET(48);func_001757E0(p,21,(u8)(*(u32*)(p+0x2D4)+56));func_001E3210(p,4);
 }
 if((s8)func_00175700(p)<0){func_002F1DF0(p);return;}
 if(*(s8*)(p+0x151)){
  p[0x151]=0;func_001E3210(p,32);func_003A82E0(p,0);func_001D6B50(p,0);p[0x28F]=0;p[0x28E]=16;
 }
}
