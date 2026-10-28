typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_00448C30[];

void residual_0017D3B0(u8 *p) {
    if (p[0x20A] == 0x11 || p[0x20A] == 0x12) {
        p[0x201] = 2;
    }
    jtbl_00448C30[p[6]](p);
}

void func_0017D400(u8 *p) {
    extern void func_00191430();
    extern void func_0018F800();
    extern void func_0018F730();
    extern void func_00178E10();
    extern void func_0018EF20();
    extern void func_0017D570();
    u32 t = p[6];
    p[6] = t + 1;
    *(s8 *)(p + 0x24E) += 1;
    p[0x24C] = 0;
    func_00191430(p);
    *(u8 **)(p + 0x1D0) = (u8 *)((u32)*(u8 **)(*(u8 **)(p + 0x1DC) + 0x184) + (p[0x1B5] & 0x7F) * 28);
    if (p[0x20A] == 0x10 || p[0x20A] == 0x12) {
        func_0018F800(p);
    } else {
        func_0018F730(p);
    }
    if ((*(u8 **)(p + 0x1D0))[1] & 0x20) {
        p[0x249] = 1;
    }
    p[0x24D] = *(s8 *)(p + 0x246);
    *(s16 *)(p + 0x140) = p[0x1E6];
    p[0x20D] = 2;
    if (p[0x1B5] & 0x80) {
        p[0x242] = (*(u8 **)(p + 0x1DC))[0x22];
        if (*(s16 *)(*(u8 **)(p + 0x1DC) + 0x140) != 0) {
            p[0x242] = (0x20 - *(s8 *)(p + 0x242)) & 0x1F;
        }
    }
    p[0x13C] = 1;
    *(u32 *)(p + 0x48) = 0;
    *(V3 *)(p + 0x50) = *(V3 *)(p + 0x298);
    *(f32 *)(p + 0x118) = 1.0f;
    func_00178E10(p);
    func_0018EF20(p);
    *(u32 *)(p + 0x6C) = 0xBF9A4924;
    *(f32 *)(p + 0x5C) = *(f32 *)(p + 0x22C);
    *(f32 *)(p + 0x60) = *(f32 *)(p + 0x230);
    *(s16 *)(p + 0x1E) = 0;
    func_0017D570(p);
}
