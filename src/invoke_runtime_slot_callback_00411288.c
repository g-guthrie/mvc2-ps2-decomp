typedef void (*RuntimeSlotCallback)(void *);
struct RuntimeSlotPair
{
    RuntimeSlotCallback callback;
    void *context;
};
extern struct RuntimeSlotPair D_004C2B10;
extern struct RuntimeSlotPair D_004C2B18;

void func_00411288(void)
{
    RuntimeSlotCallback callback = D_004C2B10.callback;
    if (callback != 0)
        callback(D_004C2B10.context);
}

void func_004112B0(void)
{
    RuntimeSlotCallback callback = D_004C2B18.callback;
    if (callback != 0)
        callback(D_004C2B18.context);
}
