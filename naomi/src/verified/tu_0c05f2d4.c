#include "objects.h"
extern unsigned char dat_0c23fe1c[],dat_0c23fe2c[],dat_0c23fe3c[],dat_0c23fe4c[],dat_0c23fe5c[],dat_0c23fe70[],dat_0c23fe80[],dat_0c23fe90[],dat_0c23fea0[];
extern unsigned char func_0c0465cc(struct Actor*),func_0c046b6c(struct Actor*),func_0c0469f4(struct Actor*),func_0c046d3c(struct Actor*),func_0c046dd0(struct Actor*,int),func_0c04608a(struct Actor*,unsigned char*);
extern int func_0c046d54(struct Actor*);
extern unsigned char func_0c046e7e(struct Actor*,unsigned char*,unsigned char*);
extern void func_0c047aac(struct Actor*,unsigned char*),func_0c045248(struct Actor*,int),func_0c045f1c(struct Actor*),func_0c0463fc(struct Actor*);
unsigned char func_0c05f3b8(struct Actor*);
unsigned char func_0c05f416(struct Actor*);
unsigned char func_0c05f490(struct Actor*);
unsigned char func_0c05f504(struct Actor*);
unsigned char func_0c05f580(struct Actor*);
unsigned char func_0c05f5c6(struct Actor*);
unsigned char func_0c05f638(struct Actor*);
unsigned char func_0c05f67e(struct Actor*);
unsigned char func_0c05f6f2(struct Actor*);
unsigned char func_0c05f790(struct Actor*);
int func_0c05f72a(struct Actor*);
int func_0c05f7ec(struct Actor*);
int func_0c05f822(struct Actor*);
int func_0c05f858(struct Actor*);
void func_0c05f2d4(struct Actor*a){
 if(func_0c0465cc(a))return;
 if(func_0c046b6c(a))return;
 if(func_0c0469f4(a))return;
 if(func_0c046d3c(a))return;
 if(func_0c05f638(a))return;
 if(func_0c05f67e(a))return;
 if(func_0c05f5c6(a))return;
 if(func_0c05f504(a))return;
 if(func_0c05f490(a))return;
 if(func_0c05f416(a))return;
 if(func_0c05f3b8(a))return;
 if(func_0c05f580(a))return;
 if(func_0c05f790(a))return;
 if(func_0c05f72a(a))return;
 if(func_0c05f6f2(a))return;
 if(func_0c04608a(a,a->x3b4))return;
 func_0c045f1c(a);func_0c0463fc(a);
}
unsigned char func_0c05f3b8(struct Actor*a){struct ActorSub2a4 *sub=&a->sub2a4;if(!func_0c046e7e(a,dat_0c23fe1c,a->x36c))return 0;else if(((unsigned char*)sub)[26])return 0;func_0c047aac(a,a->x36c);a->b5=0;a->b7=0;a->b6=0;a->b1e9=1;func_0c045248(a,21);return 1;}
unsigned char func_0c05f416(struct Actor*a){int one;if(!func_0c046e7e(a,dat_0c23fe2c,a->x374))goto fail;if(a->f56<a->f41c+137.142853f)goto fail;if(a->b1d4){if(!a->b1fc){fail:return 0;}}one=1;a->b1d4=one;func_0c047aac(a,a->x374);a->b5=0;a->b6=one;a->b7=0;a->b1e9=one;func_0c045248(a,21);return one;}
unsigned char func_0c05f490(struct Actor*a){if(!func_0c046e7e(a,dat_0c23fe3c,a->x37c))return 0;func_0c047aac(a,a->x37c);a->b5=0;a->b7=0;a->b6=0;a->b1e9=2;func_0c045248(a,21);return 1;}
unsigned char func_0c05f504(struct Actor*a){int one;if(!func_0c046e7e(a,dat_0c23fe4c,a->x384))goto fail;if(a->f56<a->f41c+137.142853f)goto fail;if(a->b1d4){if(!a->b1fc){fail:return 0;}}one=1;a->b1d4=one;func_0c047aac(a,a->x384);a->b5=0;a->b6=one;a->b7=0;a->b1e9=2;func_0c045248(a,21);return one;}
unsigned char func_0c05f580(struct Actor*a){if(!func_0c046e7e(a,dat_0c23fe5c,a->x38c))return 0;func_0c047aac(a,a->x38c);a->b5=0;a->b7=0;a->b6=0;a->b1e9=3;func_0c045248(a,21);return 1;}
unsigned char func_0c05f5c6(struct Actor*a){if(!func_0c046e7e(a,dat_0c23fe70,a->x394))return 0;else if(!*a->p40c)return 0;a->b5=0;a->b7=0;a->b6=0;a->b1e9=7;func_0c045248(a,29);return 1;}
unsigned char func_0c05f638(struct Actor*a){if(!func_0c046e7e(a,dat_0c23fe80,a->x39c))return 0;else if(!*a->p40c)return 0;a->b5=0;a->b7=0;a->b6=0;a->b1e9=9;func_0c045248(a,29);return 1;}
unsigned char func_0c05f67e(struct Actor*a){int zero=0;if(!func_0c046e7e(a,dat_0c23fe90,a->x3a4)||!*a->p40c)return 0;if(a->b1f9==2){if(a->b1d4&&!a->b1fc)return 0;a->b1d4=1;a->b32=1;}else a->b32=zero;a->b5=zero;a->b7=zero;a->b6=zero;a->b1e9=6;func_0c045248(a,29);return 1;}
unsigned char func_0c05f6f2(struct Actor*a){if(!func_0c046dd0(a,8))return 0;a->b5=0;a->b7=0;a->b6=0;a->b1e9=8;func_0c045248(a,21);return 1;}
int func_0c05f72a(struct Actor*a){if(!func_0c046d54(a))return 0;else if(!*a->p40c)return 0;a->b1e9=14;a->b5=0;func_0c045248(a,29);a->b6=(((char*)a)[7]=0);return 1;}
unsigned char func_0c05f790(struct Actor*a){if(!func_0c046e7e(a,dat_0c23fea0,a->x3ac))return 0;else if(a->b1d4&&!a->b1fc)return 0;a->b1d4=1;func_0c047aac(a,a->x3ac);a->b5=0;a->b7=0;a->b6=0;a->b1e9=15;func_0c045248(a,21);return 1;}
int func_0c05f7ec(struct Actor*a){if(!func_0c046e7e(a,dat_0c23fe70,a->x394))return 0;else if(!*a->p40c)return 0;a->b258=7;return 1;}
int func_0c05f822(struct Actor*a){if(!func_0c046e7e(a,dat_0c23fe80,a->x39c))return 0;else if(!*a->p40c)return 0;a->b258=9;return 1;}
int func_0c05f858(struct Actor*a){if(!func_0c046e7e(a,dat_0c23fe90,a->x3a4))return 0;else if(!*a->p40c)return 0;a->b32=0;a->b258=6;return 1;}
int func_0c05f8c4(struct Actor*a){if(func_0c05f822(a)||func_0c05f858(a)||func_0c05f7ec(a))return 1;return 0;}
/* Actor +0x2a4 record bytes used by the 0x0c05f8f2 state handlers. */
struct Fx_05f8f2 { unsigned char pad0[18]; signed char t18; unsigned char pad19[6]; char f25; unsigned char pad26[2]; char f28; };
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c0344a0(struct Actor *, int);
extern void func_0c0346da(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c044cbc(struct Actor *);
extern char dat_0c23fdd4[], dat_0c23fdd8[], dat_0c23fddc[];
extern char dat_0c23fde0[], dat_0c23fde4[], dat_0c23fde8[];
extern char dat_0c23fdec[], dat_0c23fdf0[], dat_0c23fdf4[];
extern char dat_0c23fe04[], dat_0c23fe08[], dat_0c23fe0c[];
extern char dat_0c23fdf8[], dat_0c23fdfc[], dat_0c23fe00[];
extern char dat_0c23fe10[], dat_0c23fe14[], dat_0c23fe18[];
extern void (*const table_0c23ff20[])(void);

void func_0c05f8f2(struct Actor *a)
{
    struct Fx_05f8f2 *s = (struct Fx_05f8f2 *)&a->sub2a4;
    if (!(!a->b5 && a->b1d0 == 21) && !(!a->b5 && a->b1d0 == 29)) {
        if (s->t18 && --s->t18 == 0)
            func_0c02a39a(a, 0);
    }
    if (s->f28) {
        if (!a->b5) {
            if (a->b1d0 == 29 && a->b1e9 == 6) return;
            if (a->b1d0 == 10 || a->b1d0 == 11 || a->b1d0 == 26) return;
        }
        s->f28 = 0;
        func_0c0344a0(a, 43);
    }
    if (s->f25) {
        if (!a->b5 && a->b1d0 == 26) return;
        s->f25 = 0;
    }
}

void func_0c05f9ac(struct Actor *a)
{
    int n = 1;
    switch (a->b1e8) {
    case 0:
        a->b158 = 0;
        a->b1a1 = 0;
        func_0c0346da(a, 20);
        a->p3f4 = dat_0c23fdd4;
        a->b1a7 = 0;
        a->pad2a2[0] = n;
        break;
    case 1:
        a->b158 = n;
        a->b1a1 = n;
        func_0c0346da(a, 21);
        a->p3f4 = dat_0c23fdd8;
        a->b1a7 = n;
        break;
    case 2:
        n = 2;
        a->b158 = n;
        a->b1a1 = n;
        func_0c0346da(a, 22);
        a->p3f4 = dat_0c23fddc;
        a->b1a7 = n;
        break;
    }
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 7, a->b158);
}

