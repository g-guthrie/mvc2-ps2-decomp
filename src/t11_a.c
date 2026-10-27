typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct V3 { f32 x, y, z; } V3;
extern u16 *D_004C26E8;
extern s16 D_004458C0[];
extern s32 func_0016B240();
extern void func_0016B0C0();
extern s32 func_00174170();
extern void func_00164E90();
extern s32 func_00175670();
extern void func_001B93D0();
extern void func_001754A0();
extern void func_0035E760(u8 *, u8 *);

extern s32 D_004C283C;
extern V3 D_004B7B20;
extern V3 D_004B8290;
extern u8 D_00453980[];
extern u8 D_004571B0[];
extern s16 D_004BF788[4];
extern void func_001830D0();
extern int func_00175700(u8 *);
extern void func_001843A0();
extern void func_0024EDA0();
extern s32 func_00189310();
extern void func_0018A990();
extern void func_00186A60();
extern void func_0031D200();
extern u8 *func_003DA750();
extern void func_003327F0();
extern void func_0033EF10();
extern void func_003349D0();
extern void func_00363C30();
extern void func_00294B20();
extern void func_001830D0();
extern void func_001757E0();
extern void func_001EC280();

void func_0024ED20(u8 *p) {
    switch (p[0x1FC]) {
    case 2:
        func_0024EDA0(p);
        break;
    case 0:
    case 1:
        if ((s8)func_00175700(p) < 0) func_001843A0(p);
        break;
    }
}
void func_0031D160(u8 *p) {
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        u32 t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        func_0031D200(p);
    }
}

void func_00332B90(u8 *p) {
    u8 *o;
    if ((o = func_003DA750(0, 6, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_003327F0;
        *(s16 *)(o + 0xCC) = 4;
        *(s32 *)(o + 0x84) = D_004C283C;
        *(s32 *)(o + 0xD0) = 0x803;
        *(V3 *)(o + 0x34) = D_004B7B20;
        *(u8 **)(o + 0x14) = p;
        *(u8 **)(o + 0xC8) = p + 0x88;
        *(s32 *)(o + 0xDC) = 1;
        *(f32 *)(o + 0x58) = *(f32 *)(*(u8 **)(o + 0x14) + 0x58);
        func_003349D0(o);
    }
}

void func_00364350(u8 *p, u8 *q) {
    s16 t;
    *(f32 *)(p + 0x50) += 0.1f;
    *(f32 *)(p + 0x54) += 0.1f;
    t = *(s16 *)(p + 0x1E) - 1;
    *(s16 *)(p + 0x1E) = t;
    if (t == 0) {
        u32 c = p[6];
        p[6] = c + 1;
        *(u32 *)(p + 0x50) = 0x3F800000;
        *(u32 *)(p + 0x54) = 0x3F800000;
        func_00363C30(q, p, 2, 0);
        func_00363C30(q, p, 2, 1);
    }
}

void func_00292790(u8 *p) {
    u8 *q;
    f32 v[4];
    p[0x40C] = 2;
    q = p + 0x2B8;
    p[0x33C] = 5;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0) {
        u32 t = p[6] + 1;
        p[6] = t;
        p[0x404] = 0;
        p[0x405] = 0;
        q[0xB] = 4;
        q[0xA] = 0xFF;
        func_00294B20(p, D_004571B0, t);
        v[0] = -13.333333f;
        v[1] = 105.0f;
        v[2] = 0.0f;
        func_001830D0(p, v, 1);
    }
}

void func_0033EE60(V3 *s) {
    u8 *o = func_003DA750(0, 6, 1);
    if (o != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_0033EF10;
        *(s16 *)(o + 0xCC) = 5;
        *(s32 *)(o + 0x84) = D_004C283C;
        *(s32 *)(o + 0xD0) = 0xC11;
        *(V3 *)(o + 0x34) = *s;
        *(V3 *)(o + 0x50) = D_004B8290;
        *(u32 *)(o + 0x80) = 0x3F800000;
        *(u32 *)(o + 0x7C) = 0x3F800000;
        *(u32 *)(o + 0x78) = 0x3F800000;
    }
}

void func_001A7750(u8 *p, u8 *q) {
    f32 t;
    func_00175700(p);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    t = *(f32 *)(q + 0x430) + (f32)D_004BF788[p[0x21]];
    if (!(t <= *(f32 *)(p + 0x38))) {
        *(f32 *)(p + 0x38) = t;
        {
            u32 c = p[5];
            p[5] = c + 1;
        }
        func_001757E0(p, 0x13, (u8)(p[0x21] + 3));
    }
}

void func_00206DC0(u8 *p) {
    f32 v[4];
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    p[0x33C] = 5;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 c = p[6];
        p[6] = c + 1;
        p[0x151] = 0;
        *(f32 *)(p + 0x60) = 68.5714264f;
        p[0x404] = 0;
        p[0x405] = 0;
        v[0] = -80.0f;
        v[1] = 85.7142792f;
        v[2] = 0.0f;
        func_001830D0(p, v, 1);
    }
}

void func_001B91D0(u8 *p) {
    if (*D_004C26E8 != *(u16 *)(*(u8 **)(p + 0x18) + 0x168)) {
        func_001B93D0(p);
        return;
    }
    if ((s8)func_00175670() < 0) {
        p[0x13C] = 0;
    }
    p[0x24] = 0;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    if (*(s8 *)(*(u8 **)(p + 0x18) + 0x150) == 1) {
        u32 c = p[4];
        p[4] = c + 1;
        *(*(u8 **)(p + 0x18) + 0x150) = 0;
        func_001754A0(p, 0x1B, 0xE);
        p[0x13C] = 1;
    }
}

void func_001A41E0(u8 *p, u8 *q) {
    s16 t;
    *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    t = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = t;
    if (t == 0) {
        u32 c = p[5];
        p[5] = c + 1;
        func_0035E760(p, q);
    }
    *(f32 *)(p + 0x60) = *(f32 *)(p + 0x5C) / (f32)(u32)p[0x21];
}

s32 func_00164C50(u8 *p, u8 *q) {
    s16 *t;
    if (func_0016B240(p, 0) == 0) return 0;
    func_0016B0C0(p, q, 0);
    func_0016B0C0(p, q, 1);
    t = D_004458C0 + *(s32 *)(p + 0x4C8) * 32;
    t += func_00174170() & 0x1F;
    *(f32 *)(p + 0x460) = 1.66666663f * (f32)*t;
    func_00164E90(p, q);
}
