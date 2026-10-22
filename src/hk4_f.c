typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct {s32 a;u32 b;s32 c;} T3_hk4f;

typedef struct {u8 prefix[0x7c];s16 count[2];} GS_hk4f;
extern GS_hk4f *D_004C2794 __attribute__((section(".sdata")));
extern void func_0029D5E0(u8 *);
extern void func_00175700(u8 *);
extern void func_001757E0(u8 *,s32,s32);
extern void func_001830D0(u8 *,T3_hk4f *,s32);

void func_0029E400(u8 *p)
{
 T3_hk4f tmp;
 if(p[7]==0) {
  if(p[0x269]==6) {
   p[0x404]=0xff;
   p[0x405]=0x10;
  }
  {u32 t=p[7]; p[7]=t+1;}
  func_0029D5E0(p);
  *(u32 *)(p+0x5c)=0xC0A00000;
  *(u32 *)(p+0x68)=0;
  if(*(s16 *)(p+0x140)!=0) {
   *(f32 *)(p+0x5c)=-*(f32 *)(p+0x5c);
  }
  p[0x1b5]=0x3d;
  p[0x1b2]=*(u16 *)(p+0x1c0)=0;
  *(u32 *)(p+0x1d8)=0;
  D_004C2794->count[p[2]]++;
  func_001757E0(p,0x16,0xa);
  return;
 }
 p[0x40c]=2;
 p[0x33c]=5;
 p[0x405]=(p[0x269]==6)?2:0;
 func_00175700(p);
 if(*(s8 *)(p+0x151)!=0) {
  {u32 t=p[6]; p[6]=t+1;}
  p[7]=0;
  p[0x151]=0;
  p[0x404]=0;
  p[0x405]=0;
  tmp.b=0x4322DB6D;
  tmp.a=0;
  tmp.c=0;
  func_001830D0(p,&tmp,1);
 }
}
