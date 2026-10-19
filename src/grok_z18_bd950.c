typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;

extern void func_001754A0(u8 *, int, int);
extern void func_001BD9D0(u8 *, u8 *);

void func_001BD950(u8 *p, u8 *q)
{
    u8 *t = *(u8 **)(p + 0x14);
    p[5]++;
    p[0x13C] = 1;
    *(f32 *)(p + 0x118) = 1.0f;
    *(s16 *)(p + 0x1C) = 5;
    p[0x31] = (s8)t[0x31] - 1;
    func_001754A0(p, 0x1B, t[0x168]);
    func_001BD9D0(p, q);
}
