typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern int func_00175700(u8 *);
extern int func_00174470(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_001E7F60(u8 *);
extern u8 D_00463631[];

void residual_003639B0(u8 *p, u8 *q)
{
    u8 *s2 = q + 0x2B8;
    u8 *o = *(u8 **)(q + 0x2B8);
    s16 face;

    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    if (s2[4]) {
        if (o[3] == 4 && *(u16 *)(o + 0x26) == 0x1003) {
            face = *(s16 *)(p + 0x140);
            if (face == 0) {
                if (*(f32 *)(p + 0x34) <= *(f32 *)(o + 0x34))
                    goto hit;
            }
            if (face == 0)
                goto done;
            if (*(f32 *)(p + 0x34) < *(f32 *)(o + 0x34))
                goto done;
        }
    } else if (func_00174470(p)) {
        u32 t = p[5];
        p[5] = t + 1;
        func_001757E0(p, 0x17, D_00463631[p[0x20] * 2]);
    }
    goto done;
hit:
    {
        u32 t = p[5];
        p[5] = t + 1;
        *(s16 *)(o + 0x1E) = *(s16 *)(o + 0x1E) + 1;
        func_001757E0(p, 0x17, D_00463631[p[0x20] * 2]);
    }
done:
    func_001E7F60(p);
}
