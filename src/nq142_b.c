typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x91]; s8 b91; u8 pad2[0x22]; s8 b4; } G32;
extern G32 *D_004C2840;
extern s8 D_004F7F3E[];
extern s8 D_004F8010[];
extern s8 D_004F8014[];
typedef struct { u16 h; u8 pad[18]; } E20;
extern E20 D_004F4484[];

typedef struct { s8 f0; s8 f1; s8 pad0[2]; s8 a[2]; s8 b[2]; s8 pad1[0x10]; s8 c; } P32;
extern s8 D_004F7F50[];

static void func_003D32A0(P32 *p, s32 i) {
    s32 f;
    if (D_004C2840->b4 != 0) return;
    if (!(p->f1 & (1 << i))) return;
    if (D_004F7F3E[0] != 0) return;
    if (*(s8 *)&((s32 *)D_004F8010)[i] == 1) {
        f = p->f0;
        if (f & 4) {
            if (p->a[i] != 0) return;
            if (f & (i + 1)) {
                p->b[i] = 2;
            } else {
                p->b[i] = 0;
            }
        } else {
            if (!(D_004F4484[i].h & 0x8000)) return;
            if (f & (i + 1)) {
                if (p->c != 0) return;
                p->b[i] = 0;
            } else {
                if (p->b[1 - i] == 2) return;
                p->b[i] = 2;
            }
        }
    } else {
        if (p->a[i] != 0) p->b[i] = 1;
    }
}

void func_003D33F0(void)
{
    extern void func_003D30A0(P32 *, s32);
    extern void func_003D31A0(P32 *);
    extern void func_003D33B0(P32 *);
    P32 *g;
    s32 f;

    g = (P32 *)D_004F7F50;
    func_003D32A0(g, 0);
    func_003D32A0(g, 1);
    if (D_004F7F50[0] == 0) {
        if (g->b[0] == 1 || g->b[1] == 1) {
            g->f0 |= 4;
            func_003D30A0(g, 0);
        } else {
            if (g->b[0] == 2) {
                g->f0 = 1;
                g->b[0] = 2;
                g->b[1] = 0;
                func_003D31A0(g);
            }
            if (g->b[1] == 2) {
                g->f0 = 2;
                g->b[0] = 0;
                g->b[1] = 2;
                func_003D31A0(g);
            }
        }
    } else {
        f = g->f0;
        if (f & 4) {
            if (g->b[0] != 1 && g->b[1] != 1) {
                g->f0 = f & 3;
                D_004C2840->b91 = 0;
                func_003D30A0(g, 1);
            }
        } else if (g->b[0] == 1 || g->b[1] == 1) {
            g->f0 |= 4;
            func_003D30A0(g, 0);
        } else if ((f == 1 && g->b[0] == 0) || (f == 2 && g->b[1] == 0)) {
            func_003D33B0(g);
        }
    }
    g->a[0] = (D_004F8010[0] == 1) ? 1 : 0;
    g->a[1] = (D_004F8014[0] == 1) ? 1 : 0;
}
