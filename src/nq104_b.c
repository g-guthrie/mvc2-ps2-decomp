typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 *D_004C2840;
extern u16 D_004F25A0[];
extern u16 D_004F2B58[];
extern u8 D_004F3173[];
extern u8 D_004F3CE3[];
extern u8 D_004F2603[];
extern u8 D_004F372B[];
extern u8 D_004F429B[];
extern u8 D_004F2BBB[];

void func_003DA2A0(void) {
    s8 *p;
    u8 t;
    u32 m;
    p = (s8 *)(D_004C2840 + 0x88);
    if (*p & 1) {
        m = (u16)(D_004F25A0[0] & 0x90);
        if (m == 0x90) {
            t = D_004F3173[0]; D_004F3173[0] = D_004F3CE3[0]; D_004F3CE3[0] = t;
        } else if (m == 0x80) {
            t = D_004F2603[0]; D_004F2603[0] = D_004F3173[0]; D_004F3173[0] = t;
        } else if (m == 0x10) {
            t = D_004F2603[0]; D_004F2603[0] = D_004F3CE3[0]; D_004F3CE3[0] = t;
        }
    }
    if (*p & 2) {
        m = (u16)(D_004F2B58[0] & 0x90);
        if (m == 0x90) {
            t = D_004F372B[0]; D_004F372B[0] = D_004F429B[0]; D_004F429B[0] = t;
        } else if (m == 0x80) {
            t = D_004F2BBB[0]; D_004F2BBB[0] = D_004F372B[0]; D_004F372B[0] = t;
        } else if (m == 0x10) {
            t = D_004F2BBB[0]; D_004F2BBB[0] = D_004F429B[0]; D_004F429B[0] = t;
        }
        return;
    }
}
