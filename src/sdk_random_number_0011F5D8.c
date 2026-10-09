typedef unsigned char u8;
typedef unsigned long long u64;
typedef signed int s32;

typedef struct ReentrantRandomContext
{
    u8 opaque[0xA8];
    u64 seed;
} ReentrantRandomContext;

extern ReentrantRandomContext *D_0043B6F8;

s32 func_0011F5D8(void)
{
    ReentrantRandomContext *context = D_0043B6F8;
    u64 next = context->seed * 0x5851f42d4c957f2dULL + 1;

    context->seed = next;
    return (s32)((next >> 32) & 0x7fffffffULL);
}
