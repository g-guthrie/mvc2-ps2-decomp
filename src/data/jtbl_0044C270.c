/* Typed callback entries recovered from the exact dispatch callers. */
/* Consumer: src/composite_dispatch_heads.c (jtbl_0044C270). */
#include "owner_effect_callbacks.h"

extern void func_001BD5E0(u8 *);
extern void func_001BD600(u8 *);
extern void func_001BD630(u8 *);
extern void func_001BD670(u8 *);
extern void func_001BD950(u8 *, void *);
extern void func_001BD9D0(u8 *, void *);
extern void func_001BDA10(u8 *, void *);

const OwnerEffectPhaseTables jtbl_0044C270 = {
    {
        func_001BD5E0,
        func_001BD600,
        func_001BD630,
        func_001BD670,
    },
    {
        func_001BD950,
        func_001BD9D0,
        func_001BDA10,
    }
};
