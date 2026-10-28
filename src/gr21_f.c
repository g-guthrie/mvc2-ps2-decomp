typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 D_004C2430;
extern s32 func_0011FFA0(s32);
extern s32 func_0011D6A8(u8 *, s32, s32);

#define BE16(p) (((p)[0] << 8) | (p)[1])
#define BE32(p) (((p)[0] << 24) | ((p)[1] << 16) | ((p)[2] << 8) | (p)[3])

s32 func_004053E8(u8 *buf, s32 len, u8 *out)
{
    u8 *s, *q, *o4, *o8, *oc, *o10, *p8, *pa, *pc, *pe, *p4;
    s32 base, size, i, j, k, n, n1, w;

    base = func_0011FFA0(D_004C2430);
    s = buf;
    if (len < 0x1800)
        return 0;
    if (BE32(s) != 0x41495846)
        return 0;
    s += 4;
    size = BE32(s);
    s += 4;
    if (func_0011D6A8(buf + (size - base) + 8, D_004C2430, base) != 0)
        return 0;
    i = 0;
    out[0] = *s++;
    out[1] = *s++;
    *(f32 *)(out + 8) = (f32)BE16(s);
    s += 2;
    w = BE32(s);
    q = s + 4;
    *(s32 *)(out + 4) = w;
    s = q; s += 8;
    n1 = BE16(s);
    *(s32 *)(out + 0x210) = n1;
    s = q + 16;
    if (n1 != 0) {
    o4 = out + 4;
    o8 = out + 8;
    oc = out + 12;
    o10 = out + 16;
    j = 0x210;
    do {
        *(s32 *)(o4 + j) = BE32(s);
        s += 4;
        *(s32 *)(o8 + j) = BE32(s);
        s += 4;
        *(s32 *)(oc + j) = BE32(s);
        s += 4;
        *(s32 *)(o10 + j) = BE32(s);
        s += 4;
    i++; j += 16;
    } while (i < *(s32 *)(out + 0x210));
    }
    n = *(s8 *)s;
    s += 8;
    *(s32 *)(out + 0x414) = n;
    if (n > 0) {
    p8 = out + 8;
    pa = out + 10;
    pc = out + 12;
    pe = out + 14;
    i = n; k = 0x410;
    do {
        *(u16 *)(p8 + k) = BE16(s);
        s += 2;
        *(u16 *)(pa + k) = BE16(s);
        s += 2;
        *(u16 *)(pc + k) = BE16(s);
        s += 2;
        *(u16 *)(pe + k) = BE16(s);
        s += 2;
    i--; k += 8;
    } while (i != 0);
    }
    i = 0;
    out[0xC] = *s;
    s += 8;
    if (*(s8 *)(out + 0xC) > 0) {
    p4 = out + 4;
    k = 0x10;
    do {
        *(s32 *)(p4 + k) = BE32(s);
        s += 4;
        out[k] = *s;
        s += 4;
    i++; k += 16;
    } while (i < *(s8 *)(out + 0xC));
    }
    return size + 8;
}
