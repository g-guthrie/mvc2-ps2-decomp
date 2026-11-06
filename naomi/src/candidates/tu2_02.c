/* Four b4c9 mode selectors sharing the pool at 0x0c0ec108; 208/212 bytes.
 * Only the case-2 constant temporary differs: retail loads `mov #2,r3` in
 * func_0c0ec088 and func_0c0ec0ca where SHC picks r2 (scratch rotation; case
 * and goto respellings and permute.py did not move it). */
#include "objects.h"

extern void func_0c045248(struct Actor *, int);

void func_0c0ec040(struct Actor *o)
{
    o->b5 = 0;
    o->b7 = 0;
    o->b6 = 0;
    switch (o->b4c9) {
    case 0:
        o->b1e9 = 5;
        break;
    case 1:
        o->b1e9 = 5;
        break;
    case 2:
        o->b1e9 = 5;
        break;
    }
    func_0c045248(o, 29);
}

void func_0c0ec064(struct Actor *o)
{
    o->b5 = 0;
    o->b7 = 0;
    o->b6 = 0;
    switch (o->b4c9) {
    case 0:
        o->b1e9 = 5;
        break;
    case 1:
        o->b1e9 = 5;
        break;
    case 2:
        o->b1e9 = 5;
        break;
    }
    func_0c045248(o, 29);
}

void func_0c0ec088(struct Actor *o)
{
    int zero = 0;
    int one = 1;
    o->b5 = zero;
    o->b7 = zero;
    o->b6 = zero;
    switch (o->b4c9) {
    case 0:
        o->b1e9 = zero;
        o->b1a3 = one;
        break;
    case 1:
        o->b1e9 = one;
        goto clear;
    case 2:
        o->b1e9 = 2;
    clear:
        o->b1a3 = zero;
        break;
    }
    func_0c045248(o, 21);
}

void func_0c0ec0ca(struct Actor *o)
{
    unsigned char zero = 0;
    int one = 1;
    o->b5 = zero;
    o->b7 = zero;
    o->b6 = zero;
    switch (o->b4c9) {
    case 0:
        o->b1e9 = zero;
        goto set;
    case 1:
        o->b1e9 = one;
        goto set;
    case 2:
        o->b1e9 = 2;
    set:
        o->b1a3 = one;
        break;
    }
    func_0c045248(o, 21);
}
