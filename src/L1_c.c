typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004F1FC8;
extern f32 D_004F1FCC;

typedef struct {
    u8 pad0[0x34];
    f32 f34;
    f32 f38;
    u8 pad3C[0x20];
    f32 f5c;
    f32 f60;
    u8 pad64[4];
    f32 f68;
    f32 f6c;
} O236;

void func_00236EE0(u8 *a, u8 *b)
{
    extern void func_00175700(), func_001757E0(), func_00184540();
    O236 *o = (O236 *)a;
    f32 t, v, z, c, d;
    s32 m;
    f32 *p5c, *p60, *p6c, *p68;
    s32 n;
    a[0x40C] = 2;
    a[0x33C] = 5;
    a[0x405] = (a[0x269] == 6) ? 2 : 0;
    func_00175700(a);
    if (a[0x15B] != 0) {
        a[0x15B] = 0;
        a[0x20D] = 2;
        c = 13.333333015441895f;
        t = c + D_004F1FC8;
        if (a[0x1E6] == 0) t = D_004F1FCC - c;
        o->f5c = (t - o->f34) / 32.0f;
        v = 12.857142448425293f;
        o->f68 = 0.0f;
        if (a[0x20] != 0) v = 8.571428298950195f;
        o->f60 = v;
        o->f6c = -0.5357142686843872f;
    }
    p5c = &o->f5c;
    p68 = &o->f68;
    p60 = &o->f60;
    p6c = &o->f6c;
    z = 0.0f;
    o->f34 += o->f5c;
    o->f5c += o->f68;
    o->f38 += o->f60;
    o->f60 += o->f6c;
    if (o->f60 < z) {
        *p60 = z;
        *p6c = z;
    }
    n = *(s16 *)(a + 0x1C) - 1;
    *(s16 *)(a + 0x1C) = n;
    if ((s16)n == 0) {
        m = (s8)a[0x211];
        if (m == 0) {
            if (o->f5c < 0.0f) m = 2;
            else m = 1;
        }
        if (m & (1 << a[0x1E6])) {
            u32 w = a[7];
            a[7] = w + 1;
            b[0x1B] = m;
            b[0x1D] = m;
            *p5c = 0.0f;
            *p60 = 0.0f;
            *p68 = 0.0f;
            *p6c = 0.0f;
            func_001757E0(a, 0x16, 0xA);
        } else {
            func_00184540(a);
        }
    }
}
