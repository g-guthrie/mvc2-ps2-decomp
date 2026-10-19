typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2840 __attribute__((section(".sdata")));
extern u32 D_004C27FC __attribute__((section(".sdata")));
extern void func_0014E770(u8 *);

void func_0014F0E0(u8 *p)
{
    s32 n;
    u8 *par;

    func_0014E770(p);
    if (p[0x23] != 0) {
        n = (s8)D_004C2840[6] + *(s16 *)(p + 0x1E) + 1;
        n = n / 10;
        if (n == 0)
            p[0x13C] = 0;
        else {
            p[0x13C] = 1;
            par = *(u8 **)(p + 0x18);
            p[0x13C] = (u8)(s8)par[0x13C];
            *(s16 *)(p + 0xCC) = (s16)(n + 0x1A);
            *(u32 *)(p + 0x84) = D_004C27FC;
        }
    } else {
        par = *(u8 **)(p + 0x18);
        n = (s8)D_004C2840[6] + *(s16 *)(p + 0x1E) + 1;
        p[0x13C] = (u8)(s8)par[0x13C];
        *(s16 *)(p + 0xCC) = (s16)(n % 10 + 0x1A);
        *(u32 *)(p + 0x84) = D_004C27FC;
    }
    par = *(u8 **)(p + 0x18);
    *(f32 *)(p + 0x74) = *(f32 *)(par + 0x74);
}
