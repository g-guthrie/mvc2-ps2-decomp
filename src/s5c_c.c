/* MW 3.0, compiled in the same mwccps2 invocation after src/e080_b.c (soft-float warm): -O3 -Op -fp off -sdatathreshold 0 */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct O6940 {
    u8 pad0[0xC];
    struct O6940 *n;
    u8 pad10[0xC];
    s16 h1C;
    s16 h1E;
    u8 pad20[2];
    u8 b22;
    u8 pad23[0x3D];
    f32 f60;
    f32 f64;
    u8 pad68[4];
    f32 f6C;
} O6940;

s32 func_001A6940(O6940 *p, O6940 *q) {
    extern s32 func_001A6A70();
    O6940 *o;
    s32 i;
    s32 r;
    s32 n;
    u8 *c;
    f32 z, x, y;
    s16 h;
    c = (u8 *)p;
    p->b22 = q->b22;
    h = p->h1C;
    r = 1;
    if (h != 0) {
        ((O6940 *)c)->h1C = h - 1;
        n = ((O6940 *)c)->h1E;
        for (i = 1; i < n; i++) {
            o = ((O6940 *)c)->n;
            z = 0.0f;
            o->f60 += o->f64;
            x = ((O6940 *)c)->f6C + o->f60;
            o->f6C = x;
            if (x < z) {
                { f32 t = 256.0f; o->f6C = x + t; }
            }
            y = o->f6C;
            if (!(y < 256.0f)) {
                o->f6C = y - 256.0f;
            }
            o->b22 = ((((u8)(u32)o->f6C + 4) >> 3) + q->b22) & 0x1F;
            c = (u8 *)o;
        }
    } else {
        r = func_001A6A70(p);
    }
    return r;
}
