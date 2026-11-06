#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern const unsigned int dat_0c248808[], dat_0c248810[], dat_0c248814[], dat_0c24881c[], dat_0c248820[], dat_0c248828[], dat_0c24882c[], dat_0c248834[], dat_0c248838[], dat_0c248840[], dat_0c248844[], dat_0c24884c[];
extern const unsigned short dat_0c24880c[], dat_0c248818[], dat_0c248824[], dat_0c248830[], dat_0c24883c[], dat_0c248848[];
extern void func_0c044cbc(struct Actor *), func_0c043352(struct Actor *), func_0c044df4(struct Actor *), func_0c0437b8(struct Actor *), func_0c0438de(struct Actor *);
extern void func_0c0421f4(struct Actor *), func_0c0420f8(struct Actor *), func_0c042018(struct Actor *), func_0c0421b8(struct Actor *), func_0c044f1c(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int), func_0c0346da(struct Actor *, int);
extern char func_0c02a026(struct Actor *);
extern void (*table_0c24892c[])(struct Actor *), (*table_0c24893c[])(struct Actor *);
void func_0c0d7254(struct Actor *a), func_0c0d7340(struct Actor *a), func_0c0d73ec(struct Actor *a), func_0c0d7518(struct Actor *a);
void func_0c0d761c(struct Actor *a), func_0c0d762e(struct Actor *a), func_0c0d7748(struct Actor *a), func_0c0d78a4(struct Actor *a);
void func_0c0d795e(struct Actor *a), func_0c0d7996(struct Actor *a), func_0c0d79ce(struct Actor *a), func_0c0d7a40(struct Actor *a);
void func_0c0d7b14(struct Actor *a), func_0c0d7b50(struct Actor *a), func_0c0d7b9e(struct Actor *a), func_0c0d7be0(struct Actor *a), func_0c0d7c02(struct Actor *a);

#define FE(a) (*(unsigned char *)&(a)->b1fe)

void func_0c0d720c(struct Actor *a)
{
    func_0c044cbc(a);
    if (FE(a) == 1) {
        if (a->b1f9 == 1) { func_0c0d7518(a); return; }
        func_0c0d73ec(a);
        return;
    }
    if (a->b1f9 == 1) { func_0c0d7340(a); return; }
    func_0c0d7254(a);
}

void func_0c0d7254(struct Actor *a)
{
    switch (a->b1e8) {
    case 0:
        a->b158 = 0; a->b1a1 = 0;
        func_0c0346da(a, 20);
        a->p3f4 = (void *)dat_0c248808;
        a->b1a7 = 0;
        break;
    case 1:
        a->b158 = 1; a->b1a1 = 1;
        func_0c0346da(a, 21);
        a->p3f4 = (void *)dat_0c24880c;
        a->b1a7 = 1;
        break;
    case 2:
        a->b158 = 2; a->b1a1 = 2;
        if (a->w1fa & 0x800) { a->b158 = 3; a->b1a1 = 18; }
        func_0c0346da(a, 22);
        a->p3f4 = (void *)dat_0c248810;
        a->b1a7 = 2;
        break;
    }
    a->w1ac = 0; a->b19e = 0; a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 7, a->b158);
}

void func_0c0d7340(struct Actor *a)
{
    switch (a->b1e8) {
    case 0:
        a->b158 = 0; a->b1a1 = 6;
        func_0c0346da(a, 20);
        a->p3f4 = (void *)dat_0c248808;
        a->b1a7 = 0;
        break;
    case 1:
        a->b158 = 1; a->b1a1 = 7;
        func_0c0346da(a, 21);
        a->p3f4 = (void *)dat_0c24880c;
        a->b1a7 = 1;
        break;
    case 2:
        a->b158 = 2; a->b1a1 = 8;
        func_0c0346da(a, 22);
        a->p3f4 = (void *)dat_0c248810;
        a->b1a7 = 2;
        break;
    }
    a->w1ac = 0; a->b19e = 0; a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 9, a->b158);
}

