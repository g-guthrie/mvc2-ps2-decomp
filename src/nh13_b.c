typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2794 __attribute__((section(".sdata")));

static void func_001EC280(u8 *p) {
    u8 v = p[0x15B];
    u32 offset;
    if (v) {
        p[0x15B] = 0;
        p[0x1B5] = v;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        offset = p[2] * 2;
        offset += (u32)D_004C2794;
        ++*(s16 *)(offset + 0x7C);
        *(u16 *)(p + 0x1C0) = 0x10;
    }
}

void func_001EC5B0(u8 *p)
{
    extern s8 func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);

    p[0x40C] = 2;
    p[0x33C] = 5;
    if (func_00175700(p) < 0) {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v <= 0) {
            u32 t = p[6];
            p[6] = t + 1;
            func_001757E0(p, 0x16, 8);
        }
        return;
    }
    *(f32 *)(p + 0x38) += -0.1339285671710968f;
    func_001EC280(p);
}
