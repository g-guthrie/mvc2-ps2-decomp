typedef struct {
    int f0;
    int count;
    struct {
        unsigned char flag;
        unsigned char val;
    } entries[512];
} D3168;

extern D3168 D_004C3168;
extern int D_004C3160;
extern int D_00438258;
extern int func_00103E10(int);
extern int func_00103D20(void);
extern int func_00103D60(void);

int func_00104C90(int a0) {
    int s0;
    int idx;

    asm volatile (
        "addiu $3, $0, -47\n"
        "syscall 0\n"
        "move %0, $2\n"
        : "=r"(s0)
    );

    if (s0 != a0) {
        return func_00103D20();
    }
    if ((unsigned int) s0 >= 0x100) {
        return -1;
    }
    if (D_00438258 == 0) {
        return -1;
    }

    idx = D_004C3168.count & 0x1FF;
    D_004C3168.count = idx + 1;
    D_004C3168.entries[idx].flag = 0;
    D_004C3168.entries[idx].val = (unsigned char) s0;
    func_00103E10(D_004C3160);
    return s0;
}

int func_00104DA8(int a0) {
    int s0;
    int idx;

    asm volatile (
        "addiu $3, $0, -47\n"
        "syscall 0\n"
        "move %0, $2\n"
        : "=r"(s0)
    );

    if (s0 != a0) {
        return func_00103D60();
    }
    if ((unsigned int)s0 >= 0x100) {
        return -1;
    }
    if (D_00438258 == 0) {
        return -1;
    }

    idx = D_004C3168.count & 0x1FF;
    D_004C3168.count = idx + 1;
    D_004C3168.entries[idx].flag = 2;
    D_004C3168.entries[idx].val = (unsigned char)s0;
    func_00103E10(D_004C3160);
    return s0;
}
