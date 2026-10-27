struct Object;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00285D20(u8 *p) {
    extern void func_0015D010();
    extern void func_001757E0();
    u32 v[4];
    f32 f;
    s8 a;
    s16 x;
    u8 *q;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x6C) = 0xBF092492;
    f = 0.0f;
    a = *(s8 *)(p + 0x1E7);
    if (a >= 0) {
        if (p[0x1E6] != 0) f = 6.666666507720947f; else f = -6.666666507720947f;
        if (a != 0) f = -f;
    }
    *(f32 *)(p + 0x5C) = f;
    if (p[0x22] & 1) {
        x = p[0x1E6] ^ 1;
        *(s16 *)(p + 0x140) = x;
        p[0x1E6] = x;
        q = *(u8 **)(p + 0x1DC);
        x = q[0x1E6] ^ 1;
        *(s16 *)(q + 0x140) = x;
        (*(u8 **)(p + 0x1DC))[0x1E6] = x;
    }
    v[0] = 0x413AAAAA;
    v[1] = 0x433C9249;
    v[2] = 0;
    func_0015D010(p, v);
    p[0x1B4] = 0xA;
    func_001757E0(p, 0xF, 1);
}

void func_00174910(u8 *p, s32 a) {
    extern f32 func_00417500(s16);
    extern f32 func_00417440(s16);
    f32 c = 256.0f * (f32)a;
    s16 ang = ((0x28 - p[0x22]) & 0x1F) << 11;
    *(f32 *)(p + 0x5C) = *(f32 *)(p + 0x68) + 1.6666666269302368f * (c * (1000.0f * func_00417500(ang)) / 100000.0f / 256.0f);
    *(f32 *)(p + 0x60) = *(f32 *)(p + 0x6C) + 2.142857074737549f * (c * (1000.0f * func_00417440(ang)) / 125000.0f / 256.0f);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
}

extern void (*D_004454C0[])();
void func_0015F020(u8 *p) {
    extern void func_003DAA40(struct Object *);
    u8 *t = *(u8 **)(p + 0x18);
    u32 a;
    u32 b;
    if (t[0] == 0) {
        func_003DAA40((struct Object *)p);
        return;
    }
    *(f32 *)(p + 0x34) = *(f32 *)(t + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(t + 0x38);
    a = t[0x14C];
    if ((s32)a > 0x50) {
        b = t[0x14D];
        *(f32 *)(p + 0x38) += *(f32 *)(t + 0x54) * (2.142857074737549f * (2.0f * (f32)((s32)(a - b) / 5)));
    } else {
        *(f32 *)(p + 0x38) += 30.0f + 2.142857074737549f * (f32)a * *(f32 *)(t + 0x54);
    }
    D_004454C0[p[4]](p);
}

typedef struct { s16 a, b; } PAIR;
extern PAIR D_0044A900[];
void func_0019C610(u8 *p) {
    extern void func_0019C750();
    u8 *s = *(u8 **)(p + 0x18);
    f32 c;
    p[0x24] = *(s8 *)(s + 0x24);
    *(s8 *)(p + 0x31) = -1;
    if (s[0x2B8] == 0) {
        p[4]++;
        func_0019C750(p);
        return;
    }
    p[0x13C] = 0;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    if ((*(u8 **)(p + 0x18))[0x15B] != 0) {
        p[0x13C] = 1;
        c = 1.6666666269302368f * (f32)D_0044A900[(*(u8 **)(p + 0x18))[0x15B]].a;
        if (*(s16 *)(*(u8 **)(p + 0x18) + 0x140) != 0) c = -c;
        *(f32 *)(p + 0x34) += c;
        *(f32 *)(p + 0x38) -= 2.142857074737549f * (f32)D_0044A900[(*(u8 **)(p + 0x18))[0x15B]].b;
    }
    if ((*(u8 **)(p + 0x18))[0x169] >= 7) p[0x13C] = 0;
    if (*(s8 *)(*(u8 **)(p + 0x18) + 0x13C) == 0) p[0x13C] = 0;
}