void func_0c0d73ec(struct Actor *a)
{
    switch (a->b1e8) {
    case 0:
        a->b158 = 0; a->b1a1 = 3;
        func_0c0346da(a, 20);
        a->p3f4 = (void *)dat_0c248814;
        a->b1a7 = 0;
        break;
    case 1:
        a->b158 = 1; a->b1a1 = 4;
        func_0c0346da(a, 21);
        a->p3f4 = (void *)dat_0c248818;
        a->b1a7 = 1;
        break;
    case 2:
        if (a->w1fa & 0x800) {
            a->b6 = 2;
            a->b158 = 4; a->b1a1 = 20;
            a->f92 = a->b1d2 ? 6.66666651f : -6.66666651f;
            a->f104 = 0.0f;
        } else if (a->w1fa & 0x400) {
            a->b6 = 1;
            a->b158 = 3; a->b1a1 = 19;
        } else {
            a->b158 = 2; a->b1a1 = 5;
        }
        func_0c0346da(a, 22);
        a->p3f4 = (void *)dat_0c24881c;
        a->b1a7 = 2;
        break;
    }
    a->w1ac = 0; a->b19e = 0; a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 8, a->b158);
}

void func_0c0d7518(struct Actor *a)
{
    switch (a->b1e8) {
    case 0:
        a->b158 = 0; a->b1a1 = 9;
        func_0c0346da(a, 20);
        a->p3f4 = (void *)dat_0c248814;
        a->b1a7 = 0;
        break;
    case 1:
        a->b158 = 1; a->b1a1 = 10;
        func_0c0346da(a, 21);
        a->p3f4 = (void *)dat_0c248818;
        a->b1a7 = 1;
        break;
    case 2:
        a->b158 = 2; a->b1a1 = 11;
        func_0c0346da(a, 22);
        a->p3f4 = (void *)dat_0c24881c;
        a->b1a7 = 2;
        break;
    }
    a->w1ac = 0; a->b19e = 0; a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 10, a->b158);
}

void func_0c0d75f4(struct Actor *a)
{
    if ((!a->b1fe && (a->b1d6 & 15)) || (FE(a) && (a->b1d6 & 0xf0))) func_0c0d761c(a);
}

void func_0c0d761c(struct Actor *a)
{
    if (FE(a) == 1) { func_0c0d7748(a); return; }
    func_0c0d762e(a);
}

void func_0c0d762e(struct Actor *a)
{
    switch (a->b1e8) {
    case 0:
        a->b158 = 0; a->b1a1 = 12;
        func_0c0346da(a, 20);
        if (!a->b1fc) a->p3f4 = (void *)dat_0c248820;
        else a->p3f4 = (void *)dat_0c248838;
        a->b1a7 = 0;
        break;
    case 1:
        a->b158 = 1; a->b1a1 = 13;
        func_0c0346da(a, 21);
        if (!a->b1fc) a->p3f4 = (void *)dat_0c248824;
        else a->p3f4 = (void *)dat_0c24883c;
        a->b1a7 = 1;
        break;
    case 2:
        a->b158 = 2; a->b1a1 = 14;
        func_0c0346da(a, 22);
        if (!a->b1fc) a->p3f4 = (void *)dat_0c248828;
        else a->p3f4 = (void *)dat_0c248840;
        a->b1a7 = 2;
        break;
    }
    a->w1ac = 0; a->b19e = 0; a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 11, a->b158);
    if (a->b1d6 & 15) a->b1d6--;
}

void func_0c0d7748(struct Actor *a)
{
    switch (a->b1e8) {
    case 0:
        if (a->w1fa & 0x1000) { a->b158 = 0; a->b1a1 = 21; }
        else { a->b158 = 3; a->b1a1 = 15; }
        func_0c0346da(a, 20);
        if (!a->b1fc) a->p3f4 = (void *)dat_0c24882c;
        else a->p3f4 = (void *)dat_0c248844;
        a->b1a7 = 0;
        break;
    case 1:
        a->b158 = 4; a->b1a1 = 16;
        func_0c0346da(a, 21);
        if (!a->b1fc) a->p3f4 = (void *)dat_0c248830;
        else a->p3f4 = (void *)dat_0c248848;
        a->b1a7 = 1;
        break;
    case 2:
        a->b158 = 5; a->b1a1 = 17;
        func_0c0346da(a, 22);
        if (!a->b1fc) a->p3f4 = (void *)dat_0c248834;
        else a->p3f4 = (void *)dat_0c24884c;
        a->b1a7 = 2;
        break;
    }
    a->w1ac = 0; a->b19e = 0; a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 12, a->b158);
    if (a->b1d6 & 0xf0) a->b1d6 -= 16;
}

