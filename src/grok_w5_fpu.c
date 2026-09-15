typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int s32;
typedef float f32;

#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define I(p, o) (*(s32 *)((u8 *)(p) + (o)))

void func_00134790(u8 *p, u8 *q)
{
    f32 a;
    f32 b;
    s32 c;

    a = 40.0f;
    b = 16.0f;
    c = 0x40A00000;
    if (q[2] == 0) {
        a = -64.0f;
        b = -40.0f;
    }
    F(p, 0x34) = a;
    F(p, 0x70) = b;
    I(p, 0x38) = c;
}

void func_003A4E50(u8 *dst, u8 *src)
{
    u8 *d;
    s32 i;
    f32 x;

    d = dst + 136;
    i = 0;
    do {
        x = F(src, 0x34);
        i++;
        F(d, 0) = x;
        F(d, 4) = F(src, 0x38);
        I(d, 8) = U16(src, 360);
        I(d, 12) = src[347];
        d += 16;
    } while (i < 4);
}
