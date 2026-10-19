#include "runtime_object_storage.h"
#include "runtime_span_types.h"
typedef struct RuntimeSpan RuntimeSpan;
typedef struct Stream Stream;
typedef struct StreamOps {
    void *unknown[6];
    void (*request)(Stream *, int, int, RuntimeSpan *);
    void (*release)(Stream *, int, RuntimeSpan *);
    void (*commit)(Stream *, int, RuntimeSpan *);
    int (*available)(Stream *, int);
} StreamOps;
struct Stream { StreamOps *ops; };
extern int func_00406AE8(int);
extern int func_004006A0(RuntimeObjectStorage *);
extern void func_004104E0(const RuntimeSpan *, int, RuntimeSpan *, RuntimeSpan *);
extern void func_004007E0(void);
extern int func_00406960(int, int, int);
extern int D_004C23B0;

void func_004007F0(RuntimeObjectStorage *object)
{
    Stream *stream = (Stream *)object->context;
    RuntimeSpan completed, remainder;
    int bytes, count, result, remaining;

    if ((signed char)object->status == 1) {
        result = func_00406AE8(object->descriptor);
        if (result == 1) {
            bytes = object->word20 << 11;
            func_004104E0((RuntimeSpan *)&object->word24, bytes, &completed, &remainder);
            stream->ops->commit(stream, 1, &completed);
            stream->ops->release(stream, 0, &remainder);
            if (func_004006A0(object) == object->sector_count && object->word38 != 0)
                ((void (*)(int))object->word38)(object->word3c);
            object->status = 0;
            object->word34 += bytes;
            if (func_004006A0(object) >= (object->byte_length + 2047) / 2048)
                object->state = 3;
            object->auxiliary = 0;
        } else if (result == 3) {
            stream->ops->release(stream, 0, (RuntimeSpan *)&object->word24);
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
        if (stream == 0 || stream->ops == 0) {
            func_004007E0();
            return;
        }
        if (stream->ops->available(stream, 1) >= object->word1c)
            return;
        stream->ops->request(stream, 0, object->word18, (RuntimeSpan *)&object->word24);
        count = object->word28 / 2048;
        remaining = object->sector_count;
        remaining -= func_004006A0(object);
        if (count >= remaining)
            count = remaining;
        if (count >= object->block_size)
            count = object->block_size;
        if (count == 0) {
            stream->ops->release(stream, 0, (RuntimeSpan *)&object->word24);
            return;
        }
        object->word20 = func_00406960(object->descriptor, count, object->word24);
        if (object->word20 <= 0) {
            stream->ops->release(stream, 0, (RuntimeSpan *)&object->word24);
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
