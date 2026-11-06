#include "objects.h"
extern void (*table_0c2480d0[])(struct Actor *);
extern unsigned char dat_0c247e10[];
extern unsigned char dat_0c247e20[];
extern unsigned char dat_0c247e40[];
extern unsigned char dat_0c247e66[];
extern struct Tbl_ub3_01*dat_0c2f83f8;
extern char func_0c02a026(struct Actor*);
extern void func_0c02a0c4(struct Actor*,int,int);
extern void func_0c02a39a(struct Actor*,int);
extern void func_0c0439c4(struct Actor*);
extern unsigned char func_0c044e52(struct Actor*);
extern void func_0c045248(struct Actor*,int);
extern unsigned char func_0c046e7e(struct Actor*,unsigned char*,unsigned char*);
extern unsigned char func_0c0474f8(struct Actor*,unsigned char*,unsigned char*);
int func_0c0ce1b4(struct Actor *a);
int func_0c0ce1e8(struct Actor *a);
int func_0c0ce220(struct Actor *a);
int func_0c0ce256(struct Actor *a);
int func_0c0ce2ac(struct Actor *a);
void func_0c0ce2e2(struct Actor*a);
void func_0c0ce31e(struct Actor*a);
void func_0c0ce35a(struct Actor *a);
void func_0c0ce3b0(struct Actor *a);
void func_0c0ce3ee(struct Actor *a);
void func_0c0ce400(struct Actor *a);
void func_0c0ce47a(struct Actor *a);
void func_0c0ce516(struct Actor *a);

int func_0c0ce1b4(struct Actor *a)
{
 if(func_0c0ce1e8(a)||func_0c0ce220(a)||func_0c0ce256(a)||func_0c0ce2ac(a))return 1;
 return 0;
}

int func_0c0ce1e8(struct Actor *a)
{
    if (!func_0c0474f8(a, dat_0c247e40, (unsigned char *)a + 0x3ac))
        return 0;
    else if (*a->p40c < 3)
        return 0;
    a->b258 = 8;
    return 1;
}

int func_0c0ce220(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c247e10, (unsigned char *)a + 0x38c))
        return 0;
    else if (!*a->p40c)
        return 0;
    a->b258 = 13;
    return 1;
}

int func_0c0ce256(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c247e20, (unsigned char *)a + 0x3b4))
        return 0;
    else if (!*a->p40c)
        return 0;
    a->b258 = 11;
    return 1;
}

int func_0c0ce2ac(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c247e66, (unsigned char *)a + 0x3cc))
        return 0;
    else if (!*a->p40c)
        return 0;
    a->b258 = 17;
    return 1;
}

void func_0c0ce2e2(struct Actor*a){
 int zero=0;a->b5=zero;a->b7=zero;a->b6=zero;
 switch(a->b4c9){case 0:a->b1e9=13;break;case 1:a->b1e9=11;break;case 2:a->b1e9=17;break;}
 func_0c045248(a,29);
}

void func_0c0ce31e(struct Actor*a){
 int zero=0;a->b5=zero;a->b7=zero;a->b6=zero;
 switch(a->b4c9){case 0:a->b1e9=13;break;case 1:a->b1e9=11;break;case 2:a->b1e9=17;break;}
 func_0c045248(a,29);
}

void func_0c0ce35a(struct Actor *a)
{
 int zero=0,one=1;a->b5=zero;a->b7=zero;a->b6=zero;
 switch(a->b4c9){case 0:a->b1e9=zero;break;case 1:a->b1e9=one;break;case 2:goto two;two:a->b1e9=2;break;default:goto call;}
 a->b1a3=one;
call:goto tail;
tail:func_0c045248(a,21);
}

void func_0c0ce3b0(struct Actor *a)
{
 int zero=0,one=1;a->b5=zero;a->b7=zero;a->b6=zero;
 switch(a->b4c9){case 0:a->b1e9=zero;break;case 1:a->b1e9=one;break;case 2:goto two;two:a->b1e9=2;break;default:goto call;}
 a->b1a3=one;
call:goto tail;
tail:func_0c045248(a,21);
}

void func_0c0ce3ee(struct Actor *a){table_0c2480d0[a->b6](a);}

void func_0c0ce400(struct Actor *a)
{
    func_0c02a39a(a, 0);
    a->b6++;
    a->b1f9 = 2;
    a->f92 = 30.0f;
    if (a->b1d2 == 0)
        a->f92 = -a->f92;
    a->f104 = 0.0f;
    a->f96 = 4.28571415f;
    a->f108 = -0.80357140303f;
    a->b1a1 = 82;
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 20, 8);
}

void func_0c0ce47a(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c044e52(a)) {
        a->b6++;
        func_0c02a0c4(a, 20, 9);
    }
}

void func_0c0ce516(struct Actor *a)
{
    if (func_0c02a026(a) < 0) {
        func_0c02a39a(a, 0);
        func_0c0439c4(a);
    } else if (a->b141)
        a->b141 = 0;
}
