/* CPU attack-state movement updaters, b1e8 dispatchers and hit handlers sharing literal pools. */
#include "objects.h"
struct MoveCounters_0c0a3a14 { unsigned char pad[124]; short counts[2]; };
extern struct MoveCounters_0c0a3a14 *dat_0c2f83f8;
extern char func_0c02a026(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c043352(struct Actor *);
extern void func_0c044df4(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c0421f4(struct Actor *);
extern void func_0c0420f8(struct Actor *);
extern void func_0c042018(struct Actor *);
extern void func_0c0421b8(struct Actor *);
extern void func_0c044f1c(struct Actor *);
extern void func_0c0438de(struct Actor *);
extern void func_0c044cbc(struct Actor *);
extern void func_0c048bb0(struct Actor *,int);
extern void func_0c0346da(struct Actor *,int);
extern void func_0c02a0c4(struct Actor *,int,int);
extern void (*dat_0c2440b8[])(struct Actor *);
void func_0c0a3a14(struct Actor *);
void func_0c0a3a9a(struct Actor *);
void func_0c0a3b28(struct Actor *);
void func_0c0a3b60(struct Actor *);
void func_0c0a3b98(struct Actor *);
void func_0c0a3bd8(struct Actor *);
void func_0c0a3c1c(struct Actor *);
void func_0c0a3c54(struct Actor *);
void func_0c0a3c6a(struct Actor *);
void func_0c0a3cac(struct Actor *);
void func_0c0a3cce(struct Actor *);
void func_0c0a3d18(struct Actor *);
void func_0c0a3d66(struct Actor *);
void func_0c0a3e36(struct Actor *);
void func_0c0a3a14(struct Actor *a)
{
    func_0c043352(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c044df4(a);
    if ((unsigned char)a->b1fe == 1) {
        if (a->b1f9 == 1) func_0c0a3bd8(a);
        else func_0c0a3b98(a);
    } else {
        if (a->b1f9 == 1) func_0c0a3b60(a);
        else func_0c0a3c1c(a);
    }
}
void func_0c0a3a9a(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c044df4(a);
    if ((unsigned char)a->b1fe == 1) {
        if (a->b1f9 == 1) func_0c0a3bd8(a);
        else func_0c0a3b98(a);
    } else {
        if (a->b1f9 == 1) func_0c0a3b60(a);
        else func_0c0a3b28(a);
    }
}
void func_0c0a3b28(struct Actor *a)
{
    switch(a->b1e8) {
    case 2: case 0: case 1:
        if(func_0c02a026(a)<0) func_0c0437b8(a);
        break;
    }
}
void func_0c0a3b60(struct Actor *a)
{
    switch(a->b1e8) {
    case 0: case 1: case 2:
        if(func_0c02a026(a)<0) func_0c0437b8(a);
        break;
    }
}
void func_0c0a3b98(struct Actor *a)
{
    switch (a->b1e8) {
    case 1: func_0c0a3d18(a); return;
    case 0:
    case 2:
        if (func_0c02a026(a)<0) func_0c0437b8(a);
        break;
    }
}
void func_0c0a3bd8(struct Actor *a)
{
    switch(a->b1e8) {
    case 0: case 1: case 2:
        if(func_0c02a026(a)<0) func_0c0437b8(a);
        break;
    }
}
void func_0c0a3c1c(struct Actor *a)
{
    switch(a->b1e8) {
    case 2: case 0: case 1:
        if(func_0c02a026(a)<0) func_0c0437b8(a);
        break;
    }
}
void func_0c0a3c54(struct Actor *a)
{
    func_0c0421f4(a);
    func_0c0420f8(a);
    func_0c0a3c6a(a);
}
void func_0c0a3c6a(struct Actor *a)
{
    func_0c042018(a);
    func_0c0421b8(a);
    if ((unsigned char)a->b1fe == 1) func_0c0a3cce(a);
    else func_0c0a3cac(a);
    if (func_0c044e52(a)) func_0c044f1c(a);
}
void func_0c0a3cac(struct Actor *a)
{
    if (func_0c02a026(a)<0) func_0c0438de(a);
}
void func_0c0a3cce(struct Actor *a)
{
    if (func_0c02a026(a)<0) func_0c0438de(a);
}
void func_0c0a3d18(struct Actor *a)
{
    if (func_0c02a026(a)<0) func_0c0437b8(a);
    if (a->b141 == 1) {
        a->b141=0;
        a->b1a1=25;
        a->w1ac=0;
        a->b19e=0;
        a->p1c4=0;
        dat_0c2f83f8->counts[a->b2]++;
    }
}
void func_0c0a3d66(struct Actor *a)
{
    if (!a->b6) {
        func_0c044cbc(a);
        a->b6=a->b6+1;
        if ((unsigned char)a->b1fe == 1) {
            func_0c048bb0(a,5);
            a->b1a1=21;
            a->w1ac=0;
            a->b19e=0;
            a->p1c4=0;
            dat_0c2f83f8->counts[a->b2]++;
            a->b1f9=0;
            func_0c0346da(a,22);
            func_0c02a0c4(a,20,3);
        }
    }
    if (a->b1ff == 3) func_0c043352(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c044df4(a);
    if (func_0c02a026(a)<0) func_0c0437b8(a);
}
void func_0c0a3e36(struct Actor *a)
{
    dat_0c2440b8[a->b6](a);
}
