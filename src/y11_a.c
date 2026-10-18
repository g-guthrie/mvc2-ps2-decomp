typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_002AF190(u8 *p) {
    extern void func_00175700();
    extern void func_001CCB70();
    u32 t;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0) {
        t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x34) += (f32)(p[0x1E6] ? 0x20 : -0x20);
        if (*(s32 *)(p + 0xD0) == 0) {
            p[0x2C7] = 1;
            func_001CCB70(p, 6);
        }
    }
}
