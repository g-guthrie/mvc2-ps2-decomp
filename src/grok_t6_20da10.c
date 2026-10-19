/* Metrowerks 3.0: ./try.sh src/grok_t6_20da10.c "-O3 -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;

extern s8 func_00175700(u8 *);
extern void func_0020F250(u8 *);
extern void func_0020DD10(u8 *, u8 *);
extern void func_00183d50(u8 *);
extern void func_001757E0(u8 *, int, int);

void func_0020DA10(u8 *p, u8 *q)
{
    f32 *vx = (f32 *)(p + 0x5C);
    f32 *vy = (f32 *)(p + 0x60);
    f32 *ax = (f32 *)(p + 0x68);
    f32 *ay = (f32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *vx;
    *vx += *ax;
    *(f32 *)(p + 0x38) += *vy;
    *vy += *ay;
    func_00175700(p);
    func_0020F250(p);
    if ((s8)p[0x151] != 0) {
        p[0x151] = 0;
        func_0020DD10(p, q);
    }
    if ((s8)p[0x1B2] != 0 && (((s8)p[0x1B2] & 0x11) || (*(u8 **)(p + 0x1C4))[0x216] != 0))
        goto skip;
    {
        s8 b = p[0x211];
        int m = b & 3;
        if (m != 0 && (m & (p[0x1E6] + 1)) == 0)
            goto skip;
        if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
            p[6] = 4;
            *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
            p[0x20D] = 0;
            *vx = 0;
            *vy = 0;
            *ax = 0;
            *ay = 0;
            func_00183d50(p);
            func_001757E0(p, 0x15, 0x1B);
            return;
        }
        {
            s16 t = *(s16 *)(p + 0x1C) - 1;
            *(s16 *)(p + 0x1C) = t;
            if (t != 0)
                return;
        }
    }
skip:
    p[6]++;
    *(f32 *)(p + 0x5C) /= 8.0f;
    *(f32 *)(p + 0x60) = 0;
    *(f32 *)(p + 0x6C) = -45.0f / 56.0f;
    func_001757E0(p, 0x15, 0x35);
}
