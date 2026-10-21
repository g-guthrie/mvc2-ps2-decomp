#include "sony29_kernel_semaphore_calls.h"
extern int D_0043AFC0;
extern int D_0043AB80[1];
extern unsigned char D_0043B3C8[];
extern int D_004399AC;
extern int func_0010F258(int);
extern void func_00106578(void *, int);
extern int func_00106E68(void *, int, int, void *, int, void *, int, void (*)(void *), void *);
int func_0010F8A0(int command)
{
    int result;
    int *send = &D_0043AFC0;
    if (!func_0010F258(0x22)) return 0;
    D_0043AFC0 = command;
    func_00106578(send, 4);
    if (func_00106E68(D_0043B3C8, 0x22, 0, send, 4, D_0043AB80, 4, 0, 0) < 0) {
        func_00103E00(D_004399AC);
        return 0;
    }
    result = *(int *)((unsigned int)D_0043AB80 | 0x20000000);
    func_00103E00(D_004399AC);
    return result;
}
