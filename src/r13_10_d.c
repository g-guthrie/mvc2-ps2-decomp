/* func_003FA040: EE GCC 2.96, ./tryee.sh <src> sn 0 O2 "" -mips4 (the -mips4 drops the mtc1 hazard nops).
   CRI ADX float-coefficient 4-bit decoder (mono). Needs D_004BB688 / D_004BBA88 in symbol_addrs. */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004BB688[];
extern f32 D_004BBA88[];

s32 func_003FA040(u8 *src, s32 n, s16 *out, s16 *st, s32 k1, s32 k2)
{
    f32 c1;
    f32 a1;
    f32 c2;
    f32 a2;
    f32 s;
    s32 blk, i;
    s16 h;

    a1 = (f32)(st[0] << 16);
    a2 = (f32)(st[1] << 16);
    c1 = (f32)((s16)k1 << 4) * (1.0f / 65536.0f);
    c2 = (f32)((s16)k2 << 4) * (1.0f / 65536.0f);
    for (blk = 0; blk < n; blk++) {
        h = (s16)(((*(u16 *)src << 8) & ~0xFF) | src[1]);
        if (h & 0x8000) return blk;
        s = (f32)((h & 0x1FFF) + 1);
        src += 2;
        for (i = 30; i >= 0; i -= 2) {
            u32 x = *src++;
            f32 t, d;
            d = D_004BB688[x];
            t = c1 * a1 + c2 * a2;
            t += d * s;
            a2 = a1;
            a1 = t;
            *out++ = (s32)a1 >> 16;
            d = D_004BBA88[x];
            t = (c1 * a1 + c2 * a2) + d * s;
            a2 = a1;
            a1 = t;
            *out++ = (s32)t >> 16;
        }
    }
    st[0] = (s32)a1 >> 16;
    st[1] = (s32)a2 >> 16;
    return n;
}
