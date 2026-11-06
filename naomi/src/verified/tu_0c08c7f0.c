#include "objects.h"
extern char func_0c02a026(struct Actor*);
extern void func_0c02a0c4(struct Actor*,int,int);
extern void func_0c043324(struct Actor*);
extern void func_0c0439c4(struct Actor*);
extern unsigned char func_0c044e52(struct Actor*);
extern void (*table_0c2427b8[])(struct Actor*);
void func_0c08c7f0(struct Actor *a);
void func_0c08c85e(struct Actor *a);
void func_0c08c880(struct Actor *a);

void func_0c08c7f0(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c044e52(a) != 0) {
        a->b6 = a->b6 + 1;
        func_0c02a0c4(a, 20, 1);
        func_0c043324(a);
    }
}

void func_0c08c85e(struct Actor *a){if(func_0c02a026(a)<0)func_0c0439c4(a);}

void func_0c08c880(struct Actor *a){table_0c2427b8[a->b6](a);}
