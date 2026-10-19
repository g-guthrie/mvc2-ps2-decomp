#include "runtime_entry_table.h"

extern int D_004C2474;
extern RuntimeEntrySlot D_00489818[16];
extern void func_0040CD38(void *);
extern void *func_0011D8F8(void *, int, unsigned int);
extern void func_0040D630(void);
extern void func_0040D580(int, int);

void func_0040D6A0(void)
{
    int i;
    RuntimeEntrySlot *p;

    if (--D_004C2474 == 0) {
        int active = 1;
        p = D_00489818;
        for (i = 15; i >= 0; i--, p++)
            if (p->in_use == active)
                func_0040CD38(p);
        func_0011D8F8(D_00489818, 0, 0x4380);
        func_0040D630();
        func_0040D580(0, 0);
    }
}
