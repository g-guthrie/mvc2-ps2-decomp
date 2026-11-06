/* Assembled by tools/clone.py from verified twins. */
#include "objects.h"
extern unsigned char func_0c046dd0(struct Actor *, int);
extern void func_0c045248(struct Actor *, int);
extern unsigned char func_0c046e7e(struct Actor *, unsigned char *, unsigned char *);
extern unsigned char dat_0c24233e[];
extern unsigned char dat_0c240c20[];
extern void (*table_0c240d10[])(struct Actor *);
extern unsigned char dat_0c24234e[];
extern unsigned char dat_0c24235e[];

/* func_0c0868fc: no verified twin. Ghidra draft:
*/
int func_0c086928(struct Actor *);
int func_0c08695e(struct Actor *);
int func_0c086994(struct Actor *);
int func_0c0868fc(struct Actor *a)
{
    if (func_0c086928(a) || func_0c08695e(a) || func_0c086994(a))
        return 1;
    return 0;
}

int func_0c086928(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c24233e, (unsigned char *)a + 0x38c))
        return 0;
    else if (!*a->p40c)
        return 0;
    a->b258 = 4;
    return 1;
}

int func_0c08695e(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c24234e, (unsigned char *)a + 0x394))
        return 0;
    else if (!*a->p40c)
        return 0;
    a->b258 = 5;
    return 1;
}

int func_0c086994(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c24235e, (unsigned char *)a + 0x39c))
        return 0;
    else if (!*a->p40c)
        return 0;
    a->b258 = 6;
    return 1;
}
