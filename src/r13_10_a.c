/* func_00404720: EE GCC 2.96, ./tryee.sh <src> sn 0 O2 */
/* EE GCC 2.96: ./tryee.sh <src> sn 0 O2 -fno-gcse ; 57/145 words differ (D_ hi not shared, blez slot fill, tail sched) */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    s8 flag;
    u8 pad1;
    u8 b2;
    u8 b3;
    u32 w4;
    u8 pad8[4];
    u32 a0C[32];
    u32 w8C;
    u32 a90[32];
    u32 w110;
    u32 w114;
    u32 w118;
    u32 w11C[32];
    u32 w19C;
    u32 w1A0;
    u32 w1A4;
    u8 b1A8;
    u8 b1A9;
    u8 pad1AA[2];
    u32 w1AC;
    u32 w1B0;
    u32 w1B4;
    u32 w1B8;
    u32 w1BC;
} Slot;

extern Slot D_00485880[];

extern void *func_0011D8F8(void *, s32, s32);
extern u32 func_00401150(s32, s32, s32);
extern u32 func_0040F5E0(u32, u32, u32);
extern u32 func_004051B8(s32, u32, u32 *);
extern void func_00404968(Slot *);

Slot *func_00404720(s32 n, s32 idx, s32 size, s32 total) {
    s32 i, k, blk, rem;
    Slot *s;
    u32 v, base;
    s32 ca, cb;

    base = (size + 0x3F) & -0x40;
    rem = total - (base - size);
    blk = (idx * 259 * 64 + 0x7F) & -0x40;
    for (i = 0; i < 4; i++) {
        if (D_00485880[i].flag == 0) break;
    }
    if (i == 4) return 0;
    s = &D_00485880[i];
    func_0011D8F8(s, 0, 0x1C0);
    s->b2 = idx;
    ca = 0x2000; cb = 0x40;
    s->w19C = ca;
    s->w1A0 = cb;
    k = 0;
    if (n > 0) {
    do {
        v = func_00401150(idx, base, blk);
        s->a0C[k] = v;
        base += blk;
        if (v == 0) goto fail;
        rem -= blk;
        s->w11C[k] = base;
        rem -= ca + cb;
        base += ca + cb;
        if (rem < 0) goto fail;
        v = func_0040F5E0(s->w11C[k], s->w19C, s->w1A0);
        s->a90[k] = v;
        if (v == 0) {
            func_00404968(s);
            goto fail;
        }
    } while (++k < n);
    }
    s->w110 = base;
    {
        s32 x = (rem - 0x2000) / 0x800 * 0x800;
        cb = 0x2000;
        s->w118 = cb;
        s->w114 = x;
        v = func_0040F5E0(base, x, cb);
        s->w8C = v;
        if (v == 0) goto fail;
        v = func_004051B8(n, v, s->a90);
        s->w4 = v;
        if (v == 0) goto fail;
    }
    s->b3 = n;
    s->w1A4 = 0;
    s->b1A8 = 0;
    s->b2 = idx;
    s->w1AC = 0;
    s->b1A9 = 1;
    s->w1B4 = 0;
    s->w1B0 = 0;
    s->w1B8 = 0;
    s->w1BC = 1;
    s->flag = 1;
    return s;
fail:
    func_00404968(s);
    return 0;
}
