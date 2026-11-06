#include "objects.h"

#define TEAM(a, k) (*(struct Actor **)((char *)(dat_0c2f8338 + 24) + ((a)->b2 ^ 1) * 12 + (k) * 4))
#define TEAM1(a, k) (*(struct Actor **)((char *)(dat_0c2f8338 + 24) + ((a)->b2 ^ one) * 12 + (k) * 4))
#define TEAMG(a, k) (*(struct Actor **)((char *)(g + 24) + ((a)->b2 ^ one) * 12 + (k) * 4))
#define TEAMS(a, k) (((struct G8338 *)dat_0c2f8338)->t[(a)->b2 ^ 1].m[k])
#define TEAMS1(a, k) (((struct G8338 *)dat_0c2f8338)->t[(a)->b2 ^ one].m[k])
#define TEAMC(a, k) (*(struct Actor **)((char *)((struct G8338 *)dat_0c2f8338)->t + ((a)->b2 ^ one) * 12 + (k) * 4))
#define TEAMC1(a, k) (*(struct Actor **)((char *)((struct G8338 *)dat_0c2f8338)->t + ((a)->b2 ^ 1) * 12 + (k) * 4))
#define TEAMCG(a, k) (*(struct Actor **)((char *)g->t + ((a)->b2 ^ 1) * 12 + (k) * 4))
#define TEAMG2(a, k) (*(struct Actor **)((char *)(g + 24) + ((a)->b2 ^ 1) * 12 + (k) * 4))
extern void func_0c02a39a(struct Actor *, int);
extern unsigned char dat_0c2f8338[];
extern unsigned char dat_0c2f833e;
extern struct Glob_042728 *dat_0c2f83f8;
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
extern struct PlayerSlotScore dat_0c2d7088[];
extern signed char dat_0c23bde4[], dat_0c23c64e[];
extern char func_0c02a026(struct Actor *);
extern int func_0c02849a(void);
extern void func_0c0344a0(struct Actor *, int);
extern void func_0c0346da(struct Actor *, int);
extern void func_0c03496a(struct Actor *, unsigned char);
extern void func_0c048ccc(struct Actor *, int);
extern int func_0c1c0fbc(struct Actor *, int);
extern void func_0c1c3c00(struct Actor *, int);
extern void func_0c1d0a8c(struct LinkedActorVec3 *, short, int, int);
extern void func_0c1d6c64(struct LinkedActorVec3 *, short, int, int);
extern void func_0c1d4b54(struct LinkedActorVec3 *, short);
extern void func_0c1d0ffa(struct Actor *);
extern void func_0c02725c(int, int);

short func_0c04283c(struct Actor *a);
void func_0c042ad2(register struct Actor *a, struct LinkedActorVec3 *p, char c);
void func_0c042cd4(struct Actor *a, struct LinkedActorVec3 *p);
void func_0c043118(struct Actor *a);
void func_0c043248(struct Actor *a);

int func_0c042728(struct Actor *a)
{
    short n[1];
    goto L0; L0:
    if (dat_0c2f8338[0] >= 5) return 1;
    if (a->w420 == 0) return 1;
    if ((n[0] = func_0c04283c(a)) == 0) return 0;
    goto L; L:
    a->b142 = 1;
    func_0c02a026(a);
    if ((a->s25c -= n[0]) > 0) return 0;
    return 1;
}

int func_0c042780(struct Actor *a)
{
    short n;
    goto L1; L1:
    if (dat_0c2f8338[0] >= 5) return 1;
    if (a->w420 == 0) return 1;
    n = func_0c04283c(a);
    if ((a->s25c -= n) > 0) return 0;
    return 1;
}

void func_0c0427be(struct Actor *a, short s)
{
    if ((a->s25c = dat_0c23bde4[func_0c02849a() & 31] + s) <= 0) a->s25c = 1;
    a->s25e = a->s25c;
}

int func_0c0427f2(struct Actor *a)
{
    if ((a->s25c = a->s25c - func_0c04283c(a)) > 0) return 0;
    a->s25c = a->s25e;
    return 1;
}

short func_0c04283c(struct Actor *a)
{
    short n = 0;
    if (!(a->w342 & 0x3c00) && (a->w348 & 0x3c00)) n = 2;
    if (a->w348 & 0x3f0) n++;
    return n;
}

