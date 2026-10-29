#include "runtime_object_storage.h"
#include "cri_sj_ring_buffer_types.h"

/* Typed view of one 64-byte RuntimeObjectStorage slot while it is streaming:
 * +0x04 is the SJ stream being filled, +0x08 the open file handle, +0x24 the
 * chunk currently being read into, +0x38/+0x3C the completion callback. */
typedef struct RuntimeStreamObject {
    signed char active;
    unsigned char state, status, auxiliary;
    SJ_OBJ *stream;
    void *file;
    signed int position, base_offset, byte_length;
    signed int read_size, low_water, sectors_read;
    SJCK chunk;
    signed int block_size, sector_count, bytes_done;
    void (*callback)(void *);
    void *callback_arg;
} RuntimeStreamObject;
typedef char RuntimeStreamObjectSizeCheck[
    (sizeof(RuntimeStreamObject) == sizeof(RuntimeObjectStorage)) ? 1 : -1];

extern int func_00406AE8(void *file);
extern int func_004006A0(RuntimeStreamObject *);
extern void func_004104E0(SJCK *, int, SJCK *, SJCK *);
extern void func_004007E0(void);
extern int func_00406960(void *file, int count, signed char *buffer);
extern int D_004C23B0;

void func_004007F0(RuntimeStreamObject *object)
{
    SJ_OBJ *stream = object->stream;
    SJCK completed, remainder;
    int bytes, count, result, remaining;

    if ((signed char)object->status == 1) {
        result = func_00406AE8(object->file);
        if (result == 1) {
            bytes = object->sectors_read << 11;
            func_004104E0(&object->chunk, bytes, &completed, &remainder);
            stream->vtbl->PutChunk(stream, 1, &completed);
            stream->vtbl->UngetChunk(stream, 0, &remainder);
            if (func_004006A0(object) == object->sector_count && object->callback != 0)
                object->callback(object->callback_arg);
            object->status = 0;
            object->bytes_done += bytes;
            if (func_004006A0(object) >= (object->byte_length + 2047) / 2048)
                object->state = 3;
            object->auxiliary = 0;
        } else if (result == 3) {
            stream->vtbl->UngetChunk(stream, 0, &object->chunk);
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
        if (stream->vtbl->GetNumData(stream, 1) >= object->low_water)
            return;
        stream->vtbl->GetChunk(stream, 0, object->read_size, &object->chunk);
        count = object->chunk.len / 2048;
        remaining = object->sector_count;
        remaining -= func_004006A0(object);
        if (count >= remaining)
            count = remaining;
        if (count >= object->block_size)
            count = object->block_size;
        if (count == 0) {
            stream->vtbl->UngetChunk(stream, 0, &object->chunk);
            return;
        }
        object->sectors_read = func_00406960(object->file, count, object->chunk.data);
        if (object->sectors_read <= 0) {
            stream->vtbl->UngetChunk(stream, 0, &object->chunk);
            if (func_00406AE8(object->file) == 3 && D_004C23B0 >= 0) {
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
