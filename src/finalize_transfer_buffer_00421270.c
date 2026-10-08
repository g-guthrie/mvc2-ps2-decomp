typedef unsigned int u32;
typedef int s32;
typedef unsigned long long u64;

struct TransferBuffer
{
    u32 unknown0;
    u32 *dmaBuffer;
    s32 length;
    u32 unknownC;
    u64 *tag;
};

extern void func_00421200(u32 *tag);

void func_00421270(struct TransferBuffer *transfer)
{
    u32 qwc;

    if (transfer->dmaBuffer != 0)
    {
        qwc = (transfer->length + 1) >> 1;
        *transfer->tag = 0x70000000 + qwc;
        *(u64 *)transfer->dmaBuffer |= 0x8000;
        func_00421200((u32 *)transfer->tag);
    }
}
