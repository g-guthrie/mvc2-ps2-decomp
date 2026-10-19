typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_00175C00(u8 *, int);
extern int func_001757E0(u8 *, int, int);

void func_002DBB70(u8 *p)
{
    unsigned int offset;
    f32 f;

    p[6]++;
    func_00175C00(p, 0);
    p[0x20D] = 2;
    *(f32 *)(p + 0x38) += 137.142852783203125f;
    f = 30.0f;
    if (p[0x1E6] == 0)
        f = -f;
    *(f32 *)(p + 0x5C) = f;
    *(u32 *)(p + 0x60) = 0xBE892492;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    p[0x1B5] = 0x5C;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    offset = p[2] * 2;
    offset += (unsigned int)D_004C2794;
    ++*(s16 *)(offset + 0x7C);
    func_001757E0(p, 0x15, 0x18);
}
