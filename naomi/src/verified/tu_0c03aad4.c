#include "objects.h"
typedef void (*ActorMethod)(struct Actor *);
extern unsigned char dat_0c2f8338;
extern unsigned char func_0c046030(struct Actor *);
extern unsigned char func_0c0464c4(struct Actor *);
extern int func_0c043c66(struct Actor *);
extern unsigned char func_0c043a10(struct Actor *);
extern unsigned char func_0c0449a8(struct Actor *);
extern unsigned char func_0c043d3a(struct Actor *);
extern unsigned char func_0c044c0c(struct Actor *);
extern void func_0c0453c4(struct Actor *, int);
extern char func_0c02a026(struct Actor *);
extern unsigned char func_0c044846(struct Actor *);
extern void func_0c045248(struct Actor *, int);
extern void func_0c03498c(struct Actor *);
extern void func_0c1d1e64(float *, int);
extern void func_0c0442fa(struct Actor *);
extern unsigned char func_0c043ec6(struct Actor *);
extern void func_0c043d5c(struct Actor *);
extern void func_0c0420f8(struct Actor *);
extern void func_0c042018(struct Actor *);
extern void func_0c04217a(struct Actor *);
extern void func_0c0421b8(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c044f1c(struct Actor *);
void func_0c03aad4(struct Actor *a)
{
    int t = a->b1;
    if (t == 45) goto dispatch;
    if (t == 53) { goto c; c: if (!a->b140) goto dispatch; }
    if (func_0c046030(a)) return;
    if (func_0c0464c4(a)) return;
    if (func_0c043c66(a)) return;
    if (func_0c043a10(a)) return;
    if (func_0c0449a8(a)) return;
    if (!a->b201) {
        if (func_0c043d3a(a)) return;
        if (func_0c044c0c(a)) return;
    } else if (a->w34e & 0x800) func_0c0453c4(a, 0);
dispatch:
    ((ActorMethod *)a->p428)[5](a);
}
void func_0c03ab7a(struct Actor *a)
{
    a->b1e0 = -76;
    a->b1df = 0xff;
if (dat_0c2f8338 < 5) {
 if ((short)a->w420 <= 0) goto ok;
 if (--a->s1e4 >= 0 && a->b1e3) { ok: func_0c02a026(a); return; }
 }
 a->b1e3 = 0;
 a->b1ef = 8;
 func_0c0453c4(a, 0);
}
void func_0c03ac06(struct Actor *a)
{
    if (func_0c044846(a)) return;
    func_0c02a026(a);
    if (a->b141 & 15) return;
    a->b1f9 = 2;
    func_0c045248(a, 14);
    a->pad1d7[2] = 0;
    func_0c03498c(a);
    func_0c1d1e64(&a->f52, 0);
}
void func_0c03ac52(struct Actor *a)
{
    struct { unsigned int x, y; } *m;
    func_0c0442fa(a);
    if (func_0c043a10(a)) return;
    m = (void *)&a->l414; if (m->x & 0x184010a0 | m->y & 0x02000801) {
        if (func_0c043ec6(a)) return;
    }
    m = (void *)&a->l414; if (m->x & 0xa8400960 | m->y & 16) func_0c043d5c(a);
    if (a->b1 == 42) ((ActorMethod *)a->p428)[24](a);
    func_0c02a026(a);
    func_0c0420f8(a);
    func_0c042018(a);
    if (func_0c044846(a)) return;
    func_0c04217a(a);
    func_0c0421b8(a);
    if (func_0c044e52(a)) func_0c044f1c(a);
}
