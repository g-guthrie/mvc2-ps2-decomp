typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern void func_00370AB0(u8 *);

void residual_00370990(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);
    u8 *r = q + 0x2B8;
    u32 bits;
    f32 f;
    if (q[0x1E4] != 0x1D || q[0x1FD] != 5) {
        p[5] = 5;
        bits = 0x417D5555;
        if (*(s16 *)(p + 0x140))
            bits = 0xC17D5555;
        *(f32 *)(p + 0x5C) = *(f32 *)&bits;
        bits = 0x3EA00000;
        if (*(s16 *)(p + 0x140))
            bits = 0xBEA00000;
        *(f32 *)(p + 0x68) = *(f32 *)&bits;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x6C) = 0;
        *(s16 *)(p + 0x1C) = 0x3C;
        r[0xE] = 0;
        return;
    }
    p[5]++;
    bits = 0xC1C80000;
    if (*(s16 *)(p + 0x140))
        bits = 0x41C80000;
    *(f32 *)(p + 0x5C) = *(f32 *)&bits;
    bits = 0x3EA00000;
    if (*(s16 *)(p + 0x140))
        bits = 0xBEA00000;
    *(f32 *)(p + 0x68) = *(f32 *)&bits;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x6C) = 0;
    *(s16 *)(p + 0x1C) = 0x18;
    *(s16 *)(r + 0x10) = 0;
    func_00370AB0(p);
}
