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
extern void func_003B1EE0(u8 *,u8 *);
extern OwnerState D_004C1FB4[2];
void func_003B1BF0(u8 *p) {
 u8 *owner=*(u8 **)(p+0x18);
 if (owner[0x169]!=21) func_003B1EE0(p,owner);
 else D_004C1FB4[p[0x20]](p,owner);
}
extern void func_003C11C0(u8 *,u8 *);
extern OwnerState D_004C20E0[2];
void func_003C0C60(u8 *p) {
 u8 *owner=*(u8 **)(p+0x18);
 if (owner[0x169]!=21) func_003C11C0(p,owner);
 else D_004C20E0[p[0x20]](p,owner);
}