void func_0c05fa6e(struct Actor *a)
{
    switch (a->b1e8) {
    case 0:
        a->b158 = 0;
        a->b1a1 = 6;
        func_0c0346da(a, 20);
        a->p3f4 = dat_0c23fdd4;
        a->b1a7 = 0;
        break;
    case 1:
        a->b158 = 1;
        a->b1a1 = 7;
        func_0c0346da(a, 21);
        a->p3f4 = dat_0c23fdd8;
        a->b1a7 = 1;
        break;
    case 2:
        if (a->w1fa & 0x400) {
            a->b158 = 3;
            a->b1a1 = 28;
        } else {
            a->b158 = 2;
            a->b1a1 = 8;
        }
        func_0c0346da(a, 22);
        a->p3f4 = dat_0c23fddc;
        a->b1a7 = 2;
        break;
    }
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 9, a->b158);
}

void func_0c05fb58(struct Actor *a)
{
    switch (a->b1e8) {
    case 0:
        a->b158 = 0;
        a->b1a1 = 3;
        func_0c0346da(a, 20);
        a->p3f4 = dat_0c23fde0;
        a->b1a7 = 0;
        break;
    case 1:
        a->b158 = 1;
        a->b1a1 = 4;
        func_0c0346da(a, 21);
        a->p3f4 = dat_0c23fde4;
        a->b1a7 = 1;
        break;
    case 2:
        if (a->w1fa & 0x800) {
            a->b6++;
            a->b7 = 0;
            a->b158 = 3;
            a->b1a1 = 19;
        } else {
            a->b158 = 2;
            a->b1a1 = 5;
        }
        func_0c0346da(a, 22);
        a->p3f4 = dat_0c23fde8;
        a->b1a7 = 2;
        break;
    }
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 8, a->b158);
}

