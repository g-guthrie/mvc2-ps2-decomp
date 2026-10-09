#include "runtime_span_types.h"

s32 func_0040FF88(struct RuntimeQueryContext *context, s32 index)
{
    struct RuntimeNode *node;
    s32 total;

    if ((u32)index >= 4)
    {
        if (context->fallback != 0)
            context->fallback(context->fallbackArgument, -3);
        return 0;
    }

    total = 0;
    node = context->entries[index];
    while (node != 0)
    {
        total += node->span.length;
        node = node->next;
    }
    return total;
}
