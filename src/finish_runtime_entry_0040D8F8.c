#include "runtime_entry_table.h"

extern void func_004005F8(unsigned char *);
extern void func_0040D4F0(void);
extern int func_0040CE38(RuntimeEntrySlot *, const char *, int, int, int);
extern char D_006320C0[40] __attribute__((aligned(4)));
extern void *memcpy(void *, const void *, unsigned int);

void func_0040D8F8(RuntimeEntrySlot *p)
{
    int first = 0, second = 0, third = 0;

    if (p->handle) {
        func_004005F8((unsigned char *)p->handle);
        p->handle = 0;
        if (((signed char *)p)[3] == 1) {
            RuntimeEntryRecord *record = &p->records[p->record_index];
            /* Retail copies only the first 39 bytes of the 40-byte name. */
            memcpy((int *)D_006320C0, (int *)record->name, 39);
            second = record->argument_30;
            first = record->argument_2c;
            third = record->argument_34;
        }
        p->remaining--;
        p->record_index = (p->record_index + 1) % 16;
        if (p->remaining <= 0) {
            func_0040D4F0();
            ((signed char *)p)[1] = 1;
        }
        if (((signed char *)p)[3] == 1)
            func_0040CE38(p, D_006320C0, first, second, third);
    }
}
