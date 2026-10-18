typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004B1130[];
extern u8 D_0043E3D0[];

void func_001347D0(u8 *p) {
    extern void func_0011F938();
    s8 buf[4];
    volatile u8 *d;
    s32 i;
    func_0011F938(buf, D_004B1130, *(s16 *)(p + 0x13E));
    d = p + 0x1B0;
    for (i = 0; i < 3; i++) {
        *d = buf[i] - 0x30;
        if ((s32)*d < 0) *d = 0xFF;
        d++;
    }
    *(u8 **)(p + 0xD8) = D_0043E3D0;
    *(u32 *)(p + 0xDC) = 0;
}