void func_0c05fc54(struct Actor *a)
{
    switch (a->b1e8) {
    case 0:
        a->b158 = 0;
        a->b1a1 = 9;
        func_0c0346da(a, 20);
        a->p3f4 = dat_0c23fde0;
        a->b1a7 = 0;
        break;
    case 1:
        a->b158 = 1;
        a->b1a1 = 10;
        func_0c0346da(a, 21);
        a->p3f4 = dat_0c23fde4;
        a->b1a7 = 1;
        break;
    case 2:
        a->b158 = 2;
        a->b1a1 = 11;
        func_0c0346da(a, 22);
        a->p3f4 = dat_0c23fde8;
        a->b1a7 = 2;
        break;
    }
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 10, a->b158);
}

void func_0c05fd00(struct Actor *a)
{
    func_0c044cbc(a);
    if ((unsigned char)a->b1fe == 1) {
        if (a->b1f9 == 1)
            func_0c05fc54(a);
        else
            func_0c05fb58(a);
    } else {
        if (a->b1f9 == 1)
            func_0c05fa6e(a);
        else
            func_0c05f9ac(a);
    }
}

void func_0c05fd74(struct Actor *a)
{
    switch (a->b1e8) {
    case 0:
        a->b158 = 0;
        a->b1a1 = 12;
        func_0c0346da(a, 20);
        if (!a->b1fc)
            a->p3f4 = dat_0c23fdec;
        else
            a->p3f4 = dat_0c23fe04;
        a->b1a7 = 0;
        break;
    case 1:
        a->b158 = 1;
        a->b1a1 = 13;
        func_0c0346da(a, 21);
        if (!a->b1fc)
            a->p3f4 = dat_0c23fdf0;
        else
            a->p3f4 = dat_0c23fe08;
        a->b1a7 = 1;
        break;
    case 2:
        a->b158 = 2;
        a->b1a1 = 14;
        func_0c0346da(a, 22);
        if (!a->b1fc)
            a->p3f4 = dat_0c23fdf4;
        else
            a->p3f4 = dat_0c23fe0c;
        a->b1a7 = 2;
        break;
    }
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 11, a->b158);
    if (a->b1d6 & 0xf)
        a->b1d6--;
}

