typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern u8 *func_003DA750(void *, int, int);
extern void func_0015DE10(u8 *);
extern u32 D_004C2838 __attribute__((section(".sdata")));

void func_0015DA50(f32 *pos, s16 face)
{
    u8 *p = func_003DA750(0, 8, 1);
    if (p) {
        u32 add;
        p[0x13C] = 1;
        *(void (**)(u8 *))(p + 0x10) = func_0015DE10;
        *(s16 *)(p + 0xCC) = 0xAA;
        *(u32 *)(p + 0x84) = D_004C2838;
        *(f32 *)(p + 0x34) = pos[0];
        *(f32 *)(p + 0x38) = pos[1];
        *(f32 *)(p + 0x3C) = pos[2];
        *(u32 *)(p + 0xD0) = 0x800415;
        *(s16 *)(p + 0x1C) = 0;
        *(s16 *)(p + 0x1E) = 0;
        *(f32 *)(p + 0x74) = 1.0f;
        *(u32 *)(p + 0x78) = 0;
        *(u32 *)(p + 0x7C) = 0;
        *(u32 *)(p + 0x80) = 0;
        *(f32 *)(p + 0x50) = 1.0f;
        *(f32 *)(p + 0x54) = 1.0f;
        *(f32 *)(p + 0x58) = 1.0f;
        *(s16 *)(p + 0x140) = face;
        add = 0;
        if (*(s16 *)(p + 0x140) != 0)
            add = 0x8000;
        *(u32 *)(p + 0x44) += add;
    }
}
