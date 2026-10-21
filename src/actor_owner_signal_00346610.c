#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
extern u16 D_004D18DC __attribute__((section(".bss")));
extern u8 D_004D18DB __attribute__((section(".bss")));
extern s8 *D_004C2934 __attribute__((section(".sdata")));
extern s8 *D_004C2938 __attribute__((section(".sdata")));
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_00346490(u8 *);
extern void func_00346110(void *);
extern void func_001E7F60(u8 *);
void func_00346610(u8 *p) {
 u8 *owner=*(u8 **)(p+0x18);
 if(owner[4]>=2) {p[4]++;p[0x13c]=0;func_00346490(p);return;}
 if(D_004D18DC & (1<<D_004D18DB))return;
 D_004C2938[1]=1;p[0x13c]=1;
 if(((u8 *)D_004C2934)[2]<((u8 *)D_004C2938)[6]) {p[0x13c]=0;return;}
 if(((u8 *)D_004C2934)[2]==((u8 *)D_004C2938)[6]) {
  D_004C2938[1]=2;D_004C2938[0]=-1;p[0x13c]=1;
 }
 if(((s8 *)p)[0x1b2]) {
  D_004C2938[1]=1;D_004C2938[0]=-1;((u8 *)D_004C2934)[7]=255;
  if(--((s8 *)p)[0x1b4]==0) {
   u8 action=86;
   if(++((u8 *)D_004C2938)[5]>=3) {((u8 *)D_004C2938)[5]=0;action=85;}
   p[0x1b5]=action;p[0x1b2]=*(u16 *)(p+0x1c0)=0;*(u32 *)(p+0x1d8)=0;
   {u32 address=p[2]*2;address+=(u32)D_004C2794;address+=0x7c;++*(s16 *)address;}
  }
 }
 func_00346110(p);
 if(((u8 *)D_004C2934)[7]==0)func_001E7F60(p);
}
