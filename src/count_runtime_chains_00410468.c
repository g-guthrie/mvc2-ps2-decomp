typedef unsigned char u8;
typedef signed int s32;

struct RuntimeChain
{
    struct RuntimeChain *next;
};

s32 func_00410468(void *context, s32 index)
{
    struct RuntimeChain *node;
    s32 count;

    count = 0;
    node = *(struct RuntimeChain **)((u8 *)context + index * 4 + 24);
    if (node != 0)
    {
        do
        {
            count++;
            node = node->next;
        } while (node != 0);
    }
    return count;
}

s32 func_004104A8(void *context)
{
    struct RuntimeChain *node;
    s32 count;

    count = 0;
    node = *(struct RuntimeChain **)((u8 *)context + 20);
    if (node != 0)
    {
        do
        {
            count++;
            node = node->next;
        } while (node != 0);
    }
    return count;
}
