/* Candidate (1034/1036): only 0x0c04dc48 differs; retail computes entry->row*3 with r1 as the copy temp (mov r3,r1; shll r3; add r1,r3), ours uses r2. Labels on every statement and *3 spellings tried. All other functions and pools exact. */
/* CPU script selection: per-actor script slots at 0x460 and the operand
 * state block between 0x43c and 0x4b8. */
#include "objects.h"

#define AI_U8(a, o) (*(unsigned char *)((char *)(a) + (o)))
#define AI_S8(a, o) (*(signed char *)((char *)(a) + (o)))
#define AI_U16(a, o) (*(unsigned short *)((char *)(a) + (o)))
#define AI_U32(a, o) (*(unsigned int *)((char *)(a) + (o)))
#define AI_F32(a, o) (*(float *)((char *)(a) + (o)))
#define AI_PTR(a, o) (*(char **)((char *)(a) + (o)))

/* Script cursor rows at actor 0x460: pointer, step and the two step bytes. */
struct AiScriptCursor8 { unsigned char *script; short step; unsigned char index, wait; };
struct AiDistance484 { unsigned char pad[0x484]; float f484, f488, f48c; };
struct AiEntry28 { unsigned char pad0[25], row, pad26[2]; };

/* CPU-control view of an actor: script tables at 0x188 and the operand state
 * from 0x43c to 0x4b8. */
struct CpuActor {
    unsigned char pad0[0x188];
    int script_tables[3];
    int script_base194;
    unsigned char pad198[0x201 - 0x198];
    unsigned char b201;
    unsigned char pad202[0x43c - 0x202];
    unsigned char b43c, b43d, b43e, pad43f, pad440, b441;
    unsigned short w442;
    unsigned char pad444[2], b446, b447, pad448[3], b44b;
    unsigned char pad44c[0x45c - 0x44c];
    unsigned char b45c, pad45d, b45e, b45f;
    struct AiScriptCursor8 cursor[3];
    unsigned char pad478[8];
    unsigned char b480, pad481, b482, b483;
    float f484, f488, f48c;
    unsigned char pad490[4];
    unsigned char b494, b495, b496, b497;
    unsigned char pad498[8];
    unsigned char b4a0, pad4a1[3], b4a4, b4a5, b4a6, b4a7;
    signed char b4a8;
    unsigned char b4a9, pad4aa[6];
    unsigned int l4b0;
    unsigned char pad4b4[4];
    struct Actor *p4b8;
};
#define CPU(a) ((struct CpuActor *)(a))

extern struct ActorFlags *dat_0c2d6f84;
extern unsigned char dat_0c23e70c[];
extern unsigned char *dat_0c23eee0[], *dat_0c23ef68[];
extern signed char *dat_0c23f174[];
extern short dat_0c2f847a;
extern struct PlayerSlotScore dat_0c2d7088[];
extern int func_0c02849a(void);

void func_0c04da30(struct Actor *a);
void func_0c04da6a(struct Actor *a);
void func_0c04dba2(struct Actor *a, int n, int k);

void func_0c04da04(struct Actor *a)
{
    if (dat_0c2d6f84->b46 == 0 && (dat_0c2d6f84->b84 & (1 << a->b2)))
        return;
    CPU(a)->b44b = 0;
    CPU(a)->b4a9 = 0;
    func_0c04da30(a);
}

void func_0c04da30(struct Actor *a)
{
    CPU(a)->b43c = 0;
    CPU(a)->b43e = 0;
    CPU(a)->b483 = 0;
    CPU(a)->b45c = 0;
    CPU(a)->b494 = 0;
    CPU(a)->b4a5 = 0;
    CPU(a)->b4a0 = 0xff;
    CPU(a)->b4a8 = -1;
    func_0c04dba2(a, 0, 0);
    func_0c04da6a(a);
}

void func_0c04da6a(struct Actor *a)
{
    CPU(a)->b45e = 0;
    CPU(a)->b4a4 = 0;
    CPU(a)->l4b0 = 0;
    CPU(a)->b495 = 0;
    CPU(a)->b496 = 0;
    CPU(a)->b497 = 0;
    CPU(a)->b201 = 0;
    CPU(a)->b482 = 0;
    CPU(a)->b480 = 0;
    CPU(a)->b4a6 = 0;
    CPU(a)->b45f = 0;
    CPU(a)->b4a7 = 0;
    CPU(a)->b446 = 0;
    CPU(a)->b447 = 0;
    CPU(a)->w442 = 0;
    CPU(a)->b441 = 0;
}

