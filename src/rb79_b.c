typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3_140110;
typedef struct { u8 pad0[0xA]; s16 s0a; } G_140110;
typedef struct {
    u8 pad0[4];
    u8 state;
    u8 pad5[0x17];
    s16 s1c;
    s16 s1e;
    u8 b20;
    u8 pad21[0x13];
    V3_140110 v34;
    u8 pad40[0x10];
    V3_140110 v50;
    u8 pad5c[0x1C];
    f32 f78, f7c, f80;
} O_140110;

extern s32 D_004B1D18[];
extern V3_140110 D_00440920[];
extern V3_140110 D_00440AD0[];
extern G_140110 *D_004C2840;
extern void func_003DAA40(void);

void func_00140110(O_140110 *p)
{
    s32 n;
    s32 i;
    V3_140110 *a, *c, *b, *d;
    s16 t;
    switch (p->state) {
    case 0:
        n = D_004B1D18[p->s1e];
        i = p->s1e + p->b20 * 3;
        a = &D_00440920[i];
        b = &D_00440920[i + 1];
        c = &D_00440AD0[i];
        d = &D_00440AD0[i + 1];
        p->v34.x += (b->x - a->x) / (f32)n;
        p->v34.y += (b->y - a->y) / (f32)n;
        p->v34.z += (b->z - a->z) / (f32)n;
        p->v50.x += (d->x - c->x) / (f32)n;
        p->v50.y += (d->y - c->y) / (f32)n;
        p->v50.z += (d->z - c->z) / (f32)n;
        t = p->s1c + 1;
        p->s1c = t;
        if (t < n) return;
        p->s1c = 0;
        p->v34 = *b;
        p->v50 = *d;
        t = p->s1e + 1;
        p->s1e = t;
        if ((u32)t < 2) return;
        p->state++;
        p->v50.z = 0;
        break;
    case 1:
        if (D_004C2840->s0a < 0x15E) return;
        p->state++;
        p->f78 = 1.0f;
        p->f7c = 1.0f;
        p->f80 = 1.0f;
        break;
    case 2:
        p->f78 -= 0.02500000037252903f;
        p->f7c -= 0.02500000037252903f;
        p->f80 -= 0.02500000037252903f;
        if (D_004C2840->s0a < 0x186) return;
        func_003DAA40();
        break;
    }
}
