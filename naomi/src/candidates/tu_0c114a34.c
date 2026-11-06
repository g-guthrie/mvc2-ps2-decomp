/* Candidate: float load scheduling in the += block and b1fd branch order differ; size exact. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
void func_0c114a34(struct Actor *a, char *state);

void func_0c114a34(struct Actor *a, char *state)
{
    int flag;
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->f92 * a->f104 > 0.0f) {
        a->f92 = 0.0f;
        a->f104 = 0.0f;
    }
    if (!(a->f41c < a->f56)) {
        a->f56 = a->f41c;
        a->b1f9 = 0;
        a->f96 = 0.0f;
        a->f108 = 0.0f;
    }
    flag = 0;
    if (a->b1d2 ? (char)a->b1fd == 1 : (char)a->b1fd == 2) flag = 1;
    if (func_0c02a026(a) < 0 || flag == 1) {
        a->b6++;
        a->f92 /= 4.0f;
        a->f104 /= 4.0f;
        if (a->b1f9 != 2) {
            a->b158 = 2;
        } else {
            a->b158 = 3;
            a->f96 /= 4.0f;
            a->f108 = -0.80357140303f;
        }
        func_0c02a0c4(a, 21, a->b158);
        state[10] = 0;
    }
}
