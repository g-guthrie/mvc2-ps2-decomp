typedef signed char s8;
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

struct TransferBackendState
{
    u8 unknown0[2];
    s8 selectedBackend;
};

extern struct TransferBackendState *D_004C2840;
extern const u32 jtbl_004A6F40[4];
extern void func_003D7310(s32 callbackAddress);
extern void func_00152960(void);

void func_004206D0(void)
{
    s8 selectedBackend;

    selectedBackend = D_004C2840->selectedBackend;
    ((void (*)(void))jtbl_004A6F40[selectedBackend])();
    func_003D7310((s32)func_00152960);
}
