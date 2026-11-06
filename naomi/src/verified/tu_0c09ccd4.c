#include "objects.h"
struct V3_0c09ccd4 { float x, y, z; };
struct Pos_0c09ccd4 { unsigned char pad[52]; struct V3_0c09ccd4 pos; };
extern void func_0c025900(struct Actor *, int, int);
extern void func_0c048ce6(struct Actor *);
extern void func_0c1d4610(struct Actor *, struct V3_0c09ccd4 *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c03f004(struct Actor *, struct Actor *);

void func_0c09ccd4(struct Actor *a)
{
    struct V3_0c09ccd4 v;
    func_0c025900(a, 6, 6);
    func_0c048ce6(a);
    a->b1a0 = 10;
    v.x = -90.0f;
    v.y = 154.28571f;
    v.z = 0.0f;
    func_0c1d4610(a, &v);
    {struct Actor *t;struct ActorFlags64 *f;f=(struct ActorFlags64 *)&(t=a->p1c8)->l414;&t;if((f->hi&0)|(f->lo&0x04000000))a->p1c8->f56=a->f41c+128.57143f;else
    {struct Actor *t;struct ActorFlags64 *f;f=(struct ActorFlags64 *)&(t=a->p1c8)->l414;&t;if((int)(f->hi&0x20000000))a->p1c8->f56=a->f41c+42.85714f;}}
    func_0c02a0c4(a, 15, 0);
    v = ((struct Pos_0c09ccd4 *)a)->pos;
    func_0c03f004(a, a->p1c8);
    ((struct Pos_0c09ccd4 *)a)->pos = v;
}

void func_0c09cd9c(struct Actor *a)
{
    struct V3_0c09ccd4 v;
    func_0c025900(a, 6, 6);
    func_0c048ce6(a);
    a->b1a0 = 10;
    v.x = -90.0f;
    v.y = 154.28571f;
    v.z = 0.0f;
    func_0c1d4610(a, &v);
    func_0c02a0c4(a, 15, 0);
    v = ((struct Pos_0c09ccd4 *)a)->pos;
    func_0c03f004(a, a->p1c8);
    ((struct Pos_0c09ccd4 *)a)->pos = v;
}
