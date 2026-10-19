typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_00185490(u8 *);
extern void func_0018C4B0(u8 *, int);
extern int func_001757E0(u8 *, int, int);
extern int func_00175700(u8 *);
extern void func_00184540(u8 *);
extern void func_003A0530(u8 *, int);

void func_002DB9D0(u8 *p)
{
    u32 off;
    int a2;
    s8 c;

    if (p[6] == 0) {
        p[6]++;
        func_00185490(p);
        func_0018C4B0(p, 5);
        p[0x1B5] = 0xD;
        {
            f32 f16 = 16.0f;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(u32 *)(p + 0x1D8) = 0;
            {
                f32 f8 = 8.0f;
                f32 f64 = 64.0f;
                off = p[2] * 2;
                off += (u32)D_004C2794;
                ++*(s16 *)(off + 0x7C);
                *(f32 *)(p + 0x5C) /= f16;
                *(f32 *)(p + 0x60) /= f8;
                *(f32 *)(p + 0x6C) /= f64;
            }
        }
        *(u32 *)(p + 0x68) = 0;
        a2 = 8;
        if (p[0x1B7] == 0)
            a2 = 7;
        func_001757E0(p, 0x14, a2 & 0xFF);
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430))
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    if ((s8)func_00175700(p) < 0) {
        func_00184540(p);
        return;
    }
    c = *(s8 *)(p + 0x151);
    if (c) {
        func_003A0530(p, (u8)(c - 1));
        p[0x151] = 0;
    }
}
