typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* Metrowerks 3.0.3: ./try.sh src/w189_l.c "-O3 -Op -sdatathreshold 0" */
typedef struct E3 { u8 pad0[0x34]; f32 f34; } E3;
typedef struct R3 { u8 pad0[0x34]; f32 f34; u8 pad38[0x2B8 - 0x38]; E3 *p2B8; u8 pad2BC[0x2C6 - 0x2BC]; u8 b2C6; u8 pad2C7[0x428 - 0x2C7]; u32 w428; } R3;
typedef struct Q3 { u8 pad0[5]; u8 b5; u8 b6; u8 pad7[0x140 - 7]; s16 h140; u8 pad142[0x1DC - 0x142]; R3 *p1DC; u8 pad1E0[0x1E4 - 0x1E0]; u8 b1E4; } Q3;
typedef struct P3 { u8 pad0[0x14]; E3 *p14; Q3 *p18; s16 h1C; s16 h1E; } P3;
extern void func_00329430();
extern void func_00175C00();
void func_00329310(P3 *p) {
    Q3 *q = p->p18;
    R3 *r;
    E3 **pp;
    f32 f;
    u32 t;
    s16 v;
    s16 w;
    if (q->b5 != 0) goto bad;
    if (q->b1E4 != 0x15) goto bad;
    t = q->b6;
    if (t == 9) goto good;
    if (t == 10) goto good;
bad:
    func_00329430(p);
    return;
good:
    v = p->h1C + 1;
    p->h1C = v;
    if (v & 1) {
        f = 3.3333332538604736f;
        if (q->h140 != 0) f = -f;
        r = q->p1DC;
        if (r->w428 & 0x800) {
            pp = &r->p2B8;
            if (r->b2C6 == 0) {
                (*pp)->f34 += f;
            }
        }
        r->f34 += f;
        if (p->p14 != 0) p->p14->f34 += f;
    }
    w = p->h1E - 1;
    p->h1E = w;
    if (w <= 0) {
        p->h1E = 4;
        func_00175C00(r, 5);
    }
}
