typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 D_004B1150[];
extern void func_0011F938();

void func_00136640(u8 *a0) {
    u32 i = *(u32 *)(a0 + 0x1E0);
    u8 *s0 = a0 + 0x1B0;
    if (i >= 1000) i = 999;
    func_0011F938(s0, D_004B1150, i);
    i = 0;
    do {
        s8 v = s0[i] - 0x30;
        s0[i] = v;
        if (v < 0) *(s8 *)(s0 + i) = -1;
        i++;
    } while (i < 3);
}
