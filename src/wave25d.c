typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct Rec8 { float a, b; } Rec8;
int func_00175670(u8 *p) {
    int result = 0;
    Rec8 *record;
    if (--*(s8 *)(p + 0x152) == 0) {
        do {
            *(Rec8 **)(p + 0x164) = *(Rec8 **)(p + 0x164) + 1;
            result = (s8)(*(s8 *)(p + 0x153) & 0x80);
            if (result) {
                record = *(Rec8 **)(p + 0x164);
                record = (Rec8 *)(*(u8 **)(p + 0x178) + *(int *)record);
                *(Rec8 **)(p + 0x164) = record;
            }
            record = *(Rec8 **)(p + 0x164);
            *(Rec8 *)(p + 0x150) = *record;
            *(int *)(p + 0x158) = 0;
            *(int *)(p + 0x15C) = 0;
            *(int *)(p + 0x160) = 0;
        } while (*(s8 *)(p + 0x152) == 0);
    }
    return result;
}

typedef struct { float x, y, z; } Vec3;
s8 func_00175700(void *a);
void func_001843A0(void *a);
void func_00183920(void *a, Vec3 *v);
void func_001E3710(void *a, s32 b);
void func_002A5970(u8 *a) {
    Vec3 v;
    if (func_00175700(a) < 0) {
        func_001843A0(a);
    } else {
        s32 f = (s8)a[0x151];
        if (f & 1) {
            a[0x151] = 0;
            v.x = -55.0f;
            v.y = 57.85714f;
            v.z = 0.0f;
            func_00183920(a, &v);
        } else if (f & 2) {
            a[0x151] = 0;
            func_001E3710(a, 0x16);
        }
    }
}

void func_001266A0(void *a, s32 b, s32 c);
void func_0020F930(u8 *a) {
    u8 *s;
    if (func_00175700(a) >= 0) {
        if ((s8)a[0x151] != 0) {
            a[0x151] = 0;
            s = *(u8 **)(a + 0x1DC);
            *(u8 **)(s + 0x1C8) = a;
            s[0x20A] = 1;
            s[0x20D] = 2;
            func_001266A0(a, 0, 0);
            s[0x1B5] = 0x20;
        }
    } else {
        *(s32 *)(a + 0x5C) = 0;
        *(s32 *)(a + 0x60) = 0;
        *(s32 *)(a + 0x68) = 0;
        *(s32 *)(a + 0x6C) = 0;
        func_001843A0(a);
    }
}

void func_00248330(void *a);
void func_00244950(u8 *a) {
    switch (a[0x1FC]) {
    case 0:
    case 1:
        if (func_00175700(a) < 0) func_001843A0(a);
        break;
    case 2:
        func_00248330(a);
        if (func_00175700(a) < 0) func_001843A0(a);
        break;
    }
}

typedef struct { u8 p0[6]; u8 f6; u8 p1[0x2D]; float f34; float f38; u8 p2[0x20]; float f5C; float f60; u8 p3[4]; float f68; float f6C; } F1;
void func_0023B7D0(F1 *a) {
    float *px;
    float *pv;
    func_00175700(a);
    px = &a->f5C;
    pv = &a->f68;
    a->f34 += a->f5C;
    a->f5C += a->f68;
    a->f38 += a->f60;
    a->f60 += a->f6C;
    if (a->f5C * a->f68 > 0.0f) {
        u32 n = a->f6;
        a->f6 = n + 1;
        *px = 0.0f;
        *pv = 0.0f;
    }
}

void func_00199DC0(void *a);
extern int func_00174470(const void *);
void func_00199D60(F1 *a) {
    a->f34 += a->f5C;
    a->f5C += a->f68;
    func_00175700(a);
    if (func_00174470(a) == 0) func_00199DC0(a);
}

float func_001AC390(void *b, s32 c);
void func_001AB780(void *a, void *b);
void func_001AB6E0(F1 *a, void *b) {
    u32 n;
    float f;
    n = ((u8 *)a)[7];
    ((u8 *)a)[7] = n + 1;
    f = func_001AC390(b, 0x38);
    if (!(a->f34 < f)) {
        *(s16 *)((u8 *)a + 0x140) = 0;
        a->f5C = -6.6666665f;
    } else {
        *(s16 *)((u8 *)a + 0x140) = 1;
        a->f5C = 6.6666665f;
    }
    *(s32 *)&a->f68 = 0;
    func_001757E0(a, 0x17, 0xC);
    func_001AB780(a, b);
}
