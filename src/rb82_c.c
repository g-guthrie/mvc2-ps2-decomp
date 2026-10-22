typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct Obj Obj;
typedef struct { void *p; s32 n; } Buf;
typedef struct {
    u8 pad0[0x18];
    s32 (*f18)(Obj *, s32, s32, Buf *);
    s32 pad1C;
    void (*f20)(Obj *, s32, Buf *);
    s32 (*f24)(Obj *, s32);
} Vt;
struct Obj { Vt *vt; };

typedef struct {
    u8 pad0[4];
    Obj *b[2];
    Obj *a[2];
    s32 pos[2];
    s32 cnt;
    s32 w20;
    f32 m24;
    u8 pad28[4];
    s32 w2C;
} Ctx;

void func_003F6150(Ctx *ctx)
{
    Buf b1;
    Buf b2;
    s32 c, sz, per, nn, mx, done, half, k, v, lim;
    s16 *sp;

    c = 0;
    sz = (s32)((f32)ctx->w20 * ctx->m24);
    if (ctx->cnt > 0) {
        do {
            per = ctx->b[c]->vt->f24(ctx->b[c], 1);
            per = (per / 2) / sz;
            lim = ctx->a[c]->vt->f24(ctx->a[c], 0) / 16;
            if (per < lim) lim = per;
            if (lim > 0) {
                nn = lim;
                do {
                    done = 0;
                    mx = 0;
                    if (sz > 0) {
                        do {
                            ctx->b[c]->vt->f18(ctx->b[c], 1, (sz - done) * 2, &b1);
                            half = b1.n / 2;
                            sp = (s16 *)b1.p;
                            for (k = 0; k < half; k++) {
                                v = *sp++;
                                if (v < 0) v = -v;
                                if (mx < v) mx = v;
                            }
                            done += half;
                            ctx->b[c]->vt->f20(ctx->b[c], 0, &b1);
                        } while (done < sz);
                    }
                    ctx->a[c]->vt->f18(ctx->a[c], 0, 0x10, &b2);
                    if (b2.n == 0) {
                        for (;;) __asm__ volatile("nop");
                    }
                    ((s32 *)b2.p)[0] = mx;
                    ((s32 *)b2.p)[1] = ctx->pos[c];
                    ((s32 *)b2.p)[2] = ctx->w20;
                    ((s32 *)b2.p)[3] = sz;
                    ctx->a[c]->vt->f20(ctx->a[c], 1, &b2);
                    ctx->pos[c] += sz;
                    ctx->w2C++;
                } while (--nn);
            }
            c++;
        } while (c < ctx->cnt);
    }
}
