#include "objects.h"

struct SpawnedActor {
    unsigned char pad0, b1;
    unsigned char pad1[2];
    unsigned char b4;
    unsigned char pad2[0x10 - 5];
    void (*p16)(struct SpawnedActor *);
    unsigned char pad3[0x18 - 0x14];
    struct Actor *p24;
    unsigned char pad4[0x20 - 0x1c];
    unsigned char b32, b33;
    unsigned char pad5[0x26 - 0x22];
    unsigned short w38;
    unsigned char pad6[0xcc - 0x28];
    short wcc;
};

typedef void (*SpawnHandler)(struct SpawnedActor *);
typedef void (*SpawnPairHandler)(struct SpawnedActor *, struct Actor *);
extern struct SpawnedActor *func_0c0374da(int, int, int);
extern SpawnPairHandler dat_0c25390c[];
extern SpawnHandler dat_0c253918[];

void func_0c17ab10(struct SpawnedActor *q);

struct SpawnedActor *func_0c17aabc(struct Actor *p, unsigned char x, unsigned char y)
{
    struct SpawnedActor *q;
    short *slot;
    if ((q = func_0c0374da(0, 1, 0)) != 0) {
        q->p16 = func_0c17ab10;
        q->w38 = 0x2e05;
        q->p24 = p;
        q->b1 = ((unsigned char *)p)[1];
        q->b32 = x;
        q->b33 = y;
        slot = &q->wcc;
        *slot = *(short *)&p->b158;
    }
    return q;
}

void func_0c17ab10(struct SpawnedActor *q)
{
    dat_0c25390c[q->b32](q, q->p24);
}

void func_0c17ab26(struct SpawnedActor *q)
{
    dat_0c253918[q->b4](q);
}
