#include "stream_group_types.h"
typedef struct QueryStream QueryStream;
struct QueryStreamOps {
    void *unknown[7];
    void (*unget)(QueryStream *, int, struct RuntimeSpan *);
    void (*put)(QueryStream *, int, struct RuntimeSpan *);
};
struct QueryStream { struct QueryStreamOps *ops; };
extern s32 func_003F81B0(void *);
extern s32 func_003F8430(void *);
extern s32 func_003F8438(void *);
extern s32 func_003F8130(void *);
extern void func_003F83F0(void *);
extern void func_004104E0(struct RuntimeSpan *, s32, struct RuntimeSpan *, struct RuntimeSpan *);

void func_003FFB08(StreamGroup *g)
{
    struct RuntimeSpan ck;
    struct RuntimeSpan rest;
    void *engine = g->engine;
    QueryStream *res = (QueryStream *)g->resource;
    s32 avail = func_003F81B0(engine);
    s32 step = func_003F8430(engine);
    s32 n = func_003F8438(engine);
    QueryStream **streams = g->streams;
    struct RuntimeSpan *span = g->stream_spans;
    s32 i;

    avail -= g->progress_34;
    if (n >= avail)
        n = avail;
    func_004104E0(&g->request_span, step, &ck, &rest);
    res->ops->put(res, 0, &ck);
    res->ops->unget(res, 1, &rest);
    for (i = 0; i < func_003F8130(g->engine); i++) {
        func_004104E0(span, n * 2, &ck, &rest);
        if (g->callback_50 != 0)
            g->callback_50(g->callback_argument_54, i, ck.start, ck.length);
        (*streams)->ops->put(*streams, 1, &ck);
        span++;
        (*streams)->ops->unget(*streams, 0, &rest);
        streams++;
    }
    g->progress_2c += n;
    g->progress_30 += step;
    g->progress_34 += n;
    g->consumed += n;
    g->progress_44 += step;
    if (g->remaining_limit >= 0 && g->consumed >= g->remaining_limit && g->callback_48 != 0)
        g->callback_48(g->callback_argument_4c);
    func_003F83F0(engine);
}
