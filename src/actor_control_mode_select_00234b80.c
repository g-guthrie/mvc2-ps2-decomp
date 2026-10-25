#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
extern u8 *D_004C2840 __attribute__((section(".sdata")));
extern void func_00175C00(u8*,int);
void func_00234B80(u8 *p)
{
 func_00175C00(p,0);
 if(*(s8*)(D_004C2840+0x8F)){
  p[0x20]=2;if(*(s8*)(D_004C2840+0xA9)&(1<<(*(s8*)(p+0x538)&1)))p[0x20]=1;
 }else{p[0x20]=2;if(*(s8*)(p+0x539))p[0x20]=1;}
}
