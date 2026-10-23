/* Scaled motion entry and animation-completion transitions. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_0018C4B0(u8 *,int),func_00175C00(u8 *,int),func_00183D10(u8 *),func_00185490(u8 *);
extern int func_001757E0(u8 *,int,int),func_00175700(u8 *);
extern void func_003A15E0(u8 *,u8),func_001D3750(u8 *,u8,u8),func_001863F0(u8 *),func_002E1520(u8 *,int);
void func_002E2350(u8 *p)
{
 if(p[6]==0) {
  func_0018C4B0(p,5);func_00175C00(p,0);
  if(p[0x20D]!=2) {func_00183D10(p);p[0x20D]=0;}
  func_00185490(p);
  p[0x1B5]=*(s8*)(p+0x1B7)*2+48;
  p[0x1B2]=*(u16*)(p+0x1C0)=0;*(u32*)(p+0x1D8)=0;
  ((s16*)(D_004C2794+0x7C))[p[2]]++;
  if(p[0x1B7])func_001757E0(p,21,0);else func_001757E0(p,21,16);
  func_003A15E0(p,2);
  func_001D3750(p,5,0);func_001D3750(p,5,1);func_001D3750(p,5,2);
  *(float*)(p+0x5C)/=8.0f;*(float*)(p+0x68)/=8.0f;
  *(float*)(p+0x60)/=8.0f;*(float*)(p+0x6C)/=8.0f;
  p[6]++;p[0x28F]=0;p[0x28E]=16;
 }
 if(p[0x20D]==2) {
  if(*(float*)(p+0x430)<=*(float*)(p+0x38)) {
   *(float*)(p+0x34)+=*(float*)(p+0x5C);
   *(float*)(p+0x5C)+=*(float*)(p+0x68);
   *(float*)(p+0x38)+=*(float*)(p+0x60);
   *(float*)(p+0x60)+=*(float*)(p+0x6C);
  }
 } else func_001863F0(p);
 if((s8)func_00175700(p)<0)func_002E1520(p,p[0x20D]);
}
