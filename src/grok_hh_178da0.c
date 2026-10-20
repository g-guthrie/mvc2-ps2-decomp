typedef unsigned char u8;
typedef float f32;

extern f32 D_004F1F4C;
extern f32 D_004F1F40[];

void func_00178DA0(u8 *p)
{
    f32 y;
    f32 t;
    f32 *table;

    y = *(f32 *)(p + 0x34);
    table = D_004F1F40;
    t = 35.0f + (D_004F1F4C - 320.0f);
    if (y <= t) {
        *(f32 *)(p + 0x34) = t;
        return;
    }
    t = table[3] + 320.0f - 35.0f;
    if (y < t)
        return;
    *(f32 *)(p + 0x34) = t;
}
