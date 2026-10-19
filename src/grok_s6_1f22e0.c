typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_001E3A40(u8 *);
extern void func_0018FDB0(u8 *);
extern u8 D_004F1F45;
extern u8 D_004F1F46;

void func_001F22E0(u8 *p)
{
    u8 *q;
    p[0x206] = 3;
    if ((s8)func_00175700(p) < 0) {
        p[7]++;
        if (p[0x1E6])
            *(f32 *)(p + 0x34) += 160.0f;
        else
            *(f32 *)(p + 0x34) -= 160.0f;
        func_001757E0(p, 15, 0x1A);
        return;
    }
    if ((s8)p[0x151] != 0) {
        p[0x151] = 0;
        D_004F1F45 = 1;
        D_004F1F46 = 1;
        func_001E3A40(p);
        q = *(u8 **)(p + 0x1DC);
        *(u8 **)(q + 0x1C8) = p;
        if (p[0x269] == 3) {
            p[0x1B5] = 0x40;
            q[0x1B5] = 0x40;
        } else {
            p[0x1B5] = (s8)p[0x1B7] + 0x3F;
            q[0x1B5] = (s8)p[0x1B7] + 0x3F;
        }
        func_0018FDB0(p);
    }
}
