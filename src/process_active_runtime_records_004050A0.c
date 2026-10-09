typedef signed char s8;
typedef signed int s32;

extern s8 D_00485880[];
extern void func_00405D38(void);
extern void func_00404E90(void *entry);

void func_004050A0(void)
{
    s32 i;
    s8 *entry;

    func_00405D38();
    entry = D_00485880;
    for (i = 3; i >= 0; i--) {
        if (*entry == 1)
            func_00404E90(entry);
        entry += 448;
    }
}
