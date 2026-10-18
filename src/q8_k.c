typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 a; u8 b; } P2;
extern P2 D_00455050[];
extern u8 D_004D18E6;

void func_0027BC50(u8 *p) {
    extern s32 func_00174170();
    u32 b = *(u16 *)(p + 0x354);
    u8 v;
    if ((b & 0x3F0) != 0) {
        if (b & 0x200) {
            p[0x20] = 5;
        } else if (b & 0x100) {
            p[0x20] = 6;
        } else if (b & 0x80) {
            p[0x20] = 7;
        } else if (b & 0x40) {
            p[0x20] = 8;
        } else if (b & 0x20) {
            p[0x20] = 9;
        } else {
            p[0x20] = 10;
        }
    } else {
        p[0x20] = D_00455050[func_00174170() & 0xF].a;
    }
    if (D_004D18E6 == 0) {
        v = p[0x20];
        if (v == 8 || v == 9 || v == 10) {
            p[0x20] = 5;
        }
    }
}
