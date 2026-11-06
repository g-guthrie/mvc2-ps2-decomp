#include "objects.h"
extern void func_0c045248(struct Actor*,int);
extern char func_0c02a026(struct Actor*);
extern void func_0c02a0c4(struct Actor*,int,int);
extern void func_0c0439c4(struct Actor*);
extern unsigned char func_0c044e52(struct Actor*);
void func_0c0b97cc(struct Actor *a);
void func_0c0b9834(struct Actor *a);

void func_0c0b97cc(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c044e52(a)) {
        a->b6++;
        func_0c02a0c4(a, 20, 1);
    }
}

void func_0c0b9834(struct Actor *a){if(func_0c02a026(a)<0)func_0c0439c4(a);}

int func_0c0b9856(struct Actor *a){return 0;}
void func_0c0b985a(struct Actor *a){}
void func_0c0b985e(struct Actor *a){}
void func_0c0b9862(struct Actor *a){}
void func_0c0b9866(struct Actor *a){}
void func_0c0b986a(struct Actor *a){}
void func_0c0b986e(struct Actor *a){}
void func_0c0b9872(struct Actor *a){}
void func_0c0b9876(struct Actor *a){a->b5=0;a->b7=0;a->b6=0;a->b1e9=4;func_0c045248(a,21);}
