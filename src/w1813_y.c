typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s32 addr; s32 len; } Rng;
typedef struct Node { struct Node *next; s32 pad4; Rng r; } Node;
typedef struct {
    u8 pad0[5]; s8 b5; u8 pad6[0xE]; Node *free; Node *list[4];
    void (*fn)(s32, s32); s32 arg;
} Obj;

void func_00410138(Obj *o, u32 n, Rng *r)
{
    extern void func_0040EFE0(void);
    extern void func_0040EFF8(void);
    Node *last;
    Node *node;
    Node **link;
    if (n >= 4) {
        if (o->fn != 0) o->fn(o->arg, -3);
        return;
    }
    if (r->len <= 0) return;
    if (r->addr == 0) return;
    func_0040EFE0();
    link = &o->list[n];
    node = *link;
    last = 0;
    while (node != 0) {
        last = node;
        node = last->next;
        link = (Node **)last;
    }
    if (o->b5 == 1 && last != 0 && last->r.addr + last->r.len == r->addr) {
        last->r.len = last->r.len + r->len;
    } else {
        last = o->free;
        if (last == 0) {
            if (o->fn != 0) o->fn(o->arg, -3);
        } else {
            node = last->next;
            last->r = *r;
            o->free = node;
            last->next = 0;
            *link = last;
        }
    }
    func_0040EFF8();
}
