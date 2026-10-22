typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2794;

void func_00388BD0(u8 *p, u8 *q) {
/*B*/
    extern void func_00389170(u8 *);
    extern void func_00389230(u8 *);
    extern s32 func_00175700(u8 *);
    extern void func_001E7F60(u8 *);
    u8 *r = q + 0x2B8;
    u32 t;
    u8 k;
    s16 h;
    if (*(s16 *)(q + 0x2D6) == 0) {
        t = p[5];
        p[5] = t + 1;
        p[6] = 0;
        p[0x13C] = 1;
        func_00389170(p);
        return;
    }
    p[0x13C] = 1;
    if (r[0x19] != 0) {
        p[0x13C] = 0;
    }
    t = p[6];
    if (t == 0) {
        p[6] = t + 1;
        p[0x1B0] = 0x44;
        p[0x1B1] = 0x44;
        p[0x1B5] = 0x49;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        {
            u8 *c = (u8 *)((p[2] << 1) + (u32)D_004C2794);
            *(s16 *)(c + 0x7C) = *(s16 *)(c + 0x7C) + 1;
        }
        *(s16 *)(p + 0x1E) = 2;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        if (*(s16 *)(r + 0x1E) < 11) {
            k = 0x4D;
        } else {
            h = *(s16 *)(p + 0x1E) - 1;
            *(s16 *)(p + 0x1E) = h;
            k = 0x49;
            if (h == 0) {
                *(s16 *)(p + 0x1E) = 2;
                k = 0x45;
            }
        }
        p[0x1B5] = k;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        {
            u8 *c = (u8 *)((p[2] << 1) + (u32)D_004C2794);
            *(s16 *)(c + 0x7C) = *(s16 *)(c + 0x7C) + 1;
        }
    }
    func_00389230(p);
    func_00175700(p);
    func_001E7F60(p);
/*E*/
}
