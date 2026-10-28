/* func_003AE000 (src/composite_dispatch_heads.c): lbu p[4], sll 2, lw, jr (tail call with p in $a0).
 * Entry 0 targets the code that directly follows func_003AE000's dispatch (0x003AE020). */
#include "mvc2_state_callbacks.h"

extern void func_003AE020(u8 *);
extern void func_003AE160(u8 *);
extern void func_003AE880(u8 *);
extern void func_003AE8A0(u8 *);

const Mvc2StateCallback jtbl_00473B40[4] = {
    func_003AE020,
    func_003AE160,
    func_003AE880,
    func_003AE8A0,
};
