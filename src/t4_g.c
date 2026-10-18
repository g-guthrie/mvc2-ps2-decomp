typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;
typedef float f32;

extern s32 func_003246B0();
extern s32 func_00175700();
extern void func_00324A30();
extern u32 D_004C2794;

void func_003244D0(u8 *p) {
    s16 *e;
    s16 t;
    if (func_003246B0(p) == 0) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        if ((s8)func_00175700(p) < 0) {
            func_00324A30(p);
            return;
        }
        if (p[0x15B] != 0) {
            p[0x15B] = 0;
            p[0x1B5] = 0x7C;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(u32 *)(p + 0x1D8) = 0;
            e = (s16 *)((p[2] << 1) + D_004C2794);
            t = e[0x3E];
            e[0x3E] = t + 1;
        }
    }
}

extern void func_0015D010();
extern void func_001266A0(void *p, s32 a, s32 b);

void func_003216C0(u8 *p) {
    u32 v[3];
    s16 h;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    h = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = h;
    if (h < 0) {
        p[0x152] = 1;
        v[0] = 0x41D55555;
        v[1] = 0x42892492;
        func_0015D010(p, v);
        p[0x1B4] = 0xA;
        func_001266A0(p, 1, 1);
    }
}

extern s32 func_001BE470(void *p, void *q, s32 m);

void func_001BE700(u8 *p, u8 *q) {
    u32 t;
    s16 h;
    if (q[0x1E4] != 0) {
        p[5] = 0;
        return;
    }
    if ((p[0x23] & 4) == 0) {
        if (func_001BE470(p, q, 4) != 0) {
            t = p[0x23];
            p[0x23] = t | 4;
        }
    }
    if ((p[0x23] & 8) == 0) {
        if (*(s16 *)(p + 0x1C) == 0) {
            if (func_001BE470(p, q, 8) != 0) {
                t = p[0x23];
                p[0x23] = t | 8;
            }
        }
    }
    h = *(s16 *)(p + 0x1C);
    if (h != 0) {
        *(s16 *)(p + 0x1C) = h - 1;
    }
}

extern u8 D_00474160[];
extern u8 D_00474170[];
extern void func_00175910(void *p, s32 a, s32 b, s32 c);

void func_003B70F0(u8 *p) {
    u8 *s = p + 0x88;
    u8 *q = *(u8 **)(p + 0x14);
    u8 *r = q + 0x88;
    u32 t = p[0x21];
    if (t == 0) {
        func_00175910(p, 0x17, 0, *(s8 *)(*(s16 *)s + (D_00474170 + *(s8 *)(s + 0xA))));
    } else if ((u8)t == *(s16 *)(r + 6)) {
        func_00175910(p, 0x17, 0, *(s8 *)(*(s16 *)s + (D_00474160 + *(s8 *)(s + 0xA))));
    } else {
        func_00175910(p, 0x17, 0, *(s8 *)(*(s16 *)s + (D_00474170 + *(s8 *)(s + 0xA))));
    }
}

extern void func_001830D0();
extern void func_001757E0(void *p, s32 a, s32 b);
extern void func_001CEAE0();

void func_002CA0F0(u8 *p) {
    u32 v[3];
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    if ((s8)func_00175700(p) < 0) {
        t = p[7];
        p[7] = t + 1;
        p[0x404] = 0;
        p[0x405] = 0;
        v[0] = 0x42855555;
        v[1] = 0x431A4924;
        v[2] = 0;
        func_001830D0(p, v, 1);
        func_001757E0(p, 0x15, 0x28);
        func_001CEAE0(p, 8);
    }
}

extern void func_001843A0();
extern void func_00126400();
extern void func_001549B0();
extern void func_001E3710();

void func_002B7EE0(u8 *p) {
    u32 v[3];
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        *(u8 **)(*(u8 **)(p + 0x220) + 0x1C8) = p;
        (*(u8 **)(p + 0x220))[0x20A] = 1;
        (*(u8 **)(p + 0x220))[0x1B5] = 0x22;
        func_00126400();
        (*(u8 **)(p + 0x220))[0x1E6] = p[0x1E6];
        {
            u8 *q = *(u8 **)(p + 0x220);
            u32 t = q[0x1E6];
            q[0x1E6] = t ^ 1;
        }
        v[0] = 0xC2960000;
        v[1] = 0x43340000;
        v[2] = 0;
        func_001549B0(p, v);
        func_001E3710(p, 1);
    }
}

extern u8 *D_004C2840;
extern s8 D_00462AF0[];
extern s8 D_00462B20[];

void func_00354000(u8 *p, u8 *q) {
    s32 a;
    s32 b;
    p[0x13C] = 0;
    b = *(s8 *)q;
    if (b == 0) {
        a = *(u16 *)(q + 0xA);
        if ((((*(u32 *)(D_004C2840 + 0x1C)) & 1) ^ (p[0x21] >> 1)) != 0) {
            a = *(u16 *)(q + 0xC) + 0x14;
        }
        if (q[1] != 0) {
            a = D_00462B20[a];
            if (a < 0) return;
        } else {
            a = D_00462AF0[a];
            if (a < 0) return;
        }
    } else {
        a = (s8)b;
    }
    p[0x13C] = 1;
    func_00175910(p, 0x16, 2, a);
}