void func_0c042868(struct Actor *a)
{
    char v[2];
    unsigned short w;
    unsigned short *pw = &w;
    if (!a->b1e3) return;
    if ((w = a->w348) == 0) return;
    v[0] = 0;
    if (w & 0x3c00) v[0] += 2;
    if (w & 0x3f0) v[0] += 1;
    v[0] += dat_0c23c64e[func_0c02849a() & 15];
    v[1] = a->b1e3 & 3;
    if ((a->b1e3 -= v[0]) < 0) a->b1e3 = 0;
    if (v[1] >= v[0]) return;
    if (a->b5 == 3 && a->b233 == 9 && a->b233 == 23) {
        a->b142 = 1;
        func_0c043248(a);
        return;
    }
    if (a->b5 != 0) return;
    if (a->b1d0 != 23) {
        if (a->b5 != 0) return;
        if (a->b1d0 != 12) return;
        a->b142 = 1;
        func_0c02a026(a);
    }
    a->b142 = 1;
}

void func_0c042960(struct Actor *a)
{
    unsigned short w;
    float d;
    if (!a->w420) return;
    if (!a->b234) return;
    if (!(w = a->w34a & 0xc00)) return;
    d = 0.0520833321f;
    if (a->b1d2) d = -0.0520833321f;
    if (w & 0x800) d = -d;
    a->f92 += d;
}

void func_0c0429a4(struct Actor *a, struct LinkedActorVec3 *p, char c)
{
    if (a->b255 == 4) {
        a->b327 = 4;
        dat_0c2f83f8->b118 = (a->b2 << 4) | 4;
        a->b328 = 16;
        func_0c042cd4(a, p);
        func_0c0346da(a, 30);
        func_0c0344a0(a, 43);
    }
    else if (a->b255 == 6) {
        func_0c1d0ffa(a);
        func_0c048ccc(a, c);
        a->b3f9 = 255;
        a->b3f8 = 16;
        func_0c02725c(a->b2, 5);
        func_0c03496a(a, dat_0c2f83f8->b116[a->b2] + 255);
    }
    else if (a->b255 <= 2) {
    a->b327 = dat_0c2f83f8->b116[a->b2];
    dat_0c2f83f8->b118 = dat_0c2f83f8->b116[a->b2] | (a->b2 << 4);
    a->b328 = 16;
    func_0c042ad2(a, p, c);
    a->b3f9 = 255;
    a->b3f8 = 16;
    }
}

void func_0c042ad2(struct Actor *a, struct LinkedActorVec3 *p, char c)
{
    struct LinkedActorVec3 v;
    int one = 1;
    a->b327 = one;
    dat_0c2f83f8->b118 = (a->b2 << 4) | one;
    a->b328 = 16;
    func_0c048ccc(a, c);
    if (func_0c1c0fbc(a, 0) == 0) return;
    v = ((struct ActorPos52 *)a)->pos;
    v.y += p->y;
    if (a->w130 == 0) v.x += p->x; else v.x -= p->x;
    func_0c1d0a8c(&v, a->w130, 0, 0);
    func_0c02725c(a->b2, 5);
    func_0c03496a(a, 0);
    func_0c0346da(a, 30);
    func_0c0344a0(a, 43);
    func_0c043118(a);
    func_0c1c3c00(a, 0);
    {
    void (*f)(struct Actor *, int) = func_0c02a39a;
    unsigned char *g = dat_0c2f8338;
    f(TEAMG(a, 0), 2);
    f(TEAMG(a, 1), 2);
    f(TEAMG(a, 2), 2);
    }
}

void func_0c042c1a(register struct Actor *a)
{
    func_0c048ccc(a, 1);
    if (func_0c1c0fbc(a, 4) == 0) return;
    func_0c043118(a);
    dat_0c2d9260.b3 = dat_0c2d9260.b4 = 1;
    func_0c02a39a(TEAMC1(a, 0), 2);
    func_0c02a39a(TEAMC1(a, 1), 2);
    func_0c02a39a(TEAMC1(a, 2), 2);
}

void func_0c042cd4(register struct Actor *a, struct LinkedActorVec3 *p)
{
    struct LinkedActorVec3 v;
    if (func_0c1c0fbc(a, 5) == 0) return;
    v = *(struct LinkedActorVec3 *)&a->f52;
    v.y += p->y;
    if (a->w130 == 0) v.x += p->x; else v.x -= p->x;
    func_0c1d0a8c(&v, a->w130, 0, 0);
    func_0c02725c(a->b2, 7);
    func_0c03496a(a, 255 + a->b259);
    func_0c0346da(a, 30);
    func_0c0344a0(a, 43);
    func_0c043118(a);
    func_0c1c3c00(a, 1);
    {
    void (*f)(struct Actor *, int) = func_0c02a39a;
    int one = 1;
    register unsigned char *g = dat_0c2f8338;
    f(TEAMG(a, 0), 2);
    f(TEAMG(a, 1), 2);
    f(TEAMG(a, 2), 2);
    }
    a->b254 = 5;
}

