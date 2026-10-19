typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern u8 *D_004C2794;
extern u8 *D_004C2840;
extern u8 D_004B9430[];
extern u8 D_004B9438[];
extern u8 D_004B9440[];
extern u8 D_004B9450[];
extern void func_003D7350(u8, u8, s32, u8 *, s16);

void func_003D9980(s32 a0)
{
    u8 *s0 = *(u8 **)(D_004C2794 + a0 * 12 + 0x18);
    u8 s1 = (u8)(s0[2] * 0x1A + 6);
    func_003D7350(s1, (u8)(D_004C2840[0xB6] + 0x19), 0x34, D_004B9430, *(s16 *)(s0 + 0x342));
    func_003D7350((u8)(s1 + 0x24), (u8)(D_004C2840[0xB6] + 0x19), 0x38, D_004B9438, *(s16 *)(s0 + 0x342));
    func_003D7350(s1, (u8)(D_004C2840[0xB6] + 0x1E), 0x35, D_004B9440, *(s16 *)(s0 + 0x342));
    func_003D7350((u8)(s1 + 0x24), (u8)(D_004C2840[0xB6] + 0x1E), 0x38, D_004B9438,
                  (s16)(*(s16 *)(s0 + 0x27C) - *(s16 *)(s0 + 0x290)));
    func_003D7350(s1, (u8)(D_004C2840[0xB6] + 0x23), 0x37, D_004B9450, *(s16 *)(s0 + 0x342));
    func_003D7350((u8)(s1 + 0x24), (u8)(D_004C2840[0xB6] + 0x23), 0x38, D_004B9438,
                  *(s16 *)(D_004C2794 + ((s0[2] ^ 1) * 2) + 0x78));
}
