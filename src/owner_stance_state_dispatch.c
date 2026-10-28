/* Dispatch owner-linked effects while the owner remains in the required stance. */
typedef unsigned char u8;
#include "mvc2_owner_stance_callbacks.h"
typedef Mvc2OwnerStanceCallback OwnerState;
extern void func_003A5D80(u8 *,u8 *);
extern OwnerState D_004C1EC4[2];
void func_003A5A80(u8 *p) {
 u8 *owner=*(u8 **)(p+0x18);
 if (owner[0x169]!=21) func_003A5D80(p,owner);
 else D_004C1EC4[p[0x20]](p,owner);
}
/* func_003B1EE0 only uses the child (p[0x13C] = 0, then func_003DAA40(p)). */
extern void func_003B1EE0(u8 *);
/* Two stance handlers, func_003B1C50 and func_003B1E00 (src/data/jtbl_004C1FB4.c);
 * selector p[0x20] is 0 or 1 (func_003B1DE0 indexes the same table with p[5]+1). */
extern OwnerState const jtbl_004C1FB4[2] __attribute__((section(".sdata")));
void func_003B1BF0(u8 *p) {
 u8 *owner=*(u8 **)(p+0x18);
 if (owner[0x169]!=21) func_003B1EE0(p);
 else jtbl_004C1FB4[p[0x20]](p,owner);
}
extern void func_003C11C0(u8 *,u8 *);
extern OwnerState D_004C20E0[2];
void func_003C0C60(u8 *p) {
 u8 *owner=*(u8 **)(p+0x18);
 if (owner[0x169]!=21) func_003C11C0(p,owner);
 else D_004C20E0[p[0x20]](p,owner);
}
