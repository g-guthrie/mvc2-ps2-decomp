typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004F1F45;
extern u8 D_004F1F46;

s32 func_00176AB0(u8 *p)
{
    extern void func_0018F320(u8 *);
    extern s32 func_00175700(u8 *);
    extern void func_001E3A10(u8 *);
    extern void func_00163D70(u8 *);
    extern s32 func_00186CE0(u8 *, s32);
    extern void func_00178E10(u8 *);
    extern void func_00178E60(u8 *);
    extern s32 func_001864A0(u8 *);
    extern void func_001E3B30(u8 *);
    extern void func_00158C70(u8 *, s32);
    extern s32 func_001757E0(u8 *, s32, s32);
    s8 t;
    s16 h;
    u32 n;
    s32 r;
    func_0018F320(p);
    func_00175700(p);
    if (*(s8 *)(p + 0x211) != 0 && p[0x24C] == 0) {
        p[0x24C] = 1;
        func_001E3A10(p);
        func_00163D70(p);
    }
    if (p[0x248] == 0) {
        if (*(s16 *)(p + 0x434) != 0) {
            t = *(s8 *)(p + 0x24D) - 1;
            p[0x24D] = t;
            if (t < 0) {
                p[0x24D] = 0;
                if (*(f32 *)(p + 0x60) < -12.857142448425293f) {
                    return func_00186CE0(p, 0xF);
                }
            }
        }
    }
    if (*(s16 *)(p + 0x1C) != 0) {
        h = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = h;
        if (h == 0)
            func_00178E10(p);
    }
    if (*(s16 *)(p + 0x1E) == 0 && *(f32 *)(p + 0x60) < 0.0f && *(s16 *)(p + 0x1C) == 0) {
        *(s16 *)(p + 0x1E) = 0xFF;
        func_00178E60(p);
    }
    if (*(f32 *)(p + 0x60) < 0.0f) {
        r = func_001864A0(p);
        if (r != 0) {
            if (*(s16 *)(p + 0x434) != 0 && p[0x248] == 0) {
                *(f32 *)(p + 0x60) = -(*(f32 *)(p + 0x60) / 2.0f);
                func_001E3B30(p);
                func_00158C70(p + 0x34, p[2]);
                return func_00186CE0(p, 0xF);
            }
            {
                func_001E3B30(p);
                func_00158C70(p + 0x34, p[2]);
                if (p[0x249] != 0) {
                    D_004F1F45 = (p[0x21B] < 5) ? 1 : 3;
                    D_004F1F46 = 1;
                }
                n = p[6];
                p[6] = n + 1;
                p[0x20D] = 3;
                return func_001757E0(p, 0xD, 0x1A);
            }
        }
    }
}
