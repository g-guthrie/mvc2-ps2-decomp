typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { s32 a, b, c; } NfRec;
typedef struct { u8 pad0[0x34]; s32 f34; u8 pad1[0x10]; s32 f48; s32 f4C; } NfG;

extern u8 D_004BF3E8[2];
extern NfRec D_00443D10[];
extern NfG D_004D1770;

void residual_00149B90(u8 *p)
{
    extern void func_00149CF0(u8 *);
    extern void func_00149EB0(u8 *, s32, s32, s32, NfRec *);
    extern u8 *func_00149D70(s32, s32, NfRec *);
    NfG *g;
    NfRec *q;
    u8 *o;
    s32 h;
    s32 v;
    u32 t;

    g = &D_004D1770;
    t = p[4];
    p[4] = t + 1;
    h = *(s16 *)(p + 0x1C);
    q = D_00443D10 + D_004BF3E8[h >> 8];
    switch (h) {
    case 0x300:
    case 0x100:
        func_00149EB0(p, g->f48, 4, 1, q);
        if (*(s16 *)(p + 0x1C) == 0x100)
            break;
        q = (NfRec *)((u8 *)q + 0x30);
    case 0x200:
        func_00149EB0(p, g->f4C, 4, 2, q);
        break;
    case 0x400:
    case 0x500:
        v = g->f34;
        o = func_00149D70(p[0x20], (v / 2) + 0x11, q++);
        if (o != 0)
            o[0x21] = 3;
        o = func_00149D70(p[0x20], (g->f34 & 1) + 4, q);
        if (o != 0)
            o[0x21] = 3;
        break;
    default:
        break;
    }
    func_00149CF0(p);
}
