typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s16 D_00448800[];
typedef struct { u8 pad[0x428]; u32 f428; u32 f42C; } SA;

u8 func_00187E00(u8 *p, u8 *q) {
    extern s32 func_0018AA50(u8 *, s32, s16 *, s32);
    extern s32 func_00186CE0(u8 *, s32);
    s16 m;
    s32 a0;

    if (*(u8 *)(*(s32 *)(p + 0x220) + 0x249) != 0) return 0;
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430) + (2.142857f * (f32)D_00448800[p[1]]) / 256.0f) return 0;
    if (func_0018AA50(p, 0x300, &m, 0) != 0) {
        *(u16 *)(q + 6) = *(u16 *)(p + 0x35E);
    } else {
        m = 0x800;
        if ((((SA *)p)->f42C & 0x84000) != 0) m = 0x3C00;
        if (((((SA *)p)->f428 & 0x100000) | (((SA *)p)->f42C & 0x200000)) != 0) m = 0xC00;
        if (q[0] == 0) {
            u32 t = *(s16 *)(p + 0x362) & m;
            *(s16 *)(q + 6) = t;
            if ((t & 0xFFFF) != 0) {
                q[1] = 0xF;
                q[0]++;
            }
            return 0;
        }
        {
            s8 v = *(s8 *)(q + 1) - 1;
            s32 x;
            q[1] = v;
            if (v <= 0) {
                return q[0] = 0;
            }
            x = (u16)(*(s16 *)(p + 0x362) & m);
            if (x == 0) return 0;
            if ((u16)x != *(u16 *)(q + 6)) return 0;
        }
    }
    q[0] = 0;
    if (p[0x20D] != 2) return 0;
    if (p[5] != 0) return 0;
    if ((p[0x15A] & 0xE0) != 0) return 0;
    a0 = *(s8 *)(p + 0x1E9);
    if (a0 != 0) return 0;
    if (p[0x1E4] == 0x1A) return 0;
    if (p[0x1E4] == 0x13) return 0;
    if (p[0x1E4] == 0x15) return 0;
    if (p[0x1E4] == 0x1D) return 0;
    if (p[0x1E4] == 0x1B) return 0;
    if (p[0x1E4] == 0x1C) return 0;
    if (p[0x215] == 0) p[0x1E9] = a0 + 1;
    m = 0x800;
    if ((((SA *)p)->f42C & 0x84000) != 0) m = 0x3C00;
    if (((((SA *)p)->f428 & 0x100000) | (((SA *)p)->f42C & 0x200000)) != 0) m = 0xC00;
    p[0x22] = (*(u16 *)(q + 6) & (u16)m) >> 10;
    return func_00186CE0(p, 0x1A);
}
