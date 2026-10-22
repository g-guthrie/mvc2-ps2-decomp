typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_001F2E40(u8 *p) {
    extern void func_001830D0(u8 *, u32 *, s32);
    extern void func_00183D90(u8 *);
    extern void func_00175700(u8 *);
    extern s32 func_001E7FD0(u8 *);
    extern void func_001266A0(u8 *, s32, s32);
    extern void func_0015D010(u8 *, u32 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00185770(u8 *, s32);
    u32 v[3];
    s32 s0;
    *(s16 *)(p + 0x3F8) = 2;
    p[0x40C] = 2;
    p[0x33C] = 5;
    if (*(s8 *)(p + 0x151) > 0) {
        p[0x404] = 0;
        p[0x405] = 0;
        p[0x151] = 0;
        v[0] = 0xC2200000;
        v[1] = 0x431A4924;
        func_001830D0(p, v, 1);
        return;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x405] = (p[0x269] == 6) ? 2 : 0;
    }
    if (*(s8 *)(p + 0x161) == 0) {
        func_00183D90(p);
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    }
    func_00175700(p);
    if ((s0 = func_001E7FD0(p)) != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[7] = 0;
        func_001266A0(p, 5, 5);
        p[0x20B] = 0xCA;
        v[0] = 0xC312AAAA;
        v[1] = 0x432B6DB6;
        func_0015D010(p, v);
        func_001757E0(p, 0xF, 0x25);
        func_00185770(p, s0);
        return;
    }
    if (p[0x1E6] != 0) {
        if (*(s8 *)(p + 0x211) & 1) {
            p[6] = 3;
            func_001757E0(p, 0xF, 0x24);
            return;
        }
    } else {
        if (*(s8 *)(p + 0x211) & 2) {
            p[6] = 3;
            func_001757E0(p, 0xF, 0x24);
            return;
        }
    }
    {
        s16 h = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = h;
        if (h == 0) {
            p[6] = 3;
            func_001757E0(p, 0xF, 0x24);
        }
    }
}
