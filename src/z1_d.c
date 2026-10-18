typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004D18A0;
extern void (*D_00456940[])(u8 *, u8 *);

void func_0028A3B0(u8 *p) {
    extern void func_0028D8B0(u8 *);
    extern void func_0028D810(u8 *, u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E3210(u8 *, s32);
    extern u8 D_00456160[];
    u8 *q;
    p[0x40C] = 2;
    q = p + 0x2B8;
    p[0x33C] = 5;
    func_0028D8B0(p);
    if (D_004D18A0 >= 5) *(s16 *)(q + 0x1E) = 0;
    if (*(s16 *)(q + 0x1E) == 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[7] = 0;
        q[0x19] = 0;
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        func_0028D810(p, D_00456160);
        func_001757E0(p, 0x16, 0x22);
        func_001E3210(p, 0x2B);
        return;
    }
    D_00456940[p[7]](p, q);
}
