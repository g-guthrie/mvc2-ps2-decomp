typedef unsigned char u8; typedef signed char s8; typedef int s32; typedef unsigned int u32;

typedef struct {
    s32 seq;
    u8 data[0x28];
    void *a2;
    s32 a3;
    s32 t0;
    s32 f38;
    s32 f3C;
} Ent;

typedef struct {
    s8 f0;
    s8 state;
    u8 pad[0x1A];
    s32 head;
    u8 pad2[4];
    s32 count;
    u8 pad3[0x10];
    Ent ent[16];
} Que;

extern char D_004BE2F8[];
extern char D_004BE320[];
extern void func_0040D5A0(const char *, ...);
extern s32 func_00120440(void *destination, const void *source, u32 maximum);

s32 func_0040CE38(Que *q, void *src, void *a2, s32 a3, s32 t0)
{
    s32 seq;
    Ent *e;
    s32 i;

    if (q == 0) {
        func_0040D5A0(D_004BE2F8);
        return -1;
    }
    if (q->count >= 16) {
        return -1;
    }
    if (src == 0) {
        func_0040D5A0(D_004BE320, src);
        return -1;
    }
    e = &q->ent[q->head];
    i = (q->head + 15) % 16;
    seq = (q->ent[i].seq == 0x7FFFFFFF) ? 0 : q->ent[i].seq + 1;
    e->seq = seq;
    func_00120440(e->data, src, 0x28);
    e->a3 = a3;
    e->t0 = t0;
    e->f3C = 0;
    e->f38 = 0;
    e->a2 = a2;
    q->head = (q->head + 1) % 16;
    q->count++;
    if (q->state == 1) {
        q->state = 2;
    }
    return seq;
}
