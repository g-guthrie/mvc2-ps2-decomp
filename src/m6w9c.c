typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;


extern void func_00175670(void *);
void func_001BCCE0(u8 *p, u8 *q) {
    func_00175670(p);
    if (q[0x1E4] != 0) {
        p[5] = 3;
        *(u32 *)(p + 0x64) = 0x3D4CCCCD;
    } else {
        f32 v;
        *(f32 *)(p + 0x118) += *(f32 *)(p + 0x64);
        v = *(f32 *)(p + 0x118);
        if (!(v < 0.300000012f)) {
            p[5]++;
            *(f32 *)(p + 0x118) = 0.300000012f;
        }
    }
}

extern s32 func_00175700(void *);
extern void func_001E3710(void *, s32);
extern void func_001843A0(void *);
extern void func_0015B200(void *, void *, s32, s32);
extern void func_00126400(void);
void func_003198E0(u8 *p) {
    f32 v[4];
    s8 r = func_00175700(p);
    if (r < 0) {
        func_001E3710(p, 0x3A);
        func_001843A0(p);
    } else if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        func_001E3710(p, 0x4A);
        v[0] = *(f32 *)(p + 0x34);
        v[1] = 34.28571319580078f + *(f32 *)(p + 0x38);
        func_0015B200(p, v, 3, 0x37A);
        func_00126400();
    }
}

extern void func_001AC3F0(void *, void *);
void func_001AABA0(u8 *p, u8 *q) {
    s8 r;
    *(f32 *)(p + 0x50) -= 0.03571428731083870f;
    *(f32 *)(p + 0x54) -= 0.03571428731083870f;
    if (*(f32 *)(p + 0x50) < 1.0f) {
        *(f32 *)(p + 0x50) = 1.0f;
        *(f32 *)(p + 0x54) = 1.0f;
    }
    r = func_00175700(p);
    if (r < 0) {
        *(u32 *)(p + 0x50) = 0x3F800000;
        *(u32 *)(p + 0x54) = 0x3F800000;
        func_001AC3F0(p, q);
    }
}
