typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef struct { u8 *w; u16 h; u8 b6; u8 b7; } E169;
typedef struct {
    u8 pad0[0x198];
    u8 *t[182];
    u8 x470;
    u8 pad471[3];
    E169 e[4];
} P169;

void func_00169E50(P169 *p, s32 a, s32 i)
{
    extern s32 func_00174170();
    extern void func_00169C90(P169 *);
    u8 *s;
    u8 *base;
    u8 *tab;
    s32 off;
    u8 b;
    E169 *q;
    u8 **tt;
    tt = p->t;
    base = s = tt[i];
    if (i == 2) {
        s += (a - 2) * 12;
        off = *(s32 *)(s + 4);
    } else {
        off = *(s32 *)(*(s32 *)(s + 4) + (s32)s + p->x470 * 4);
    }
    tab = (u8*)(u32)base; tab = (u8*)((u32)off + (u32)tab);
    b = tab[func_00174170(tt) & 0x1F];
    q = p->e;
    q += i;
    q->w = base + *(s32 *)(*(s32 *)(s + 8) + (s32)base + b * 4);
    q->h = 0;
    q->b6 = b;
    q->b7 = 0;
    func_00169C90(p);
}
