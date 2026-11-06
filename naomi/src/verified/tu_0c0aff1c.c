#include "objects.h"
extern unsigned char dat_0c244980[];
extern unsigned char dat_0c244990[];
extern unsigned char dat_0c2449a0[];
extern unsigned char dat_0c2449b0[];
extern unsigned char dat_0c2449c4[];
extern unsigned char dat_0c2449d4[];
extern unsigned int dat_0c2449e4[];
extern void func_0c045248(struct Actor*,int);
extern void func_0c045f1c(struct Actor*);
extern void func_0c0463fc(struct Actor*);
extern unsigned char func_0c0465cc(struct Actor*);
extern unsigned char func_0c0469f4(struct Actor*);
extern unsigned char func_0c046b6c(struct Actor*);
extern unsigned char func_0c046d3c(struct Actor*);
extern int func_0c046d54(struct Actor*);
extern unsigned char func_0c046dd0(struct Actor*,int);
extern unsigned char func_0c046e7e(struct Actor*,unsigned char*,unsigned char*);
extern void func_0c047aac(struct Actor*,unsigned char*);
void func_0c0aff1c(struct Actor *a);
void func_0c0aff38(struct Actor *a);
unsigned char func_0c0affec(struct Actor *a);
unsigned char func_0c0b006c(struct Actor *a);
unsigned char func_0c0b00b2(struct Actor *a);
unsigned char func_0c0b0120(struct Actor *a);
unsigned char func_0c0b01a0(struct Actor *a);
unsigned char func_0c0b0214(struct Actor *a);
int func_0c0b029c(struct Actor *a);
int func_0c0b02dc(struct Actor *a);

void func_0c0aff1c(struct Actor *a)
{
    register unsigned int i;
    register unsigned int limit = 112;
    register unsigned int *out = *((unsigned int **)((char *)a + 0x428));
    register unsigned int *in = dat_0c2449e4;
    i = 0;
copy_next:
    *(unsigned int *)((char *)out + i) = *(unsigned int *)((char *)in + i);
    i += 4;
    if (i < limit) goto copy_next;
}

void func_0c0aff38(struct Actor *a){if(func_0c0465cc(a))return;if(func_0c046b6c(a))return;if(func_0c0469f4(a))return;if(func_0c046d3c(a))return;if(func_0c0b01a0(a))return;if(func_0c0b0214(a))return;if(func_0c0b0120(a))return;if(func_0c0b00b2(a))return;if(func_0c0b006c(a))return;if(func_0c0affec(a))return;if(func_0c0b029c(a))return;if(func_0c0b02dc(a))return;func_0c045f1c(a);func_0c0463fc(a);}

unsigned char func_0c0affec(struct Actor *a)
{
    struct ActorSub2a4 *sub = &a->sub2a4;
    if (!func_0c046e7e(a, dat_0c244980, a->x36c) || *(char *)&sub->w4) return 0;
    if (a->b1f9 == 2) {
        if (a->b1d4 && !a->b1fc) return 0;
        a->b1d4++;
    }
    func_0c047aac(a, a->x36c);
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    a->b1e9 = 0;
    func_0c045248(a, 21);
    return 1;
}

unsigned char func_0c0b006c(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c244990, a->x374)) return 0;
    func_0c047aac(a, a->x374);
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    a->b1e9 = 1;
    func_0c045248(a, 21);
    return 1;
}

unsigned char func_0c0b00b2(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c2449a0, a->x37c)) return 0;
    func_0c047aac(a, a->x37c);
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    a->b1e9 = 2;
    func_0c045248(a, 21);
    return 1;
}

unsigned char func_0c0b0120(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c2449b0, a->x384)) return 0;
    if (a->b1f9 == 2) {
        if (a->b1d4 && !a->b1fc) return 0;
        a->b1d4++;
    }
    func_0c047aac(a, a->x384);
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    a->b1e9 = 3;
    func_0c045248(a, 21);
    if (a->b1f9 == 2) a->b6 = 1;
    else a->b6 = 0;
    return 1;
}

unsigned char func_0c0b01a0(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c2449c4, a->x38c)) goto fail;
    if (!*a->p40c) {
fail:
        return 0;
    }
    func_0c047aac(a, a->x38c);
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    a->b1e9 = 4;
    func_0c045248(a, 29);
    return 1;
}

unsigned char func_0c0b0214(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c2449d4, a->x394) || !*a->p40c) return 0;
    if (a->b1f9 == 2 && !a->b1fc) {
        if (a->b1d4) return 0;
        a->b1d4++;
    }
    func_0c047aac(a, a->x394);
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    a->b1e9 = 5;
    func_0c045248(a, 29);
    if (a->b1f9 == 2) a->b6 = 1;
    else a->b6 = 0;
    return 1;
}

int func_0c0b029c(struct Actor *a)
{
    if (!func_0c046d54(a)) goto fail;
    if (!*a->p40c) {
fail:
        return 0;
    }
    a->b1e9 = 6;
    a->b5 = 0;
    func_0c045248(a, 29);
    a->b6 = a->b7 = 0;
    return 1;
}

int func_0c0b02dc(struct Actor *a)
{
    if (!func_0c046dd0(a, 7)) return 0;
    a->b1e9 = 7;
    a->b5 = 0;
    func_0c045248(a, 21);
    a->b6 = a->b7 = 0;
    return 1;
}
