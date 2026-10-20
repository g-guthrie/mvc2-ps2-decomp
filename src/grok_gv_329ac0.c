/* ./try.sh src/grok_gv_329ac0.c "-O4,p -sdatathreshold 8" */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;

extern u32 D_004F2608[];
extern u32 D_004F2BC0[];
extern u32 D_004F260C[];
extern u32 D_004F2BC4[];
extern u32 D_004F2610[];
extern u32 D_004F2BC8[];
extern u32 D_004F2614[];
extern u32 D_004F2BCC[];
extern u8 *D_004C2840;
extern u32 D_00583BCC[];
extern u32 D_00583BD0[];
extern u32 D_00583BA0[];
extern u32 D_00583BB0[];
extern u32 D_00583BA4[];
extern u32 D_00583BB4[];
extern u8 D_00583B9D[];

void func_00329AC0(s8 idx)
{
    s32 n = idx * 2;
    u8 *p = D_004C2840;
    u32 w0 = *(u32 *)(p + 0x30) | (D_004F2608[0] | D_004F2BC0[0]);
    u32 w1 = *(u32 *)(p + 0x34) | (D_004F260C[0] | D_004F2BC4[0]);
    u32 w2 = *(u32 *)(p + 0x38) | (D_004F2610[0] | D_004F2BC8[0]);
    u32 w3 = *(u32 *)(p + 0x3C) | (D_004F2614[0] | D_004F2BCC[0]);

    D_00583BCC[n] = 0;
    D_00583BD0[n] = 0;
    if ((s8)p[0x4C] != 5) {
        D_00583BA0[n] = w0 | 0xFFFF77;
        D_00583BB0[n] = D_00583BA0[n];
        D_00583BA4[n] = w1 | 0x2000004;
        D_00583BB4[n] = D_00583BA4[n];
        D_00583BCC[n] |= w2;
        D_00583BD0[n] |= w3;
    }
    if (D_00583BA0[n] == 0xF8FFFFFF
        && D_00583BA4[n] == 0x7FFFFFF
        && D_00583BCC[n] == 0xF8FFFFFF
        && D_00583BD0[n] == 0x7FFFFFF)
        D_00583B9D[0] = 1;
}
