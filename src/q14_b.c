typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_001947C0(u8 *a) {
    u8 *o = *(u8**)(a + 0x14);
    s32 v;
    if (a[0x21] >= 0x80) {
        u32 t = a[5];
        a[5] = t + 1;
    }
    v = 0;
    if (o[0x21] != 0) v = 0x2000;
    if (*(s16*)(o + 0x140) == 0) v = (s16)-v;
    *(f32*)(o + 0x34) = *(f32*)(a + 0x34) + 1.6666666f * (f32)v / 256.0f;
}

extern void func_00175700(u8 *p);
extern u8 D_00456240[];
extern void func_0028D810(u8 *p, u8 *t, s32 n);
extern void func_001830D0(u8 *p, f32 *v, s32 n);
void func_0028B420(u8 *p) {
    u8 *q = p + 0x2B8;
    f32 v[4];
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    if (*(s8*)(p + 0x151) == 0) {
        u32 t = p[6] + 1;
        p[6] = t;
        p[0x404] = 0;
        p[0x405] = 0;
        q[0xB] = 4;
        q[0xA] = 0xFF;
        func_0028D810(p, D_00456240, t);
        v[0] = -13.333333015f;
        v[1] = 105.0f;
        v[2] = 0.0f;
        func_001830D0(p, v, 1);
    }
}

extern void func_001830D0(u8 *p, f32 *v, s32 n);
extern void func_00175700(u8 *p);
void func_0021A640(u8 *p) {
    f32 v[4];
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    if (*(s8*)(p + 0x151) != 0) {
        u32 t = p[7];
        p[7] = t + 1;
        if (p[0x269] != 5) {
            p[0x404] = 0;
            p[0x405] = 0;
            v[0] = -80.0f;
            v[1] = 34.28571320f;
            func_001830D0(p, v, 1);
        }
    }
}

extern void func_00175700(u8 *p);
extern void func_001266A0(u8 *p, s32 a, s32 b);
extern void func_001549B0(u8 *p, f32 *v);
void func_002B1FA0(u8 *p) {
    f32 v[4];
    func_00175700(p);
    if (*(s8*)(p + 0x151) != 0) {
        u32 t;
        func_001266A0(p, 0, 0);
        t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        *(u8**)(*(u8**)(p + 0x1DC) + 0x1C8) = p;
        *(u8*)(*(u8**)(p + 0x1DC) + 0x20A) = 3;
        *(u8*)(*(u8**)(p + 0x1DC) + 0x1B5) = 0x21;
        *(f32*)(p + 0x5C) = 0.0f;
        *(f32*)(p + 0x68) = 0.0f;
        *(f32*)(p + 0x60) = -4.28571415f;
        *(f32*)(p + 0x6C) = -0.803571403f;
        v[0] = 45.0f;
        v[1] = 145.714279f;
        func_001549B0(p, v);
    }
}
