typedef unsigned char u8;
#include "sony_pad_slot.h"
extern u8 *func_0010D860(int port,int slot);
int func_0010DA40(int port,int slot,int value){u8 *p;if(!D_004C83D0[port][slot].enabled)return 0;p=func_0010D860(port,slot);p[113]=value;return 1;}
