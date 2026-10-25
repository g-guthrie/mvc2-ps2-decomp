#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
extern int func_00175700(u8*),func_003A38B0(int);
extern s16 D_004C27A4 __attribute__((section(".sdata")));
void func_002E5FC0(u8 *p,u8 *work)
{
 func_00175700(p);
 if(*(s8*)(p+0x151)){
  if(D_004C27A4>6){++p[7];work[2]=0;work[4]=6;func_003A38B0((int)p);return;}
  p[6]=2;
 }
}
