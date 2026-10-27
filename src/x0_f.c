typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004537A0[];
extern u8 D_00454780[];
extern u8 D_004592E0[];

void func_001F6710(u8 *p) {
    extern s8 func_00175700();
    extern void func_001843A0();
    extern void func_001549B0();
    extern void func_001E3710();
    extern void func_001266A0();
    u32 v[4];
    u8 *q;
    if (func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    if (*(s8 *)(p + 0x151) == 2) {
        p[0x151] = 0;
        v[0] = 0xC2D55555;
        v[1] = 0x434DB6DB;
        func_001549B0(p, v);
        func_001E3710(p, 0xC);
    } else if (*(s8 *)(p + 0x151) == 1) {
        p[0x151] = 0;
        func_001266A0(p, 0, 0);
        q = *(u8 **)(p + 0x1DC);
        *(u8 **)(q + 0x1C8) = p;
        q[0x20A] = 1;
        q[0x1B5] = 0x23;
        p[0x1B5] = 0x23;
    }
}

void func_002590A0(u8 *p) {
    extern s32 func_00174170();
    extern s32 func_001841C0();
    u32 h = *(u16 *)(p + 0x354);
    if ((h & 0x3F0) != 0) {
        if ((h & 0x200) != 0) {
            p[0x20] = 5;
        } else if ((h & 0x100) != 0) {
            p[0x20] = 6;
        } else if ((h & 0x80) != 0) {
            p[0x20] = 7;
        } else if ((h & 0x40) != 0) {
            p[0x20] = 8;
        } else if ((h & 0x20) != 0) {
            p[0x20] = 9;
        } else {
            p[0x20] = 0xA;
        }
    } else {
        p[0x20] = D_004537A0[(func_00174170() & 0xF) * 2];
    }
    if (func_001841C0(p) > 1) p[0x20] = 5;
}

s32 func_0026F2B0(u8 *p) {
    extern s32 func_00189310();
    extern void func_0018A990();
    extern void func_00186A60();
    if (func_00189310(p, D_00454780, p + 0x3A8) == 0) return 0;
    if (**(s8 **)(p + 0x420) == 0) return 0;
    if (p[0x20D] == 2) {
        if (p[0x210] == 0) {
            s32 t = *(s8 *)(p + 0x1E8);
            if (t != 0) return 0;
            p[0x1E8] = t + 1;
        }
    }
    func_0018A990(p, p + 0x3A8);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 5;
    func_00186A60(p, 0x1D);
    if (p[0x20D] == 2) p[6] = 1;
    else p[6] = 0;
    return 1;
}

s32 func_002B8720(u8 *p) {
    extern s32 func_00189310();
    extern void func_0018A990();
    extern void func_00186A60();
    if (func_00189310(p, D_004592E0, p + 0x3C0) == 0) return 0;
    if (**(s8 **)(p + 0x420) == 0) return 0;
    if (p[0x20D] == 2) {
        if (p[0x210] == 0) {
            s32 t = *(s8 *)(p + 0x1E8);
            if (t != 0) return 0;
            p[0x1E8] = t + 1;
        }
    }
    func_0018A990(p, p + 0x3C0);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 0xB;
    func_00186A60(p, 0x1D);
    return 1;
}

void func_001F69C0(u8 *p) {
    extern s8 func_00175700();
    extern void func_001843A0();
    extern void func_001549B0();
    extern void func_001E3210();
    extern void func_001266A0();
    u32 v[4];
    u8 *q;
    if (func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    if (*(s8 *)(p + 0x151) == 2) {
        p[0x151] = 0;
        v[0] = 0xC33AAAAA;
        v[1] = 0x43092492;
        func_001549B0(p, v);
        func_001E3210(p, 0x20);
    } else if (*(s8 *)(p + 0x151) == 1) {
        p[0x151] = 0;
        func_001266A0(p, 0, 0);
        q = *(u8 **)(p + 0x1DC);
        *(u8 **)(q + 0x1C8) = p;
        q[0x20A] = 1;
        q[0x1B5] = 0x24;
        p[0x1B5] = 0x24;
    }
}
