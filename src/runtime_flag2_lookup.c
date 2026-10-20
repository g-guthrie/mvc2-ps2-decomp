/* Old-MWCC counterpart of the flag-1 runtime lookup. */
typedef unsigned int u32;
typedef int s32;
extern u32 *func_003F1F00(void *file);
extern u32 *func_003F1F10(s32,s32);
s32 func_003F1AB0(s32 a) {
    u32 *p;
    if ((*func_003F1F00((void *)a) & 2) != 0) {
        if ((p = func_003F1F10(a, 2)) != 0) return p[1];
        return 0;
    }
    return 0;
}
