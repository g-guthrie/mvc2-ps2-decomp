/* Mode-gated dispatch and the owner-provided animation transition. */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef void (*NoArgCallback)(void);
extern int func_003299D0(void);
extern int D_004C25D8 __attribute__((section(".sdata")));
extern u8 *D_004C2840 __attribute__((section(".sdata")));
extern NoArgCallback const D_0043CC90[];
extern void func_0034B040(u8 *,u8 *);
extern int func_00175700(u8 *),func_001757E0(u8 *,int,int);
void func_001290A0(void)
{
 if(func_003299D0()==0) {
  if(D_004C25D8)D_0043CC90[*(s8*)(D_004C2840+0x4C)]();
  else D_004C25D8=1;
 } else D_004C25D8=0;
}
void func_0034A950(u8 *p,u8 *owner)
{
 u8 *work=owner+0x2B8;
 func_0034B040(p,owner);
 if((s8)func_00175700(p)<0) {p[5]++;*(s16*)(p+0x1C)=1;work[13]=1;func_001757E0(p,22,16);}
}
