typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_002A6180(u8 *p) {
    extern void func_00175700();
    extern void func_001266A0();
    u8 *q;
    f32 x;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        q = *(u8 **)(p + 0x1DC);
        *(u8 **)(q + 0x1C8) = p;
        q[0x20A] = 1;
        q[0x1B5] = 0x20;
        func_001266A0(p, 0, 0);
        p[0x20D] = 2;
        if (p[0x1E6] != 0) {
            x = -6.666666507720947f;
        } else {
            x = 6.666666507720947f;
        }
        *(f32 *)(p + 0x5C) = x;
        if (p[0x1E6] != 0) {
            x = 0.0325520820915699f;
        } else {
            x = -0.0325520820915699f;
        }
        *(f32 *)(p + 0x68) = x;
        *(u32 *)(p + 0x60) = 0x419A4924;
        *(u32 *)(p + 0x6C) = 0xBFC52492;
        if (p[0x1E6] == 0) {
            *(f32 *)(p + 0x34) += 53.33333206176758f;
        } else {
            *(f32 *)(p + 0x34) -= 53.33333206176758f;
        }
        *(f32 *)(p + 0x38) += 51.42856979370117f;
    }
}
