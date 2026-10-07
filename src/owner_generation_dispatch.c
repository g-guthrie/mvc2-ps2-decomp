/* Validate owner generation before dispatching the paired state callback. */
typedef unsigned char u8;
#include "mvc2_owner_generation_callbacks.h"
typedef Mvc2OwnerGenerationCallback OwnerState;
extern void func_003DAA40(u8 *);
extern OwnerState D_00475F60[4];
void func_003C4CD0(u8 *p,u8 *owner) {
 if (*(unsigned short *)(p+0xd8)!=*(unsigned short *)(owner+0x168)) func_003DAA40(p);
 else D_00475F60[p[4]](p,owner);
}
extern OwnerState D_00475F90[4];
void func_003C5080(u8 *p,u8 *owner) {
 if (*(unsigned short *)(p+0xd8)!=*(unsigned short *)(owner+0x168)) func_003DAA40(p);
 else D_00475F90[p[4]](p,owner);
}
extern OwnerState D_00475FA0[4];
void func_003C5310(u8 *p,u8 *owner) {
 if (*(unsigned short *)(p+0xd8)!=*(unsigned short *)(owner+0x168)) func_003DAA40(p);
 else D_00475FA0[p[4]](p,owner);
}
