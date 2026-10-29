/* Sony EE GCC 2.9: ./trysony29.sh src/r12_00_c.c 0 O2. Lever: one int variable (idx) reused for packet size, quad count and handler id; one pointer (s) reused for the copy cursor and the handler. */
typedef unsigned char u8;
typedef signed int s32;
typedef unsigned int u32;
typedef int u128 __attribute__((mode(TI)));
typedef void (*HFn)(void *, s32);
typedef struct { HFn fn; s32 arg; } HEnt;
typedef struct { u8 *buf; s32 pad4; s32 pad8; HEnt *tab1; s32 n1; HEnt *tab2; s32 n2; } HCtl;
extern HCtl D_004C3AD8;
extern void func_0010CA68(void);
extern s32 func_001041D0(void);
s32 func_00106450(s32 cause)
{
    u128 buf[7];
    HCtl *c;
    u8 *src;
    u128 *s, *d;
    s32 i, idx;
    HEnt *e;
    func_0010CA68();
    c = &D_004C3AD8;
    src = c->buf;
    idx = *(volatile u8 *)src;
    if (idx == 0)
        return 0;
    idx = (idx + 15) / 16;
    *(volatile u8 *)src = 0;
    s = (u128 *)src;
    if (idx > 0) {
        i = idx;
        d = buf;
        do {
            i--;
            *d++ = *s++;
        } while (i != 0);
    }

    func_001041D0();
    if (((volatile s32 *)buf)[2] < 0) {
        idx = ((volatile s32 *)buf)[2] & 0x7FFFFFFF;
        if (idx < c->n1) {
            e = (HEnt *)((idx << 3) + (u32)c->tab1);
            if ((s = (u128 *)e->fn) != 0)
                ((HFn)s)(buf, e->arg);
        }
    } else {
        idx = ((volatile s32 *)buf)[2];
        if (idx < c->n2) {
            e = (HEnt *)((idx << 3) + (u32)c->tab2);
            if ((s = (u128 *)e->fn) != 0)
                ((HFn)s)(buf, e->arg);
        }
    }
    __asm__ volatile("sync");
    __asm__ volatile("ei");
    return 0;
}
