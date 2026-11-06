/* Hit-stun entry chosen by stance and air/ground state, and its dispatcher. */
#include "objects.h"
extern void func_0c044cbc(struct Actor *);
extern void func_0c0344a0(struct Actor *, int);
extern void func_0c0346da(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, char);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern const unsigned short dat_0c24db50[], dat_0c24db54[], dat_0c24db58[];
extern const unsigned short dat_0c24db5c[], dat_0c24db64[];
extern const unsigned int dat_0c24db60[];
void func_0c129712(struct Actor *a);
void func_0c1297d4(struct Actor *a);
void func_0c1298cc(struct Actor *a);
void func_0c12998c(struct Actor *a);
void func_0c1296d0(struct Actor *a)
{
    func_0c044cbc(a);
    if (a->b1fe == 0) {
        if (a->b1f9 == 0) func_0c129712(a);
        else func_0c1297d4(a);
    } else {
        if (a->b1f9 == 0) func_0c1298cc(a);
        else func_0c12998c(a);
    }
}
void func_0c129712(struct Actor *a)
{
    int motion, animation;
    unsigned int sound;
    switch (a->b1e8) {
    case 0:
        motion = 0;
        animation = 0;
        sound = 30;
        a->p3f4 = (void *)dat_0c24db50;
        a->b1a7 = animation;
        break;
    case 1:
        a->b32 = 0;
        a->p3f4 = (void *)dat_0c24db54;
        sound = 31;
        motion = 1;
        animation = 1;
        a->b1a7 = animation;
        break;
    case 2:
        motion = 2;
        animation = 2;
        sound = 32;
        a->p3f4 = (void *)dat_0c24db58;
        a->b1a7 = animation;
        break;
    }
    a->b1a1 = motion;
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c0344a0(a, sound);
    func_0c02a0c4(a, 7, animation);
}
void func_0c1297d4(struct Actor *a)
{
    
    int motion; int animation;
    unsigned int sound;
    a->b6 = 0;
    switch (a->b1e8) {
    case 0:
        motion = 6;
        animation = 0;
        sound = 30;
        a->p3f4 = (void *)dat_0c24db50;
        a->b1a7 = animation;
        break;
    case 1:
        motion = 7;
        animation = 1;
        sound = 31;
        a->p3f4 = (void *)dat_0c24db54;
        a->b1a7 = animation;
        break;
    case 2:
        a->p3f4 = (void *)dat_0c24db58;
        a->b1a7 = 2;
        if (a->w1fa & 0x800) {
            a->b6 = 1;
            motion = 18;
            animation = 5;
            a->f92 = 0.0f;
            a->f96 = 0.0f;
            a->f104 = 0.0f;
            a->f108 = 0.0f;
        } else {
            motion = 8;
            animation = 2;
            a->b6 = 0;
            a->f92 = -5.0f;
            a->f104 = 0.0f;
            sound = 32;
            if (a->b1d2)
                a->f92 = -a->f92;
        }
        break;
    }
    a->b1a1 = motion;
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 9, animation);
    if (!a->b6)
        func_0c0344a0(a, sound);
}
void func_0c1298cc(struct Actor *a)
{
    register int motion; char animation;
    unsigned int sound;
    switch (a->b1e8) {
    case 0:
        motion = 3;
        animation = 0;
        sound = 20;
        a->p3f4 = (void *)dat_0c24db5c;
        a->b1a7 = animation;
        break;
    case 1:
        motion = 4;
        animation = 1;
        sound = 21;
        a->p3f4 = (void *)dat_0c24db60;
        a->b1a7 = animation;
        break;
    case 2:
        motion = 5;
        animation = 2;
        sound = 22;
        a->p3f4 = (void *)dat_0c24db64;
        a->b1a7 = animation;
        break;
    }
    a->b1a1 = motion;
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c0346da(a, sound);
    func_0c02a0c4(a, 8, animation);
}
void func_0c12998c(struct Actor *a)
{
    register int motion; char animation;
    unsigned int sound;
    switch (a->b1e8) {
    case 0:
        motion = 9;
        animation = 0;
        sound = 20;
        a->p3f4 = (void *)dat_0c24db5c;
        a->b1a7 = animation;
        break;
    case 1:
        motion = 10;
        animation = 1;
        sound = 21;
        a->p3f4 = (void *)dat_0c24db60;
        a->b1a7 = animation;
        break;
    case 2:
        motion = 11;
        animation = 2;
        sound = 22;
        a->p3f4 = (void *)dat_0c24db64;
        a->b1a7 = animation;
        break;
    }
    a->b1a1 = motion;
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c0346da(a, sound);
    func_0c02a0c4(a, 10, animation);
}
