typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;
typedef signed int s32;

extern s32 func_00175700();
extern void func_001843A0();
extern void func_00183920();
extern void func_001E3710();
extern void func_001830D0();
extern void func_0036BFF0();
extern u8 *D_004C2794;
static void func_002CFA20(u8 *p) {
    s32 command = p[0x15B];
    if (command) {
        u32 offset;
        p[0x1B5] = command;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        offset = p[2] * 2;
        offset += (u32)D_004C2794;
        ++*(s16 *)(offset + 0x7C);
        p[0x15B] = 0;
    }
}

void func_00261890(u8 *p) {
    u32 v[4];
    s8 r = func_00175700(p);
    if (r < 0) {
        func_001843A0(p);
    } else {
        if (*(s8 *)(p + 0x151) == 1) {
            p[0x151] = 0;
            v[0] = 0x42555555;
            v[1] = 0x43092492;
            func_00183920(p, v);
        }
        if (*(s8 *)(p + 0x151) == 2) {
            p[0x151] = 0;
            func_001E3710(p, 0x1A);
        }
    }
}

void func_002CFB80(u8 *p) {
    u32 v[3];
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    func_002CFA20(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        p[0x404] = 0;
        p[0x405] = 0;
        v[0] = 0xC2200000;
        v[1] = 0x424DB6DB;
        v[2] = 0;
        func_001830D0(p, v, 1);
    }
}

extern void func_001D0130();
extern void func_0018F4C0();

void func_00177DC0(u8 *p) {
    u32 t = p[6];
    if (t == 0) {
        p[6] = t + 1;
        *(s16 *)(p + 0x1E) = (p[0x1B7] << 2) + 3;
        *(s16 *)(p + 0x1C) = 0;
    }
    {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v < 0) {
            s16 w;
            *(s16 *)(p + 0x1C) = 2;
            w = *(s16 *)(p + 0x1E);
            if (w != 0) {
                s16 x;
                func_001D0130(p, w & 0xFF);
                x = *(s16 *)(p + 0x1E) - 1;
                *(s16 *)(p + 0x1E) = x;
                if (x == 0)
                    *(s16 *)(p + 0x1C) = 10;
            } else {
                func_0018F4C0(p);
            }
        }
    }
}

void func_00313F10(u8 *p, u8 *q) {
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    if (*(s8 *)(p + 0x151) & 1)
        *(s8 *)(p + 0x151) = *(s8 *)(p + 0x151) & ~1;
    if (*(s8 *)(p + 0x151) & 2)
        *(s8 *)(p + 0x151) = *(s8 *)(p + 0x151) & ~2;
    if (q[0x12] != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        *(s16 *)(p + 0x1C) = 0xC;
    }
}

void func_001D6680(u8 *p, u8 *q) {
    extern s32 func_001745B0();
    extern void func_001D6B20();
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24) + *(s8 *)(p + 0x31);
    if (*(s8 *)(p + 0x24) > 7) *(s8 *)(p + 0x24) = 7;
    if (*(s8 *)(p + 0x24) < 0) *(s8 *)(p + 0x24) = 0;
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    func_00175700(p);
    if (func_001745B0(p) == 0) p[0x13C] = 0;
    else p[0x13C] = 1;
    if (q[0x169] != 0x16) {
        u32 t = p[4];
        p[4] = t + 1;
        func_001D6B20(p, q);
    }
}

void func_0025B280(u8 *p) {
    extern void func_0036A8D0();
    if (*(f32 *)(p + 0x60) < 0.0f) {
        u32 t = p[6];
        p[6] = t + 1;
        func_00175700(p);
        return;
    }
    {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v == 0) {
            func_0036A8D0(p, 1);
            func_0036A8D0(p, 2);
            *(s16 *)(p + 0x1C) = 6;
        }
    }
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(s8 *)(p + 0x151) == 0)
        func_00175700(p);
}

void func_001B7970(u8 *p) {
    extern void func_00175670();
    extern void func_001754A0();
    extern void func_001E3210();
    u8 *q = *(u8 **)(p + 0x18);
    func_00175670(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) < *(f32 *)(q + 0x430)) {
        u32 t = p[4];
        p[4] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
        func_001754A0(p, 0x1B, 6);
        func_001E3210(p, 0x1E);
    }
}

