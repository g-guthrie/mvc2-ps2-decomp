#include "runtime_entry_table.h"
typedef signed int s32;

extern RuntimeU8 D_00489818[];
extern void func_0040DA50(void *entry);

void func_0040D118(void)
{
    RuntimeEntrySlot *entry = (RuntimeEntrySlot *)D_00489818;
    s32 index = 15;

    do {
        if (entry->in_use == 1)
            func_0040DA50(entry);
        entry++;
    } while (--index >= 0);
}
