typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad[0x74]; f32 f74; f32 f78; f32 f7C; f32 f80;
} S152;
extern f32 D_004F1D0C;
extern f32 D_004F1D10;
extern f32 D_004F1D14;

void func_00152400(u8 *p)
{
    extern s32 func_00119098(f32);
    extern void func_003DF850(s32, u32);
    S152 *q = (S152 *)p;
    f32 sc = 1.0f;
    f32 r, g, b;
    u32 fl = *(u32 *)(p + 0xD0);
    u32 c;
    if (fl & 0x20) sc = q->f74;
    if (fl & 0x400) {
        if (fl & 0x800) {
            r = q->f78 * D_004F1D0C;
            g = q->f7C * D_004F1D10;
            b = q->f80 * D_004F1D14;
        } else {
            r = q->f78;
            g = q->f7C;
            b = q->f80;
        }
    } else if (fl & 0x800) {
        r = D_004F1D0C;
        g = D_004F1D10;
        b = D_004F1D14;
    } else {
        r = 1.0f;
        g = r;
        b = r;
    }
    c = (func_00119098(255.0f * sc) & 0xFF) << 24;
    c |= (func_00119098(255.0f * r) & 0xFF) << 16;
    { u32 t = func_00119098(255.0f * g); c = ((t & 0xFF) << 8) | c; }
    { u32 t = func_00119098(255.0f * b); func_003DF850(0x66, (t & 0xFF) | c); }
}
