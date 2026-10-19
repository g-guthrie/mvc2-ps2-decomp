typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed int s32;
typedef float f32;

extern void func_0016B0C0(u8 *, u8 *, s32);

void func_00167060(u8 *p, u8 *q)
{
    s32 n;
    s32 a;

    func_0016B0C0(p, q, 0);
    n = 0;
    do {
        func_0016B0C0(p, q, 1);
        *(s32 *)(p + 0x460) = *(s32 *)(p + 0x4C8);
        func_0016B0C0(p, q, 3);
        if (*(f32 *)(p + 0x4C8) > *(f32 *)(p + 0x498)) {
            n += 1;
            break;
        }
        n += 1;
    } while (n < 3);
    a = 3 - n;
    a = a * 3 + 1;
    *(u16 *)(q + 4) += (u16)a;
    p[0x492] = *(s8 *)(p + 0x460);
    p[0x494] = 1;
    p[0x451] = 0;
    p[0x452] = 0;
    p[0x453] = 0;
}
