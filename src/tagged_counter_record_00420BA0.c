typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed int s32;
typedef signed short s16;

typedef struct {
    volatile u64 *output0;
    volatile u64 *output1;
    volatile u32 counter;
    volatile s32 payload;
    u8 padding[10];
    volatile s16 mode;
} TaggedCounterRecord;

int func_00420BA0(TaggedCounterRecord *record)
{
    s16 mode;
    s32 payload;
    volatile u64 *output;
    u32 counter;

    mode = record->mode;
    payload = record->payload;
    output = record->output1;
    *output = ((u64)0x04000000u << 32) |
              (u64)payload |
              ((u64)mode << 60);
    record->payload = 0;
    counter = record->counter;
    record->counter = (counter + 1) & ~1u;
    return 1;
}
