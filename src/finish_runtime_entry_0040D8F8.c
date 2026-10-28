#include "runtime_entry_table.h"

/* EE GCC 2.96: -O2 -G0 (sibling calls on; func_0040D848 ends in one).
   The do { } while (0) wrappers keep the final calls of func_0040D8F8 and
   func_0040DA50 as jal: GCC 2.96 does not turn a call inside a loop
   construct into a sibling call, and retail has jal there. */

extern void func_004005F8(unsigned char *);
extern void func_0040D4F0(void);
extern int func_0040CE38(RuntimeEntrySlot *, const char *, int, int, int);
extern char D_006320C0[40] __attribute__((aligned(4)));
extern void *memcpy(void *, const void *, unsigned int);

extern RuntimeS32 func_00400650(RuntimeS32);
extern RuntimeS32 func_004006A0(RuntimeS32);
extern void func_0040D5A0(void *);
extern RuntimeU8 D_004BE430[];

void func_0040D848(RuntimeEntrySlot *p)
{
    RuntimeEntryRecord *record;
    RuntimeS32 status;

    if (p->handle == 0) {
        func_0040D5A0(D_004BE430);
        return;
    }
    record = (RuntimeEntryRecord *)((RuntimeU8 *)p + (p->record_index << 6) + 0x38);
    status = func_00400650(p->handle);
    if (status == 4)
        ((signed char *)p)[1] = 3;
    else if (status == 2)
        record->value_3c = func_004006A0(p->handle);
    else if (status == 3) {
        RuntimeS32 size = p->scaled_size;
        record->word_38 = 2;
        record->value_3c = size;
    }
}

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
        if (((signed char *)p)[3] == 1) {
            do {
                func_0040CE38(p, D_006320C0, first, second, third);
            } while (0);
        }
    }
}

/* func_0040D848 and func_0040D8F8 must be defined above: EE GCC 2.96 treats
   calls to functions already compiled in the unit as non-throwing, and only
   then does reorg see the delay-slot registers die across those calls (retail
   has plain bne where extern callees give bnel). */
extern void func_0040D738(RuntimeEntrySlot *);
void func_0040DA50(RuntimeEntrySlot *p)
{
    RuntimeS32 mode;

    if (((signed char *)p)[4] != 1) {
        mode = ((signed char *)p)[1];
        if (mode == 2 && p->remaining > 0) {
            if (p->records[p->record_index].word_38 == 1)
                func_0040D848(p);
            if (p->records[p->record_index].word_38 == mode)
                func_0040D8F8(p);
            if (p->records[p->record_index].word_38 == 0) {
                do {
                    func_0040D738(p);
                } while (0);
            }
        }
    }
}