void func_0c042dfc(struct Actor *a)
{
    a->b327 = dat_0c2f83f8->b116[a->b2] + 1;
    dat_0c2f83f8->b118 = (dat_0c2f83f8->b116[a->b2] + 1) | (a->b2 << 4);
    a->b328 = 16;
    if (func_0c1c0fbc(a, 1) == 0) return;
    func_0c043118(a);
    func_0c0346da(a, 30);
    func_0c0344a0(a, 43);
    func_0c1c3c00(a, 0);
    dat_0c2d9260.b3 = 1;
    dat_0c2d9260.b4 = 7;
    {
    struct G8338 *g = (struct G8338 *)dat_0c2f8338;
    void (*f)(struct Actor *, int) = func_0c02a39a;
    f(TEAMCG(a, 0), 2);
    f(TEAMCG(a, 1), 2);
    f(TEAMCG(a, 2), 2);
    }
}

void func_0c042ed6(struct Actor *a, struct LinkedActorVec3 *p)
{
    struct LinkedActorVec3 v;
    a->b327 = 1;
    dat_0c2f83f8->b118 = (a->b2 << 4) | 1;
    a->b328 = 16;
    if (func_0c1c0fbc(a, 2) == 0) return;
    v = *(struct LinkedActorVec3 *)&a->f52;
    v.y += p->y;
    if (a->w130 == 0) v.x += p->x; else v.x -= p->x;
    func_0c1d0a8c(&v, a->w130, 0, 0);
    func_0c02725c(a->b2, 5);
    func_0c03496a(a, 0);
    func_0c0346da(a, 30);
    func_0c0344a0(a, 43);
    func_0c043118(a);
    func_0c1c3c00(a, 0);
    dat_0c2d9260.b3 = dat_0c2d9260.b4 = 9;
    {
    struct G8338 *g = (struct G8338 *)dat_0c2f8338;
    void (*f)(struct Actor *, int) = func_0c02a39a;
    f(TEAMCG(a, 0), 2);
    f(TEAMCG(a, 1), 2);
    f(TEAMCG(a, 2), 2);
    }
}

void func_0c043014(register struct Actor *a, struct LinkedActorVec3 *p)
{
    struct LinkedActorVec3 v;
    func_0c048ccc(a, 1);
    if (func_0c1c0fbc(a, 6) == 0) return;
    v = *(struct LinkedActorVec3 *)&a->f52;
    v.y += p->y;
    if (a->w130 == 0) v.x += p->x; else v.x -= p->x;
    func_0c1d6c64(&v, a->w130, 0, 0);
    func_0c0346da(a, 64);
    func_0c043118(a);
    {
    void (*f)(struct Actor *, int) = func_0c02a39a;
    int one = 1;
    register unsigned char *g = dat_0c2f8338;
    f(TEAMG(a, 0), 2);
    f(TEAMG(a, 1), 2);
    f(TEAMG(a, 2), 2);
    }
}

void func_0c043118(struct Actor *a)
{
    a->b248 |= 1 << a->b2;
    dat_0c2f833e = a->b248;
    a->b249 = 0;
    dat_0c2d9260.b5 = 0;
    dat_0c2d9260.b6 = 1;
    dat_0c2d9260.b3 = dat_0c2d9260.b4 = 10;
}

void func_0c043150(register struct Actor *a)
{
    void (*f)(struct Actor *, int) = func_0c02a39a;
    int one = 1;
    a->b248 &= ~(one << a->b2);
    f(TEAMC(a, 0), 10);
    f(TEAMC(a, 1), 10);
    f(TEAMC(a, 2), 10);
}

void func_0c0431ec(struct Actor *a)
{
    struct PlayerSlotScore *s;
    int n = sizeof(struct PlayerSlotScore);
    if (--a->b249 != 0 && a->b5 == 0 && (a->b1d0 == 29 || a->b1d0 == 28))
        return;
    a->b248 = 0;
    s = dat_0c2d7088;
    do {
        func_0c02a39a(&s->actor, 1);
        s = (struct PlayerSlotScore *)((char *)s + n);
    } while (s < dat_0c2d7088 + 6);
}

void func_0c043248(struct Actor *a)
{
    char c;
    struct AnimationFrame20 *p;
    if ((c = a->b140) >= 0) return;
    p = a->p154;
    func_0c02a026(a);
    if ((unsigned char)c == (signed char)a->b140) return;
    if (!((unsigned char)c & 64)) {
        if ((unsigned char)(c &= 15) == 0) return;
        p -= (unsigned char)c - 1;
    } else {
        unsigned char n = (c & 63) * 4;
        p = (struct AnimationFrame20 *)((char *)p + n);
    }
    a->p154 = p;
    *(struct AnimationFrame20 *)&a->b140 = *p;
    a->b142++;
    func_0c02a026(a);
}

void func_0c0432ca(struct Actor *a)
{
    struct LinkedActorVec3 v;
    v.x = a->f52;
    v.y = a->f41c;
    v.z = a->f60;
    func_0c1d4b54(&v, a->w130);
}
