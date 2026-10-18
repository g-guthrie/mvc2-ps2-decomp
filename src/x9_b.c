typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_002776A0(u8 *p) {
    extern void func_00277790();
    extern s8 func_00175700();
    extern s32 func_00174170();
    extern void func_001757E0();
    func_00277790(p);
    if (func_00175700(p) < 0) {
        if (*(s8 *)(p + 0x539) != 0) {
            if (func_00174170() & 1) {
                *(s32 *)(p + 0x2C0) = 1;
            } else {
                *(s32 *)(p + 0x2C0) = 0;
            }
        }
        if (*(s32 *)(p + 0x2C0) > 0) {
            func_001757E0(p, 0x14, 3);
            *(s32 *)(p + 0x2C0) = 0;
        } else {
            u32 t = p[6];
            p[6] = t + 1;
            func_001757E0(p, 0x14, 4);
            *(s32 *)(p + 0x2C0) = 0;
        }
    }
}
