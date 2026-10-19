typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_00185490(u8 *);
extern int func_001757E0(u8 *, int, int);
extern int func_00175700(u8 *);
extern void func_001843A0(u8 *);

void func_00257A70(u8 *p)
{
    s16 t;

    if ((s8)p[0x151] == 1) {
        p[0x151] = 0;
        *(f32 *)(p + 0x68) = 4.0f * *(f32 *)(p + 0x68);
    }
    if ((s8)p[0x151] == 2) {
        p[0x151] = 0;
        *(f32 *)(p + 0x68) = 4.0f * *(f32 *)(p + 0x68);
    }
    if (*(f32 *)(p + 0x5C) * *(f32 *)(p + 0x68) > 0.0f) {
        *(f32 *)(p + 0x5C) = 0.0f;
        *(f32 *)(p + 0x60) = 0.0f;
        *(f32 *)(p + 0x68) = 0.0f;
        *(f32 *)(p + 0x6C) = 0.0f;
    }
    p[0x209] = 2;
    t = *(s16 *)(p + 0x1C);
    *(s16 *)(p + 0x1C) = t - 1;
    if (t <= 0) {
        if ((*(u16 *)(p + 0x35C) & 0x100) != 0) {
            p[7]++;
            p[0x209] = 2;
            func_00185490(p);
            p[0x1B5] = 0x16;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(u32 *)(p + 0x1D8) = 0;
            ((s16 *)(D_004C2794 + 0x7C))[p[2]]++;
            func_001757E0(p, 0x14, 4);
        }
    }
    if (((s8)func_00175700(p)) < 0) {
        func_001843A0(p);
    }
}
