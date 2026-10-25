#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern int func_00175700(u8*);
extern void func_001843A0(u8*),func_001E3210(u8*,int),func_003B69D0(void*,u8);
extern void func_00185490(u8*),func_0018C4B0(u8*,int);
extern int func_001757E0(u8*,int,int);
#define SET(action) do{p[0x1B5]=(action);p[0x1B2]=*(u16*)(p+0x1C0)=0;*(u32*)(p+0x1D8)=0;{u32 a=p[2]*2;a+=(u32)D_004C2794;a+=0x7C;++*(s16*)a;}}while(0)
void func_00305FE0(u8 *p)
{
 s8 *work=(s8*)(p+0x2B8);
 switch(p[0x1FC]){
 case 0:if((s8)func_00175700(p)<0)func_001843A0(p);break;
 case 1:
  if((s8)func_00175700(p)<0)func_001843A0(p);
  if(*(s8*)(p+0x151)){p[0x151]=0;SET(20);}break;
 case 2:
  switch(p[7]){
  case 0:++p[7];work[9]=0;
  case 1:
   if(*(s8*)(p+0x151)){
    work[9]=*(s8*)(p+0x151);func_003B69D0(p,1);func_001E3210(p,38);++p[7];*(s16*)(p+0x1C)=20;
   }
   func_00175700(p);break;
  case 2:
   if(!--*(s16*)(p+0x1C)){++p[7];work[9]=0;func_001757E0(p,9,3);}
   work[9]=*(s8*)(p+0x151);func_00175700(p);break;
  case 3:
   if((s8)func_00175700(p)<0)func_001843A0(p);
   work[9]=*(s8*)(p+0x151);if(!work[9])work[9]=-1;break;
  }break;
 }
}
