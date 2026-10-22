typedef float f32;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_0017FB10(u8 *p) {
    extern void func_00183C40(u8 *);
    extern void func_001E04D0(u8 *, u32);
    extern void func_0018F800(u8 *);
    extern void func_00178E10(u8 *);
    extern void func_0018EF20(u8 *);
    extern void func_0017FC40(u8 *);
    s16 v, h;
    u8 *q, *base;
    u32 i;
    p[0x201] = 2;
    func_00183C40(p);
    v = *(s16 *)(p + 0x1E) - 1;
    *(s16 *)(p + 0x1E) = v;
    if (v < 0) {
        if ((h = *(s16 *)(p + 0x1C)) != 0) {
            func_001E04D0(p, (u16)h & 3);
            *(s16 *)(p + 0x1E) = 2;
            v = *(s16 *)(p + 0x1C) - 1;
            *(s16 *)(p + 0x1C) = v;
            if (v == 0) {
                *(s16 *)(p + 0x1E) = 10;
            }
        } else {
            u32 t = p[6];
            p[6] = t + 1;
            q = *(u8 **)(p + 0x1DC);
            i = p[0x1B5];
            base = *(u8 **)(q + 0x184);
            *(u8 **)(p + 0x1D0) = (u8 *)((s32)base + (i & 0x7F) * 28);
            func_0018F800(p);
            if (*(*(u8 **)(p + 0x1D0) + 1) & 0x20) {
                p[0x249] = 1;
            }
            p[0x24D] = *(s8 *)(p + 0x246);
            *(u16 *)(p + 0x140) = p[0x1E6];
            func_00178E10(p);
            func_0018EF20(p);
            *(u32 *)(p + 0x6C) = 0xBF9A4924;
            *(f32 *)(p + 0x5C) = *(f32 *)(p + 0x22C);
            *(f32 *)(p + 0x60) = *(f32 *)(p + 0x230);
            *(s16 *)(p + 0x1C) = 0;
            func_0017FC40(p);
        }
    }
}
