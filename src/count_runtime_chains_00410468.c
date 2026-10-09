#include "runtime_span_types.h"

s32 func_00410468(struct RuntimeQueryContext *context, s32 index)
{
    struct RuntimeNode *node;
    s32 count;

    count = 0;
    node = context->entries[index];
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

s32 func_004104A8(struct RuntimeQueryContext *context)
{
    struct RuntimeNode *node;
    s32 count;

    count = 0;
    node = context->moved;
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