void func_0020CF40(u8 *p, u8 *q) {
    extern void func_0020D2F0();
    extern void func_001757E0();
    s8 v;
    u32 *a, *b;
    func_0020D2F0(p);
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0) {
        a = (u32 *)(p + 0x60);
        b = (u32 *)(p + 0x6C);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
            *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
            *a = 0;
            *b = 0;
        }
    }
    v = *(s8 *)(q + 0xC) - 1;
    *(s8 *)(q + 0xC) = v;
    if (v == 0) {
        u32 t = p[7];
        p[7] = t + 1;
        func_001757E0(p, 0x14, 0xF);
    }
}

void func_002BDB00(u8 *p) {
    extern void func_00183d50();
    extern void func_001757E0();
    u32 *r5c, *r60, *r68, *r6c;
    func_00175700(p);
    r5c = (u32 *)(p + 0x5C);
    r68 = (u32 *)(p + 0x68);
    r60 = (u32 *)(p + 0x60);
    r6c = (u32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        u32 t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        *r5c = 0;
        *r60 = 0;
        *r68 = 0;
        *r6c = 0;
        func_00183d50(p);
        func_001757E0(p, 0x16, 0xE);
    }
}



void func_00315B70(u8 *p) {
    extern void func_00183d50();
    extern void func_001757E0();
    u32 *r5c, *r60, *r68, *r6c;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0) {
        r5c = (u32 *)(p + 0x5C);
        r68 = (u32 *)(p + 0x68);
        r60 = (u32 *)(p + 0x60);
        r6c = (u32 *)(p + 0x6C);
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        if (!(*(f32 *)(p + 0x430) < *(f32 *)(p + 0x38))) {
            u32 t;
            *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
            *r5c = 0;
            *r60 = 0;
            *r68 = 0;
            *r6c = 0;
            func_001757E0(p, 0xF, 5);
            func_00183d50(p);
            t = p[6];
            p[6] = t + 1;
        }
    }
}

void func_0018EE50(u8 *p, u8 *q) {
    extern void func_00185550();
    extern void func_0018F1A0();
    struct { f32 x, y; } t;
    f32 pad[2];
    f32 a, b;
    u8 *r;
    func_00185550(p);
    func_0018F1A0(p[0x242], q, &t);
    r = *(u8 **)(p + 0x1C8);
    if ((*(f32 *)(p + 0x34) < *(f32 *)(r + 0x34) && t.x < 0.0f) || (*(f32 *)(p + 0x34) > *(f32 *)(r + 0x34) && t.x > 0.0f))
        t.x = -t.x;
    *(f32 *)(p + 0x22C) = t.x;
    *(u32 *)(p + 0x68) = 0;
    *(f32 *)(p + 0x230) = t.y;
    *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
}

void func_003142F0(u8 *p, u8 *q) {
    extern void func_003C42D0();
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t;
        p[0x151] = 0;
        t = p[7];
        p[7] = t + 1;
        *(u32 *)(p + 0x5C) = 0xBFD55555;
        if (*(s16 *)(p + 0x140) != 0)
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        func_003C42D0(p, 0, 0);
        func_003C42D0(p, 0, 1);
        func_003C42D0(p, 0, 2);
        func_003C42D0(p, 1, 0);
        q[2] = 1;
        *(s16 *)(p + 0x1E) = 0x10;
        q[0xB] = 0;
    }
}

f32 func_001AC390();

void func_001AB360(u8 *p, u8 *q) {
    f32 v;
    s16 h;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    v = func_001AC390(q, 0x38);
    h = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = h;
    if (h == 0
        || (*(s16 *)(p + 0x140) == 0 && *(f32 *)(p + 0x34) <= v)
        || (*(s16 *)(p + 0x140) != 0 && !(*(f32 *)(p + 0x34) < v))) {
        u32 t = p[7];
        p[7] = t + 1;
        func_001757E0(p, 0x17, 0x1A);
    }
}

typedef struct { s32 pad0[2]; s32 f8; s32 padc; u16 h[16]; } E30;
extern E30 D_004F54D0[];

void func_00255310(u8 *p, u8 i) {
    E30 *e = &D_004F54D0[*(s16 *)(p + 0x13E) + 1];
    e->f8 = 1;
    if (e->h[i] >= 0xF000) e->h[i] |= 0xF000;
    else e->h[i] += 0x1000;
}
