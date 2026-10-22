typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

extern void func_00135DB0(s32);
extern u8 *D_004C2794;
extern u8 *D_004C2840;
void func_003D8B70(void) {
    s32 x = *(s8 *)(D_004C2794 + 0x3E);
    if (x < 0) {
        func_00135DB0(0);
    } else {
        s32 m = *(s8 *)(D_004C2840 + 0x88);
        if (m == 3) {
            func_00135DB0(x + 6);
        } else if (m & (1 << x)) {
            func_00135DB0(4);
        } else {
            func_00135DB0(5);
        }
    }
}

extern void func_00161510();
extern void func_00161410();
extern u8 D_004D18D8[];
void func_00161380(void) {
    u8 *g = D_004C2840;
    if (*(s8 *)(g + 0xB0)) {
        if (D_004D18D8[0]) {
            func_00161510();
        } else {
            func_00161410();
        }
    } else {
        switch (*(s8 *)(g + 0x9C) & 0xF) {
        case 4:
            func_00161510();
            break;
        default:
            func_00161410();
            break;
        }
    }
}

extern void *func_003DA750(s32, s32, s32);
extern void func_0013FF00();
extern u8 *D_004C2818;
extern void func_00170DF0(u32);
void func_0013FE60(u8 *a, V3 *b) {
    u8 *r = func_003DA750(0, 0xD, 1);
    if (r) {
        r[0x13C] = 1;
        *(void **)(r + 0x10) = func_0013FF00;
        *(s16 *)(r + 0xCC) = 5;
        *(u8 **)(r + 0x84) = D_004C2818;
        *(u8 **)(r + 0xD0) = a;
        if (b) *(V3 *)(r + 0x34) = *b;
        func_00170DF0((u32)*(u8 **)(D_004C2818 + 0x14) + 0x384);
    }
}
