typedef unsigned char u8;typedef signed char s8;typedef short s16;typedef unsigned int u32;
extern u32 *D_004C2794 __attribute__((section(".sdata")));
#include "input_device_view.h"
extern void *D_004C2A68 __attribute__((section(".sdata")));
extern u32 D_004773F0[];
static u32 func_003D6850(int i) {
 u32 f=0; InputDeviceView *devices=(InputDeviceView *)D_004C2A68; s16 x=devices[i].second.y; u32 old;
 if(x < -0x32) f|=0x2000;
 if(x > 0x32) f|=0x1000;
 old=D_004773F0[i];D_004773F0[i]=f;return f & ~old;
}
extern void func_003D72F0(void);
typedef struct {u8 a[0xa];s16 delay;u8 b[0xe];s8 enabled;u8 c[0xf];s16 selection;s8 owner;} Selector;
/* Provisional: selection bounds, resource lifetime, and nonzero count are not fully proven. */
void func_003D68B0(u8 *p){
 Selector *z=(Selector *)p;
 s8 index=(s8)(z->owner-1);
 if(z->enabled==0){
  z->selection=0;
  if(z->delay) --z->delay;
  else ++z->enabled;
 }else{
  u8 *actor=(u8 *)D_004C2794[index*3+6];
  s16 count=**(u8 **)(actor+0x1ac);
  u32 f=func_003D6850(index);
  if(f&0x2000)--z->selection;
  if(f&0x1000)++z->selection;
  z->selection=(z->selection+count)%count;
 }
 func_003D72F0();
}
