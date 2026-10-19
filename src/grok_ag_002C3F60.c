typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern void func_002C40D0(u8 *);
extern void func_00183D10(u8 *);
extern void func_002C25A0(u8 *);
extern void func_001E3210(u8 *, int);
extern void func_0018C4B0(u8 *, int);
extern void func_001757E0(u8 *, int, int);

void residual_002C3F60(u8 *p)
{
    u8 *s = p + 0x2B8;

    p[6]++;
    if (p[0x215]) {
        func_002C40D0(p);
        return;
    }
    if (p[0x210])
        p[0x210] = 0;
    if (p[0x20D] != 2) {
        func_00183D10(p);
        func_002C25A0(p);
    }
    *(s16 *)(s + 8) = 0x258;
    func_001E3210(p, 4);
    p[0x215] = 1;
    p[0x20D] = 2;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0x414DB6DB;
    *(u32 *)(p + 0x6C) = 0x3E892492;
    func_0018C4B0(p, 0xA);
    func_001757E0(p, 0x1A, 0);
}
