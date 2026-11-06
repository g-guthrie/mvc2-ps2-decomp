#include "objects.h"
extern char func_0c02a026(struct Actor*);
extern void func_0c02a0c4(struct Actor*,int,int);
extern void func_0c03edcc(struct Actor*,struct Actor*);
extern void func_0c0439c4(struct Actor*);
extern unsigned char func_0c044e52(struct Actor*);
extern void func_0c045248(struct Actor*,int);
void func_0c0b7fe8(struct Actor *a);
void func_0c0b8050(struct Actor *a,struct ActorSub2a4 *state);
int func_0c0b8072(void);
void func_0c0b8076(struct Actor *a);
void func_0c0b807a(struct Actor *a);
void func_0c0b807e(struct Actor *a);
void func_0c0b808c(struct Actor *a);
void func_0c0b80b2(struct Actor *a);
void func_0c0b80d8(struct Actor *a);
void func_0c0b812c(struct Actor *a);
void func_0c0b8162(struct Actor *a);

void func_0c0b7fe8(struct Actor *a)
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

void func_0c0b8050(struct Actor *a,struct ActorSub2a4 *state){if(func_0c02a026(a)<0)func_0c0439c4(a);}

int func_0c0b8072(void) { return 0; }

void func_0c0b8076(struct Actor *a) {}

void func_0c0b807a(struct Actor *a) {}

void func_0c0b807e(struct Actor *a)
{
    func_0c03edcc(a->p1c8, a);
}

void func_0c0b808c(struct Actor *a)
{
 int zero=0;a->b6=a->b7=a->b5=zero;
 switch(a->b4c9){case 0:a->b1e9=zero;break;case 1:a->b1e9=zero;break;case 2:a->b1e9=zero;break;}
 func_0c045248(a,29);
}

void func_0c0b80b2(struct Actor *a)
{
 int zero=0;a->b6=a->b7=a->b5=zero;
 switch(a->b4c9){case 0:a->b1e9=zero;break;case 1:a->b1e9=zero;break;case 2:a->b1e9=zero;break;}
 func_0c045248(a,29);
}

void func_0c0b80d8(struct Actor *a)
{
 int zero=0;a->b5=zero;a->b7=zero;a->b6=zero;
 switch(a->b4c9){case 0:case 1:((volatile unsigned char *)a)[0x1e9]=zero;break;case 2:a->b1e9=zero;break;default:goto call;}
 a->b1a3=1;
call:func_0c045248(a,21);
}

void func_0c0b812c(struct Actor *a)
{
 int zero=0;a->b5=zero;a->b7=zero;a->b6=zero;
 switch(a->b4c9){case 0:case 1:((volatile unsigned char *)a)[0x1e9]=zero;break;case 2:a->b1e9=zero;break;default:goto call;}
 a->b1a3=1;
call:func_0c045248(a,21);
}

void func_0c0b8162(struct Actor *a)
{
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    a->b1e9 = 4;
    func_0c045248(a, 21);
}
