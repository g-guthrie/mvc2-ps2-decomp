typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_00185490(u8 *);
extern void func_0018C4B0(u8 *, int);
extern void func_001757E0(u8 *, int, int);

void residual_00265540(u8 *p)
{
    unsigned int offset;
    u32 bits;
    p[6]++;
    *(s16 *)(p + 0x1C) = p[0x1B7] ? 0x1E : 0x28;
    func_00185490(p);
    func_0018C4B0(p, 5);
    p[0x20D] = 0;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    p[0x1B5] = p[0x1B7];
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    offset = p[2] * 2;
    offset += (unsigned int)D_004C2794;
    ++*(s16 *)(offset + 0x7C);
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    func_001757E0(p, 0x15, 0xC);
    bits = 0xC0E2AAAA;
    if (*(s16 *)(p + 0x140) != 0)
        bits = 0x40E2AAAA;
    *(f32 *)(p + 0x5C) = *(f32 *)&bits;
    p[0x206] = 10;
    p[0x207] = 10;
}
