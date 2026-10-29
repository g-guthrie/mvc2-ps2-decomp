typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

/* CRI ADX 4-bit block decoder with scale-key decryption (mono, 32 samples per block). */
extern s32 gAdxSignedNibbleTable_004BADB8[16]; /* signed low-nibble table */

s32 func_003FA728(u8 *p, s32 n, s16 *out, s16 *st, s16 c1, s16 c2, u16 *pred, s16 c3, s16 c4) {
    s32 i;
    u8 *q = p;
    s32 h1 = st[0];
    s32 h2 = st[1];
    for (i = 0; i < n; i++) {
        s16 h = (*(u16 *)q << 8 & ~0xFF) | q[1];
        s32 k, d, s, b, t, x;
        if (h & 0x8000) return i;
        q += 2;
        k = ((h ^ *pred) & 0x1FFF) + 1;
        *pred = ((s16)*pred + k) * c3 + c4;
        for (d = 0; d < 32; d += 2) {
            x = *q++;
            b = (s8)x;
            t = b >> 4;
            s = ((c1 * h1 + c2 * h2) >> 12) + t * k;
            if ((u32)(s + 0x8000) > 0xFFFF) {
                if (s < -0x8000) s = -0x8000;
                else if (s > 0x7FFF) s = 0x7FFF;
            }
            h2 = h1;
            h1 = s;
            *out++ = s;
            b = gAdxSignedNibbleTable_004BADB8[b & 0xF];
            s = ((c1 * h1 + c2 * h2) >> 12) + b * k;
            if ((u32)(s + 0x8000) > 0xFFFF) {
                if (s < -0x8000) s = -0x8000;
                else if (s > 0x7FFF) s = 0x7FFF;
            }
            h2 = h1;
            h1 = s;
            *out++ = h1;
        }
    }
    st[0] = h1;
    st[1] = h2;
    return n;
}
