/* func_0010D5C0: libpad scePadPortOpen (PsIIlibpad 2500), Sony EE GCC 2.9.
 * Adapted from devin-thomas/guilty-gear-x-plus src/sdk/sce/libpad.c
 * (CC0 1.0 Universal). */
typedef struct {
    void *dmaArea;
    int *cmdBuf;
    int *iopBuf;
    int dmaId;
    int opened;
    int pad14;
    int pad18;
} PadSlot;
typedef struct { unsigned char b[0x50]; } RpcClient;
extern int D_0043991C;
extern char D_004AB300[];
extern char D_004AB330[];
extern RpcClient D_004C8380[2];
extern PadSlot D_004C83D0[2][4];
extern int D_004C84C0[2][4][8];
extern int D_004C85C0[32];
extern int func_00105E80(const char *, ...);
extern void *func_0011D8F8(void *, int, unsigned int);
extern int func_00106E68(void *, unsigned int, unsigned int, void *, int, void *, int, void (*)(void *), void *);

int func_0010D5C0(int port, int slot, void *addr)
{
    int ret;
    int val;
    int i;
    char *p;
    int *q;

    if (((unsigned int)addr & 0x3F) != 0) {
        if (D_0043991C != 0) {
            func_00105E80(D_004AB300, addr);
        }
        return 0;
    }
    if (D_004C83D0[port][slot].opened == 1) {
        if (D_0043991C != 0) {
            func_00105E80(D_004AB330, port, slot);
        }
        return 0;
    }
    p = (char *)addr;
    for (i = 0; i < 2; i++) {
        *(int *)(p + 0x58) = 0;
        p[0x70] = 5;
        p[0x71] = 2;
        p[0x67] = 0;
        func_0011D8F8(p, 0xFF, 0x20);
        *(int *)(p + 0x60) = 0;
        p += 0x80;
    }
    D_004C85C0[0] = 1;
    D_004C85C0[1] = port;
    D_004C85C0[2] = slot;
    D_004C85C0[4] = (int)addr;
    ret = func_00106E68(&D_004C8380[0], 1, 0, D_004C85C0, 0x80, D_004C85C0, 0x80, 0, 0);
    if (ret < 0) {
        return 0;
    }
    q = D_004C84C0[port][slot];
    val = (int)*(void **)&D_004C85C0[5];
    D_004C83D0[port][slot].opened = 1;
    D_004C83D0[port][slot].iopBuf = (int *)val;
    D_004C83D0[port][slot].dmaArea = addr;
    D_004C83D0[port][slot].cmdBuf = q;
    q[0] = 0;
    D_004C83D0[port][slot].dmaId = 0;
    return D_004C85C0[3];
}
