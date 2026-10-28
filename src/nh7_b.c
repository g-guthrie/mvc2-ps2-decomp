typedef unsigned char u8;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct O {
    u8 pad[0x14];
    struct O *next;
    struct O *parent;
    u8 pad1c[4];
    u8 n;
    u8 pad21[0x17];
    f32 x;
} O;

void func_001C1630(O *p, O *q)
{
f32 d; q = p->parent; d = (q->next->x - q->x - 34.28571319580078f) / 8.0f; p->x = q->x + d * (f32)(u32)p->n;
}
