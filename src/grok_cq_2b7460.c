typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern s8 func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);
extern u8 *func_001E7FD0(u8 *);
extern void func_00185770(u8 *, u8 *);

void residual_002B7460(u8 *p)
{
    p[0x40C] = 2;
    p[0x33C] = 5;
    if (func_00175700(p) < 0) {
        p[6]++;
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        if (*(s16 *)(p + 0x140))
            *(u32 *)(p + 0x5C) = 0xBDD55555;
        else
            *(u32 *)(p + 0x5C) = 0x3DD55555;
        func_001757E0(p, 22, 7);
        return;
    }
    if ((s8)p[0x151] == 0) {
        u8 *hit;
        *(f32 *)(p + 0x34) = *(f32 *)(p + 0x34) + *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) = *(f32 *)(p + 0x5C) + *(f32 *)(p + 0x68);
        hit = func_001E7FD0(p);
        if (hit != 0) {
            u8 *o = *(u8 **)(p + 0x220);
            if (o[0x20D] != 2) {
                p[7]++;
                p[0x20B] = 0xC3;
                func_00185770(p, hit);
                func_001757E0(p, 15, 3);
            }
        }
    }
}
