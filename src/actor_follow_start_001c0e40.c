#include "owned_actor_states_0044c770.h"
typedef unsigned char u8;
typedef short s16;
extern void func_001C0E60(u8*,u8*);
void func_001C0E40(u8 *p,u8 *owner) {
 ++p[5];
 *(s16*)(p+0x1c)=0;
 p[0x24]=15;
 func_001C0E60(p,owner);
}
