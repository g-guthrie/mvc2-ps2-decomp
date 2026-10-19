#include "actor_action_event.h"
extern void func_001E3710(u8 *,int);
#define GP(name) extern u8 name[] __attribute__((section(".sdata")))
GP(D_004C04C4); GP(D_004C04C8); GP(D_004C04CC); GP(D_004C051C); GP(D_004C0538);
#define SELECT_EVENT(event) select_event(p,p[0x1B5],event)

void func_00256580(u8 *p)
{
    u8 *q=p+0x2B8;
    *(u16 *)(p+0x2BC)=0;
    if (p[0x1FC]>=3) *(u16 *)(q+4)=1;
    switch (p[0x1FC]) {
    case 0:
        *(u16 *)(q+2)=1;
        p[0x168]=0; p[0x1B5]=3;
        func_001E3710(p,20);
        *(u8 **)(p+0x408)=D_004C04C4; p[0x1BB]=0;
        break;
    case 1:
        *(u16 *)(q+2)=1;
        p[0x168]=1; p[0x1B5]=4;
        func_001E3710(p,21);
        *(u8 **)(p+0x408)=D_004C04C8; p[0x1BB]=1;
        break;
    case 2:
        p[0x168]=2; p[0x1B5]=5;
        *(u8 **)(p+0x408)=D_004C04CC; p[0x1BB]=2;
        break;
    case 3:
        p[0x168]=10; p[0x1B5]=0x49;
        *(u8 **)(p+0x408)=D_004C051C;
        SELECT_EVENT(20); p[0x1BB]=0; return;
    case 4:
        p[0x168]=17; p[0x1B5]=0x50;
        *(u8 **)(p+0x408)=D_004C0538;
        SELECT_EVENT(20); p[0x1BB]=0; return;
    default:
        *(u16 *)(q+2)=1;
        p[0x168]=0; p[0x1B5]=3;
        func_001E3710(p,20);
        *(u8 **)(p+0x408)=D_004C04C4; p[0x1BB]=0;
        return;
    }
    SELECT_EVENT(8);
}

void func_002567A0(u8 *p)
{
    u8 *q=p+0x2B8;
    *(u16 *)(p+0x2BC)=0;
    if (p[0x1FC]>=3) *(u16 *)(q+4)=1;
    switch (p[0x1FC]) {
    case 0:
        *(u16 *)(q+2)=1;
        p[0x168]=0; p[0x1B5]=9;
        func_001E3710(p,20);
        *(u8 **)(p+0x408)=D_004C04C4; p[0x1BB]=0;
        break;
    case 1:
        *(u16 *)(q+2)=1;
        p[0x168]=1; p[0x1B5]=10;
        func_001E3710(p,21);
        *(u8 **)(p+0x408)=D_004C04C8; p[0x1BB]=1;
        break;
    case 2:
        p[0x168]=2; p[0x1B5]=11;
        *(u8 **)(p+0x408)=D_004C04CC; p[0x1BB]=2;
        break;
    case 3:
        p[0x168]=10; p[0x1B5]=0x49;
        *(u8 **)(p+0x408)=D_004C051C;
        SELECT_EVENT(20); p[0x1BB]=0; return;
    case 4:
        p[0x168]=17; p[0x1B5]=0x50;
        *(u8 **)(p+0x408)=D_004C0538;
        SELECT_EVENT(20); p[0x1BB]=0; return;
    default:
        *(u16 *)(q+2)=1;
        p[0x168]=0; p[0x1B5]=9;
        func_001E3710(p,20);
        *(u8 **)(p+0x408)=D_004C04C4; p[0x1BB]=0;
        *(u16 *)(q+4)=0;
        return;
    }
    SELECT_EVENT(10);
}
