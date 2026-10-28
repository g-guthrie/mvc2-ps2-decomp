/* func_00105260: Sony EE GCC 2.9, ./trysony29.sh src/s6a_j.c 0 O2 (exact). Volatile reads of D_004C36D0.fC/.f0, including the f0 call argument, give retail's load order and slot fills. */
#include "sony_deci2_call.h"

int func_00104E88(int value);
int func_00104EB0(int first, signed char second);
void func_00104EE0(int value);
typedef struct { int f0; volatile int f4; int f8; int fC; char *f10; } DebugTx;
extern DebugTx D_004C36D0;
extern char D_004C3700[];
extern void func_0010CA20(void);
extern void func_0010CA68(void);

int func_00105260(char *src, int n)
{
    int count = 0;
    int i = 0;
    char *buf;
    char *d;
    DebugTx *t;
    DebugTx *g = &D_004C36D0;

    if (*(volatile int *)&D_004C36D0.fC != 0) return -1;
    func_0010CA20();
    g->fC = 1;
    buf = (char *)((unsigned int)D_004C3700 | 0x20000000);
    g->f10 = buf;
    d = buf + 12;
    while (--n != -1) {
        if (*src == '\n') {
            *d++ = '\r';
            if (++i >= 0x100) break;
        }
        *d++ = *src++;
        i++;
        count++;
        if (i >= 0x100) break;
    }
    t = &D_004C36D0;
    t->f4 = i + 12;
    *(short *)buf = t->f4;
    if (func_00104EB0(*(volatile int *)&D_004C36D0.f0, buf[7]) < 0) {
        t->fC = 0;
        func_0010CA68();
        return -1;
    }
    while (*(volatile int *)&D_004C36D0.fC != 0) func_00104EE0(*(volatile int *)&D_004C36D0.f0);
    func_0010CA68();
    return count;
}
