#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c043324(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int);
extern void func_0c0437b8(struct Actor *);
extern void func_0c0442fa(struct Actor *);
extern void (*table_0c244280[])(struct Actor *);
extern void (*table_0c244288[])(struct Actor *);
void func_0c0a6864(struct Actor *a)
{
    a->b3f9=0;
    a->b3f8=0;
    a->b327=0;
    a->b328=0;
    if (a->f56<a->f41c) {
        a->b6=a->b6+1;
        a->f92=0;
        a->f104=0;
        a->f96=0;
        a->f108=0;
        a->f56=a->f41c;
        func_0c043324(a);
        func_0c02a0c4(a,22,8);
        return;
    }
    a->f52+=a->f92;
    a->f92+=a->f104;
    a->f56+=a->f96;
    a->f96+=a->f108;
    func_0c02a026(a);
}
void func_0c0a68fe(struct Actor *a)
{
    a->i72=0;
    if (func_0c02a026(a)<0) func_0c0437b8(a);
}
void func_0c0a6926(struct Actor *a)
{
    table_0c244280[a->b6](a);
}
void func_0c0a6938(struct Actor *a)
{
    a->b6=a->b6+1;
    a->f92=0;
    a->f96=0;
    a->f104=0;
    a->f108=0;
    a->b1f9=0;
    a->f56=a->f41c;
    func_0c0442fa(a);
    func_0c02a0c4(a,21,31);
}
void func_0c0a6978(struct Actor *a)
{
    if (func_0c02a026(a)<0) func_0c0437b8(a);
}
void func_0c0a699a(struct Actor *a)
{
    table_0c244288[a->b6](a);
}
