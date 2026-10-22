typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 p0[0x14]; u32 f14; u32 p1; u32 f1c; } DA;
typedef struct { u32 p0[1]; u32 f4; } DB;
typedef struct { u8 p0[0x14]; u32 f14; u32 p1; u32 *f1c; } DC;
typedef struct { u8 p0[0x14]; DA *a14; u32 p1; DB *a1c; } DD;
typedef struct { u8 p0[0x1C]; s16 h1C; s16 h1E; u8 p1[0x64]; DC *f84; u8 p2[0x44]; s16 hCC; } P1;
typedef struct { P1 *p; s32 z; } SB;

extern DD *D_004C2824;
extern void func_0013E0F0(P1 *);
extern void func_0013E570(void);
extern void func_00170E60(u32, u32, u32, u32, void *, u32);

void func_0013E4D0(P1 *p)
{
    SB s;
    DC *c;
    DD *d;
    SB *q;
    s16 t = p->h1C;
    if (t != 0x3C) {
        p->h1C = t + 1;
        func_0013E0F0(p);
    }
    p->h1E += 0x14;
    if (p->h1E >= 0x168) p->h1E = 0;
    c = p->f84;
    d = D_004C2824;
    q = &s;
    s.p = p;
    s.z = 0;
    func_00170E60((u32)d->a14, d->a1c->f4, c->f14, c->f1c[p->hCC], (void *)func_0013E570, (u32)q);
}
