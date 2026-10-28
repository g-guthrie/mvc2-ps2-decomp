/* Typed callback entries recovered from the exact dispatch callers. */
/* Consumers: src/composite_dispatch_heads.c (jtbl_00473D00 via 003B1610,
 * table 00473D10 via 003B1C50). Both heads forward the owner that
 * 003B11C0 and 003B1BF0 load from object+0x18. */
#include "mvc2_state_callbacks.h"

extern void func_003B1630(u8 *, void *);
extern void func_003B1850(u8 *, void *);
extern void func_003B1A70(u8 *, void *);
extern void func_003B1A90(u8 *, void *);
extern void func_003B1C70(u8 *, void *);
extern void func_003B1DE0(u8 *, void *);
extern void func_003B1EC0(u8 *, void *);
extern void func_003B1EE0(u8 *, void *);

const Mvc2OwnerStateCallback jtbl_00473D00[8] = {
    func_003B1630,
    func_003B1850,
    func_003B1A70,
    func_003B1A90,
    func_003B1C70,
    func_003B1DE0,
    func_003B1EC0,
    func_003B1EE0,
};
