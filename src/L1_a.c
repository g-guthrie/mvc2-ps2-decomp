typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 D_004F20B0[];
extern u8 D_00583B90[];
extern u8 D_00583B92[];
extern volatile s8 D_00583BC7[];
extern s8 D_004C27C0[2];
extern s8 D_004C27C4[2];
extern u8 *D_004C2840[1];


void func_0032CB40(void)
{
    extern void func_0032DF90(), func_0032E600(), func_00138280(), func_001E60B0(), func_001E6490(), func_0032E350();
    u8 *p;
    p = D_004F20B0 + (*(s8 *)(D_004C2840[0] + 0x88) - 1) * 0x5B8;
    switch (p[5]) {
    case 0:
        p[5] = p[5] + 1;
        D_00583B90[(s8)p[0x538]] = 0;
        D_00583BC7[0] = p[0x538] ^ 1;
        func_0032DF90(D_00583BC7[0]);
        D_00583B92[D_00583BC7[0]] = 0;
        func_0032E600();
        func_00138280(p[0x538], 0);
        D_004C27C4[0] = 1;
        D_004C27C0[0] |= (s8)p[0x538] + 1;
        func_001E60B0((s8)p[0x538]);
        func_001E6490((s8)p[0x538]);
        break;
    case 1:
        if (D_00583B90[(s8)p[0x538]] == 0) p[5] = p[5] + 1;
        break;
    case 2:
        if (D_00583B90[(s8)p[0x538]] == 1) { p[5] = p[5] + 1; *(s16 *)(p + 0x1C) = 0x14; }
        break;
    case 3:
        *(s16 *)(p + 0x1C) -= 1;
        if (*(s16 *)(p + 0x1C) <= 0) {
            *(s8 *)(D_004C2840[0] + 4) += 1;
            p[5] = 0;
            D_00583B92[D_00583BC7[0]] = 0x77;
            func_0032E350(D_00583BC7[0]);
            D_00583B90[D_00583BC7[0]] = 0;
            {
                s8 t = D_00583BC7[0];
                D_004C27C4[0] = 1;
                D_004C27C0[0] |= (s8)(t + 1);
                func_001E60B0(t);
            }
            func_001E6490(D_00583BC7[0]);
        }
        break;
    }
}
