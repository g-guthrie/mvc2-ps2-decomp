#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_00183D10(u8*);
extern void func_00185490(u8*),func_0018C4B0(u8*,int);
extern int func_001757E0(u8*,int,int);
#define SET(action) do{p[0x1B5]=(action);p[0x1B2]=*(u16*)(p+0x1C0)=0;*(u32*)(p+0x1D8)=0;{u32 a=p[2]*2;a+=(u32)D_004C2794;a+=0x7C;++*(s16*)a;}}while(0)
void func_00323670(u8 *p)
{
 ++p[6];func_00185490(p);
 if(p[0x20D]!=2){
  *(float*)(p+0x5C)=0;*(float*)(p+0x60)=0;*(float*)(p+0x68)=0;*(float*)(p+0x6C)=0;p[0x20D]=0;func_00183D10(p);
 }else{
  *(float*)(p+0x5C)/=16.0f;*(float*)(p+0x60)/=8.0f;*(float*)(p+0x6C)/=64.0f;*(float*)(p+0x68)=0;
 }
 func_0018C4B0(p,5);*(s16*)(p+0x1C)=1;SET(48);func_001757E0(p,21,(u8)(p[0x1B7]+3));
}
