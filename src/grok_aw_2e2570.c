typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_0018C4B0(u8 *, int);
extern void func_00175C00(u8 *, int);
extern void func_001757E0(u8 *, int, int);
extern void func_00183D10(u8 *);
extern void func_00185490(u8 *);
extern void func_002E2680(u8 *);

void residual_002E2570(u8 *p)
{
    unsigned int offset;

    p[0x1B5] = 0x33;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    offset = p[2] * 2;
    offset += (unsigned int)D_004C2794;
    ++*(s16 *)(offset + 0x7C);
    func_0018C4B0(p, 0x10);
    func_00175C00(p, 0);
    p[0x2C6] = 0;
    p[0x2C0] = 0;
    func_001757E0(p, 0x15, 1);
    if (p[0x20D] == 2) {
        *(f32 *)(p + 0x5C) /= 8.0f;
        *(f32 *)(p + 0x68) /= 8.0f;
        *(f32 *)(p + 0x60) /= 2.0f;
        *(f32 *)(p + 0x6C) /= 2.0f;
    } else {
        func_00183D10(p);
        p[0x20D] = 0;
    }
    func_00185490(p);
    p[6]++;
    func_002E2680(p);
}