void func_0c05fe94(struct Actor *a)
{
    switch (a->b1e8) {
    case 0:
        a->b158 = 0;
        a->b1a1 = 15;
        func_0c0346da(a, 20);
        if (!a->b1fc)
            a->p3f4 = dat_0c23fdf8;
        else
            a->p3f4 = dat_0c23fe10;
        a->b1a7 = 0;
        break;
    case 1:
        a->b158 = 1;
        a->b1a1 = 16;
        func_0c0346da(a, 21);
        if (!a->b1fc)
            a->p3f4 = dat_0c23fdfc;
        else
            a->p3f4 = dat_0c23fe14;
        a->b1a7 = 1;
        break;
    case 2:
        if (a->w1fa & 0x1000) {
            a->b6 = 2;
            a->b7 = 0;
            a->b1fc = 0;
            a->f92 = 0.0f;
            a->f96 = 0.0f;
            a->f104 = 0.0f;
            a->f108 = 0.0f;
            a->b158 = 5;
            a->b1a1 = 18;
        } else {
            a->b158 = 2;
            a->b1a1 = 17;
        }
        func_0c0346da(a, 22);
        if (!a->b1fc)
            a->p3f4 = dat_0c23fe00;
        else
            a->p3f4 = dat_0c23fe18;
        a->b1a7 = 2;
        break;
    }
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 12, a->b158);
    if (a->b1d6 & 0xf0)
        a->b1d6 -= 16;
}

void func_0c05ffec(struct Actor *a)
{
    struct Fx_05f8f2 *s = (struct Fx_05f8f2 *)&a->sub2a4;
    if (s->f25) {
        s->f25 = 0;
        if (a->f96 > 0.0f)
            a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = -0.80357140303f;
    }
    if ((unsigned char)a->b1fe == 1)
        func_0c05fe94(a);
    else
        func_0c05fd74(a);
}

void func_0c060028(struct Actor *a)
{
    struct Fx_05f8f2 *s = (struct Fx_05f8f2 *)&a->sub2a4;
    if (s->f25) {
        s->f25 = 0;
        if (a->f96 > 0.0f)
            a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = -0.80357140303f;
    }
    if (!a->b1fe && (a->b1d6 & 0xf))
        func_0c05ffec(a);
    else if (a->b1fe && (a->b1d6 & 0xf0))
        func_0c05ffec(a);
    else
        return;
}

void func_0c06007a(struct Actor *a)
{
    func_0c05fd00(a);
}

void func_0c06007e(struct Actor *a)
{
    ((void (*)(struct Actor *))table_0c23ff20[a->b1ff])(a);
}
