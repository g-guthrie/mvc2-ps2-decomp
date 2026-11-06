/* Move-counter state handlers 0x0c0a346c-0x0c0a3a14. func_0c0a375e tail-branches to a
 * selector func_0c0a3786 (retail bra 0x0c0a3786) and reads through a volatile pointer. */
#include "objects.h"
struct MoveCounters_0c0a346c { unsigned char pad[124]; short counts[2]; };
extern struct MoveCounters_0c0a346c *dat_0c2f83f8;
extern void func_0c0346da(struct Actor *,int);
extern void func_0c02a0c4(struct Actor *,int,int);
extern unsigned char dat_0c243b18[];
extern unsigned char dat_0c243b1c[];
extern unsigned char dat_0c243b20[];
extern unsigned char dat_0c243b24[];
extern unsigned char dat_0c243b28[];
extern unsigned char dat_0c243b2c[];
extern unsigned char dat_0c243b30[];
extern unsigned char dat_0c243b34[];
extern unsigned char dat_0c243b38[];
extern unsigned char dat_0c243b3c[];
extern unsigned char dat_0c243b40[];
extern unsigned char dat_0c243b44[];
extern unsigned char dat_0c243b48[];
extern unsigned char dat_0c243b4c[];
extern unsigned char dat_0c243b50[];
extern unsigned char dat_0c243b54[];
extern unsigned char dat_0c243b58[];
extern unsigned char dat_0c243b5c[];
extern void (*dat_0c2440a8[])(struct Actor *);
void func_0c0a3798(struct Actor *);
void func_0c0a38ae(struct Actor *);
void func_0c0a346c(register struct Actor *a)
{
    switch (a->b1e8) {
    case 0:
        a->b158=0;
        a->b1a1=0;
        func_0c0346da(a,20);
        a->p3f4=dat_0c243b18;
        a->b1a7=0;
        break;
    case 1:
        a->b158=1;
        a->b1a1=1;
        func_0c0346da(a,21);
        a->p3f4=dat_0c243b1c;
        a->b1a7=1;
        break;
    case 2:
        a->b158=2;
        a->b1a1=2;
        func_0c0346da(a,26);
        a->p3f4=dat_0c243b20;
        a->b1a7=2;
        break;
    }
    a->w1ac=0;
    a->b19e=0;
    a->p1c4=0;
    dat_0c2f83f8->counts[a->b2]++;
    func_0c02a0c4(a,7,a->b158);
}
void func_0c0a3514(register struct Actor *a)
{
    switch (a->b1e8) {
    case 0:
        a->b158=0;
        a->b1a1=6;
        func_0c0346da(a,20);
        a->p3f4=dat_0c243b18;
        a->b1a7=0;
        break;
    case 1:
        a->b158=1;
        a->b1a1=7;
        func_0c0346da(a,21);
        a->p3f4=dat_0c243b1c;
        a->b1a7=1;
        break;
    case 2:
        a->b158=2;
        a->b1a1=8;
        func_0c0346da(a,26);
        a->p3f4=dat_0c243b20;
        a->b1a7=2;
        break;
    }
    a->w1ac=0;
    a->b19e=0;
    a->p1c4=0;
    dat_0c2f83f8->counts[a->b2]++;
    func_0c02a0c4(a,9,a->b158);
}
void func_0c0a35e4(register struct Actor *a)
{
    switch (a->b1e8) {
    case 0:
        a->b158=0;
        a->b1a1=3;
        func_0c0346da(a,20);
        a->p3f4=dat_0c243b24;
        a->b1a7=0;
        break;
    case 1:
        a->b158=1;
        a->b1a1=4;
        func_0c0346da(a,21);
        a->p3f4=dat_0c243b28;
        a->b1a7=1;
        break;
    case 2:
        a->b158=2;
        a->b1a1=5;
        func_0c0346da(a,22);
        a->p3f4=dat_0c243b2c;
        a->b1a7=2;
        break;
    }
    a->w1ac=0;
    a->b19e=0;
    a->p1c4=0;
    dat_0c2f83f8->counts[a->b2]++;
    func_0c02a0c4(a,8,a->b158);
}
void func_0c0a3690(register struct Actor *a)
{
    switch (a->b1e8) {
    case 0:
        a->b158=0;
        a->b1a1=9;
        func_0c0346da(a,20);
        a->p3f4=dat_0c243b24;
        a->b1a7=0;
        break;
    case 1:
        a->b158=1;
        a->b1a1=10;
        func_0c0346da(a,21);
        a->p3f4=dat_0c243b28;
        a->b1a7=1;
        break;
    case 2:
        a->b158=2;
        a->b1a1=11;
        a->p3f4=dat_0c243b2c;
        a->b1a7=2;
        break;
    }
    a->w1ac=0;
    a->b19e=0;
    a->p1c4=0;
    dat_0c2f83f8->counts[a->b2]++;
    func_0c02a0c4(a,10,a->b158);
}
void func_0c0a3786(struct Actor *a);
void func_0c0a375e(volatile struct Actor *a)
{
    if (!a->b1fe && (a->b1d6 & 15) || a->b1fe && (a->b1d6 & 0xf0))
        func_0c0a3786((struct Actor *)a);
}
void func_0c0a3786(struct Actor *a)
{
    if ((unsigned char)a->b1fe == 1) func_0c0a38ae(a);
    else func_0c0a3798(a);
}
void func_0c0a3798(register struct Actor *a)
{
    switch (a->b1e8) {
    case 0:
        a->b158=0;
        a->b1a1=12;
        func_0c0346da(a,20);
        if (!a->b1fc) a->p3f4=dat_0c243b30;
        else a->p3f4=dat_0c243b48;
        a->b1a7=0;
        break;
    case 1:
        a->b158=1;
        a->b1a1=13;
        func_0c0346da(a,21);
        if (!a->b1fc) a->p3f4=dat_0c243b34;
        else a->p3f4=dat_0c243b4c;
        a->b1a7=1;
        break;
    case 2:
        a->b158=2;
        a->b1a1=14;
        func_0c0346da(a,26);
        if (!a->b1fc) a->p3f4=dat_0c243b38;
        else a->p3f4=dat_0c243b50;
        a->b1a7=2;
        break;
    }
    a->w1ac=0;
    a->b19e=0;
    a->p1c4=0;
    dat_0c2f83f8->counts[a->b2]++;
    func_0c02a0c4(a,11,a->b158);
    if (a->b1d6 & 15) a->b1d6=a->b1d6-1;
}
void func_0c0a38ae(register struct Actor *a)
{
    switch (a->b1e8) {
    case 0:
        a->b158=0;
        a->b1a1=15;
        func_0c0346da(a,20);
        if (!a->b1fc) a->p3f4=dat_0c243b3c;
        else a->p3f4=dat_0c243b54;
        a->b1a7=0;
        break;
    case 1:
        a->b158=1;
        a->b1a1=16;
        func_0c0346da(a,21);
        if (!a->b1fc) a->p3f4=dat_0c243b40;
        else a->p3f4=dat_0c243b58;
        a->b1a7=1;
        break;
    case 2:
        a->b158=2;
        a->b1a1=17;
        func_0c0346da(a,22);
        if (!a->b1fc) a->p3f4=dat_0c243b44;
        else a->p3f4=dat_0c243b5c;
        a->b1a7=2;
        break;
    }
    a->w1ac=0;
    a->b19e=0;
    a->p1c4=0;
    dat_0c2f83f8->counts[a->b2]++;
    func_0c02a0c4(a,12,a->b158);
    if (a->b1d6 & 240) a->b1d6=a->b1d6-16;
}
void func_0c0a39ce(struct Actor *a)
{
    dat_0c2440a8[a->b1ff](a);
}
