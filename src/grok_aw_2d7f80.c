typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_00185490(u8 *);
extern void func_00175C00(u8 *, int);
extern void func_00183D10(u8 *);
extern int func_001757E0(u8 *, int, int);

void func_002D7F80(u8 *p)
{
    unsigned int offset;

    p[0x2BD] = 0;
    p[6]++;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    p[0x20D] = 0;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    func_00185490(p);
    func_00175C00(p, 0);
    func_00183D10(p);
    if (p[0x269] == 3) {
        p[0x1B5] = 0x3F;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        offset = p[2] * 2;
        offset += (unsigned int)D_004C2794;
        ++*(s16 *)(offset + 0x7C);
    } else {
        p[0x1B5] = (u8)((s8)p[0x1B7] * 2 + 0x30);
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        offset = p[2] * 2;
        offset += (unsigned int)D_004C2794;
        ++*(s16 *)(offset + 0x7C);
    }
    func_001757E0(p, 0x15, (p[0x1B7] * 2 + 5) & 0xFF);
}
