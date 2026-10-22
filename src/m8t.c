typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00175700(void *p);
extern void func_001757E0(void *p, s32 a, s32 b);
extern f32 func_002ADC20(void *p);

void func_002AEE50(u8 *p) {
    func_00175700(p);
    if (func_002ADC20(p) < 0.0f) {
        *(f32 *)(p + 0x5C) = 0.0f;
        *(f32 *)(p + 0x68) = 0.0f;
    }
    if (*(f32 *)(p + 0x60) < 0.0f) {
        u32 t = p[6];
        p[6] = t + 1;
        *(u32 *)(p + 0x60) = 0xC0092492;
        func_001757E0(p, 0x15, (u8)(p[0x1B7] + 8));
    }
}

void func_001D5910(u8 *p, u8 *q) {
    s16 v;
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        u32 t = p[5];
        p[5] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
        *(s16 *)(p + 0x1C) = 0x10;
        func_001757E0(p, 0x12, 7);
    }
}

extern void func_001754A0(void *p, s32 a, s32 b);
extern void func_001C9490(void *p, s32 a, s32 b);

void func_001C98C0(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    s16 v;
    *(s16 *)(p + 0x1C) = 0x81;
    p[0x31] = 10;
    *(u32 *)(p + 0x34) = 0x42555555;
    *(u32 *)(p + 0x38) = 0;
    v = *(s16 *)(q + 0x140);
    *(s16 *)(p + 0x140) = v;
    if (v != 0) {
        *(f32 *)(p + 0x34) = -*(f32 *)(p + 0x34);
    }
    *(f32 *)(p + 0x34) += *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) += *(f32 *)(q + 0x38);
    func_001754A0(p, 0x1B, 0x29);
    func_001C9490(p, 8, 0);
}

extern void func_0015D010(void *p, u32 *v);
extern void func_0018C6E0(void *);

void func_002ED360(u8 *p) {
    u32 v[4];
    if (p[0x22] & 1) {
        u32 t = p[0x1E6];
        p[0x1E6] = t ^ 1;
        *(s16 *)(p + 0x140) = p[0x1E6];
    }
    p[0x1B4] = 10;
    func_001757E0(p, 0xF, 4);
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    v[0] = 0xC2695555;
    v[1] = 0x43070000;
    v[2] = 0;
    func_0015D010(p, v);
    func_0018C6E0(p);
    *(s16 *)(p + 0x1C) = 0x3C;
}
