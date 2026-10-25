#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
extern u8 D_004C1718[][2] __attribute__((section(".sdata")));
extern u8 *func_001E7FD0(u8*);
extern int func_00174170(void);
u8 *func_0031A350(u8 *p)
{
 u8 *result;
 if(p[0x20D]==0||p[0x20D]==2){
  u16 buttons=*(u16*)(p+0x20E);*(u16*)(p+0x2C2)=buttons;
  if((buttons&0xC00)&&p[0x1B7]){
   if(!(result=func_001E7FD0(p)))return 0;
   if(p[0x212]==1){if(p[0x20D]==2)result=0;else p[0x20B]=2;}
   else if(p[0x20D]!=2){
    if(!*(s8*)(p+0x2BF)){p[0x2BE]=func_00174170()&3;p[0x20B]=D_004C1718[*(s8*)(p+0x2BE)][0];}
    else p[0x20B]=2;
   }else p[0x20B]=1;
  }else result=0;
 }else result=0;
 return result;
}
