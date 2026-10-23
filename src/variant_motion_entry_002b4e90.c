/* Variant-dependent motion and cycling animation state entry. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern const u8 D_004B7570[],D_004B7572[];
extern void func_00185490(u8 *),func_0018C4B0(u8 *,int),func_00183D10(u8 *),func_00175C00(u8 *,int);
extern int func_001757E0(u8 *,int,int);
#define ACTION(n) do {p[0x1B5]=(n);p[0x1B2]=*(u16*)(p+0x1C0)=0;*(u32*)(p+0x1D8)=0;((s16*)(D_004C2794+0x7C))[p[2]]++;}while(0)
void func_002B4E90(u8 *p)
{
 u8 *state=p+0x2B8;
 p[6]++;func_00185490(p);func_0018C4B0(p,13);func_00183D10(p);
 if(p[0x1B7]==0) {
  ACTION(51);
  *(float*)(p+0x5C)=-3.3333332538604736328125f;
  *(float*)(p+0x68)=0.520833313465118408203125f;
  *(float*)(p+0x60)=17.142856597900390625f;
 } else {
  if(p[0x269]==3) {ACTION(87);}else {ACTION(55);}
  *(float*)(p+0x5C)=-10.0f;
  *(float*)(p+0x68)=0.520833313465118408203125f;
  *(float*)(p+0x60)=34.28571319580078125f;
 }
 *(float*)(p+0x6C)=-1.0714285373687744140625f;
 if(*(s16*)(p+0x140)) {
  *(float*)(p+0x5C)=-*(float*)(p+0x5C);
  *(float*)(p+0x68)=-*(float*)(p+0x68);
 }
 func_001757E0(p,21,D_004B7572[p[0x1B7]]);
 state[1]++;state[1]&=3;
 if(state[1])func_001757E0(p,21,D_004B7570[p[0x1B7]]);
 else {func_001757E0(p,21,D_004B7572[p[0x1B7]]);func_00175C00(p,8);}
}
