#include "stream_group_types.h"
#include "cri_sj_ring_buffer_types.h"
extern s32 func_003F8120(void *);
extern s32 func_003FFFF0(StreamGroup *);
extern s32 func_003FFFC0(StreamGroup *);
extern void func_003F8320(void *, s32, s32);
extern void func_003F83A8(void *);

void func_003FF930(StreamGroup *p) {
    void *engine = p->engine;
    SJ_OBJ *resource = (SJ_OBJ *)p->resource;
    SJ_OBJ *stream;
    s32 avail;
    if (p->mode == 1) {
        if (resource->vtbl->GetNumData(resource, 1) == 0) {
            p->lifecycle = 3;
            return;
        }
    }
    resource->vtbl->GetChunk(resource, 1, 0x7FFFFFFF, (SJCK *)&p->request_span);
    if (func_003F8120(engine) == 0 && p->request_span.length >= 2) {
        u8 *d = (u8 *)p->request_span.start;
        if ((u16)((*(u16 *)d << 8) | d[1]) == 0x8001) goto fail;
    }
    if (p->progress_34 < func_003FFFF0(p)) goto ok;
fail:
    p->lifecycle = 3;
    resource->vtbl->UngetChunk(resource, 1, (SJCK *)&p->request_span);
    return;
ok:
    avail = func_003FFFC0(p);
    stream = (SJ_OBJ *)p->streams[0];
    if (stream->vtbl->GetNumData(stream, 0) / 2 < avail) {
        resource->vtbl->UngetChunk(resource, 1, (SJCK *)&p->request_span);
        return;
    }
    if (func_003F8120(engine) == 10)
        resource->vtbl->UngetChunk(resource, 1, (SJCK *)&p->request_span);
    func_003F8320(engine, p->request_span.start, p->request_span.length);
    func_003F83A8(engine);
}
