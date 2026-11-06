#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c045248(struct Actor *, int);
extern void func_0c0346da(struct Actor *, int);
extern void func_0c043014(struct Actor *, struct LinkedActorVec3 *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c242c00[])(struct Actor *);
extern void (*table_0c242c08[])(struct Actor *);
void func_0c091044(struct Actor *a)
{
    a->b6++;
    a->f56 = a->f41c;
    a->b1f9 = 0;
    func_0c0442fa(a);
    func_0c0432ca(a);
    a->f92 = 0;
    a->f96 = 0;
    a->f104 = 0;
    a->f108 = 0;
    a->b1a1 = 38;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 21, 16);
}
void func_0c0910b2(struct Actor *a) { if (func_0c02a026(a) < 0) func_0c0437b8(a); }
void func_0c0910d4(struct Actor *a) { table_0c242c00[a->b6](a); }
void func_0c0910e6(struct Actor *a)
{
    a->b6++;
    a->f56 = a->f41c;
    a->b1f9 = 0;
    func_0c0442fa(a);
    func_0c0432ca(a);
    a->f92 = 0;
    a->f96 = 0;
    a->f104 = 0;
    a->f108 = 0;
    a->b1a1 = 72;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 21, 17);
}
void func_0c091154(struct Actor *a)
{
    struct LinkedActorVec3 position;
    if (func_0c02a026(a) < 0) { func_0c0437b8(a); goto done; }
    if (a->b141 & 1) {
        a->b141 ^= 1;
        position.x = -23.3333321f;
        position.y = 171.42856f;
        func_0c043014(a, &position);
    }
    if (a->b141 & 2) {
        a->b141 ^= 2;
        func_0c0346da(a, 22);
    }
done:
    ;
}
void func_0c0911de(struct Actor *a)
{
    a->b5 = 0;
    a->b6 = 0;
    a->b7 = 0;
    a->b1e9 = 4;
    func_0c045248(a, 29);
}
void func_0c0911f2(struct Actor *a)
{
    a->b5 = 0;
    a->b6 = 0;
    a->b7 = 0;
    a->b1e9 = 4;
    func_0c045248(a, 29);
}
void func_0c091206(struct Actor *a)
{
    a->b5 = 0;
    a->b6 = 0;
    a->b7 = 0;
    switch ((char)a->b4c9) {
    case 0: a->b1e9 = 0; goto clear;
    case 1: a->b1e9 = 1;
clear:
        a->b1a3 = 0; break;
    case 2: a->b1e9 = 6; a->b1a3 = 1; break;
    }
    func_0c045248(a, 21);
}
void func_0c091248(struct Actor *a)
{
    a->b5 = 0;
    a->b6 = 0;
    a->b7 = 0;
    switch ((char)a->b4c9) {
    case 0: a->b1e9 = 0; goto clear;
    case 1: a->b1e9 = 1;
clear:
        a->b1a3 = 0; break;
    case 2: a->b1e9 = 6; a->b1a3 = 1; break;
    }
    func_0c045248(a, 21);
}
void func_0c09128a(struct Actor *a) { table_0c242c08[a->b6](a); }
