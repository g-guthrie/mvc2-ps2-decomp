typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

typedef struct O {
    u8 pad0[0x34];
    V3 v34;
    u8 pad40[0x50 - 0x40];
    f32 f50;
    f32 f54;
    u8 pad58[0x14C - 0x58];
    u8 b14C;
    u8 b14D;
    u8 b14E;
} O;

extern s8 D_004D1917[];
extern s32 fptosi(f32);

void func_0015B200(O *a, V3 *pos, u8 n, u16 flags)
{
    extern s32 func_00417A40(void);
    extern void func_0015B000(O *, V3 *, f32, s32, s32, u16);
    extern void func_0015AD80(O *, V3 *, f32, s32, s32, u16);
    extern void func_0015AA90(O *, V3 *, f32, s32, s32, u16);
    extern void func_0015A720(O *, V3 *, f32, s32, s32, u16);
    V3 t;
    s32 i;
    s32 r;
    s32 v;
    s32 m;
    s32 w;
    u32 fl;
    f32 x;
    if (D_004D1917[0] >= 7) return;
    if (D_004D1917[0] + n > 6) {
        n = 6 - D_004D1917[0];
    }
    D_004D1917[0] += (s8)n;
    for (i = 0; i < n; i++) {
        fl = flags;
        m = n;
        if (fl & 2) {
            t = a->v34;
            r = func_00417A40();
            v = fptosi(1.6666666269302368f * (f32)(u32)a->b14E * a->f50);
            if (r % 2 != 0) w = r % v;
            else w = -(r % v);
            t.x += (f32)w;
            r = func_00417A40();
            v = fptosi(2.142857074737549f * (f32)(u32)a->b14C * a->f54);
            t.y += (f32)(r % v);
            if (fl & 4) {
                x = (func_00417A40() % 2 != 0) ? 1.0f : 1.5f;
            } else if (fl & 0x100) {
                x = 1.5f;
            } else if (fl & 0x400) {
                x = 0.6000000238418579f;
            } else {
                x = 1.0f;
            }
            if (fl & 0x200) x *= 10.0f;
            func_0015B000(a, &t, x, m, i, flags);
            func_0015AD80(a, &t, x, m, i, flags);
            func_0015AA90(a, &t, x, m, i, flags);
            func_0015A720(a, &t, x, m, i, flags);
        } else {
            if (fl & 4) {
                x = (func_00417A40() % 2 != 0) ? 1.0f : 1.5f;
            } else if (fl & 0x100) {
                x = 1.5f;
            } else if (fl & 0x400) {
                x = 0.6000000238418579f;
            } else {
                x = 1.0f;
            }
            if (fl & 0x200) x *= 10.0f;
            func_0015B000(a, pos, x, m, i, flags);
            func_0015AD80(a, pos, x, m, i, flags);
            func_0015AA90(a, pos, x, m, i, flags);
            func_0015A720(a, pos, x, m, i, flags);
        }
    }
}
