typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern s8 func_00175700(u8 *);
extern int func_003777B0(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_001E7F60(u8 *);

void func_00377390(u8 *p, u8 *q)
{
    u8 *o;
    u32 a, b;
    if (func_00175700(p) < 0)
        *(s16 *)(p + 0x1C) -= 1;
    if (func_003777B0(p))
        return;
    if (*(s8 *)(p + 0x151)) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    } else {
        o = *(u8 **)(q + 0x220);
        {
            f32 x = *(f32 *)(o + 0x34);
            f32 px = *(f32 *)(p + 0x34);
            if (!(x - 80.0f < px) || (x + 80.0f <= px) || o[0x20D] == 2) {
                if (*(s16 *)(p + 0x1C) != 1) {
                    a = 0x409A4924;
                    b = 0xBF4DB6DB;
                    *(u32 *)(p + 0x60) = a;
                    *(u32 *)(p + 0x6C) = b;
                    func_001E7F60(p);
                    return;
                }
            }
        }
        p[5]++;
        if (q[0x1B7] == 0)
            func_001757E0(p, 0x17, 8);
        else
            func_001757E0(p, 0x17, 9);
    }
    func_001E7F60(p);
}
