#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern int func_0c02850e(struct Actor *);
extern void func_0c037d0c(struct Actor *);
extern void func_0c037688(void);
void func_0c16e194(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c02a026(a);
    if (a->b19e || a->b19f) {
        a->b4++;
        a->b12c = 0;
        return;
    }
    if (a->s28)
        a->s28--;
    else if (!func_0c02850e(a)) {
        a->b4++;
        a->b12c = 0;
    }
    func_0c037d0c(a);
}
void func_0c16e22e(void){func_0c037688();}
