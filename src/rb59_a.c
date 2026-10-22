typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0021FEB0(u8 *p)
{
    extern void func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern u8 *func_003556D0(u8 *, s32);
    u8 *q;
    s16 n, k, m;
    f32 f, c;
    u8 *e;
    s32 t;

    q = p + 0x2B8;
    p[0x40C] = 2;
    p[0x33C] = 5;
    *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) - 1;
    if (*(s16 *)(p + 0x1C) <= 0) {
        u32 b = p[6];
        p[6] = b + 1;
        *(s16 *)(p + 0x1C) = 0x38;
        func_001757E0(p, 0x15, 0x10);
        return;
    }
    func_00175700(p);
    {
        s32 d = q[0x14];
        q[0x14] = d - 1;
    }
    if (*(s8 *)(q + 0x14) > 0) return;
    q[0x14] = 12;
    f = -13.333333015441895f;
    if (p[0x1E6] != 0) f = -f;
    q[0x28] = q[0x28] + 1;
    m = ((*(s8 *)(q + 0x28) & 1) != 0) ? 4 : 0;
    for (n = 0, k = 0; k < 4; k++) {
        s32 h = *(s16 *)(p + 0x1E);
        e = func_003556D0(p, (h / 2) & 0xFF);
        if (e == 0) break;
        *(f32 *)(e + 0x34) = f + *(f32 *)(p + 0x34);
        c = 227.14285278320312f;
        *(f32 *)(e + 0x38) = c + *(f32 *)(p + 0x38);
        *(s16 *)(e + 0x1E) = m;
        e[0x22] = (*(s8 *)(p + 0x1E) + n) & 0x1F;
        n += 8;
    }
    if (p[0x1E6] != 0)
        *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1E) - 2;
    else
        *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1E) + 2;
    *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1E) & 0x1F;
}
