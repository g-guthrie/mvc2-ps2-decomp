#include "owned_actor_states_0044c770.h"
typedef unsigned char u8;
typedef signed char s8;
extern void func_001C1330(u8*,u8*);
extern int func_00175670(u8*);
void func_001C0C60(u8 *p,u8 *owner) {
 func_001C1330(p,owner);
 *(s8*)(p+0x24)=*(s8*)(owner+0x24);
 if((s8)func_00175670(p)<0) {++p[4];p[0x13c]=0;}
}
