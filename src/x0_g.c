typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { s32 x[49]; } S983B0;
typedef struct { f32 x, y, z; } V983B0;
typedef struct { f32 x, y, z; } V343250;
extern V343250 D_00460720[];
extern s32 D_004F1CDC;

void func_001983B0(u8 *d, u8 *s) {
    extern void func_001754A0();
    *(S983B0 *)(d + 0xEC) = *(S983B0 *)(s + 0xEC);
    d[0x13C] = 1;
    d[2] = s[2];
    d[1] = s[1];
    *(f32 *)(d + 0x50) = *(f32 *)(s + 0x50);
    *(f32 *)(d + 0x54) = *(f32 *)(s + 0x54);
    d[0x1B7] = s[0x1B7];
    d[0x1B8] = s[0x1B8];
    *(s8 *)(d + 0x30) = *(s8 *)(s + 0x30);
    *(V983B0 *)(d + 0x50) = *(V983B0 *)(s + 0x50);
    *(s8 *)(d + 0x24) = *(s8 *)(s + 0x24);
    *(s16 *)(d + 0x140) = *(s16 *)(s + 0x140);
    *(f32 *)(d + 0x34) = *(f32 *)(s + 0x34);
    *(f32 *)(d + 0x38) = *(f32 *)(s + 0x38);
    func_001754A0(d, 0x1B, 3);
}

void func_00343250(u8 *p) {
    extern void func_00342880();
    extern void func_003DAA40();
    s32 i;
    switch (p[4]) {
    case 0:
        p[4] = p[4] + 1;
        *(V343250 *)(p + 0x34) = D_00460720[p[0x20]];
        break;
    case 1:
        if (D_004F1CDC == 1) {
            p[4] = p[4] + 1;
            i = 0;
            do {
                func_00342880(p + 0x34, i);
                i++;
            } while (i < 4);
        }
        break;
    case 2:
        func_003DAA40();
        break;
    default:
        break;
    }
}
