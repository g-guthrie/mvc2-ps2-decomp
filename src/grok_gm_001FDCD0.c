typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;

extern void func_001861B0(u8 *);
extern void func_0018C4B0(u8 *, int);
extern void func_001757E0(u8 *, int, int);
extern void func_001E3710(u8 *, int);
extern void func_00183D90(u8 *);
extern void func_001863F0(u8 *);
extern s8 func_00175700(u8 *);
extern void func_001843A0(u8 *);
extern u8 *D_004C2794;

void residual_001FDCD0(u8 *p)
{
    if (p[6] == 0) {
        func_001861B0(p);
        {
            u32 t = p[6];
            p[6] = t + 1;
        }
        func_0018C4B0(p, 5);
        if (p[0x212] == 0) {
            p[0x1B5] = 0x36;
            p[0x20D] = 1;
            func_001757E0(p, 20, 9);
            p[0x1B5] = *(volatile u8 *)(p + 0x1B5);
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(u32 *)(p + 0x1D8) = 0;
            {
                u8 *q = (u8 *)((p[2] << 1) + (u32)D_004C2794);
                *(s16 *)(q + 0x7C) = *(s16 *)(q + 0x7C) + 1;
            }
            func_001E3710(p, 22);
        }
    }
    if (p[0x213] == 3)
        func_00183D90(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_001863F0(p);
    if ((s8)func_00175700(p) < 0)
        func_001843A0(p);
}
