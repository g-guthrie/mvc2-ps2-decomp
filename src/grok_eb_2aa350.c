typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;

extern int func_00175700(u8 *);
extern int func_00185980(u8 *);
extern void func_001757E0(u8 *, int, int);

void func_002AA350(u8 *p)
{
    u8 *q;
    f32 d;

    p[0x40C] = 2;
    p[0x33C] = 5;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if ((s8)p[0x1B2] != 0) {
        if (func_00185980(p)) {
            p[6]++;
            q = *(u8 **)(p + 0x1C4);
            d = p[0x1E6] ? 100.0f : -100.0f;
            *(f32 *)(q + 0x34) = *(f32 *)(p + 0x34) + d;
            *(f32 *)(q + 0x38) = *(f32 *)(p + 0x38);
            q[0x20D] = 0;
            *(f32 *)(p + 0x5C) /= 8.0f;
            func_001757E0(p, 22, 3);
            return;
        }
        *(s16 *)(p + 0x1C) = 1;
    }
    {
        int n = *(s16 *)(p + 0x1C);
        n -= 1;
        *(s16 *)(p + 0x1C) = (s16)n;
        if ((s16)n == 0) {
            p[6] = 4;
            *(f32 *)(p + 0x5C) /= 8.0f;
            func_001757E0(p, 22, 1);
        }
    }
}
