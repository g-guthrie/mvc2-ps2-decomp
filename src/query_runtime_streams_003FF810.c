#include "stream_group_types.h"
#include "runtime_stream_query.h"
#include "runtime_span_types.h"
typedef struct QueryStream QueryStream;
struct QueryStreamOps {
    void *unknown[6];
    void (*request)(QueryStream *, int, int, struct RuntimeSpan *);
};
struct QueryStream { struct QueryStreamOps *ops; };
extern s8 func_003F8130(void *);
extern int func_0040FCD0(QueryStream *);
extern int func_003F8118(void *);
int func_003FF810(u8 *opaque, int *position, int *available, int *remaining)
{
    StreamGroup *context = (StreamGroup *)opaque;
    int i;
    QueryStream *first = context->streams[0];
    QueryStream **streams = context->streams;
    struct RuntimeSpan *span = context->stream_spans;
    int count, maximum;

    for (i = 0; i < func_003F8130(context->engine); i++) {
        QueryStream *stream = streams[i];
        stream->ops->request(stream, 0, 0x4000, &span[i]);
    }
    *position = (context->stream_spans[0].start - func_0040FCD0(first)) / 2;
    count = context->stream_spans[0].length / 2;
    maximum = context->maximum_available;
    if (count < maximum)
        maximum = count;
    *available = maximum;
    if (context->remaining_limit >= 0)
        *remaining = context->remaining_limit - context->consumed;
    else
        *remaining = 0x1FFFFFFF;
    return func_003F8118(context->engine);
}
