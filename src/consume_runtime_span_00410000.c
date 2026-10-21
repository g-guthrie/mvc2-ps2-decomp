#include "runtime_span_types.h"
#include "cri_sj_ring_buffer_types.h"

extern void func_0040EFE0(void);
extern void func_0040EFF8(void);
extern void func_004104E0(const struct RuntimeSpan *source, s32 maximum,
                          struct RuntimeSpan *span,
                          struct RuntimeSpan *remainder);

void func_00410000(SJ_OBJ *object, s32 index,
                   s32 length, SJCK *chunk)
{
    struct RuntimeQueryContext *context = (struct RuntimeQueryContext *)object;
    struct RuntimeSpan *result = (struct RuntimeSpan *)chunk;
    struct RuntimeNode *node;
    struct RuntimeSpan range;
    struct RuntimeSpan remainder;

    if ((u32)index >= 4)
    {
        if (context->fallback != 0)
            context->fallback(context->fallbackArgument, -3);
        result->start = 0;
        result->length = 0;
        return;
    }

    func_0040EFE0();
    node = context->entries[index];
    if (node == 0)
    {
        result->start = 0;
        result->length = 0;
    }
    else
    {
        range = node->span;
        if (length >= range.length)
        {
            *result = range;
            context->entries[index] = node->next;
            node->next = context->moved;
            context->moved = node;
        }
        else if (context->mode == 1)
        {
            func_004104E0(&range, length, &range, &remainder);
            *result = range;
            node->span = remainder;
        }
        else
        {
            result->start = 0;
            result->length = 0;
        }
    }
    func_0040EFF8();
}
