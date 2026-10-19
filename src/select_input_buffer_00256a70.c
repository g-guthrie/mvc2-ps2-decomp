/* Unary input-selection helper, called with actor A0 at 00256A58. */
#include "actor_action_event.h"
typedef signed char s8;
typedef signed int s32;
extern u8 D_004C04D0[] __attribute__((section(".sdata")));
extern u8 D_004C04D4[] __attribute__((section(".sdata")));
extern u8 D_004C04D8[] __attribute__((section(".sdata")));
extern u8 D_004C04E8[] __attribute__((section(".sdata")));
extern u8 D_004C04EC[] __attribute__((section(".sdata")));
extern u8 D_004C04F0[] __attribute__((section(".sdata")));
void func_00256A70(u8 *p)
{
    s32 flags;
    switch(p[0x1FC]) {
    case 0:
        p[0x168]=0;p[0x1B5]=12;
        if(p[0x210]==0) *(u8 **)(p+0x408)=D_004C04D0;
        else *(u8 **)(p+0x408)=D_004C04E8;
        p[0x1BB]=0;
        break;
    case 1:
        p[0x168]=1;p[0x1B5]=13;
        if(p[0x210]==0) *(u8 **)(p+0x408)=D_004C04D4;
        else *(u8 **)(p+0x408)=D_004C04EC;
        p[0x1BB]=1;
        break;
    case 2:
        p[0x168]=2;p[0x1B5]=14;
        if(p[0x210]==0) *(u8 **)(p+0x408)=D_004C04D8;
        else *(u8 **)(p+0x408)=D_004C04F0;
        p[0x1BB]=2;
        select_event(p,p[0x1B5],11);
        flags=*(s8 *)(p+0x1EA);
        if(flags&15) p[0x1EA]=flags-1;
        return;
    }
    select_event(p,p[0x1B5],11);
    flags=*(s8 *)(p+0x1EA);
    if(flags&15) p[0x1EA]=flags-1;
}
