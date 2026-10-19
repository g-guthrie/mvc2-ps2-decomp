typedef signed int s32;

extern s32 *func_003F1F90(void *, s32);

void *func_003F26E0(void *p, s32 index, s32 sub)
{
    s32 *e;
    s32 i;

    e = func_003F1F90(p, 0x10000);
    if (e == 0)
        return 0;
    e = (s32 *)((char *)e + 12);
    i = 0;
    if (index > 0) {
        if (index >= 9) {
            s32 lim = index - 8;
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
        while (i < index) {
            e = (s32 *)((char *)e + 4 + (*e << 3));
            i++;
        }
    }
    if (sub >= *e)
        return 0;
    return (char *)e + 4 + (sub << 3);
}
