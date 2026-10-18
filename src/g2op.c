typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00137E60(u8 *p) {
    *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 1;
    if (*(s16 *)(p + 0x1C) >= 0x32) *(s16 *)(p + 0x1C) = 0;
    *(u32 *)(p + 0xD0) |= 0x20000;
    *(u32 *)(p + 0xE0) = 0;
    *(f32 *)(p + 0xE4) = 0.0199999995529651641845703125f * (f32)*(s16 *)(p + 0x1C);
}
void func_00163B00(u8 *p) {
    *(f32 *)(p + 0x78) -= 0.1666666716337204f;
    *(f32 *)(p + 0x7C) -= 0.1666666716337204f;
    *(f32 *)(p + 0x80) -= 0.1666666716337204f;
    {
        u32 t = p[5] + 1;
        p[5] = t;
        if ((u8)t > 6) {
            u32 u = p[4];
            p[4] = u + 1;
        }
    }
}
extern void func_001757E0();
void func_00230CC0(u8 *p) {
    f32 c;
    p[7]++;
    c = 16.666666030883789f;
    if (*(s16 *)(p + 0x140) == 0) c = -c;
    *(f32 *)(p + 0x5C) = c;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0x404DB6DB;
    *(u32 *)(p + 0x6C) = 0xBEAB6DB6;
    p[0x169] = 0x16;
    p[0x168] = 3;
    func_001757E0(p, p[0x169], p[0x168]);
}
extern void func_00175700();
void func_00265360(u8 *a) {
    func_00175700(a);
    if (*(s8 *)(a + 0x151) != 0) {
        f32 k;
        u32 t = a[6];
        a[6] = t + 1;
        if (a[0x1E6] != 0) k = 86.66666412353516f;
        else k = -86.66666412353516f;
        *(f32 *)(a + 0x34) += k;
    }
}
