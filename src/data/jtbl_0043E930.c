/* Typed callback entries recovered from the exact dispatch callers. */
/* Consumer: src/composite_dispatch_heads.c (jtbl_0043E930). */
#include "mvc2_state_callbacks.h"

/* The dispatcher forwards actor and owner to every slot. */
typedef void (*Mvc2OwnerByteCallback)(u8 *, u8 *);

extern void func_00133BC0(u8 *, u8 *);
extern void func_00133C10(u8 *, u8 *);
extern void func_00133C70(u8 *, u8 *);
extern void func_00133CE0(u8 *, u8 *);
extern void func_00133F40(u8 *, u8 *);
extern void func_00133FA0(u8 *, u8 *);
extern void func_00133FF0(u8 *, u8 *);
extern void func_00134120(u8 *, u8 *);

const Mvc2OwnerByteCallback jtbl_0043E930[8] = {
    func_00133BC0,
    func_00133C10,
    func_00133C70,
    func_00133CE0,
    func_00133F40,
    func_00133FA0,
    func_00133FF0,
    func_00134120,
};
