typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
typedef float f32;

extern void func_00176160(u8 *, int, int, int);
extern void func_00175C00(u8 *, int);
extern int func_001757E0(u8 *, int, int);
extern void func_001E3210(u8 *, int);
extern void func_00191210(u8 *);
extern u8 *D_004C2840 __attribute__((section(".sdata")));
extern u8 D_004F1F45;
extern u8 D_004F1F46;

void func_00266CA0(u8 *p, u8 *s0)
{
    p[0x40C] = 2;
    p[0x33C] = 5;
    if (!(*(u32 *)(D_004C2840 + 0x1C) & 1))
        func_00176160(p, 0, p[0x25] + 6, 1);
    else
        func_00175C00(p, 8);
    if (!(*(u32 *)(D_004C2840 + 0x1C) & 7)) {
        D_004F1F45 = 2;
        D_004F1F46 = 1;
    }
    *(f32 *)(s0 + 0xC) += 0.019999999552965164f;
    *(f32 *)(s0 + 0x14) += 0.019999999552965164f;
    *(f32 *)(p + 0x50) = *(f32 *)(s0 + 0xC);
    *(f32 *)(p + 0x54) = *(f32 *)(s0 + 0x14);
    if (*(f32 *)(s0 + 0x14) <= 1.0f)
        goto end;
    {
        volatile f32 *pc = (f32 *)(s0 + 0xC);
        *pc = 1.0f;
        *pc = 1.0f;
    }
    *(f32 *)(p + 0x50) = 1.0f;
    *(f32 *)(p + 0x54) = *(f32 *)(s0 + 0x14);
    p[7]++;
    *(s16 *)(s0 + 8) = 0x1E;
    func_001757E0(p, 0x16, 0x37);
    func_00175C00(p, 0);
    func_00176160(p, 0, p[0x25] + 6, 1);
    func_00176160(p, 2, 0xC, 2);
    func_001E3210(p, 0x25);
end:
    p[0x216] |= 0x80;
    p[0x1FF] = 2;
    func_00191210(p);
}
