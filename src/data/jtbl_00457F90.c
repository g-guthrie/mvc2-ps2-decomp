/* Typed callback entries recovered from the exact dispatch callers. */
/* Consumer: src/composite_dispatch_heads.c (jtbl_00457F90). */
#include "mvc2_state_callbacks.h"

extern u8 *func_0029A260(u8 *);
extern void func_0029A300(u8 *);
extern void func_0029A310(u8 *);
extern void func_0029A3E0(u8 *);
extern void func_0029A4A0(u8 *);
extern void func_0029A560(u8 *);
extern void func_0029A5E0(u8 *);

/* These slots intentionally discard the selected target pointer return. */
const Mvc2StateCallback jtbl_00457F90[9] = {
    (Mvc2StateCallback)func_0029A260,
    func_0029A300,
    func_0029A310,
    (Mvc2StateCallback)func_0029A260,
    func_0029A3E0,
    func_0029A4A0,
    func_0029A4A0,
    func_0029A560,
    func_0029A5E0,
};
