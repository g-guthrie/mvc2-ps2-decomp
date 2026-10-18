typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

s32 func_004000D0(s32 a0) { return a0 + 0x58; }

s32 func_001044C8(s32 descriptor) { return -1; }

s32 func_001044D0(void) { return -1; }
extern struct { u8 pad[0x1C]; u32 f1c; } *D_004C2840;

void func_00370390(u8 *a) {
    extern void func_00370730();
    extern void func_00175700();
    extern void func_001757E0();
    func_00370730(a);
    if ((*(u8 **)(a + 0x18))[0x23] != 0) {
        *(f32 *)(a + 0x38) = *(f32 *)(a + 0x60);
        if (!(D_004C2840->f1c & 1)) *(f32 *)(a + 0x38) -= 5.0f;
    }
    if ((*(u8 **)(a + 0x18))[0x23] == 0) *(f32 *)(a + 0x38) = *(f32 *)(a + 0x60);
    if ((*(u8 **)(a + 0x18))[6] == 8) func_00175700(a);
    if ((*(u8 **)(a + 0x18))[6] == 0xC) {
        u32 t = a[5];
        a[5] = t + 1;
        *(s16 *)(a + 0x1C) = 0x3C;
        *(s32 *)(a + 0x5C) = 0;
        *(s32 *)(a + 0x68) = 0;
        *(s32 *)(a + 0x60) = 0;
        *(u32 *)(a + 0x6C) = 0xBF4DB6DB;
        func_001757E0(a, 0x17, 0x30);
    }
}
