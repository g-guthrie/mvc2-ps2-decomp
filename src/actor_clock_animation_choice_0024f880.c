/* Select animation and phase advancement from the clock table and actor state. */
#pragma padloop on
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 D_004D18E6 __attribute__((section(".bss")));
extern u8 *D_004C2840 __attribute__((section(".sdata")));
extern u8 D_004C0488[] __attribute__((section(".sdata"))),D_004C048C[] __attribute__((section(".sdata")));
extern int func_001841C0(u8 *),func_001757E0(u8 *,int,int);
extern void func_00176160(u8 *,int,int,int);
void func_0024F880(u8 *p)
{
 if(D_004D18E6)*(short*)(p+0x1C)=D_004C0488[*(u32*)(D_004C2840+0x1C)&3];
 else *(short*)(p+0x1C)=D_004C048C[*(u32*)(D_004C2840+0x1C)&3];
 if(func_001841C0(p)>=2)*(short*)(p+0x1C)=2;
 switch(*(short*)(p+0x1C)){
 case 0:++p[6];p[0x168]=0;break;
 case 1:p[6]+=2;p[0x168]=1;func_00176160(p,5,0,1);break;
 case 2:p[6]+=3;p[0x168]=2;break;
 }
 func_001757E0(p,19,p[0x168]);
}
