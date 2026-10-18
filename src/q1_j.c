typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { u8 b[28]; } E28;
typedef struct { u8 pad[0x184]; E28 *tab; } T184;

extern u8 *D_004C2840;

void func_00157740(u8 *p)
{
    extern void func_003DAA40();
    extern void func_00157330();
    extern void func_00157540();
    extern void func_001576A0();
    s32 i;
    if (*(s8 *)(D_004C2840 + 0x91) != 0) {
        p[0x13C] = 0;
        func_003DAA40(p);
        return;
    }
    switch (p[4]) {
    case 0:
        i = 0;
        do {
            func_00157330(p + 0x34, i);
            i++;
        } while (i < 13);
        p[4]++;
        break;
    case 1: {
        s16 v = *(s16 *)(p + 0x1C) + 1;
        *(s16 *)(p + 0x1C) = v;
        if (v > 15) {
            func_00157540(p + 0x34);
            p[4]++;
            *(s16 *)(p + 0x1C) = 0;
        }
        break;
    }
    case 2:
        func_001576A0(p + 0x34);
        func_003DAA40(p);
        break;
    }
}

typedef struct { s32 x[49]; } S49;
extern u8 *D_004C29A4;

#define SRC (*(u8 **)(p + 0x18))

void func_003817F0(u8 *p)
{
    extern void func_00381420();
    extern void func_00381920();
    p[4]++;
    *(S49 *)(p + 0xEC) = *(S49 *)(SRC + 0xEC);
    p[0x13C] = 1;
    p[2] = SRC[2];
    p[1] = SRC[1];
    *(f32 *)(p + 0x50) = *(f32 *)(SRC + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(SRC + 0x54);
    p[0x1B7] = SRC[0x1B7];
    p[0x1B8] = SRC[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(SRC + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(SRC + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(SRC + 0x24);
    p[0x13C] = 0;
    p[0x24] = 0xB;
    *(u32 *)(p + 0x50) = 0x3F866666;
    *(u32 *)(p + 0x54) = 0x3F800000;
    D_004C29A4[3] = 0;
    D_004C29A4[1] = 1;
    *(s16 *)(p + 0x1E) = 1;
    func_00381420(p);
    func_00381920(p);
}
