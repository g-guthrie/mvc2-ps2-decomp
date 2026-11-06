/* Complete 0x0c0cbd20..0x0c0cbfa8 group, including both literal pools. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0437b8(struct Actor *);
extern void func_0c043324(struct Actor *);
extern void func_0c0442fa(struct Actor *);
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c1af2b8(struct Actor *, int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
typedef void (*handler_ub4_03)(struct Actor *);
extern handler_ub4_03 dat_0c247fb4[];

void func_0c0cbd20(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->f56 <= a->f41c) {
        a->b6++;
        a->f56 = a->f41c;
        a->b1f9 = 0;
        func_0c02a0c4(a, 21, 7);
        func_0c043324(a);
    } else {
        func_0c02a026(a);
    }
}

void func_0c0cbd9c(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c0cbdbe(struct Actor *a)
{
    if (a->b141 > 0) {
        a->b141 = 0;
        a->b1a1 = ((unsigned char)a->b1a3) + 61;
        a->w1ac = 0;
        a->b19e = 0;
        a->p1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
    }
}

void func_0c0cbdf6(struct Actor *a)
{
    dat_0c247fb4[a->b6](a);
}

void func_0c0cbe08(struct Actor *a)
{
    float f;

    a->b6++;
    func_0c0442fa(a);
    func_0c048bb0(a, 5);
    a->b1a1 = ((unsigned char)a->b1a3) + 61;
    a->w1ac = 0;
    a->b19e = 0;
    a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    f = ((unsigned char)a->b1a3) ? 4.16666651f : 2.5f;
    /* Keep the shared native negation block, including its branch sense. */
    if (a->b1d2) {
        if (a->f92 < 0) goto neg;
    } else {
        f = -f;
        if (a->f92 > 0) goto neg;
    }
    goto done;
neg:
    f = -f;
done:;
    a->f92 += f;
    a->f104 = 0;
    func_0c1af2b8(a, 0);
    a->s28 = ((unsigned char)a->b1a3) * 2 + 1;
    func_0c02a0c4(a, 21, 8);
}

void func_0c0cbee0(struct Actor *a)
{
 a->f52 += a->f92; a->f92 += a->f104;
 a->f56 += a->f96; a->f96 += a->f108;
 if(a->f56 <= a->f41c){
  a->b6=3; a->f56=a->f41c; a->b1f9=0;
  func_0c043324(a); func_0c02a0c4(a,1,3); return;
 }
 if(a->b141<0){
  a->b141=0;
  if(--a->s28<0){a->b6++;func_0c02a0c4(a,21,10);return;}
 }
 func_0c02a026(a); func_0c0cbdbe(a);
}
