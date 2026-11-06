#include "objects.h"

typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c248960[];
extern ActorHandler table_0c248968[];
extern ActorHandler table_0c24897c[];
extern ActorHandler table_0c248984[];
extern ActorHandler table_0c2489b4[];
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0437b8(struct Actor *);
extern void func_0c043352(struct Actor *);
extern int func_0c03916c(struct Actor *);
extern int func_0c02849a(void);

void func_0c0d7f10(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c02a026(a);
    if (a->f56 <= a->f41c) {
        a->b6++;
        a->f56 = a->f41c;
        a->b1f9 = 0;
        a->f96 = 0.0f;
        a->f108 = 0.0f;
        func_0c02a0c4(a, 2, 3);
    }
}

void func_0c0d7f92(struct Actor *a)
{
    if (func_0c02a026(a) < 0) {
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
        func_0c0437b8(a);
        return;
    }
    if (a->b141) {
        func_0c043352(a);
        a->f52 += a->f92;
        a->f92 += a->f104;
        a->f56 += a->f96;
        a->f96 += a->f108;
    }
}

void func_0c0d800a(struct Actor *a) { table_0c248960[a->b6](a); }
void func_0c0d801c(struct Actor *a)
{
    a->b6++;
    a->b12c = 1;
    func_0c02a0c4(a, 18, 0);
}
void func_0c0d8030(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        a->b5++;
}
void func_0c0d8050(struct Actor *a)
{
    if (func_0c03916c(a))
        func_0c0437b8(a);
    else
        table_0c248968[a->b32](a);
}
void func_0c0d809c(struct Actor *a) { table_0c24897c[a->b6](a); }
void func_0c0d80ae(struct Actor *a)
{
    a->b6++;
    a->s28 = func_0c02849a() & 3;
    switch (a->s28) {
    case 0: func_0c02a0c4(a, 19, 0); break;
    case 1: func_0c02a0c4(a, 19, 1); break;
    case 2: func_0c02a0c4(a, 19, 2); break;
    case 3: func_0c02a0c4(a, 19, 3); break;
    }
}
void func_0c0d80f8(struct Actor *a) { func_0c02a026(a); }
void func_0c0d80fe(struct Actor *a)
{
    if (a->b6 == 0) { a->b6++; func_0c02a0c4(a, 19, 3); }
    else func_0c02a026(a);
}
void func_0c0d8118(struct Actor *a)
{
    if (a->b6 == 0) { a->b6++; func_0c02a0c4(a, 19, 4); }
    else func_0c02a026(a);
}
void func_0c0d8132(struct Actor *a)
{
    if (a->b6 == 0) { a->b6++; func_0c02a0c4(a, 19, 5); }
    else func_0c02a026(a);
}
void func_0c0d814c(struct Actor *a) { table_0c248984[a->b1e9](a); }
void func_0c0d8160(struct Actor *a) { table_0c2489b4[a->b6](a); }
