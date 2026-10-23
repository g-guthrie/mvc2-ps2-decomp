/* Choose the recovery action using mode, counters, and the native random source. */
typedef unsigned char u8;
typedef signed char s8;
extern u8 *D_004C2840 __attribute__((section(".sdata")));
extern u8 D_004D18E6;
extern int func_001841C0(u8 *),func_00417A40(void),func_001757E0(u8 *,int,int);
extern void func_0019DE50(u8 *,u8,u8);
extern unsigned int func_0035AEA0(u8 *,u8,u8);
void func_0022EC90(u8 *p)
{
 u8 *work=p+0x2B8;
 if(!(*(int*)(D_004C2840+0x1C)&1)||*(s8*)(D_004C2840+0x8C)!=0) {
  if(D_004D18E6&&func_001841C0(p)==1) {
   p[0x21]=5;p[0x168]=7;func_0019DE50(p,0,0);
  } else if(func_00417A40()&1) {p[0x21]=0;p[0x168]=0;}
  else {p[0x21]=2;p[0x168]=4;func_0035AEA0(work,0,2);}
 } else {
  if(D_004D18E6&&func_001841C0(p)==1) {p[0x21]=1;p[0x168]=1;}
  else if(func_00417A40()&1) {p[0x21]=0;p[0x168]=0;}
  else {p[0x21]=2;p[0x168]=4;func_0035AEA0(work,0,2);}
 }
 p[0x169]=19;func_001757E0(p,p[0x169],p[0x168]);
}
