typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct N { u8 pad[0xC]; struct N *next; } N;
typedef struct R { u8 p0[5]; u8 b5; u8 p6[0x24-6]; s8 b24; u8 p25[0x34-0x25]; f32 f34; f32 f38; u8 p3c[0x1E4-0x3C]; u8 b1E4; u8 p1e5[0x1FD-0x1E5]; u8 b1FD; u8 b1FE; } R;
typedef struct Q { u8 p0[0xE]; u8 bE; u8 pf; f32 f10; f32 f14; f32 f18; f32 f1C; u8 p20[0x34-0x20]; u8 b34; u8 p35; u8 b36; } Q;
extern void (*D_00473A80[])();
void func_003AA8F0(u8 *p, Q *q) {
    extern void func_003ACC30();
    R *r; N *n; s32 i; u8 c;
    r = *(R **)(p + 0x18);
    if (r->b5 != 0) goto fail;
    c = r->b1E4;
    if (c == 0x15 && r->b1FD != q->b36) goto fail;
    if (c == 0x1D && r->b1FD != q->b36) goto fail;
    if (c != 0x15 && c != 0x1D) {
fail:
        func_003ACC30(p, q);
        return;
    }
    {
        r->b1FE = 1;
        q->bE = 0xE;
        q->f10 = r->f34 + q->f18;
        q->f14 = r->f38 + q->f1C;
        *(s8 *)(p + 0x24) = r->b24;
        p[0x13C] = 0;
        q->b34 = 0;
        n = (N *)p;
        for (i = 0; i < 14; i++) { n = n->next; ((u8 *)n)[0x13C] = 0; }
        D_00473A80[p[5]](p, q);
    }
}
