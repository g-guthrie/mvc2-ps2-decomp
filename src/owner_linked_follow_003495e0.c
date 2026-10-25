/* Follow the owner until its animation changes; splice in the next effect. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef float f32;
extern u16 D_004D18DC __attribute__((section(".bss")));
extern u8 D_004D18DB __attribute__((section(".bss")));
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern int func_001757E0(u8 *,int,int);
extern int func_00175700(u8 *);
extern void func_001E7F60(u8 *);
extern u8 *func_00348E40(u8 *);
void func_003495E0(u8 *p,u8 *q)
{
 if(*(u16*)(q+0x168)!=*(u16*)(p+0x88)){
  ++p[5];p[0x169]=22;p[0x168]=32;
  func_001757E0(p,p[0x169],p[0x168]);
 }else{
  *(f32*)(p+0x34)=*(f32*)(q+0x34)+*(f32*)(p+0x5C);
  *(f32*)(p+0x38)=*(f32*)(q+0x38)+*(f32*)(p+0x60);
  if(D_004D18DC & (1<<D_004D18DB))return;
  func_00175700(p);
  if(*(s8*)(p+0x150)){
   u8 *next;
   p[0x150]=0;p[0x1B5]=70;
   p[0x1B2]=*(u16*)(p+0x1C0)=0;
   *(u32*)(p+0x1D8)=0;
   {u32 a=p[2]*2;a+=(u32)D_004C2794;a+=0x7C;++*(s16*)a;}
   next=func_00348E40(p);
   if(next){*(u8**)(*(u8**)(p+0x14)+0x14)=next;*(u8**)(p+0x14)=next;}
  }
  func_001E7F60(p);
 }
}
