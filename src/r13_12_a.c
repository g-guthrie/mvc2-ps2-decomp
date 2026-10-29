/* func_00422150: one record of the menu text byte code (header codes until
 * code 1, then one glyph per byte, drawn by func_00421FB0).
 * Built like its caller func_004220B0 (src/s9a_b.c) with opt_propagation off:
 * that keeps the int texture size 512 a variable, so retail's runtime
 * li 0x200 / cvt.s.w / mov.s divisor pair comes out. */
#pragma opt_propagation off

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s32 a, b, c, d; } R4;
typedef struct { f32 a, b, c, d; } F4;

extern s32 D_004C2BA4;
extern s32 D_004C2BA8;
extern s32 D_004C2BAC;
extern s32 D_004C2BB0;
extern u8 D_004F7F52[];
extern s32 D_0057FB70[];
extern R4 D_004A7F80[];
extern R4 D_004A6F80[];

static inline void set_uv(F4 *uv, R4 *r, s32 w, s32 h)
{
    uv->b = (f32)r->b / (f32)w;
    uv->a = (f32)r->a / (f32)h;
    uv->c = (f32)r->c / (f32)w;
    uv->d = (f32)r->d / (f32)h;
}

#define RD() p[(*pos)++]

s32 func_00422150(u8 *p, s32 *pos, s32 x, s32 y, f32 f)
{
    extern void func_00422BE0(u32 *, s32);
    extern void func_00421FB0(s32, R4 *, F4 *, u32, f32);
    s32 done;
    s32 adv;
    s32 sx, sy;
    u8 cr, cg, cb, ca;
    s32 tex;
    s32 space;
    u8 op;
    s32 off;
    s32 w, h;
    s32 W, H;
    u32 v, lo;
    f32 sc;
    R4 r;
    F4 uv;
    R4 t;
    u32 col;

    done = 0;
    adv = 0;
    ca = cb = cg = cr = 0xFF;
    space = RD();
    for (;;) {
        if (done) break;
        switch (RD()) {
        case 11:
            tex = RD();
            break;
        case 12:
            RD();
            RD();
            break;
        case 5:
            adv = RD();
            break;
        case 1:
            v = RD(); lo = RD(); D_004C2BB0 = lo + (v << 8);
            sx = D_004C2BB0;
            v = RD(); lo = RD(); D_004C2BAC = lo + (v << 8);
            sy = D_004C2BAC;
            v = RD();
            sc = (f32)v / 256.0f;
            done = 1;
            break;
        case 6:
            cr = RD();
            break;
        case 7:
            cg = RD();
            break;
        case 8:
            cb = RD();
            break;
        case 9:
            ca = RD();
            break;
        case 0:
        case 2:
        case 3:
        case 4:
        case 10:
            break;
        }
    }
    sx += x;
    sy += y;
    W = 512; H = 512;
    if (sc != -1.0f) sc = f;
    for (;;) {
        op = RD();
        if (op == 1) {
            v = RD();
            lo = RD();
            D_004C2BB0 = lo + (v << 8);
            sx = D_004C2BB0;
            (*pos)++;
            (*pos)++;
            (*pos)++;
        } else if (op == 5) {
            sx += adv;
        } else if (op == 13) {
            sx += 8;
        } else if (op == 0) {
            D_004C2BA4 = 0;
            D_004C2BA8 = 0;
            D_004C2BAC = 0;
            D_004C2BB0 = 0;
            break;
        } else if (op == 4) {
            v = RD();
            v = D_004C2BA8 + v;
            D_004C2BA4 = 0;
            D_004C2BA8 = 0;
            sy += v;
        } else {
            off = 0;
            switch (op) {
            case 10:
                r = D_004A7F80[RD()];
                set_uv(&uv, &r, W, H);
                break;
            default:
                if (op == 0x3A) off = -2;
                r = D_004A6F80[op];
                set_uv(&uv, &r, W, H);
                break;
            }
            t = r;
            w = t.c - t.a;
            h = t.d - t.b;
            r.a = sx + D_004C2BA4;
            r.b = sy + off;
            r.c = r.a + w;
            r.d = r.b + h;
            D_004C2BA4 += w + space;
            if (D_004C2BA8 < h) D_004C2BA8 = h;
            col = (cr << 24) | (cg << 16) | (cb << 8) | ca;
            if (D_004F7F52[0] != 0) func_00422BE0(&col, (u8)D_004F7F52[0] + 0x60);
        func_00421FB0(D_0057FB70[tex], &r, &uv, col, sc);
        }
    }
    return 0;
}


