typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C26D8;
extern u8 *D_004C2840;
extern void func_001754A0();
extern s8 func_00175670(u8 *);
extern void func_001AFC90(u8 *);

void func_001AF9B0(u8 *a) {
    u32 t = a[5];
    if (t == 0 && *(s8 *)(D_004C26D8 + 0xA) > 0) {
        a[5] = t + 1;
        if (a[0x21] != 0) {
            func_001754A0(a, 0x1B, 0x1D);
        } else {
            func_001754A0(a, 0x1B, 0x1C);
        }
    }
    if (func_00175670(a) < 0) {
        func_001AFC90(a);
    } else {
        a[0x13C] = *(s8 *)(D_004C2840 + 0x1C) & 1;
    }
}
