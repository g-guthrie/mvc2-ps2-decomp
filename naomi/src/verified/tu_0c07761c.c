/* Actor callback dispatch and shared animation-failure flow. */
#include "objects.h"
extern void func_0c0421f4(struct Actor *);
extern void func_0c0420f8(struct Actor *);
extern void func_0c042018(struct Actor *);
extern void func_0c0421b8(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c044f1c(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c0438de(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
void func_0c077632(struct Actor *);
void func_0c077674(struct Actor *);
void func_0c077696(struct Actor *);

void func_0c07761c(struct Actor *a)
{
    func_0c0421f4(a);
    func_0c0420f8(a);
    func_0c077632(a);
}

void func_0c077632(struct Actor *a)
{
    func_0c042018(a);
    func_0c0421b8(a);
    if ((unsigned char)a->b1fe == 1)
        func_0c077696(a);
    else
        func_0c077674(a);
    if (func_0c044e52(a))
        func_0c044f1c(a);
}

void func_0c077674(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0438de(a);
}

void func_0c077696(struct Actor *a)
{
    signed char prior;
    if (a->b1e8 != 2) {
        if (func_0c02a026(a) < 0)
            goto failed;
        goto done;
    }
    prior = a->b141;
    if (func_0c02a026(a) < 0 && prior < 0)
        goto failed;
    goto check_flag;
failed:
    goto finish;
finish:
    func_0c0438de(a);
    return;
check_flag:
    if (a->b141 == 1) {
        a->b141 = 0;
        a->b1a1 = 21;
        a->w1ac = 0;
        a->b19e = 0;
        *(unsigned int *)&a->p1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
    }
done:
    ;
}
