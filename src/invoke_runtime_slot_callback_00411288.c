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

typedef signed int s32;

typedef struct RuntimeCallbackEntryB
{
    s32 (*callback)(s32 argument);
    s32 argument;
} RuntimeCallbackEntryB;

extern const char D_004BEB40[];
extern RuntimeCallbackEntryB D_00632360[];
extern void func_00411380(const char *message);

/* Must follow func_004112B0 in this unit: EE GCC 2.96 treats calls to
   functions it has already compiled as non-throwing, which changes how reorg
   fills the delay slots after those calls. */
s32 func_004115E0(s32 mode, s32 (*callback)(s32), s32 argument)
{
    s32 i;

    func_00411288();
    for (i = 0; i < 4; i++) {
        RuntimeCallbackEntryB *entry = &D_00632360[mode * 4 + i];
        if (entry->callback == 0) {
            entry->callback = callback;
            entry->argument = argument;
            break;
        }
    }
    if (i == 4)
        func_00411380(D_004BEB40);
    func_004112B0();
    return i == 4 ? -1 : i;
}
