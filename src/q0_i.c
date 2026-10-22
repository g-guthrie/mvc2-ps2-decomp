typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { u8 a[6]; } E6;
extern E6 D_0044C0E0[];
extern V3 D_004B38E0;

void func_001BD6C0(u8 *p, void *q_context) {
    u8 *q = (u8 *)q_context;
    extern void func_00175580(u8 *, s32, u8, s32);
    f32 f;
    s16 v;
    if (*(s8 *)(q + 0x151) == 0 || q[4] > 0) {
        p[4]++;
        p[0x13C] = 0;
        return;
    }
    if (p[5] == 0) {
        p[5]++;
        *(u32 *)(p + 0x118) = 0x3F800000;
        *(s16 *)(p + 0x1C) = 10;
    } else {
        f = *(f32 *)(p + 0x118);
        *(f32 *)(p + 0x118) += -f / (f32)*(s16 *)(p + 0x1C);
        v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v == 0) {
            p[4]++;
            p[0x13C] = 0;
            return;
        }
    }
    *(s16 *)(p + 0x140) = *(s16 *)(q + 0x140);
    *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
    func_00175580(p, 0x1B, *((u8 *)&D_0044C0E0[p[0x20]] + 5), *(s8 *)(q + 0x150));
}

void func_00224E90(u8 *p) {
    extern void func_00175700();
    extern void func_00224BB0(u8 *);
    extern void func_00356330();
    extern s32 func_0018AB10(u8 *);
    extern void func_00175910(u8 *, s32, s32, s32);
    s16 v;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700();
    func_00224BB0(p);
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        func_00356330();
    }
    if (*(s16 *)(p + 0x1E) >= 0) {
        if (func_0018AB10(p) != 0) {
            *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1E) - 1;
            *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 1;
        }
    }
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v > 0) return;
    p[0x40D] = 0;
    p[0x40C] = 0;
    p[0x33B] = 0;
    p[0x33C] = 0;
    p[6]++;
    *(s16 *)(p + 0x1C) = 0x3C;
    if (p[0x20D] != 2) {
        func_00175910(p, 0x16, 6, *(s8 *)(p + 0x150));
        return;
    }
    func_00175910(p, 0x16, 7, *(s8 *)(p + 0x150));
}

void func_0014FED0(u8 *p, s32 b, s32 c) {
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_0014FFF0();
    extern void func_00150520(u8 *, f32, f32, f32);
    u8 *o;
    f32 one;
    if ((o = func_003DA750(0, 0xD, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_0014FFF0;
        *(s32 *)(o + 0xD0) = 0x431;
        switch (c) {
        case 0:
            *(u32 *)(o + 0x34) = 0xC0FDC28F;
            break;
        case 1:
            *(u32 *)(o + 0x34) = 0xC0E8F5C3;
            break;
        case 2:
            *(u32 *)(o + 0x34) = 0xC0D428F6;
            break;
        }
        *(u32 *)(o + 0x38) = 0x3EC28F5C;
        *(u32 *)(o + 0x3C) = 0x3D8F5C29;
        *(s16 *)(o + 0x1E) = b;
        one = 1.0f;
        o[0x23] = c;
        func_00150520(o, one, one, 0.0f);
        *(V3 *)(o + 0x50) = D_004B38E0;
        *(u8 **)(o + 0xC8) = p + 0x88;
        *(u8 **)(o + 0x18) = p;
    }
}

void func_00225840(u8 *p) {
    extern void func_001266A0();
    extern void func_0015D010(u8 *, u32 *);
    extern void func_0018C6E0(void *);
    extern void func_001757E0(u8 *, s32, s32);
    u32 v[4];
    func_001266A0(p, 5, 5);
    if (*(u32 *)(*(u8 **)(p + 0x1DC) + 0x42C) & 0x4000000) *(u32 *)(*(u8 **)(p + 0x1DC) + 0x38) = 0x42F44924;
    if (*(u32 *)(*(u8 **)(p + 0x1DC) + 0x428) & 0x10000000) *(u32 *)(*(u8 **)(p + 0x1DC) + 0x38) = 0x41F00000;
    if (*(u32 *)(*(u8 **)(p + 0x1DC) + 0x428) & 0x20000000) *(u32 *)(*(u8 **)(p + 0x1DC) + 0x38) = 0x4284DB6D;
    if (*(u32 *)(*(u8 **)(p + 0x1DC) + 0x428) & 0x400000) *(u32 *)(*(u8 **)(p + 0x1DC) + 0x38) = 0x41F00000;
    if (*(u32 *)(*(u8 **)(p + 0x1DC) + 0x42C) & 0x2000000) *(u32 *)(*(u8 **)(p + 0x1DC) + 0x38) = 0x42340000;
    if (*(u32 *)(*(u8 **)(p + 0x1DC) + 0x428) & 0x80) *(u32 *)(*(u8 **)(p + 0x1DC) + 0x38) = 0x42340000;
    v[0] = 0xC2960000;
    v[1] = 0x432B6DB6;
    func_0015D010(p, v);
    p[0x1B4] = 0xA;
    func_0018C6E0(p);
    p[6] = 0;
    func_001757E0(p, 0xF, 1);
}
