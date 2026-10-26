typedef unsigned char u8;typedef signed char s8;typedef unsigned short u16;
#include "actor_action_event.h"
static inline void reset_action(u8 *p,u8 action) {
 u32 counterOffset;
 ((ActorActionView*)p)->action=action;
 p[0x1B2]=*(u16*)(p+0x1C0)=0;
 *(u32*)(p+0x1D8)=0;
 counterOffset=p[2]*2;counterOffset+=(u32)D_004C2794;counterOffset+=0x7C;++*(s16*)counterOffset;
}

extern void func_0018C4B0(u8*,int),func_00185490(u8*),func_00175C00(u8*,int),func_00183D10(u8*);
extern int func_001757E0(u8*,int,int);
extern void func_002465F0(u8*,void*);
void func_00246510(u8*p,void*work){
 ++p[6];func_0018C4B0(p,5);func_00185490(p);func_00175C00(p,0);func_00183D10(p);
 *(float*)(p+0x5C)=0;*(float*)(p+0x60)=0;*(float*)(p+0x68)=0;*(float*)(p+0x6C)=0;p[0x20D]=0;*(float*)(p+0x38)=*(float*)(p+0x430);
 p[0x1B5]=*(s8*)(p+0x1B7)+54;reset_action(p,p[0x1B5]);func_001757E0(p,21,5);
 ((u8*)work)[9]=0; func_002465F0(p,work);
}
