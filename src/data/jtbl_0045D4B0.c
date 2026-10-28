/* Typed callback entries recovered from the exact dispatch callers. */
/* Consumer: src/composite_dispatch_heads.c (jtbl_0045D4B0). */
#include "mvc2_state_callbacks.h"

/* The dispatcher forwards actor and owner to every slot. */
typedef void (*Mvc2OwnerByteCallback)(u8 *, u8 *);

extern void func_00313400(u8 *, u8 *);
extern void func_003134E0(u8 *, u8 *);
extern void func_003135D0(u8 *, u8 *);
extern void func_00313690(u8 *, u8 *);
extern void func_00313730(u8 *, u8 *);
extern void func_003137D0(u8 *, u8 *);

const Mvc2OwnerByteCallback jtbl_0045D4B0[6] = {
    func_00313400,
    func_003134E0,
    func_003135D0,
    func_00313690,
    func_00313730,
    func_003137D0,
};
