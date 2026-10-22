typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 D_00583B90[];
extern u8 D_004F20B0[];
extern s16 D_00583BDC[];
extern s8 *D_004C28FC;
extern s8 D_004C28F8;
extern u16 D_004C291C[4];
extern u8 D_00583B92[];
extern u8 D_00583BC6[];
extern s8 D_00583B98[];
typedef struct { u8 pad[0x4C]; s8 b4C; } G2840;
extern G2840 *D_004C2840;

void func_0032B3D0(u8 *p) {
    extern void func_001E3CE0(u8);
    extern void func_0012E780(s32);
    extern void func_0038CBB0(void);
    u32 st = p[6];
    switch (st) {
    case 0:
        if (D_00583B90[(s8)p[0x538]] == 2) {
            p[6] = st + 1;
            func_001E3CE0((s8)p[0x538] * 3 + 0x34);
        }
        break;
    case 1:
        D_004C28FC = (s8 *)D_004F20B0 + (((s8)p[0x538] + *(s16 *)(p + 0x1E) * 2) * 0x5B8);
        D_004C28F8 = D_004C28FC[0x4DD];
        if (D_00583BDC[0] == 0) {
            D_004C291C[(s8)p[0x538]] = 0x200;
        } else {
            s32 i = (s8)p[0x538];
            if (D_004C291C[i] & 0x2000) {
                func_001E3CE0(i * 2 + 0x40);
                D_004C28F8 = D_004C28F8 - 1;
            }
            i = (s8)p[0x538];
            if (D_004C291C[i] & 0x1000) {
                func_001E3CE0(i * 2 + 0x40);
                D_004C28F8 = D_004C28F8 + 1;
            }
            D_004C28F8 = (D_004C28F8 + 3) % 3;
            D_004C28FC[0x4DD] = D_004C28F8;
            if ((D_004C291C[(s8)p[0x538]] & 0x3FC) == 0) return;
        }
        func_001E3CE0((s8)p[0x538] * 2 + 0x41);
        func_001E3CE0((s8)p[0x538] + 0x35);
        D_00583B92[(s8)p[0x538]] |= (u8)(0x10 << (s8)p[0x1E]);
        D_00583BC6[0] |= (u8)(1 << (s8)p[0x538]);
        p[5] = 3;
        p[6] = 0;
        if (*(s16 *)(p + 0x1E) >= 2) D_00583B98[(s8)p[0x538]] |= 0x80;
        if (D_00583B92[(s8)p[0x538]] == 0x77) func_0012E780((s8)p[0x538] + 0xD);
        if (D_00583B92[0] == 0x77 && D_00583B92[1] == 0x77) func_0012E780(2);
        if (D_004C2840->b4C == 0) func_0038CBB0();
        break;
    }
}
