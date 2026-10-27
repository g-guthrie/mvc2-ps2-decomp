/* Placeholder: input BSS ownership, aliases, and device lifetime remain unproved. */
typedef unsigned char u8; typedef signed char s8; typedef unsigned short u16; typedef short s16; typedef unsigned int u32;
#include "input_device_view.h"
typedef struct {u16 buttons,previous,pressed,released;u8 gap08[4];s16 x,y;u8 gap10[4];} Input;
typedef struct {s8 active,previous,aux;u8 gap;} Status;
extern void *D_004C2A68 __attribute__((section(".sdata")));
#define DEVICES ((InputDeviceView *)D_004C2A68)
extern Input D_004F4480[2]; extern int D_004F8010[4];
extern void func_003DAE90(void);
void func_0012F0B0(void) {
 u8 i; u32 raw; u16 flags;
 func_003DAE90();
 for(i=0;i<4;i++) {
  ((s8 *)&D_004F8010[i])[1]=((s8 *)&D_004F8010[i])[0];
  if(DEVICES[i].state==1) ((s8 *)&D_004F8010[i])[0]=(DEVICES[i].mode&3)?1:0;
  else ((s8 *)&D_004F8010[i])[0]=0;
  ((s8 *)&D_004F8010[i])[2]=0;
 }
 for(i=0;i<2;i++) {
  if(DEVICES[i].state==1) {
   D_004F4480[i].previous=D_004F4480[i].buttons;
   if(DEVICES[i].flags&0x30){D_004F4480[i].x=DEVICES[i].first.x;D_004F4480[i].y=DEVICES[i].first.y;}
   raw=DEVICES[i].buttons;flags=0;
   if(raw&1) flags|=0x2000;
   if(raw&2) flags|=0x1000;
   if(raw&4) flags|=0x0800;
   if(raw&8) flags|=0x0400;
   if((DEVICES[i].flags&0x30) && !flags) {
    if(raw&0x10000)flags|=0x2000;
    if(raw&0x20000)flags|=0x1000;
    if(raw&0x40000)flags|=0x0800;
    if(raw&0x80000)flags|=0x0400;
   }
   if(raw&0x8000)flags|=0x8000;
   if(raw&0x4000)flags|=0x0002;
   if(raw&0x0100)flags|=0x0200;
   if(raw&0x0200)flags|=0x0100;
   if(raw&0x0800)flags|=0x0080;
   if(raw&0x0010)flags|=0x0040;
   if(raw&0x0020)flags|=0x0020;
   if(raw&0x0400)flags|=0x0010;
   if(raw&0x0040)flags|=0x0008;
   if (raw & 0x80) flags |= 4; D_004F4480[i].buttons=flags;
  } else {D_004F4480[i].buttons=0;D_004F4480[i].x=0;D_004F4480[i].y=0;}
  D_004F4480[i].pressed=(u16)(~D_004F4480[i].previous & D_004F4480[i].buttons);
  D_004F4480[i].released=(u16)(D_004F4480[i].previous & ~D_004F4480[i].buttons);
 }
}
