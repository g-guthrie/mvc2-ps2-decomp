/* func_003FA910: EE GCC 2.96, ./tryee.sh <src> sn (default -O2 -G0). Needs D_004BADB8 in symbol_addrs. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern s32 D_004BADB8[];

#define CLAMP16(x) { if ((u32)((x) + 0x8000) > 0xFFFF) { if ((x) < -0x8000) (x) = -0x8000; else if ((x) > 0x7FFF) (x) = 0x7FFF; } }

s32 func_003FA910(u8 *src, s32 n, s16 *outL, s16 *stL, s16 *outR, s16 *stR,
                  s16 k1, s16 k2, u16 *key, s16 mul, s16 add)
{
    s32 half;
    s32 i, j;
    s32 a, b, c, d;
    s32 h, sl, sr;
    s32 v, w, x;
    s32 kv;
    s32 vl, wl;
    s32 wh;
    s32 *tbl;

    half = n / 2;
    a = stL[0];
    b = stL[1];
    c = stR[0];
    d = stR[1];
    for (i = 0; i < half; i++) {
        h = (s16)(((*(u16 *)src << 8) & ~0xFF) | src[1]);
        if (h & 0x8000)
            return i * 2;
        sl = ((h ^ *key) & 0x1FFF) + 1;
        kv = ((s16)*key + sl) * mul + add;
        *key = kv;
        h = (s16)(((*(u16 *)(src + 0x12) << 8) & ~0xFF) | src[0x13]);
        if (h & 0x8000)
            return i * 2;
        sr = ((h ^ kv) & 0x1FFF) + 1;
        *key = ((s16)kv + sr) * mul + add;
        src += 2;
        tbl = D_004BADB8;
        for (j = 0; j < 0x20; j += 2) {
            v = src[0] << 24;
            w = src[0x12] << 24;
            wl = w >> 24;
            src++;
            x = ((k1 * a + k2 * b) >> 12) + (v >> 28) * sl;
            vl = v >> 24;
            wh = w >> 28;
            CLAMP16(x);
            b = a;
            a = x;
            x = ((k1 * c + k2 * d) >> 12) + wh * sr;
            CLAMP16(x);
            d = c;
            c = x;
            x = (a + c) * 7 / 10;
            CLAMP16(x);
            *outR++ = x;
            *outL++ = x;
            vl = tbl[vl & 0xF];
            x = ((k1 * a + k2 * b) >> 12) + vl * sl;
            wl = tbl[wl & 0xF];
            CLAMP16(x);
            b = a;
            a = x;
            x = ((k1 * c + k2 * d) >> 12) + wl * sr;
            CLAMP16(x);
            d = c;
            c = x;
            x = (a + c) * 7 / 10;
            CLAMP16(x);
            *outR++ = x;
            *outL++ = x;
        }
        src += 0x12;
    }
    stL[0] = a;
    stL[1] = b;
    stR[0] = c;
    stR[1] = d;
    return n;
}
