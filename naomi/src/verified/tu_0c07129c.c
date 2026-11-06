#include "objects.h"
extern void func_0c03edcc(struct Actor *, struct Actor *);
extern void func_0c045248(struct Actor *, int);
extern void func_0c1fba00(void *, int, int);

void func_0c07129c(struct Actor *a)
{
    if (a->p1c8->b141) func_0c03edcc(a->p1c8, a);
}
void func_0c0712bc(struct Actor *a)
{
    a->b6 = a->b7 = a->b5 = 0;
    switch (a->b4c9) {
    case 0: a->b1e9 = 2; break;
    case 1: a->b1e9 = 2; break;
    case 2: a->b1e9 = 2; break;
    }
    func_0c045248(a, 29);
}
void func_0c0712e0(struct Actor *a)
{
    a->b6 = a->b7 = a->b5 = 0;
    switch (a->b4c9) {
    case 0: a->b1e9 = 2; break;
    case 1: a->b1e9 = 2; break;
    case 2: a->b1e9 = 2; break;
    }
    func_0c045248(a, 29);
}
void func_0c071304(struct Actor *a)
{
 int zero=0;
 a->b6=a->b7=a->b5=zero;
 switch(a->b4c9){case 0:a->b1e9=zero;a->b1a3=zero;goto setup;case 1:a->b1e9=3;goto strength;case 2:goto variant;variant:a->b1e9=7;strength:a->b1a3=1;break;}
 setup:
 func_0c045248(a,21);
}
void func_0c071348(struct Actor *a)
{
 int zero=0;
 a->b6=a->b7=a->b5=zero;
 switch(a->b4c9){case 0:a->b1e9=zero;a->b1a3=zero;goto setup;case 1:a->b1e9=3;goto strength;case 2:goto variant;variant:a->b1e9=7;strength:a->b1a3=1;break;}
 setup:
 func_0c045248(a,21);
}
void func_0c07139e(struct Actor *a)
{
    func_0c1fba00(&a->sub2a4, 0, 0x80);
}
