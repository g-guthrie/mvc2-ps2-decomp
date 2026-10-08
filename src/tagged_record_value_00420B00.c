typedef unsigned char u8;
typedef unsigned long long u64;
typedef signed short s16;

typedef struct {
    volatile u64 *output;
    u8 padding[24];
    volatile s16 value;
} TagRecord;

int func_00420B00(TagRecord *record)
{
    s16 value;
    volatile u64 *output;

    value = record->value;
    output = record->output;
    *output = ((u64)0x10000000u << 32) | (u64)value;
    record->value = 0;
    return 1;
}
