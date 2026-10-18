typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_00445320[];
void func_0015DD60(u8 *p) {
    extern void func_003DAA40(void);
    if (*(s16 *)(p + 0x1C) > 0x14) {
        func_003DAA40();
        return;
    }
    if (*(s16 *)(p + 0x1C) < 8) {
        *(f32 *)(p + 0x38) -= 6.0f;
    }
    *(f32 *)(p + 0x78) = D_00445320[*(s16 *)(p + 0x1C)];
    *(f32 *)(p + 0x7C) = D_00445320[*(s16 *)(p + 0x1C)];
    *(f32 *)(p + 0x80) = D_00445320[*(s16 *)(p + 0x1C)];
    *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 1;
}

void func_002AD410(u8 *p) {
    extern void func_00176160(u8 *, s32, s32, s32);
    extern void func_001CCB70(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    f32 a, b;
    u32 t = p[7];
    p[7] = t + 1;
    p[0x13C] = 1;
    *(f32 *)(p + 0x2B8) = *(f32 *)(p + 0x34);
    b = 320.0f;
    a = 10.0f;
    if (*(s16 *)(p + 0x140) != 0) {
        b = -b;
        a = -a;
    }
    *(f32 *)(p + 0x5C) = a;
    *(f32 *)(p + 0x34) -= b;
    *(s32 *)(p + 0x6C) = 0;
    *(s32 *)(p + 0x60) = 0;
    *(s32 *)(p + 0x68) = 0;
    func_00176160(p, 1, p[0x25] * 2 + 8, 2);
    func_001CCB70(p, 2);
    func_001757E0(p, 0x12, 3);
}
