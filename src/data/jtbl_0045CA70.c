/* Native consumer: residual_0030422C loads A0=p and A1=p+0x2B8 before jr. */
#include "mvc2_state_callbacks.h"

extern void func_003034E0(u8 *, void *);
extern void func_00303E20(u8 *, void *);
extern void func_00303200(u8 *, void *);
extern void func_003037C0(u8 *, void *);
extern void func_00303F00(u8 *, void *);
extern void func_00303980(u8 *, void *);
extern void func_003040F0(u8 *, void *);
extern void func_00304210(u8 *, void *);

const Mvc2OwnerStateCallback jtbl_0045CA70[10] = {
    func_003034E0,
    func_00303E20,
    func_00303200,
    func_003037C0,
    func_00303F00,
    func_00303980,
    func_00303200,
    func_00303200,
    func_003040F0,
    func_00304210,
};
