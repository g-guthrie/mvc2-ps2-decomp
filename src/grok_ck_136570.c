typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;

extern u8 D_004B1138[];
extern u8 D_004B1140[];
extern u8 D_004B1148[];
extern void func_0011F938(void *, void *, u32);

void func_00136570(u8 *p)
{
    u32 n = *(u32 *)(p + 0x1DC);
    u8 *s0 = p + 0x1B0;
    u32 i;
    if (n >= 10)
        n = 9;
    func_0011F938(s0, D_004B1138, n);
    if (n) {
        func_0011F938(s0 + 1, D_004B1140, *(u32 *)(p + 0x1E0));
    } else {
        s0[0] = 0x20;
        func_0011F938(s0 + 1, D_004B1148, *(u32 *)(p + 0x1E0));
    }
    i = 0;
    do {
        s8 v = s0[i] - 0x30;
        s0[i] = v;
        if (v < 0)
            *(s8 *)(s0 + i) = -1;
        i++;
    } while (i < 9);
}
