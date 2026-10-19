typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern void func_001757E0(u8 *, int, int);
extern void func_00176160(u8 *, int, int, int);
extern void func_00154470(u8 *, int, int, f32, f32);
extern f32 D_004F1FC8;
extern f32 D_004F1FCC;

void func_00374000(u8 *p)
{
    u8 *q;
    u32 one = 0x3F800000;
    u32 a = 0x40CDB6DB;
    u32 b = 0xBEF00000;
    f32 four = 4.0f;
    f32 lim;
    p[5]++;
    p[6] = 0;
    *(u32 *)(p + 0x54) = one;
    *(u32 *)(p + 0x50) = one;
    func_001757E0(p, 0x16, p[0x20]);
    q = *(u8 **)(p + 0x18);
    *(s16 *)(p + 0x140) = *(s16 *)(q + 0x140);
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = a;
    *(u32 *)(p + 0x6C) = b;
    func_00176160(p, 2, 2, 2);
    func_00154470(p, 0, 0x90, four, four);
    func_00154470(p, 0x10, 0x90, four, four);
    func_00154470(p, 0xF0, 0x90, four, four);
    if (*(s16 *)(q + 0x140) != 0) {
        lim = D_004F1FCC - 160.0f;
        if (!(*(f32 *)(p + 0x34) <= lim))
            *(f32 *)(p + 0x34) = lim;
    } else {
        lim = 160.0f + D_004F1FC8;
        if (*(f32 *)(p + 0x34) < lim)
            *(f32 *)(p + 0x34) = lim;
    }
}
