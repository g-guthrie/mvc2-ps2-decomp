/* Typed callback entries recovered from the exact dispatch callers. */
/* Consumer: src/composite_dispatch_heads.c (jtbl_00472D20). */
#include "mvc2_state_callbacks.h"

/* The dispatcher forwards actor and owner to every slot. */
typedef void (*Mvc2OwnerByteCallback)(u8 *, u8 *);

extern void func_003A45B0(u8 *, u8 *);
extern void func_003A4670(u8 *, u8 *);
extern void func_003A47A0(u8 *, u8 *);
extern void func_003A4870(u8 *, u8 *);
extern void func_003A4B80(u8 *, u8 *);
extern void func_003A4D10(u8 *, u8 *);
extern void func_003A4E40(u8 *, u8 *);

const Mvc2OwnerByteCallback jtbl_00472D20[7] = {
    func_003A45B0,
    func_003A4670,
    func_003A47A0,
    func_003A4870,
    func_003A4B80,
    func_003A4D10,
    func_003A4E40,
};
