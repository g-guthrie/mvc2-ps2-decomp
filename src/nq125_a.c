/* sceSifInitRpc-style SIF RPC initialisation. */
typedef unsigned int u32;
extern int D_00438270;
extern u32 D_004C3C80[];
extern u32 D_004C4480[];
extern u32 D_004C4C80[];
typedef struct { int pid; void *pkt_table; int pkt_table_len; int unused1; int unused2; void *rdata_table; int rdata_table_len; void *client_table; int client_table_len; int rdata_table_idx; } RD;
extern RD D_004C5480;
extern int func_0010CA20(void);
extern void func_0010CA68(void);
extern void func_00105F58(void);
extern void func_00106240(u32, void (*)(), void *);
extern void func_00106928();
extern void func_00106BE8();
extern void func_00106DD8();
extern void func_001069E0();
extern int func_001041F0(u32);
extern int func_001063D0(u32, void *, int, int, int, int);
extern int func_00105F10(int);
extern void func_001041E0(u32, int);

void func_00106628(int mode)
{
    u32 *q;
    func_0010CA20();
    if (D_00438270) {
        func_0010CA68();
        return;
    }
    D_00438270 = 1;
    func_0010CA68();
    func_00105F58();
    func_0010CA20();

    D_004C5480.pkt_table = (void *)((u32)D_004C3C80 | 0x20000000);
    D_004C5480.pkt_table_len = 0x20;
    D_004C5480.unused1 = 0;
    D_004C5480.unused2 = 0;
    D_004C5480.rdata_table = (void *)((u32)D_004C4480 | 0x20000000);
    D_004C5480.rdata_table_len = 0x20;
    D_004C5480.client_table = (void *)((u32)D_004C4C80 | 0x20000000);
    D_004C5480.client_table_len = 0x20;
    D_004C5480.pid = 1;
    D_004C5480.rdata_table_idx = 0;
    func_00106240(0x80000008, func_00106928, &D_004C5480);
    func_00106240(0x80000009, func_00106BE8, &D_004C5480);
    func_00106240(0x8000000A, func_00106DD8, &D_004C5480);
    func_00106240(0x8000000C, func_001069E0, &D_004C5480);
    func_0010CA68();
    if (func_001041F0(0x80000002) != 0)
        return;
    q = D_004C3C80 + 0x10;
    q[3] = 1;
    func_001063D0(0x80000002, q, 0x10, 0, 0, 0);
    while (func_00105F10(0) == 0)
        ;
    func_001041E0(0x80000002, 1);
}
