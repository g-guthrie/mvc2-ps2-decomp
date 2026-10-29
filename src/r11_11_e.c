typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u32 addr; u32 size; u32 align; u32 pad; } Blk;
typedef struct { s32 n; u32 f4; Blk *tab; s32 dir; u32 top; u16 *idx; } Pool;

u32 func_003F0E60(Pool *h)
{
    extern void func_003F5710(u32, u32, u32);
    u32 g;
    u16 *list;
    s32 cnt;
    s32 n;
    s32 i;
    s32 j;
    s32 k;
    u32 a;
    Blk *e;
    Blk *f;
    u16 t;

    if (h->dir != 0) list = h->idx - h->n;
    else list = h->idx;
    cnt = 0;
    for (i = 0; i < h->n; i++) {
        if (h->tab[i].size != 0) list[cnt++] = i;
    }
    if (cnt == 0) {
        h->top = (u32)h->idx;
        return h->top;
    }
    n = cnt;
    if (h->dir != 0) {
        for (k = 0; k < n; k++, cnt--) {
            for (i = 0; i < cnt - 1; i++) {
                if (h->tab[list[i]].addr > h->tab[list[i + 1]].addr) {
                    t = list[i + 1];
                    list[i + 1] = list[i];
                    list[i] = t;
                }
            }
        }
        f = h->tab; e = (Blk *)((list[0] << 4) + (u32)f);
        { u32 s = (u32)h->idx + e->align - 1; a = s & ~(e->align - 1); }
        if (a != e->addr) {
            func_003F5710(a, e->addr, e->size);
            h->tab[list[0]].addr = a;
        }
        if (n < 2) {
            e = (Blk *)((u32)h->tab + (list[0] << 4));
            h->top = e->addr + e->size;
        } else {
            for (k = 1; k < n; k++) {
                e = &h->tab[list[k]];
                f = &h->tab[list[k - 1]];
                a = (f->addr + f->size + e->align - 1) & ~(e->align - 1);
                if (a != e->addr) {
                    func_003F5710(a, e->addr, e->size);
                    h->tab[list[k]].addr = a;
                }
            }
            h->top = h->tab[list[k - 1]].addr + h->tab[list[k - 1]].size;
        }
    } else {
        for (k = 0; k < n; k++, cnt--) {
            for (i = 0; i < cnt - 1; i++) {
                if (h->tab[list[i]].addr < h->tab[list[i + 1]].addr) {
                    t = list[i + 1];
                    list[i + 1] = list[i];
                    list[i] = t;
                }
            }
        }
        g = (u32)h->tab; g = (list[0] << 4) + g; e = (Blk *)g;
        { u32 s = (u32)h->idx - e->size; a = s & ~(e->align - 1); }
        if (a != e->addr) {
            func_003F5710(a, e->addr, e->size);
            h->tab[list[0]].addr = a;
        }
        if (n < 2) {
            h->top = (&h->tab[list[0]])->addr;
        } else {
            for (k = 1; k < n; k++) {
                e = &h->tab[list[k - 1]];
                f = &h->tab[list[k]];
                { u32 s = e->addr - f->size; a = s & ~(f->align - 1); }
                if (a != f->addr) {
                    func_003F5710(a, f->addr, f->size);
                    h->tab[list[k]].addr = a;
                }
            }
            h->top = (&h->tab[list[k - 1]])->addr;
        }
    }
    return h->top;
}
