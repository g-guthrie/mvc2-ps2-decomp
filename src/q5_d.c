typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct S18 {
    u8 p0[0x34]; f32 f34; u8 p38[0x30]; f32 f68;
    u8 p6c[0x15C]; struct S18 *p1c8; struct S18 *p1cc;
    u8 p1d0[0x50]; struct S18 *p220; u8 p224[8]; f32 f22c;
} S18;
extern s16 D_00446C40[];

void func_0018CC30(S18 *a, s32 idx) {
    S18 *t;
    f32 f;
    if (a->p1c8 == a->p1cc) {
        *((u8 *)a->p1cc + 0x209) = 3;
    }
    t = a->p1cc;
    if (t == 0) {
        t = a->p220;
    }
    f = 1.6666666269302368f * (f32)D_00446C40[(u8)idx] / 256.0f;
    *(u32 *)&a->f68 = 0x3FFD5555;
    if (a->f34 < t->f34) {
        f = -f;
        a->f68 = -a->f68;
    }
    a->f22c = f;
}

typedef struct { f32 x, y, z; } V3;
extern s8 func_00175700(u8 *);
extern void func_001830D0();

void func_0031F290(u8 *a) {
    a[0x40C] = 2;
    a[0x33C] = 5;
    a[0x405] = (a[0x269] == 6) ? 2 : 0;
    func_00175700(a);
    if (*(s8 *)(a + 0x151) & 2) {
        V3 v;
        u32 n = a[7] + 1;
        a[7] = n;
        a[0x151] = 0;
        a[0x404] = 0;
        a[0x405] = 0;
        v.x = 3.3333332538604736f;
        v.y = 102.85713958740234f;
        func_001830D0(a, &v, 1, n);
    }
}


void func_00318F50(u8 *a) {
    s8 c;
    a[0x40C] = 2;
    a[0x33C] = 5;
    a[0x405] = (a[0x269] == 6) ? 2 : 0;
    func_00175700(a);
    c = *(s8 *)(a + 0x2B8) - 1;
    *(s8 *)(a + 0x2B8) = c;
    if (c < 0) {
        V3 v;
        u32 n = a[6];
        a[6] = n + 1;
        a[0x404] = 0;
        a[0x405] = 0;
        v.y = 171.42855834960938f;
        v.x = 0.0f;
        v.z = 0.0f;
        func_001830D0(a, &v, 1);
    }
}

void func_002062D0(u8 *a) {
    a[0x40C] = 2;
    a[0x33C] = 5;
    a[0x405] = (a[0x269] == 6) ? 2 : 0;
    a[0x33C] = 5;
    func_00175700(a);
    if (*(s8 *)(a + 0x151) == 0) {
        V3 v;
        u32 n = a[6] + 1;
        a[6] = n;
        a[0x1B2] = 0;
        a[0x404] = 0;
        a[0x405] = 0;
        v.x = -26.66666603088379f;
        v.y = 274.28570556640625f;
        v.z = 0.0f;
        func_001830D0(a, &v, 1, n);
    }
}
