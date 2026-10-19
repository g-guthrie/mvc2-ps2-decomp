typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;

extern void func_00175910(u8 *, int, int, int);

void func_003A4E90(u8 *p, u8 *q)
{
    f32 *s0;
    int i;
    u8 *src;

    *(f32 *)(p + 0x34) = *(f32 *)(p + 0x88);
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x8C);
    *(u16 *)(p + 0x168) = *(u16 *)(p + 0x90);
    {
        int rec = *(int *)(p + 0x94);
        s0 = (f32 *)(p + 0x88);
        func_00175910(p, p[0x169], p[0x168], rec);
    }
    i = 0;
    do {
        f32 a = s0[4];
        f32 b = s0[5];
        f32 c = s0[6];
        f32 d = s0[7];
        s0[0] = a;
        s0[1] = b;
        s0[2] = c;
        s0[3] = d;
        s0 += 4;
        i++;
    } while (i < 3);
    if (!p[0x20]) {
        s0[0] = *(f32 *)(q + 0x34);
        s0[1] = *(f32 *)(q + 0x38);
        *(u32 *)(s0 + 2) = *(u16 *)(q + 0x168);
        *(u32 *)(s0 + 3) = q[0x15B];
    } else {
        src = *(u8 **)(p + 8);
        s0[0] = *(f32 *)(src + 0x34);
        s0[1] = *(f32 *)(src + 0x38);
        *(u32 *)(s0 + 2) = *(u16 *)(src + 0x168);
        *(u32 *)(s0 + 3) = src[0x15B];
    }
}
