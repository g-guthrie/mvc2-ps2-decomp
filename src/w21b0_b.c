typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3b;
extern s8 D_004D1900;
extern V3b D_00444BA0;



void func_002F6620(u8 *p) {
    extern s8 func_00175700(u8 *);
    extern void func_002F6450(u8 *);
    extern void func_00126400();
    extern void func_001E3A40(u8 *);
    s32 v;
    if (p[7] == 0) {
        if (*(s8 *)(p + 0x151) > 0) {
            *(s8 *)(p + 0x151) = 0;
            v = *(s16 *)(p + 0x140) ^ 1;
            *(s16 *)(p + 0x140) = v;
            *(s8 *)(p + 0x1E6) = *(s8 *)(p + 0x140);
        }
        if (*(s8 *)(p + 0x151) >= 0) {
            func_00175700(p);
        }
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
            *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
            p[7]++;
            p[0x20D] = 0;
        }
    } else {
        if (func_00175700(p) < 0) {
            func_002F6450(p);
            return;
        }
        if (p[0x15B] != 0) {
            (*(u8 **)(p + 0x1DC))[0x20A] = 0xB;
            (*(u8 **)(p + 0x1DC))[0x1B5] = p[0x15B];
            *(u8 **)(*(u8 **)(p + 0x1DC) + 0x1C8) = p;
            p[0x15B] = 0;
            func_00126400();
            func_001E3A40(*(u8 **)(p + 0x1DC));
        }
    }
}
