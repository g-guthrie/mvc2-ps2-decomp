typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;

struct DmaContext
{
    u8 unknown0[16];
    u8 * volatile alignedBuffer;
    s32 qwordCount;
};

extern void func_00420970(void *context);

void func_00420980(struct DmaContext *context, u8 *buffer, s32 size)
{
    u32 alignedAddress;
    u8 *alignedBuffer;

    func_00420970(context);
    alignedAddress = ((u32)buffer + 63) & 0xffffffc0;
    alignedBuffer = (u8 *)alignedAddress;
    context->alignedBuffer = alignedBuffer;
    context->qwordCount = size >> 3;
    alignedBuffer = context->alignedBuffer;
    ((u64 *)alignedBuffer)[0] = 0x70000000;
    ((u64 *)alignedBuffer)[1] = 0;
}
