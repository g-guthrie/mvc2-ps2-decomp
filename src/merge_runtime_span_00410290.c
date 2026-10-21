#include "runtime_span_types.h"
#include "cri_sj_ring_buffer_types.h"

extern void func_0040EFE0(void);
extern void func_0040EFF8(void);

void func_00410290(SJ_OBJ *object, s32 index, SJCK *chunk)
{
    struct RuntimeQueryContext *context = (struct RuntimeQueryContext *)object;
    const struct RuntimeSpan *span = (const struct RuntimeSpan *)chunk;
    struct RuntimeNode *node;

    if ((u32)index >= 4)
    {
        if (context->fallback != 0)
            context->fallback(context->fallbackArgument, -3);
        return;
    }
    if (span->length <= 0 || span->start == 0)
        return;

    func_0040EFE0();
    node = context->entries[index];
    if (context->mode == 1 && node != 0)
    {
        s32 start = span->start;
        s32 length = span->length;

        if (start + length == node->span.start)
        {
            node->span.start = start;
            node->span.length += length;
            goto unlock;
        }
    }

    node = context->moved;
    if (node == 0)
    {
        if (context->fallback != 0)
            context->fallback(context->fallbackArgument, -3);
    }
    else
    {
        context->moved = node->next;
        node->span = *span;
        node->next = 0;
        node->next = context->entries[index];
        context->entries[index] = node;
    }
unlock:
    func_0040EFF8();
}
