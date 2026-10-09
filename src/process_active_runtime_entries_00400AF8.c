typedef signed char s8;
typedef signed int s32;

extern s8 D_00484AC0[];
extern void func_003F9630(void);
extern void func_00400AD0(void *entry);
extern void func_003F9660(void);

void func_00400AF8(void)
{
    s32 i;
    s8 *entry;

    func_003F9630();
    entry = D_00484AC0;
    for (i = 39; i >= 0; i--) {
        if (*entry == 1)
            func_00400AD0(entry);
        entry += 64;
    }
    func_003F9660();
}
