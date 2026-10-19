typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern s8 *D_004C2840;
extern s32 D_004F1CDC;
extern void func_001266A0(s32, s32, s32);
extern void func_003D9440(void);

void func_003D80E0(u8 *a0)
{
    s32 v1;
    D_004C2840[0x19] = 1;
    D_004C2840[0x9C] = 0;
    a0[1] = 0xA;
    a0[2] = 0;
    a0[3] = 0;
    *(s32 *)(a0 + 8) = 0;
    a0[7] = 0;
    *(s32 *)(a0 + 0xC) = 0;
    *(s16 *)(a0 + 0x12) = 1;
    if (a0[0x45] == 0) {
        func_001266A0(0, 0xB, 0xB);
        v1 = 1;
    } else {
        if (a0[0x48] == 8 && D_004C2840[0xAF] != 0) {
            D_004C2840[0x19] = 0;
            if (a0[0x45] == 1) {
                *(s16 *)(a0 + 0x12) = 0x1A4;
                D_004F1CDC = 1;
            } else {
                *(s16 *)(a0 + 0x12) = 0x12C;
                D_004F1CDC = 2;
            }
        }
        func_003D9440();
        v1 = 1;
    }
    a0[0] = (u8)v1;
}
