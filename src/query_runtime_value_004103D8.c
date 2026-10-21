#include "runtime_span_types.h"
#include "cri_sj_ring_buffer_types.h"

s32 func_004103D8(SJ_OBJ *object, s32 index,
                  s32 expected, s32 *actual)
{
    struct RuntimeQueryContext *context = (struct RuntimeQueryContext *)object;
    struct RuntimeNode *node;
    struct RuntimeSpan span;

    *actual = 0;
    if ((u32)index >= 4)
    {
        if (context->fallback != 0)
            context->fallback(context->fallbackArgument, -3);
        return 0;
    }

    node = context->entries[index];
    if (node == 0)
        return 0;

    span = node->span;
    *actual = span.length;
    if (context->mode == 1)
    {
        if (span.length < expected)
            return 0;
        return 1;
    }
    return span.length == expected;
}
