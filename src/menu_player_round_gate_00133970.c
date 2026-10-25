typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned int u32;
extern u8 *D_004C2840 __attribute__((section(".sdata")));
extern u8 D_004D18A0[3];
extern void func_001345C0(u8*,u8*,u32);
extern void func_001E3CE0(int);
/* func_00133720 constructs exactly player slots 0 and 1 through
 * func_00133760, which stores the slot at actor byte 2. */
void func_00133970(u8 *p,u8 *q) {
 if(*(s8*)(D_004C2840+2)==2 && D_004D18A0[0]<5 && D_004D18A0[0]>=4) {
  u32 selection=D_004D18A0[2];
  if(selection) {
  if(q[2]!=(selection&127)) {p[5]=0;p[0x20]=1;}
  else {
   ++p[5];p[0x14C]=0;func_001345C0(p,q,p[0x14C]);
   if(*(s8*)(D_004C2840+0x18)&(1U<<p[2]))func_001E3CE0(10);
   *(s16*)(p+0x1C)=0;
  }
  }
 }
}
