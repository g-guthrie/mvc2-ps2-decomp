typedef unsigned char u8;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

extern void func_0037B400(u8 *, int, int);

void func_0037B850(u8 *p, u8 *q)
{
    s32 v;
    u32 bits;
    if (q[1] != (*(u8 **)(q + 0x18))[1]) {
        func_0037B400(p, 0, 0);
        return;
    }
    if (q[4] == 4) {
        func_0037B400(p, 0, 0);
        return;
    }
    v = *(s32 *)(p + 0xDC);
    {
        s32 bit = v & 1;
        if (v < 0 && bit)
            bit -= 2;
        *(s32 *)(p + 0xDC) = bit;
    }
    if (*(s32 *)(p + 0xDC))
        bits = 0x3F666666;
    else
        bits = 0x3F800000;
    *(f32 *)(p + 0x50) = *(f32 *)&bits;
    if (*(s32 *)(p + 0xDC))
        bits = 0x3F666666;
    else
        bits = 0x3F800000;
    *(f32 *)(p + 0x54) = *(f32 *)&bits;
    *(s32 *)(p + 0xDC) += 1;
    *(s32 *)(p + 0x48) += 0x1F4A;
}
