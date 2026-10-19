typedef unsigned char u8;
typedef signed short s16;
typedef float f32;

extern void func_003BD7B0(u8 *);
extern void func_003BA2C0(u8 *);
extern void func_003BB8F0(u8 *);
extern void func_003BB910(u8 *);
extern int func_003BD1D0(u8 *);
extern int func_00175700(u8 *);

void func_003BBCD0(u8 *p)
{
    u8 **slot = (u8 **)(p + 0xD0);
    u8 *s2;
    u8 *s3;
    u8 *a1;

    func_003BD7B0(p);
    s2 = *(u8 **)(p + 0x18);
    s3 = s2 + 0x2B8;
    if (!p[6]) {
        p[6]++;
        func_003BA2C0(p);
    }
    if (!s3[3] || s2[0x425]) {
        func_003BB8F0(p);
        return;
    }
    a1 = *slot;
    *(f32 *)(p + 0x34) = *(f32 *)(a1 + 0x34);
    if (a1[5] != 3) {
        func_003BB910(p);
        return;
    }
    if (a1[0x247] == 9 || a1[0x247] == 0x17) {
        *(s16 *)(a1 + 0x1F8) = 2;
        a1[0x24D] = 2;
        if (func_003BD1D0(p))
            func_003BB910(p);
        else
            func_00175700(p);
    } else
        func_003BB910(p);
}
