typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_001E7F60(u8 *);
extern void func_003B2E60(u8 *, u8 *);
extern s32 func_00175670(u8 *);
extern s16 D_004BF958[4];

void func_003B2BC0(u8 *p, u8 *q)
{
    if (*(s8 *)(q + 0x151) != 0) p[0x21] = 1;
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_001E7F60(p);
    if (!(*(f32 *)(q + 0x430) + 212.14285278f < *(f32 *)(p + 0x38))) {
        p[5]++;
        func_003B2E60(p, q);
    }
}

void func_001B7110(u8 *p, u8 *q)
{
    s32 t;
    func_00175670(p);
    t = q[0x15F];
    if (t != 0) {
        u8 u = t;
        if (u == 4) {
            p[5]++;
            *(u32 *)(p + 0x60) = 0x42092492;
            *(u32 *)(p + 0x6C) = 0x3E892492;
        } else {
            *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38) + 2.14285707f * (f32)D_004BF958[u] / 256.0f;
        }
    }
}
