typedef unsigned char u8;
#include "sony_pad_slot.h"

typedef struct { void *src; void *dest; int size; int attr; } NqDma;

extern int func_00104180(int);
extern int func_001041A0(NqDma *, int);
extern void func_001046D8(void *, void *);
extern void func_00105E80();
extern int D_0043991C;
extern char D_004AB268[];

int func_0010D248(int port, int slot)
{
    NqDma d[16];
    u8 *cmd;
    u8 *dest;
    int id;

    cmd = D_004C83D0[port][slot].command;
    if (D_004C83D0[port][slot].dma_id != 0 && func_00104180(D_004C83D0[port][slot].dma_id) >= 0)
        goto err;
    *(int *)cmd = *(int *)cmd + 1;
    dest = D_004C83D0[port][slot].dma_destination + ((*(int *)cmd & 1) << 5);
    func_001046D8(cmd, cmd + 0x20);
    d[0].dest = dest;
    d[0].src = cmd;
    d[0].size = 0x20;
    d[0].attr = 0;
    id = func_001041A0(d, 1);
    if (id != 0)
        goto ok;
err:
    if (D_0043991C)
        func_00105E80(D_004AB268);
    return 0;
ok:
    D_004C83D0[port][slot].dma_id = id;
    return 1;
}
