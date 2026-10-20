/* State callbacks receive the actor and the owner loaded by func_00388310. */
#include "mvc2_state_callbacks.h"
extern void func_00388390(u8 *, void *);
extern void func_00388440(u8 *, void *);
extern void func_003884D0(u8 *, void *);
const Mvc2OwnerStateCallback jtbl_00464A40[3] = {
    func_00388390, func_00388440, func_003884D0,
};
