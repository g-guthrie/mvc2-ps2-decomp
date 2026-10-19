typedef signed short s16;
typedef signed int s32;

extern s16 D_0062BC34;
extern s32 *func_003EB960(void);
extern void func_003EBA10(s32, s32 *);
extern void func_003EB9C0(s32 *);

s32 func_003EBC20(s32 *s1, s32 *s0)
{
    s32 *a0;
    if (s1 == 0) {
        s1 = func_003EB960();
        if (s1 == 0)
            return 0;
        func_003EBA10(0, s1);
        *(s16 *)((char *)s1 + 0x14) = D_0062BC34;
    } else {
        a0 = (s32 *)s1[1];
        if (a0 != 0) {
            while ((*(s16 *)((char *)a0 + 0x14) - *(s16 *)((char *)s1 + 0x14)) < *(s16 *)((char *)s0 + 0x10)) {
                func_003EB9C0(a0);
                a0 = (s32 *)s1[1];
                if (a0 == 0)
                    break;
            }
        }
    }
    *(s16 *)((char *)s0 + 0x12) = *(s16 *)((char *)s1 + 0x14);
    s1[2] = (s32)s0;
    s1[3] = s0[1];
    s1[4] = s0[0];
    *(s16 *)((char *)s1 + 0x16) = *(s16 *)((char *)s0 + 0x10);
    return 1;
}
