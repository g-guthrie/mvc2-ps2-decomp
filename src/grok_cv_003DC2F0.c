typedef signed int s32;
typedef unsigned int u32;

extern s32 D_0062BFD8;
extern void func_0010CA20(void);
extern void *func_003DD030(void *);
extern void func_0010CA68(void);

s32 func_003DC2F0(void *item, s32 *base)
{
    s32 ret = -1;
    s32 off;
    s32 *slot;
    s32 *w;
    void *p;
    s32 idx;
    func_0010CA20();
    off = D_0062BFD8 * 4;
    slot = (s32 *)((char *)base + off);
    if ((u32)(base[1] - 1) >= (u32)slot[0x14 / 4]) {
        ret = 0;
        p = func_003DD030((void *)slot[0xC / 4]);
        slot[0x14 / 4] = slot[0x14 / 4] + 1;
        w = (s32 *)((char *)base + off);
        idx = w[0x1C / 4];
        w[0x1C / 4] = idx + 1;
        *(void **)((char *)p + idx * 4) = item;
        if (w[0x1C / 4] == base[1]) {
            s32 *c = w + (0x1C / 4);
            *c = 0;
        }
    }
    func_0010CA68();
    return ret;
}
