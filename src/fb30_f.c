typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern s8 *D_004C2840;
extern s8 D_004C292C;
extern s16 D_00583BDC[];
extern u8 D_00583B9D[];
extern u8 D_0045E220[];
extern u8 D_004F20B0[];
typedef struct { u8 b0; s8 b1; u8 pad2[0x4DB]; u8 b4DD; u8 pad4DE[0x540 - 0x4DE]; s8 b540; u8 pad541[0x553 - 0x541]; u8 b553; } E;
#define EL(k) ((E *)(D_004F20B0 + ((s8)p[0x538] + (k)) * 0x5B8))

void func_0032AA40(u8 *p) {
    extern s32 func_00417A40(void);
    extern void func_0032E600();
    extern void func_0012E720(void);
    extern void func_0012E780(s32);
    s8 i; s32 j, k;
    s32 sel;
    if (((s8)p[0x4DC] & (D_004C2840[0x89] | D_004C2840[0x88])) != 0) {
    p[4] = 1;
    p[5] = 0;
    *(s16 *)(p + 0x1E) = 0;
    *(s16 *)(p + 0x1C) = 1;
    if (D_004C292C >= 0) {
        sel = (s8)p[0x4DC];
        if (sel == D_004C2840[0x90]) {
            s32 t = D_004F20B0[4 + ((s8)p[0x538] ^ 1) * 0x5B8];
            if (t < 8 || t >= 10) D_004C292C = sel;
        }
    }
    if ((D_004C2840[0x88] & (s8)p[0x4DC]) != 0) return;
    if ((s8)p[0x4DC] == D_004C2840[0x90]) {
        s32 r;
        D_00583BDC[0] = 0xE10;
        r = func_00417A40();
        p[0x524] = r % 4;
        func_0032E600();
        func_0012E720();
        func_0012E780(0x11);
    }
    if (D_00583B9D[0] != 0) {
        i = 0;
        j = 0;
        for (; i < 3; i++) {
            EL(j)->b540 = D_0045E220[(s8)p[0x538] * 12];
            EL(j)->b1 = EL(j)->b540;
            EL(j)->b4DD = 0;
            EL(j)->b553 = i;
            j += 2;
        }
    } else {
        s32 k2, j2; s8 i2;
        i2 = 0;
        k2 = 0;
        j2 = 0;
        for (; i2 < 3; i2++) {
            EL(j2)->b540 = (D_0045E220 + (s8)p[0x538] * 12)[k2];
            EL(j2)->b1 = EL(j2)->b540;
            EL(j2)->b4DD = 0;
            EL(j2)->b553 = i2;
            j2 += 2;
            k2 += 4;
        }
    }
    }
}
