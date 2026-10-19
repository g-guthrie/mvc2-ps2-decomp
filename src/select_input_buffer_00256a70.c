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

/* Unary helper called at 00256A48 when actor selector 0x212 equals 1. */
extern void func_001E3710(u8 *, int);
extern u8 D_004C04DC[] __attribute__((section(".sdata")));
extern u8 D_004C04E0[] __attribute__((section(".sdata")));
extern u8 D_004C04E4[] __attribute__((section(".sdata")));
extern u8 D_004C04F4[] __attribute__((section(".sdata")));
extern u8 D_004C04F8[] __attribute__((section(".sdata")));
extern u8 D_004C04FC[] __attribute__((section(".sdata")));
void func_00256C20(u8 *p)
{
    s32 flags;
    switch(p[0x1FC]) {
    case 0:
        p[0x168]=0;p[0x1B5]=15;func_001E3710(p,20);
        if(p[0x210]==0) *(u8 **)(p+0x408)=D_004C04DC;
        else *(u8 **)(p+0x408)=D_004C04F4;
        p[0x1BB]=0;
        break;
    case 1:
        p[0x168]=1;p[0x1B5]=16;func_001E3710(p,21);
        if(p[0x210]==0) *(u8 **)(p+0x408)=D_004C04E0;
        else *(u8 **)(p+0x408)=D_004C04F8;
        p[0x1BB]=1;
        break;
    case 2:
        p[0x168]=2;p[0x1B5]=17;
        if(*(u16 *)(p+0x20E)&0x1000) {p[0x168]=6;p[0x1B5]=20;}
        if(p[0x210]==0) *(u8 **)(p+0x408)=D_004C04E4;
        else *(u8 **)(p+0x408)=D_004C04FC;
        p[0x1BB]=2;
        select_event(p,p[0x1B5],12);
        flags=*(s8 *)(p+0x1EA);
        if(flags&15) p[0x1EA]=flags-1;
        return;
    }
    select_event(p,p[0x1B5],12);
    flags=*(s8 *)(p+0x1EA);
    if(flags&0xF0) p[0x1EA]=flags-16;
}
