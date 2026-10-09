typedef signed int s32;
typedef unsigned int u32;

typedef struct RuntimeCallbackEntry
{
    s32 (*callback)(s32 argument);
    s32 argument;
} RuntimeCallbackEntry;

extern const char D_004BEBE0[];
extern const char D_004BEC08[];
extern RuntimeCallbackEntry D_00632360[];
extern void func_00411380(const char *message);

s32 func_00411978(s32 mode, s32 flag)
{
    s32 result = 0;
    RuntimeCallbackEntry *entry;

    if ((u32)flag >= 4)
        func_00411380(D_004BEBE0);
    if (mode < 0 || flag >= 7)
        func_00411380(D_004BEC08);

    entry = &D_00632360[mode * 4 + flag];
    if (entry->callback != 0)
        result = entry->callback(entry->argument);
    return result;
}
