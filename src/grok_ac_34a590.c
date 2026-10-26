/* Metrowerks 3.0: ./try.sh src/grok_ac_34a590.c "-O3 -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern void (*D_00461F88[])(u8 *, u8 *);
extern u8 *func_0034A140(u8 *);
extern void func_001E7F60(u8 *);

void func_0034A590(u8 *p, u8 *q)
{
    u8 *s = q + 0x2B8;

    *(s8 *)(p + 0x31) = -2;
    if (q[5] != 0 || q[0x1E4] != 0x1D) {
        p[4]++;
        p[0x13C] = 0;
        return;
    }
    if (p[0x20] < 4 && *(s16 *)(p + 0x1E) != 0) {
        s16 v = *(s16 *)(p + 0x1E) - 1;
        *(s16 *)(p + 0x1E) = v;
        if (v == 0) {
            if (func_0034A140(p))
                *(s8 *)(s + 0x15) = *(s8 *)(s + 0x15) + 1;
        }
    }
    D_00461F88[p[5]](p, q);
    func_001E7F60(p);
}
