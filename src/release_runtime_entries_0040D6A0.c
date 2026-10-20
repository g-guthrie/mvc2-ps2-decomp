#include "runtime_entry_table.h"
typedef unsigned int u32;

extern int D_004C2474;
extern RuntimeU8 D_00489818[];
extern void func_0040CD38(void *);
extern void *func_0011D8F8(void *, int, unsigned int);
extern void func_0040D630(void);
extern void func_0040D580(int, int);

void func_0040D6A0(void)
{
    int i;
    RuntimeEntrySlot *p;
    u32 address;

    if (--D_004C2474 == 0) {
        int active = 1;
        address = (u32)D_00489818;
        for (i = 15; i >= 0; i--, address += 0x438) {
            p = (RuntimeEntrySlot *)address;
            if (p->in_use == active)
                func_0040CD38(p);
        }
        func_0011D8F8(D_00489818, 0, 0x4380);
        func_0040D630();
        func_0040D580(0, 0);
    }
}
