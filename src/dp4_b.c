typedef unsigned char u8;
typedef signed short s16;
typedef float f32;
extern void func_00175670(u8 *);
extern void func_001AFC90(u8 *);

void func_001AD7E0(u8 *p)
{
    u8 *q;
    f32 t;
    t = *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x34) += t;
    t = *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x5C) += t;
    t = *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x38) += t;
    t = *(f32 *)(p + 0x6C);
    *(f32 *)(p + 0x60) += t;
    q = *(u8 **)(p + 0x18);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(q + 0x430)) {
        p[5]++;
        *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x430);
        *(f32 *)(p + 0x60) = -((double)*(f32 *)(p + 0x60) / 2.0);
        *(s16 *)(p + 0x1C) = 0x30;
    }
}

void func_001AD8B0(u8 *p)
{
    s16 v;
    func_00175670(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v != 0) {
        p[0x13C] = (*(s16 *)(p + 0x1C) & 4) ? 1 : 0;
        if (*(f32 *)(p + 0x38) <= *(f32 *)(*(u8 **)(p + 0x18) + 0x430)) {
            *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x430);
            *(f32 *)(p + 0x60) = -((double)*(f32 *)(p + 0x60) / 2.0);
        }
    } else {
        func_001AFC90(p);
    }
}
