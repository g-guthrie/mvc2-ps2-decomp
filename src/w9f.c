typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2840;
extern void func_003D8F90(u8 *p);

void func_003D81C0(u8 *p) {
    s16 v = *(s16 *)(p + 0x12) - 1;
    *(s16 *)(p + 0x12) = v;
    if (v <= 0) {
        func_003D8F90(p);
        if (p[0x45] == 0) {
            *(s16 *)(p + 0x12) = 0x78;
        } else {
            *(s16 *)(p + 0x12) = 1;
        }
        D_004C2840[0x19] = 0;
        p[0] = 2;
    }
}

extern s8 D_004C2A2C;
extern s8 D_004C2A30;
extern u8 D_004B8F10[];
extern void func_003D7350(s32 a, s32 b, s32 c, u8 *d);

void func_003D26F0(void) {
    D_004C2A2C = D_004C2A2C - 1;
    if (D_004C2A2C == 0) {
        D_004C2A30 = 1 - D_004C2A30;
        if (D_004C2A30 == 0) {
            D_004C2A2C = 0xF;
        } else {
            D_004C2A2C = 0x14;
        }
    }
    if (D_004C2A30 == 1) {
        func_003D7350(0x34, 0x62, 0xB, D_004B8F10);
    }
}

extern s32 D_004C283C;
extern u8 D_004C27D0;
extern u8 *func_003DA750();
extern void func_0033DAD0();
extern void func_00170DF0();
extern void func_0033DB90();

void func_0033DA40(void) {
    u8 *o = func_003DA750(0, 6, 1);
    if (o != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_0033DAD0;
        *(s16 *)(o + 0xCC) = 0x22;
        *(s32 *)(o + 0x84) = D_004C283C;
        *(u32 *)(o + 0xD0) = 0x800820;
        *(u32 *)(o + 0x74) = 0x3F000000;
        func_00170DF0(*(s32 *)(o + 0x84));
        if ((D_004C27D0 & 0x1F) == 4) {
            func_0033DB90();
        }
    }
}
