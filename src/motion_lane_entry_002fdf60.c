/* Ground/air variant selection and signed fixed-point motion lanes. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern const s32 D_0045C130[][4],D_0045C134[][4],D_0045C138[][4],D_0045C13C[][4];
extern void func_0018C4B0(u8 *,int),func_00185490(u8 *),func_00175C00(u8 *,int),func_00183D10(u8 *),func_002FE150(u8 *,u8 *);
extern int func_001757E0(u8 *,int,int);
void func_002FDF60(u8 *p,void *state)
{
 p[6]++;func_0018C4B0(p,5);func_00185490(p);func_00175C00(p,0);
 if(p[0x20D]!=2) {
  p[0x20D]=0;func_00183D10(p);
  *(float*)(p+0x38)=*(float*)(p+0x430);
  if(p[0x1B7]==0)p[0x21]=0;else p[0x21]=1;
 } else {
  if(p[0x1B7]==0)p[0x21]=2;else p[0x21]=3;
 }
 p[0x1B5]=*(s8*)(p+0x1B7)+48;
 p[0x1B2]=*(u16*)(p+0x1C0)=0;*(u32*)(p+0x1D8)=0;
 ((s16*)(D_004C2794+0x7C))[p[2]]++;
 func_001757E0(p,21,p[0x1B7]);
 *(float*)(p+0x5C)=1.66666662693023681640625f*(float)D_0045C130[p[0x21]][0]/65536.0f;
 *(float*)(p+0x68)=1.66666662693023681640625f*(float)D_0045C134[p[0x21]][0]/65536.0f;
 *(float*)(p+0x60)=2.142857074737548828125f*(float)D_0045C138[p[0x21]][0]/65536.0f;
 *(float*)(p+0x6C)=2.142857074737548828125f*(float)D_0045C13C[p[0x21]][0]/65536.0f;
 if(p[0x1E6]) {*(float*)(p+0x5C)=-*(float*)(p+0x5C);*(float*)(p+0x68)=-*(float*)(p+0x68);}
 ((u8*)state)[10]=0;func_002FE150(p,state);
}
