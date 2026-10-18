typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 *D_004C2840;
extern void (*D_004C1D70[2])(u8 *p, u8 *q);
extern void (*D_004C1B90[2])(u8 *p, u8 *q);
extern void (*D_004C1C78[2])(u8 *p);
extern void func_0013D350(u8 *p);
extern void func_003DAA40(u8 *p);
extern void func_001619B0(void);
extern void func_001618E0(void);

void func_0014A0E0(u8 *p) {
    u8 *q = p + 0x74;
    if (*(s8 *)(D_004C2840 + 4) == p[0x20]) {
        *(u32 *)(q + 4) = 0x3F800000;
        *(u32 *)(q + 8) = 0x3F800000;
        *(u32 *)(q + 12) = 0x3F800000;
    } else {
        *(u32 *)(q + 4) = 0x3F4CCCCD;
        *(u32 *)(q + 8) = 0x3F4CCCCD;
        *(u32 *)(q + 12) = 0x3F4CCCCD;
    }
}

void func_00386210(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    s32 n = *(s8 *)(p + 0x1B4);
    if (n) {
        *(s8 *)(p + 0x1B4) = n - 1;
    } else {
        D_004C1D70[p[5]](p, q);
    }
}

void func_0035E090(u8 *p, u8 *q) {
    if (q[0x169] != 0x16) {
        p[4]++;
    } else {
        D_004C1B90[p[5]](p, q);
    }
}

void func_0036B790(u8 *p) {
    D_004C1C78[p[5]](p);
    if (*(s8 *)(p + 0x1B2)) {
        p[4]++;
        p[0x13C] = 0;
    }
}
