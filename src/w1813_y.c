typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
#include "cri_sj_ring_buffer_types.h"

typedef struct { s32 addr; s32 len; } Rng;
typedef struct Node { struct Node *next; s32 pad4; Rng r; } Node;
typedef struct {
    u8 pad0[5]; s8 b5; u8 pad6[0xE]; Node *free; Node *list[4];
    void (*fn)(s32, s32); s32 arg;
} Obj;

void func_00410138(SJ_OBJ *object, s32 index, SJCK *chunk)
{
#define OBJECT ((Obj *)object)
#define INDEX ((u32)index)
#define CHUNK ((Rng *)chunk)
    extern void func_0040EFE0(void);
    extern void func_0040EFF8(void);
    Node *last;
    Node *node;
    Node **link;
    if (INDEX >= 4) {
        if (OBJECT->fn != 0) OBJECT->fn(OBJECT->arg, -3);
        return;
    }
    if (CHUNK->len <= 0) return;
    if (CHUNK->addr == 0) return;
    func_0040EFE0();
    link = &OBJECT->list[INDEX];
    node = *link;
    last = 0;
    while (node != 0) {
        last = node;
        node = last->next;
        link = (Node **)last;
    }
    if (OBJECT->b5 == 1 && last != 0 && last->r.addr + last->r.len == CHUNK->addr) {
        last->r.len = last->r.len + CHUNK->len;
    } else {
        last = OBJECT->free;
        if (last == 0) {
            if (OBJECT->fn != 0) OBJECT->fn(OBJECT->arg, -3);
        } else {
            node = last->next;
            last->r = *CHUNK;
            OBJECT->free = node;
            last->next = 0;
            *link = last;
        }
    }
    func_0040EFF8();
#undef OBJECT
#undef INDEX
#undef CHUNK
}
