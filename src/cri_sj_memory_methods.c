#include "cri_sj_ring_buffer_types.h"
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


void func_0040F728(SJ_OBJ *object)
{
    SJRBFRecord *p = (SJRBFRecord *)object;
    signed int v = p->bsize;
    p->unk34 = 0;
    p->unk0C = 0;
    p->unk14 = 0;
    p->unk18 = 0;
    p->unk28 = 0;
    p->unk2C = 0;
    p->unk30 = 0;
    p->unk10 = v;
}

typedef struct { char *data; int length; } CriSjChunk;
extern void func_0040EFE0(void);
extern void func_0040EFF8(void);
void func_0040F228(CriSjMemory *record, int line, int requested, CriSjChunk *output)
{
    int amount;
    func_0040EFE0();
    if (line == 0) {
        output->length = 0;
        output->data = 0;
    } else if (line == 1) {
        amount = record->remaining < requested ? record->remaining : requested;
        output->length = amount;
        {
            int offset = record->offset;
            record->offset = offset + amount;
            output->data = record->buffer + offset;
        }
        record->remaining -= output->length;
    } else {
        output->length = 0;
        output->data = 0;
        if (record->error_callback)
            record->error_callback(record->error_context, -3);
    }
    func_0040EFF8();
}

int func_0040F528(CriSjMemory *record) { return record->size; }

void func_0040F010(void *context, int error)
{
    for (;;) {}
}
void func_0040F530(void *context, int error)
{
    for (;;) {}
}
