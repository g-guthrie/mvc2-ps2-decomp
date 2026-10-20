#include "runtime_entry_table.h"
typedef signed int s32;
typedef unsigned int u32;

extern RuntimeU8 D_00489818[];
extern void func_0040DA50(void *entry);

void func_0040D118(void)
{
    u32 address = (u32)D_00489818;
    RuntimeEntrySlot *entry;
    s32 index = 15;

    do {
        entry = (RuntimeEntrySlot *)address;
        if (entry->in_use == 1)
            func_0040DA50(entry);
        address += 0x438;
    } while (--index >= 0);
}
