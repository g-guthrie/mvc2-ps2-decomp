/* State dispatchers, the landing-timer clear and three reset handlers for one move family. */
#include "objects.h"
extern void (*table_0c2483b4[])(struct Actor *);
extern void func_0c044fbe(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c02a39a(struct Actor *, int);
extern char func_0c02a026(struct Actor *);
extern void func_0c043324(struct Actor *);
extern void func_0c025900(struct Actor *, char, char);
extern void func_0c0437b8(struct Actor *);
extern unsigned char func_0c046e7e(struct Actor *, unsigned char *, unsigned char *);
extern unsigned char dat_0c23f24c[], dat_0c23f25c[], dat_0c23f26c[];
extern void (*table_0c23f44c[])(struct Actor *);
extern void func_0c03f004(struct Actor *, struct Actor *);
extern void func_0c045248(struct Actor *, int);
int func_0c054cee(struct Actor *);
int func_0c054d58(struct Actor *);
int func_0c054d8e(struct Actor *);
typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c2483c0[];
extern struct Actor *func_0c037d54(struct Actor *);
extern void func_0c1d4610(struct Actor *,struct LinkedActorVec3 *);
extern void func_0c048ce6(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int);
extern void func_0c03edcc(struct Actor *, struct Actor *);
extern void (*table_0c240bb8[])(struct Actor *);
extern void *func_0c1fba00(void *,int,unsigned int);
extern void func_0c045248(struct Actor*,int);
void func_0c09d758(struct Actor *a);
void func_0c09d788(struct Actor *a);
void func_0c09d7b8(struct Actor *a);
void func_0c09d7fa(struct Actor *a);
void func_0c09d840(struct Actor *a);

void func_0c0d25c4(struct Actor *a) {
  a->b1ea = 1;
  table_0c2483b4[a->b6](a);
}

void func_0c0d25de(struct Actor *a)
{
    func_0c03f004(a->p1c8, a);
}

void func_0c0d25ec(struct Actor *a)
{
    if (a->s28) {
        func_0c02a026(a);
        if (a->b143 & 0x80)
            a->s28 = 0;
    }
}

void func_0c0d2610(void) {}

void func_0c0d2614(struct Actor *a)
{
    table_0c2483c0[a->b1f7&63](a);
}

void func_0c0d262c(struct Actor *a)
{
    a->b6 = a->b7 = a->b5 = 0;
    switch (a->b4c9) {
    case 0: a->b1e9 = 1; break;
    case 1: a->b1e9 = 1; break;
    case 2: a->b1e9 = 1; break;
    }
    func_0c045248(a, 29);
}

void func_0c0d2650(struct Actor *a)
{
    a->b6 = a->b7 = a->b5 = 0;
    switch (a->b4c9) {
    case 0: a->b1e9 = 1; break;
    case 1: a->b1e9 = 1; break;
    case 2: a->b1e9 = 1; break;
    }
    func_0c045248(a, 29);
}

void func_0c0d2674(struct Actor *a)
{
 int zero=0;a->b5=zero;a->b7=zero;a->b6=zero;
 switch(a->b4c9){case 0:a->b1e9=6;goto common;case 1:a->b1e9=5;goto common;case 2:goto two;two:((volatile unsigned char *)a)[0x1e9]=4;common:a->b1a3=1;break;}
 func_0c045248(a,21);
}
