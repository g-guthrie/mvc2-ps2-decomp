/* SJMEM reset has the void-return SJ interface contract. */
#include "cri_sj_memory_types.h"
void func_0040F1D0(CriSjMemory *p)
{
    int size=p->size;
    p->offset=0;
    p->remaining=size;
}

extern void func_0040EFE0(void);
extern void func_0040EFF8(void);
int func_0040F478(CriSjMemory *record,int line,int requested,int *available)
{
    int amount;
    func_0040EFE0();
    if (line==0) amount=0;
    else if (line==1) {
        amount=record->remaining<requested?record->remaining:requested;
    } else {
        amount=0;
        if (record->error_callback) record->error_callback(record->error_context,-3);
    }
    *available=amount;
    func_0040EFF8();
    return amount==requested;
}
