/* SJ memory-pool GetChunk: take up to `nbyte` bytes from the head chunk queued
 * on line `id`.  Each pool node carries an SJCK payload (see
 * src/cri_sj_pool_support.c), so the queues are written here directly in
 * SJCK terms and func_004104E0 (the SJCK splitter, src/s4.c) gets real SJCKs. */
#include "cri_sj_ring_buffer_types.h"

typedef unsigned int u32;
typedef signed int s32;
typedef signed char s8;
typedef unsigned char u8;

typedef struct SjPoolChunkNode SjPoolChunkNode;
struct SjPoolChunkNode {
    SjPoolChunkNode *next;
    u32 unknown;
    SJCK chunk;
};
typedef char SjPoolChunkNode_size_check[sizeof(SjPoolChunkNode) == 16 ? 1 : -1];

typedef struct SjPoolChunkObject {
    SJ_OBJ sj;
    s8 active;
    s8 mode;
    u8 padding6[2];
    UUID *uuid;
    SjPoolChunkNode *pool;
    s32 capacity;
    SjPoolChunkNode *free_nodes;
    SjPoolChunkNode *queue[4];
    SJRBFErrorCallback err_func;
    void *err_obj;
} SjPoolChunkObject;
typedef char SjPoolChunkObject_size_check[sizeof(SjPoolChunkObject) == 0x30 ? 1 : -1];

extern void func_0040EFE0(void);
extern void func_0040EFF8(void);
extern void func_004104E0(SJCK *source, s32 maximum, SJCK *span, SJCK *remainder);

void func_00410000(SJ_OBJ *object, s32 id, s32 nbyte, SJCK *chunk)
{
    SjPoolChunkObject *pool = (SjPoolChunkObject *)object;
    SjPoolChunkNode *node;
    SJCK range;
    SJCK remainder;

    if ((u32)id >= 4)
    {
        if (pool->err_func != 0)
            pool->err_func(pool->err_obj, -3);
        chunk->data = 0;
        chunk->len = 0;
        return;
    }

    func_0040EFE0();
    node = pool->queue[id];
    if (node == 0)
    {
        chunk->data = 0;
        chunk->len = 0;
    }
    else
    {
        range = node->chunk;
        if (nbyte >= range.len)
        {
            *chunk = range;
            pool->queue[id] = node->next;
            node->next = pool->free_nodes;
            pool->free_nodes = node;
        }
        else if (pool->mode == 1)
        {
            func_004104E0(&range, nbyte, &range, &remainder);
            *chunk = range;
            node->chunk = remainder;
        }
        else
        {
            chunk->data = 0;
            chunk->len = 0;
        }
    }
    func_0040EFF8();
}
