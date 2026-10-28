typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

static void func_003BB8F0(u8 *p) { p[4]++; p[5] = 0; p[6] = 0; p[316] = 1; }
static void func_003BB910(u8 *p) { p[4]++; p[5] = 1; p[6] = 0; p[316] = 1; }

void func_003BBCD0(u8 *p) {
    extern void func_003BD7B0(u8 *);
    extern void func_003BA2C0(u8 *);
    extern s32 func_003BD1D0(u8 *);
    extern void func_00175700(u8 *);
    u8 *o;
    u8 *r;
    u8 *q;
    u8 *a;
    u32 t;
    q = p + 0xD0;
    func_003BD7B0(p);
    o = *(u8 **)(p + 0x18);
    r = o + 0x2B8;
    if ((t = p[6]) == 0) {
        p[6] = t + 1;
        func_003BA2C0(p);
    }
    if (r[3] == 0 || o[0x425] != 0) {
        func_003BB8F0(p);
        return;
    }
    a = *(u8 **)q;
    *(f32 *)(p + 0x34) = *(f32 *)(a + 0x34);
    if (a[5] != 3) {
        func_003BB910(p);
    } else if ((t = a[0x247]) == 9 || t == 0x17) {
        *(s16 *)(a + 0x1F8) = 2;
        a[0x24D] = 2;
        if (func_003BD1D0(p) != 0) {
            func_003BB910(p);
        } else {
            func_00175700(p);
        }
    } else {
        func_003BB910(p);
    }
}