int func_0c04daae(struct Actor *a, int n, int k)
{
    unsigned char *p;
    switch (dat_0c23e70c[n]) {
    case 0: {
        char **tab = (char **)((char *)a + 0x188);
        char *q = tab[k];
        char *base = q;
        if (k == 2)
            q += (n - 2) * 12;
        p = (unsigned char *)base + *(int *)q;
        break;
    }
    case 1:
        if (k != 2)
            return 0;
        p = dat_0c23eee0[n - 3];
        break;
    case 2:
        if (k != 2)
            return 0;
        p = dat_0c23ef68[n - 29];
        break;
    }
    return (unsigned)(func_0c02849a() & 31) < *(unsigned char *)((int)p + dat_0c2f847a);
}

int func_0c04db58(struct Actor *a, int n)
{
    signed char *p0, *p1; int v;
    p0 = dat_0c23f174[n]; p1 = dat_0c23f174[n + 1]; v = *(signed char *)((int)p0 + dat_0c2f847a) + p1[func_0c02849a() & 31];
    if (v < 0)
        v = 0;
    return v;
}

void func_0c04dba2(struct Actor *a, int n, int k)
{
    int *tab = (int *)((char *)a + 0x188);
    int *q = (int *)tab[k];
    int base = (int)q;
    unsigned char *sel;
    int idx;
    int *scripts;
    struct AiScriptCursor8 *c;
    if (k == 2) {
        q += (n - 2) * 3;
        sel = (unsigned char *)q[1];
        sel += base;
    } else {
        int *rows = (int *)(q[1] + base);
        sel = (unsigned char *)rows[CPU(a)->b45c];
        sel += base;
    }
    idx = sel[func_0c02849a() & 31];
    scripts = (int *)(q[2] + base);
    c = (struct AiScriptCursor8 *)((char *)a + 0x460) + k;
    c->script = (unsigned char *)(scripts[idx] + base);
    c->step = 0;
    c->index = idx;
    c->wait = 0;
    func_0c04da6a(a);
}

void func_0c04dc48(struct Actor *a)
{
    int base;
    int *row;
    unsigned char *sel;
    int *scripts;
    int idx;
    struct Actor *o = *(struct Actor **)((char *)a + 0x4b8);
    struct AiEntry28 *entry = (struct AiEntry28 *)AI_PTR(o, 0x174);
    entry += CPU(a)->b4a0;
    goto LB0_176; LB0_176:
    base = (int)AI_PTR(a, 0x194);
    row = (int *)base;
    row += entry->row * 3;
    scripts = (int *)(row[2] + base);
    goto c; c: sel = (unsigned char *)(row[1] + base);
    idx = sel[func_0c02849a() & 31];
    CPU(a)->cursor[2].script = (unsigned char *)(scripts[idx] + base);
    CPU(a)->cursor[2].step = 0;
    CPU(a)->cursor[2].index = idx;
    CPU(a)->cursor[2].wait = 0;
    func_0c04da6a(a);
}

void func_0c04dcc2(struct Actor *a)
{
    struct PlayerSlotScore *p;
    struct Actor *o = a->p20c;
    float d, e;
    int sel;
    int i;
    d = o->f52 - a->f52;
    if (0.0f > d)
        d = -d;
    p = dat_0c2d7088 + (a->b2 ^ 1);
    sel = -1;
    for (i = 0; i < 3; i++, p += 2) {
        if (!p->actor.b0)
            continue;
        e = p->actor.f52 - a->f52;
        if (0.0f > e)
            e = -e;
        if (!(e > d)) {
            d = e;
            sel = p->actor.pad7cc[0];
        }
    }
    if (sel != -1)
        p = dat_0c2d7088 + sel;
    CPU(a)->f488 = d;
    CPU(a)->f48c = p->actor.f56 - a->f56;
    CPU(a)->f484 = CPU(a)->f488 - (float)p->actor.b13e * 1.66666663f;
}

int func_0c04dd88(struct Actor *a, int n, int v)
{
    if (CPU(a)->b43c == n)
        return 1;
    {
        int one = 1;
        if (CPU(a)->l4b0 & (one << n))
            return 1;
        goto o; o: CPU(a)->l4b0 |= one << n;
        if (CPU(a)->b43c > one)
            goto set;
    }
    if (!func_0c04daae(a, n, 2))
        return 1;
set:
    CPU(a)->b43c = n;
    CPU(a)->b43d = 0;
    CPU(a)->b43e = 0;
    func_0c04da6a(a);
    CPU(a)->b494 = v;
    return 0;
}

int func_0c04ddf6(struct Actor *a, int n)
{
    CPU(a)->l4b0 &= ~(1 << n);
    return 1;
}
