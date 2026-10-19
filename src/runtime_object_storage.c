#include "runtime_object_storage.h"

typedef signed int s32;

void func_00400148(RuntimeObjectStorage *object, s32 first, s32 second, s32 bytes, s32 context)
{
    s32 sectors = bytes / 2048;
    object->context = context;
    object->descriptor = first;
    object->base_offset = second;
    object->block_size = 512;
    object->sector_count = sectors;
    object->state = 1;
    object->status = 0;
    object->position = 0;
    object->byte_length = bytes;
    if (bytes - sectors * 2048 > 0)
        object->sector_count = sectors + 1;
    object->active = 1;
}

extern s32 D_004C23A8, D_004C23AC, D_004C23A0, D_004C23A4;
RuntimeObjectStorage *func_00400258(s32 a, s32 b, s32 c, s32 d) {
    RuntimeObjectStorage *p = 0;
    s32 i;
    for (i = 0; i < D_004C23AC; i++) {
        p = &gRuntimeObjectPool_00484AC0[D_004C23A8 + i];
        if (p->active == 0) break;
    }
    if (i == D_004C23AC) return 0;
    func_00400148(p, a, b, c, d);
    return p;
}

RuntimeObjectStorage *func_004001A8(s32 a, s32 b, s32 c, s32 d) {
    RuntimeObjectStorage *p = 0;
    s32 i;
    for (i = 0; i < D_004C23A4; i++) {
        p = &gRuntimeObjectPool_00484AC0[D_004C23A0 + i];
        if (p->active == 0) break;
    }
    if (i == D_004C23A4) return 0;
    func_00400148(p, a, b, c, d);
    return p;
}
