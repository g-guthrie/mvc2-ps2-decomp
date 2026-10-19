typedef signed int s32;
typedef unsigned int u32;

extern s32 *func_003F1F90(void *, s32);

s32 func_003F2920(void *p, s32 index, s32 sub)
{
    s32 *e;
    s32 i;

    e = func_003F1F90(p, 0x20000);
    if (e == 0)
        return 0;
    e = (s32 *)((char *)e + 12);
    i = 0;
    if (index > 0) {
        if (index >= 9) {
            s32 lim = index - 8;
            do {
                e = (s32 *)((char *)e + 4 + (*e << 2));
                e = (s32 *)((char *)e + 4 + (*e << 2));
                e = (s32 *)((char *)e + 4 + (*e << 2));
                e = (s32 *)((char *)e + 4 + (*e << 2));
                e = (s32 *)((char *)e + 4 + (*e << 2));
                e = (s32 *)((char *)e + 4 + (*e << 2));
                e = (s32 *)((char *)e + 4 + (*e << 2));
                e = (s32 *)((char *)e + 4 + (*e << 2));
                i += 8;
            } while (i < lim);
        }
        while (i < index) {
            e = (s32 *)((char *)e + 4 + (*e << 2));
            i++;
        }
    }
    if ((u32)*e < (u32)sub)
        return 0;
    return *(s32 *)((char *)e + 4 + (sub << 2));
}
