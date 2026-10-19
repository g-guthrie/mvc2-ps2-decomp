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
int func_003FF810(u8 *context, int *position, int *available, int *remaining)
{
    int i;
    QueryStream *first = *(QueryStream **)(context + 0xC);
    QueryStream **streams = (QueryStream **)(context + 0xC);
    struct RuntimeSpan *span = (struct RuntimeSpan *)(context + 0x1C);
    int count, maximum;

    for (i = 0; i < func_003F8130(*(void **)(context + 4)); i++) {
        QueryStream *stream = streams[i];
        stream->ops->request(stream, 0, 0x4000, &span[i]);
    }
    *position = (*(int *)(context + 0x1C) - func_0040FCD0(first)) / 2;
    count = *(int *)(context + 0x20) / 2;
    maximum = *(int *)(context + 0x38);
    if (count < maximum)
        maximum = count;
    *available = maximum;
    if (*(int *)(context + 0x3C) >= 0)
        *remaining = *(int *)(context + 0x3C) - *(int *)(context + 0x40);
    else
        *remaining = 0x1FFFFFFF;
    return func_003F8118(*(void **)(context + 4));
}
