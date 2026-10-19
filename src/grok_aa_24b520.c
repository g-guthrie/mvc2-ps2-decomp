typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_00185490(u8 *);
extern void func_00175C00(u8 *, int);
extern void func_0018C4B0(u8 *, int);
extern void func_001757E0(u8 *, int, int);
extern void func_0024B610(u8 *);

void residual_0024B520(u8 *p)
{
    unsigned int offset;
    {
        u32 t = p[7];
        p[7] = t + 1;
    }
    *(s16 *)(p + 0x1E) = 1;
    p[0x2BE] = 0;
    func_00185490(p);
    func_00175C00(p, 0);
    *(f32 *)(p + 0x5C) = *(f32 *)(p + 0x5C) / 8.0f;
    *(u32 *)(p + 0x68) = 0;
    *(f32 *)(p + 0x60) = *(f32 *)(p + 0x60) / 8.0f;
    *(f32 *)(p + 0x6C) = *(f32 *)(p + 0x6C) / 64.0f;
    func_0018C4B0(p, 5);
    p[0x1B5] = 0x38;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    offset = p[2] * 2;
    offset += (unsigned int)D_004C2794;
    ++*(s16 *)(offset + 0x7C);
    func_001757E0(p, 0x15, 5);
    func_0024B610(p);
}
