#include "actor_action_event.h"

extern u8 D_004C078C[] __attribute__((section(".sdata")));
extern u8 D_004C0790[] __attribute__((section(".sdata")));
extern u8 D_004C0794[] __attribute__((section(".sdata")));
#define SELECT_EVENT(event) select_event(p,p[0x1B5],event)

void func_00274060(u8 *p)
{
    switch(p[0x1FC]) {
    case 0:
        p[0x168]=0; p[0x1B5]=3; *(u8 **)(p+0x408)=D_004C078C; p[0x1BB]=0;
        break;
    case 1:
        p[0x168]=1; p[0x1B5]=4; *(u8 **)(p+0x408)=D_004C0790; p[0x1BB]=1;
        break;
    case 2:
        if (*(u16 *)(p+0x20E)&0x800) {
            p[0x168]=3; p[0x1B5]=18; *(u8 **)(p+0x408)=D_004C0794; p[0x1BB]=2;
        } else {
            p[0x168]=2; p[0x1B5]=5; *(u8 **)(p+0x408)=D_004C0794; p[0x1BB]=2;
        }
        break;
    }
    SELECT_EVENT(8);
}
