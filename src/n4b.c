typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0016F4D0(u32 *p, u8 *base) {
    u8 *q = base;
    p[0] += (u32)p;
    p[1] += (u32)p;
    p[2] += (u32)p;
    while (*(s16 *)q > 0) {
        *(u32 *)(q + 8) += (u32)base;
        q += 16;
    }
}

extern void func_00123090();
extern void func_00151A20();
extern void func_003CE980();
extern void func_00152180();
extern u8 *D_004D36D0;

void func_001528B0(void) {
    u8 *p;
    func_00123090();
    func_00151A20(0x10);
    p = D_004D36D0;
    while (p != 0) {
        if (*(s8 *)(p + 0x13C) != 0) {
            if (*(u32 *)(p + 0xD8) != 0) {
                func_003CE980(p);
            } else {
                func_00152180(p, 0x10);
            }
        }
        p = *(u8 **)(p + 0xC);
    }
}
