typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

extern s32 func_00175700();
extern void func_001830D0(void *p, V3 *v, s32 n);
void func_002370F0(u8 *p) {
    V3 v;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        p[7] = 0;
        p[0x404] = 0;
        p[0x405] = 0;
        v.x = 20.0f;
        v.y = 132.8571319580078f;
        func_001830D0(p, &v, 1);
    }
}

void func_00318620(u8 *p) {
    V3 v;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        p[6]++;
        p[0x404] = 0;
        p[0x405] = 0;
        v.x = -10.0f;
        v.y = 282.8571472167969f;
        v.z = 0.0f;
        func_001830D0(p, &v, 1);
    }
}

void func_001EBFB0(u8 *p) {
    V3 v;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        p[6]++;
        p[0x151] = 0;
        p[0x404] = 0;
        p[0x405] = 0;
        v.x = 40.0f;
        v.y = 137.14285278320312f;
        v.z = 0.0f;
        func_001830D0(p, &v, 1);
    }
}

extern void func_003CA780(void *p);
extern void func_001757E0(void *p, s32 a, s32 b);
void func_00323D20(u8 *p) {
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    if (p[7] == 0) {
        u32 t = p[7];
        p[7] = t + 1;
        func_003CA780(p);
    }
    {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v <= 0) {
            p[0x40D] = 0;
            p[0x40C] = 0;
            p[0x33B] = 0;
            p[0x33C] = 0;
            p[6]++;
            *(s16 *)(p + 0x1C) = 0x3C;
            func_001757E0(p, 0x16, 3);
        }
    }
}
