#include "objects.h"
extern struct PlayerSlotScore dat_0c2d7088[];
struct GameSides { unsigned char pad[0x9c]; unsigned char b9c, b9d; };
extern struct GameSides dat_0c2f8338;
extern void *func_0c1fba00(void *, int, unsigned int);
void func_0c040b96(void);
void func_0c040c0e(void);
void func_0c040b8c(void)
{
    func_0c040b96();
    func_0c040c0e();
}
void func_0c040b96(void)
{
    unsigned char i;
    struct Actor *p;
    for (i = 0; i < 3; i++) {
        p = &dat_0c2d7088[i * 2].actor;
        func_0c1fba00(p, 0, 0x4bc);
        p->b2 = 0;
        p->pad7cc[0] = i * 2;
        p->b411 = i;
        p->b412 = i;
    }
    p = &dat_0c2d7088[0].actor;
    dat_0c2f8338.b9c = p->b52f;
    if (p->b525) dat_0c2f8338.b9c = 0;
}
void func_0c040c0e(void)
{
    unsigned char i;
    struct Actor *p;
    for (i = 0; i < 3; i++) {
        p = &(dat_0c2d7088 + i * 2 + 1)->actor;
        func_0c1fba00(p, 0, 0x4bc);
        p->b2 = 1;
        p->pad7cc[0] = i * 2 + 1;
        p->b411 = i;
        p->b412 = i;
    }
    p = &dat_0c2d7088[1].actor;
    dat_0c2f8338.b9d = p->b52f;
    if (p->b525) dat_0c2f8338.b9d = 0;
}
