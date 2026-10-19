typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_00175700(u8 *);
extern void func_001863F0(u8 *);
extern void func_0022FFB0(u8 *, u8 *);
extern void func_0019DE50(u8 *, s32, s32);
extern void func_002301C0(u8 *, u8 *);

void func_00230060(u8 *p, u8 *q)
{
    unsigned int offset;
    func_00175700(p);
    if ((s8)p[0x151] == 0) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        func_001863F0(p);
        return;
    }
    {
        u32 t = p[7];
        p[7] = t + 1;
    }
    func_0022FFB0(p, q);
    func_0019DE50(p, 4, 0);
    func_0019DE50(p, 4, 1);
    func_0019DE50(p, 4, 2);
    if (p[0x269] == 3) {
        p[0x1B5] = 0x43;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        offset = p[2] * 2;
        offset += (unsigned int)D_004C2794;
        ++*(s16 *)(offset + 0x7C);
    } else {
        p[0x1B5] = (s8)p[0x1B7] + 0x42;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        offset = p[2] * 2;
        offset += (unsigned int)D_004C2794;
        ++*(s16 *)(offset + 0x7C);
    }
    func_002301C0(p, q);
}
