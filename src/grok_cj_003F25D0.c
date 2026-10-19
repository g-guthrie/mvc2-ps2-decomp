typedef signed int s32;

extern s32 *func_003F1F90(void *, s32);

s32 func_003F25D0(void *p, s32 index)
{
    s32 *e;
    s32 i;
    s32 lim;
    s32 n;

    n = index;
    e = func_003F1F90(p, 0x10000);
    if (e != 0) {
        e = (s32 *)((char *)e + 12);
        if (0 < n) {
            i = 0;
            if (n >= 9) {
                lim = n - 8;
                do {
                    e = (s32 *)((char *)e + 4 + (*e << 3));
                    e = (s32 *)((char *)e + 4 + (*e << 3));
                    e = (s32 *)((char *)e + 4 + (*e << 3));
                    e = (s32 *)((char *)e + 4 + (*e << 3));
                    e = (s32 *)((char *)e + 4 + (*e << 3));
                    e = (s32 *)((char *)e + 4 + (*e << 3));
                    e = (s32 *)((char *)e + 4 + (*e << 3));
                    e = (s32 *)((char *)e + 4 + (*e << 3));
                    i += 8;
                } while (i < lim);
            }
            for (; i < n; i++)
                e = (s32 *)((char *)e + 4 + (*e << 3));
        }
        return *e;
    }
    return -1;
}
