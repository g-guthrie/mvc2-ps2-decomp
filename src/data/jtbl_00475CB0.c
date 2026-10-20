/* Owner-context state dispatch from func_003C1350. */
#include "mvc2_state_callbacks.h"

extern void func_003C13B0(u8 *, void *);
extern void func_003C1A20(u8 *, void *);
extern void func_003C1D60(u8 *, void *);
extern void func_003C1FF0(u8 *, void *);
extern void func_003C2590(u8 *, void *);
extern void func_003C2930(u8 *, void *);
extern void func_003C2CD0(u8 *, void *);
extern void func_003C3120(u8 *, void *);
extern void func_003C3470(u8 *, void *);
extern void func_003C3700(u8 *, void *);

const Mvc2OwnerStateCallback jtbl_00475CB0[10] = {
    func_003C13B0,
    func_003C1A20,
    func_003C1D60,
    func_003C1FF0,
    func_003C2590,
    func_003C2930,
    func_003C2CD0,
    func_003C3120,
    func_003C3470,
    func_003C3700,
};
