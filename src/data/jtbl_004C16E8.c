/* Typed callback entries recovered from the exact dispatch callers. */
/* Consumer: src/grok_w5_disp.c (jtbl_004C16E8). */
#include "mvc2_state_callbacks.h"

/* The dispatcher forwards actor and owner to every slot. */
typedef void (*Mvc2OwnerByteCallback)(u8 *, u8 *);

extern void func_00313820(u8 *, u8 *);
extern void func_00313AA0(u8 *, u8 *);

const Mvc2OwnerByteCallback jtbl_004C16E8[2] = {
    func_00313820,
    func_00313AA0,
};
