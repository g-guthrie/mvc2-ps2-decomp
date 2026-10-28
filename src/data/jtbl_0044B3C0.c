/* Typed callback entries recovered from the exact dispatch callers. */
/* Consumer: src/composite_dispatch_heads.c (jtbl_0044B3C0). */
#include "mvc2_state_callbacks.h"

/* The dispatcher forwards actor and owner to every slot. */
typedef void (*Mvc2OwnerByteCallback)(u8 *, u8 *);

extern void func_001A5BE0(u8 *, u8 *);
extern void func_001A5D30(u8 *, u8 *);
extern void func_001A5D70(u8 *, u8 *);

const Mvc2OwnerByteCallback jtbl_0044B3C0[3] = {
    func_001A5BE0,
    func_001A5D30,
    func_001A5D70,
};
