/* func_0018F320: MW 3.0.3 -O3 -sdatathreshold 0 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[0x34];
    f32 f34;
    f32 f38;
    u8 pad3c[0x5C - 0x3C];
    f32 f5c;
    f32 f60;
    u8 pad64[4];
    f32 f68;
    f32 f6c;
    u8 pad70[0x234 - 0x70];
    f32 f234;
    f32 f238;
} S18F;

void func_0018F320(u8 *p)
{
    extern void func_0018F460(u8 *);
    S18F *s = (S18F *)p;
    f32 z;
    s8 v;
    u8 *q;

    if ((*(u16 *)(p + 0x1C2) & 0x1010) != 0) {
        if (*(u8 **)(p + 0x1C8) == *(u8 **)(p + 0x1CC)) {
            (*(u8 **)(p + 0x1CC))[0x209] = 3;
        }
    }
s->f234 += s->f238; z = 0.0f; if (s->f238) { if (!(s->f238 * s->f234 <= z)) { s->f238 = z; s->f234 = z; } }    v = p[0x211];
    if (v != 0 && p[0x249] == 0 && ((*(u8 **)(p + 0x1D0))[1] & 0x80) == 0
        && ((p[0x242] + 1) & 0x1F) > 2) {
        q = *(u8 **)(p + 0x1CC);
        if (q == 0) q = *(u8 **)(p + 0x220);
        if (((s8)v ^ 3) != (s8)q[0x211]) {
            ((S18F *)q)->f34 -= s->f234;
        }
    }
    s->f34 += s->f5c;
    s->f5c += s->f68;
    s->f38 += s->f60;
    s->f60 += s->f6c;
    func_0018F460(p);
}

