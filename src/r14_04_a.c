/* func_003FA1B0 / func_003FA448: EE GCC 2.96,
   ./tryee.sh <src> sn 8 O2 "" -mips4   (-mips4 on the SN assembler drops the mtc1 hazard nops).
   CRI ADX float-coefficient 4-bit decoders, stereo (two channels, 0x12-byte blocks each):
   func_003FA1B0 writes the two channels to separate buffers; func_003FA448 mixes them
   with a volume global into both buffers. Siblings: func_003FA040 (src/r13_10_d.c, mono).
   The walking source pointer is a local copy (q = src) and, in 1B0, the coefficient
   conversions go through temps: both fix the prologue's local-alloc lengths (lh temps).
   func_003FA448 keeps the volume in $f16 via a register variable: with vol and sa
   both 8 weighted refs and vol's range nested inside sa's, global.c always ranks vol
   above sa and c2, so no plain local reproduces retail's c2/sa/vol = f14/f15/f16.
   Needs D_004BB688 / D_004BBA88 / D_004BF284 in symbol_addrs. */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004BB688[];
extern f32 D_004BBA88[];
extern f32 D_004BF284;

s32 func_003FA1B0(u8 *src, s32 n, s16 *out0, s16 *st0, s16 *out1, s16 *st1, s32 k1, s32 k2)
{
    f32 c1, c2; f32 a1, a2, b1, b2; f32 sa, sb;
    s32 blk, i; s16 h; u8 *p; u8 *q;
    {
    f32 tc1, tc2;
    a1 = (f32)(st0[0] << 16);
    q = src;
    tc1 = (f32)((s16)k1 << 4);
    a2 = (f32)(st0[1] << 16);
    b1 = (f32)(st1[0] << 16);
    b2 = (f32)(st1[1] << 16);
    c1 = tc1 * (1.0f / 65536.0f);
    tc2 = (f32)((s16)k2 << 4);
    c2 = tc2 * (1.0f / 65536.0f);
    }

    for (blk = 0; blk < n / 2; blk++) {
        p = q;
        q += 0x12;
        h = (s16)(((*(u16 *)p << 8) & ~0xFF) | p[1]);
        if (h & 0x8000)
            return blk * 2;
        sa = (f32)((h & 0x1FFF) + 1);
        h = (s16)(((*(u16 *)q << 8) & ~0xFF) | q[1]);
        if (h & 0x8000)
            return blk * 2;
        sb = (f32)((h & 0x1FFF) + 1);
        p += 2;
        q += 2;
        for (i = 0; i < 32; i += 2) {
            u32 x, y; f32 t, d, e; s32 o;
            x = *p++;
            y = *q++;
            d = D_004BB688[x];
            t = (c1 * a1 + c2 * a2) + d * sa;
            a2 = a1;
            a1 = t;
            e = D_004BB688[y];
            t = (c1 * b1 + c2 * b2) + e * sb;
            b2 = b1;
            b1 = t;
            o = (s32)a1;
            *out0++ = o >> 16;
            o = (s32)b1;
            *out1++ = o >> 16;
            d = D_004BBA88[x];
            t = (c1 * a1 + c2 * a2) + d * sa;
            a2 = a1;
            a1 = t;
            e = D_004BBA88[y];
            t = c1 * b1 + c2 * b2;
            t += e * sb;
            b2 = b1;
            b1 = t;
            o = (s32)a1;
            *out0++ = o >> 16;
            o = (s32)b1;
            *out1++ = o >> 16;
        }

    }
    st0[0] = (s32)a1 >> 16;
    st0[1] = (s32)a2 >> 16;
    st1[0] = (s32)b1 >> 16;
    st1[1] = (s32)b2 >> 16;

    return n;
}

s32 func_003FA448(u8 *src, s32 n, s16 *out0, s16 *st0, s16 *out1, s16 *st1, s32 k1, s32 k2)
{
    u8 *q;
    f32 c1, c2; f32 b1, a1, a2, b2; f32 sa, sb;
    register f32 vol __asm__("$f16");
    s32 blk, i; s16 h; u8 *p;
    a1 = (f32)(st0[0] << 16);
    a2 = (f32)(st0[1] << 16);
    q = src;
    b1 = (f32)(st1[0] << 16);
    b2 = (f32)(st1[1] << 16);
    c1 = (f32)((s16)k1 << 4) * (1.0f / 65536.0f);
    c2 = (f32)((s16)k2 << 4) * (1.0f / 65536.0f);

    for (blk = 0; blk < n / 2; blk++) {
        p = q;
        q += 0x12;
        h = (s16)(((*(u16 *)p << 8) & ~0xFF) | p[1]);
        if (h & 0x8000)
            return blk * 2;
        sa = (f32)((h & 0x1FFF) + 1);
        h = (s16)(((*(u16 *)q << 8) & ~0xFF) | q[1]);
        if (h & 0x8000)
            return blk * 2;
        sb = (f32)((h & 0x1FFF) + 1);
        p += 2;
        vol = D_004BF284;
        q += 2;
        for (i = 0; i < 32; i += 2) {
            u32 x, y; f32 t, d, e; s32 o; s16 v;
            x = *p++;
            y = *q++;
            d = D_004BB688[x];
            t = (c1 * a1 + c2 * a2) + d * sa;
            a2 = a1;
            a1 = t;
            e = D_004BB688[y];
            t = (c1 * b1 + c2 * b2) + e * sb;
            b2 = b1;
            b1 = t;
            v = (s32)((a1 + b1) * vol) >> 16;
            *out0++ = *out1++ = v;
            d = D_004BBA88[x];
            t = (c1 * a1 + c2 * a2) + d * sa;
            a2 = a1;
            a1 = t;
            e = D_004BBA88[y];
            t = c1 * b1 + c2 * b2;
            t += e * sb;
            b2 = b1;
            b1 = t;
            v = (s32)((a1 + b1) * vol) >> 16;
            *out0++ = *out1++ = v;
        }
    }
    st0[0] = (s32)a1 >> 16;
    st0[1] = (s32)a2 >> 16;
    st1[0] = (s32)b1 >> 16;
    st1[1] = (s32)b2 >> 16;
    return n;
}
