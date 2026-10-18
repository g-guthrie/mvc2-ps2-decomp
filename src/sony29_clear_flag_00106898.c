typedef unsigned int u32;
typedef struct { char pad[16]; u32 state; char pad2[4]; u32 status; } Record;

void func_00106898(Record *record)
{
    record->status = 0;
    record->state &= 0xFFFFFFFEu;
}
