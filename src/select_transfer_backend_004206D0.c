typedef signed char s8;
typedef unsigned char u8;
typedef unsigned int u32;

struct TransferBackendState
{
    u8 unknown0[2];
    s8 selectedBackend;
};

extern struct TransferBackendState *D_004C2840;
extern void (*jtbl_004A6F40[4])(void);
extern void func_003D7310(void (*callback)(void));
extern void func_00152960(void);

void func_004206D0(void)
{
    s8 selectedBackend;

    selectedBackend = D_004C2840->selectedBackend;
    jtbl_004A6F40[selectedBackend]();
    func_003D7310(func_00152960);
}
