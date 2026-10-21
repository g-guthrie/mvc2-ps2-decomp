#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef struct {f32 x,y,z;} V3;
/* Observed GP-relative CODE access only: this undefined extern emits no storage
 * and does not recover an original ELF section name or array extent.
 * The native byte-table read requires a valid phase index0..7. */
extern const u8 D_004C1A20[] __attribute__((section(".sdata")));
extern void func_00154470(u8 *,int,int,f32,f32);
extern void func_001E3430(u8 *,u8 *,int);
extern int func_001757E0(u8 *,int,int);
extern int func_00175700(u8 *);
void func_0034CA70(u8 *p) {
 u8 *q=*(u8 **)(p+0x18);
 if(q[5]!=3 || q[0x247]!=20) {
  p[4]++;p[0x13c]=0;
  func_00154470(q,0,0,2.0f,2.0f);
  func_00154470(q,16,0,2.0f,2.0f);
  func_00154470(q,240,0,2.0f,2.0f);
 }else {
  q[0x13c]=0;
  *(V3 *)(p+0x34)=*(V3 *)(q+0x34);
  *(s16 *)(p+0x140)=*(s16 *)(q+0x140);
  if(q[6]!=p[6]) {
   p[6]=q[6];p[0x168]=D_004C1A20[p[6]];
   if(p[6]==4) {
    if(q[0x20d]==2)p[0x168]=6;
    func_001E3430(*(u8 **)(p+0x18),*(u8 **)(p+0x14),47);
   }
   func_001757E0(p,23,p[0x168]);
  }else func_00175700(p);
  if(q[6]==6 && ((s8 *)p)[0x151]==0) {
   f32 speed;
   if(((s8 *)q)[0x1e7]>0)speed=-2.5f;
   else speed=2.9166665077209473f;
   if(q[0x1e6])*(f32 *)(q+0x5c)=speed;
   else *(f32 *)(q+0x5c)=-speed;
   *(f32 *)(q+0x34)+=*(f32 *)(q+0x5c);
  }
 }
}
