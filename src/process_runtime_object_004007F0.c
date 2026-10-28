/* Provisional: shared storage still exposes descriptor and chunk as integer words. */
#include "runtime_object_storage.h"
#include "cri_sj_ring_buffer_types.h"
extern int func_00406AE8(int);
extern int func_004006A0(RuntimeObjectStorage *);
extern void func_004104E0(SJCK *, int, SJCK *, SJCK *);
extern void func_004007E0(void);
extern int func_00406960(int, int, int);
extern int D_004C23B0;

void func_004007F0(RuntimeObjectStorage *object)
{
    SJ_OBJ *stream = (SJ_OBJ *)object->context;
    SJCK completed, remainder;
    int bytes, count, result, remaining;

    if ((signed char)object->status == 1) {
        result = func_00406AE8(object->descriptor);
        if (result == 1) {
            bytes = object->word20 << 11;
            func_004104E0((SJCK *)&object->word24, bytes, &completed, &remainder);
            stream->vtbl->PutChunk(stream, 1, &completed);
            stream->vtbl->UngetChunk(stream, 0, &remainder);
            if (func_004006A0(object) == object->sector_count && object->word38 != 0)
                ((void (*)(int))object->word38)(object->word3c);
            object->status = 0;
            object->word34 += bytes;
            if (func_004006A0(object) >= (object->byte_length + 2047) / 2048)
                object->state = 3;
            object->auxiliary = 0;
        } else if (result == 3) {
            stream->vtbl->UngetChunk(stream, 0, (SJCK *)&object->word24);
            if (D_004C23B0 >= 0) {
                if ((signed char)object->auxiliary >= D_004C23B0)
                    object->state = 4;
                else
                    object->auxiliary++;
            }
            object->status = 0;
        }
    }
    if (object->status == 0) {
        if (stream == 0 || stream->vtbl == 0) {
            func_004007E0();
            return;
        }
        if (stream->vtbl->GetNumData(stream, 1) >= object->word1c)
            return;
        stream->vtbl->GetChunk(stream, 0, object->word18, (SJCK *)&object->word24);
        count = object->word28 / 2048;
        remaining = object->sector_count;
        remaining -= func_004006A0(object);
        if (count >= remaining)
            count = remaining;
        if (count >= object->block_size)
            count = object->block_size;
        if (count == 0) {
            stream->vtbl->UngetChunk(stream, 0, (SJCK *)&object->word24);
            return;
        }
        object->word20 = func_00406960(object->descriptor, count, object->word24);
        if (object->word20 <= 0) {
            stream->vtbl->UngetChunk(stream, 0, (SJCK *)&object->word24);
            if (func_00406AE8(object->descriptor) == 3 && D_004C23B0 >= 0) {
                if ((signed char)object->auxiliary >= D_004C23B0)
                    object->state = 4;
                else
                    object->auxiliary++;
            }
        } else {
            object->status = 1;
        }
    }
}
