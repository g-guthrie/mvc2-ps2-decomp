typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0018D0C0(u8 *p)
{
    u8 *q;
    u8 *r;
    s32 c;
    s8 m;
    s32 idx;
    f32 z;
    if ((*(u16 *)(p + 0x1C2) & 0x1010) != 0) {
        if (*(u32 *)(p + 0x1C8) == *(u32 *)(p + 0x1CC)) {
            (*(u8 **)(p + 0x1CC))[0x209] = 3;
        }
    }
    c = *(s8 *)(p + 0x211);
    if (c != 0 && (r = *(u8 **)(p + 0x1D0)) != 0 && (r[1] & 0x80) == 0) {
        m = c;
        idx = p[0x1E6];
        if ((m & (1 << idx)) != 0) {
            if (idx == 0) {
                if (*(f32 *)(p + 0x5C) < 0.0f) goto E;
            }
            if (idx != 0) {
                if (!(*(f32 *)(p + 0x5C) <= 0.0f)) goto E;
            }
            {
                z = 0.0f;
                q = *(u8 **)(p + 0x1CC);
                if (q == 0) {
                    q = *(u8 **)(p + 0x220);
                }
                if (*(s8 *)(q + 0x211) != (m ^ 3)) {
                    *(f32 *)(q + 0x34) -= *(f32 *)(p + 0x5C);
                    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
                    if (!(*(f32 *)(p + 0x5C) * *(f32 *)(p + 0x68) < z)) {
                        *(f32 *)(p + 0x5C) = z;
                        *(f32 *)(p + 0x68) = z;
                    }
                    return;
                }
            }
        }
    }
E:
    z = 0.0f;
    *(f32 *)(p + 0x34) += *(f32 *)((s32)p + 0x5C);
    *(f32 *)((s32)p + 0x5C) += *(f32 *)((s32)p + 0x68);
    if (!(*(f32 *)((s32)p + 0x5C) * *(f32 *)((s32)p + 0x68) < z)) {
        *(f32 *)((s32)p + 0x5C) = z;
        *(f32 *)((s32)p + 0x68) = z;
    }
}
