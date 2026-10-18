typedef struct {
    int f0;
    int count;
    struct {
        unsigned char flag;
        unsigned char val;
    } entries[256];
} D3168;

extern D3168 D_004C3168;
extern int D_004C3160;
extern int D_00438258;
extern int func_00103E10(int);

int func_00104D28(int a0) {
    int idx;

    if ((unsigned int) a0 >= 0x80 || D_00438258 == 0) {
        return -1;
    }

    idx = D_004C3168.count & 0x1FF;
    D_004C3168.count = idx + 1;
    D_004C3168.entries[idx].flag = 1;
    D_004C3168.entries[idx].val = (unsigned char) a0;
    func_00103E10(D_004C3160);
    return a0;
}
