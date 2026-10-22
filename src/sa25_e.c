typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { s32 seq; u8 data[0x28]; s32 f2C; s32 f30; s32 f34; s32 f38; s32 f3C; } Slot;
typedef struct { u8 pad0; s8 b1; u8 pad2[0x1A]; s32 head; s32 pad20; s32 cnt; u8 pad28[0x10]; Slot slots[16]; } Q;
extern char D_004BE2F8[];
extern char D_004BE320[];

s32 func_0040CE38(Q *q, u8 *src, s32 a2, s32 a3, s32 a4) {
    extern void func_0040D5A0(char *);
    extern void func_00120440(u8 *, u8 *, s32);
    Slot *s;
    s32 seq;
    s32 h;
    if (q == 0) {
        func_0040D5A0(D_004BE2F8);
        __asm__ volatile("");
        return -1;
    }
    if (q->cnt >= 16) return -1;
    if (src == 0) {
        func_0040D5A0(D_004BE320);
        return -1;
    }
    h = q->head;
    s = &q->slots[h];
    { s32 k; k = (h + 15) % 16; seq = q->slots[k].seq; }
    { s32 m = 0x7FFFFFFF; s32 t = seq; seq = t + 1; if (t == m) seq = 0; }
    s->seq = seq;
    func_00120440(s->data, src, 0x28);
    *(volatile s32 *)&s->f30 = a3;
    *(volatile s32 *)&s->f34 = a4;
    *(volatile s32 *)&s->f3C = 0;
    *(volatile s32 *)&s->f38 = 0;
    *(volatile s32 *)&s->f2C = a2;
    q->head = (q->head + 1) % 16;
    q->cnt++;
    if (q->b1 == 1) q->b1 = 2;
    return seq;
}