void func_0c0d7882(struct Actor *a)
{
    struct Actor *p = a;
    table_0c24892c[p->b1ff](a);
}

void func_0c0d7896(struct Actor *a)
{
    func_0c043352(a);
    func_0c0d78a4(a);
}

void func_0c0d78a4(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c044df4(a);
    if (FE(a) == 1) {
        if (a->b1f9 == 1) { func_0c0d7b50(a); return; }
        func_0c0d79ce(a);
        return;
    }
    if (a->b1f9 == 1) { func_0c0d7996(a); return; }
    func_0c0d795e(a);
}

void func_0c0d795e(struct Actor *a)
{
    switch (a->b1e8) {
    case 0: case 1: case 2:
        if (func_0c02a026(a) < 0) func_0c0437b8(a);
        break;
    }
}

void func_0c0d7996(struct Actor *a)
{
    switch (a->b1e8) {
    case 0: case 1: case 2:
        if (func_0c02a026(a) < 0) func_0c0437b8(a);
        break;
    }
}

void func_0c0d79ce(struct Actor *a)
{
    switch (a->b1e8) {
    case 2:
        if (a->b6 == 1) { func_0c0d7a40(a); return; }
        if (func_0c02a026(a) < 0) goto fall;
        if (a->b6 == 2) { func_0c0d7b14(a); return; }
        break;
    case 0: case 1:
        goto x; x: if (func_0c02a026(a) < 0) { fall: func_0c0437b8(a); }
        break;
    }
}

void func_0c0d7a40(struct Actor *a)
{
    struct Actor *p = a;
    table_0c24893c[p->b7](a);
}

void func_0c0d7a52(struct Actor *a)
{
    func_0c02a026(a);
    if (a->b141) {
        a->b7++;
        a->b141 = 0;
        a->f92 = a->b1d2 ? 5.0f : -5.0f;
        a->f104 = 0.0f;
        a->f96 = 8.5714283f;
        a->f108 = -1.0044643f;
    }
}

void func_0c0d7aa2(struct Actor *a)
{
    if (!a->b141) func_0c02a026(a);
    if (a->f56 > a->f41c) return;
    a->b7++;
    a->f56 = a->f41c;
    a->b1fc = 0;
    a->b210 = 0;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
}

void func_0c0d7af2(struct Actor *a)
{
    if (func_0c02a026(a) < 0) func_0c0437b8(a);
}

void func_0c0d7b14(struct Actor *a)
{
    if (a->b141) {
        a->b6 = 0;
        a->f92 = 0.0f;
    }
}

void func_0c0d7b50(struct Actor *a)
{
    switch (a->b1e8) {
    case 0: case 1: case 2:
        if (func_0c02a026(a) < 0) func_0c0437b8(a);
        break;
    }
}

void func_0c0d7b88(struct Actor *a)
{
    func_0c0421f4(a);
    func_0c0420f8(a);
    func_0c0d7b9e(a);
}

void func_0c0d7b9e(struct Actor *a)
{
    func_0c042018(a);
    func_0c0421b8(a);
    if (FE(a) == 1) func_0c0d7c02(a);
    else func_0c0d7be0(a);
    if (func_0c044e52(a)) func_0c044f1c(a);
}

void func_0c0d7be0(struct Actor *a)
{
    if (func_0c02a026(a) < 0) func_0c0438de(a);
}

void func_0c0d7c02(struct Actor *a)
{
    if (func_0c02a026(a) < 0) func_0c0438de(a);
}
