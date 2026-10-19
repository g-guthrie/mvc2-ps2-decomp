typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef float f32;

extern void func_003A2AE0(u8 *, u8 *);
extern int func_00174470(u8 *);
extern void func_003DAA40(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void (*D_00472B58[])(u8 *, u8 *);

void func_003A25E0(u8 *p, u8 *q)
{
    if (!p[4]) {
        u32 k;
        func_003A2AE0(p, q);
        p[0xD4] = 0xB;
        p[0xD5] = 0;
        k = 0x41892492;
        *(f32 *)(p + 0xD0) = *(f32 *)(p + 0x38) - *(f32 *)&k;
        p[6] = 1;
        if (!func_00174470(p)) {
            func_003DAA40(p);
            return;
        }
        func_001757E0(p, 0x16, 3);
        *(s8 *)(p + 0x31) = -8;
    }
    {
        s8 *b = (s8 *)(p + 0xD0);
        s8 t = b[4] - 1;
        b[4] = t;
        if (t < 0)
            b[4] = 0xB;
        if (b[5])
            b[5]--;
    }
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    D_00472B58[p[5]](p, q);
}
