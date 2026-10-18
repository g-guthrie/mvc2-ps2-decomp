typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_00162DF0();
extern void func_00162BB0();
void func_00162FE0(s32 a, s32 b, s32 c, s32 d, s32 e) {
    func_00162DF0();
    func_00162BB0(a, b, c, d, e);
}
extern s32 func_00189310();
extern void func_00186A60();
extern u8 D_0045BA70[];
s32 func_002F2570(u8 *a) {
    if (func_00189310(a, D_0045BA70, a + 0x3B8) == 0) {
        return 0;
    } else {
        a[0x1B7] = 2;
        a[5] = 0;
        a[7] = 0;
        a[6] = 0;
        a[0x1FD] = 4;
        func_00186A60(a, 0x15);
        return 1;
    }
}
extern void func_00175700();
extern u32 func_00174170();
void func_0027EAA0(u8 *a) {
    func_00175700(a);
    if (*(s8 *)(a + 0x151) != 0) {
        u32 t;
        *(s8 *)(a + 0x151) = 0;
        t = a[6];
        a[6] = t + 1;
        *(s16 *)(a + 0x1C) = 3;
        *(s16 *)(a + 0x1E) = 0;
        a[0x22] = func_00174170();
        a[0x21] = func_00174170() % 3;
    }
}
extern void func_00175700();
void func_00204C60(u8 *a) {
    func_00175700(a);
    if (*(s8 *)(a + 0x151) != 0) {
        u32 t = a[6];
        a[6] = t + 1;
        *(u32 *)(a + 0x5C) = 0xC1200000;
        *(u32 *)(a + 0x68) = 0x3F200000;
        if (*(s16 *)(a + 0x140) != 0) {
            *(f32 *)(a + 0x5C) = -*(f32 *)(a + 0x5C);
            *(f32 *)(a + 0x68) = -*(f32 *)(a + 0x68);
        }
    }
}
extern void func_001E3A10();
extern void func_00158C70();
extern u8 D_004F1F45;
extern u8 D_004F1F46;
void func_00177D50(u8 *a) {
    u8 v;
    func_001E3A10(a);
    func_00158C70(a + 0x34, a[2]);
    if (a[0x21B] < 5) v = 1;
    else v = 3;
    D_004F1F45 = v;
    D_004F1F46 = 1;
    *(u32 *)(a + 0x60) = 0x412B6DB6;
    *(u32 *)(a + 0x6C) = 0xBF4DB6DB;
}
extern s8 D_00583B96[];
extern s8 D_00583B94[];
void func_00137F20(u8 i) {
    s8 *p = D_00583B96 + i;
    s8 *q;
    if (*p >= 8) *p = 0;
    if (*p < 0) *p = 7;
    q = D_00583B94 + i;
    if (*q >= 8) *q = 0;
    if (*q < 0) *q = 7;
}
extern void func_00183050();
extern u8 D_004D18A0;
extern void (*D_004488E8[])(u8 *);
void func_001769F0(u8 *a) {
    func_00183050(a);
    if (D_004D18A0 < 5 && a[0x1F0] != 0 && a[0x24C] != 0) a[0x201] = 2;
    D_004488E8[a[6]](a);
}
extern void func_001266A0();
extern void func_0015D010();
extern void func_0018C6E0();
extern void func_001757E0();
void func_001F6430(u8 *a) {
    u32 v[4];
    a[0x1B4] = 10;
    a[7] = 0;
    a[6] = 0;
    func_001266A0(a, 5, 5);
    v[0] = 0xC32D5555;
    v[1] = 0x43092492;
    func_0015D010(a, v);
    func_0018C6E0(a);
    func_001757E0(a, 0xF, 2);
}
extern void func_00175700();
extern void func_001DF4E0();
extern u8 D_004D18A0;
void func_00318180(u8 *a) {
    if (D_004D18A0 >= 2) {
        func_00175700();
        if (*(s8 *)(a + 0x151) != 0) {
            u32 t;
            *(s8 *)(a + 0x151) = 0;
            t = a[6];
            a[6] = t + 1;
            func_001DF4E0(a);
            *(s16 *)(a + 0x1C) = -1;
        } else if (a[0x15B] != 0) {
            a[0x15B] = 0;
        }
    }
}
extern void func_0022B340();
void func_0022B2C0(u8 *a) {
    f32 z = 0.0f;
    a[0x40C] = 2;
    a[0x33C] = 5;
    *(f32 *)(a + 0x34) += *(f32 *)(a + 0x5C);
    *(f32 *)(a + 0x5C) += *(f32 *)(a + 0x68);
    if (*(f32 *)(a + 0x68) * *(f32 *)(a + 0x5C) >= z) {
        u32 t;
        a[0x40D] = 0;
        a[0x40C] = 0;
        a[0x33B] = 0;
        a[0x33C] = 0;
        t = a[6];
        a[6] = t + 1;
        *(f32 *)(a + 0x68) = z;
        *(f32 *)(a + 0x5C) = z;
    }
    func_0022B340(a);
}
extern void func_002CF110();
void func_002CF090(u8 *a) {
    f32 z = 0.0f;
    f32 *p = (f32 *)(a + 0x5C);
    f32 *q = (f32 *)(a + 0x68);
    a[0x40C] = 2;
    a[0x33C] = 5;
    *(f32 *)(a + 0x34) += *(f32 *)(a + 0x5C);
    *(f32 *)(a + 0x5C) += *(f32 *)(a + 0x68);
    if (*(f32 *)(a + 0x68) * *(f32 *)(a + 0x5C) > z) {
        u32 t = a[6];
        a[6] = t + 1;
        *p = z;
        *q = z;
        a[0x40D] = 0;
        a[0x40C] = 0;
        a[0x33B] = 0;
        a[0x33C] = 0;
    }
    func_002CF110(a);
}
extern void func_001757E0();
void func_00252600(u8 *a, u8 *b) {
    a[0x40C] = 2;
    a[0x33C] = 5;
    if (*(s8 *)(b + 0xB) < 0) {
        a[6] = 0xF;
        func_001757E0(a, 0x16, 0xD);
    }
    if (*(s8 *)(b + 0xB) >= 2) {
        u32 t = a[6];
        a[6] = t + 1;
        a[0x40D] = 0;
        a[0x40C] = 0;
        a[0x33B] = 0;
        a[0x33C] = 0;
    }
}
void func_00127BB0(u8 *p) {
    s32 i = 0;
    s32 off = 0;
    do {
        u8 *e = p + off;
        u8 *x = e + 0xC;
        if (e[0xC] == 0x2A) {
            u8 *y = e + 0xD;
            if (e[0xD] == 0x2A) {
                u8 *z = e + 0xE;
                if (e[0xE] == 0x2A) {
                    *x = 2;
                    *y = 0;
                    *z = 15;
                }
            }
        }
        i++;
        off += 0x18;
    } while (i < 0x15);
}
