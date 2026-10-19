/* EE GCC 2.96: -O2 -G0 -fno-optimize-sibling-calls. */
typedef signed int s32;
typedef unsigned int u32;

typedef struct RuntimeCallbackEntry {
    s32 (*callback)(s32 argument);
    s32 argument;
} RuntimeCallbackEntry;

extern const char D_004BEB90[];
extern const char D_004BEBB8[];
extern RuntimeCallbackEntry D_00632360[];
extern void func_00411380(const void *source);
extern void func_00411288(void);
extern void func_004112B0(void);

void func_00411720(s32 mode, s32 flag,
                   s32 (*callback)(s32 argument), s32 argument)
{
    RuntimeCallbackEntry *entry;

    if ((u32)flag >= 4)
        func_00411380(D_004BEB90);
    if (mode < 0 || flag >= 7)
        func_00411380(D_004BEBB8);

    func_00411288();
    entry = &D_00632360[mode * 4 + flag];
    entry->callback = callback;
    entry->argument = argument;
    func_004112B0();
}
