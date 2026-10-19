typedef unsigned char u8;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_001E7F60(u8 *);
extern void func_0015B200(u8 *, f32 *, int, int);

void func_003B77D0(u8 *p)
{
    u8 *o;

    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    o = *(u8 **)(p + 0x18);
    if (*(f32 *)(o + 0x430) > *(f32 *)(p + 0x38)) {
        p[4]++;
        *(f32 *)(p + 0x38) = *(f32 *)(o + 0x430);
        func_0015B200(p, (f32 *)(p + 0x34), 1, 8);
    } else {
        func_00175700(p);
        func_001E7F60(p);
    }
}
