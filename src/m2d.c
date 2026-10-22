typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_0015D010(void *p, f32 *v);
extern void func_0018C6E0(void *);
extern void func_001757E0(void *p, s32 a, s32 b);

void func_00277B40(u8 *p) {
    f32 v[4];
    v[0] = -123.33332825f;
    v[1] = 162.857131958f;
    func_0015D010(p, v);
    func_0018C6E0(p);
    p[0x1B4] = 10;
    func_001757E0(p, 0xF, 1);
}

void func_001B59B0(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    *(f32 *)(p + 0x50) = 0.3f + *(f32 *)(q + 0x2C4);
    *(f32 *)(p + 0x54) = 0.2f + *(f32 *)(q + 0x2CC);
    if (*(f32 *)(q + 0x2C4) >= 1.0f) {
        p[4] = 2;
        p[0x13C] = 0;
        return;
    }
}

extern s8 func_00175670(void *p);
void func_001BB830(u8 *p, u8 *q) {
    s8 r;
    f32 v = *(f32 *)(p + 0x118) - 0.00952380895614624f;
    *(f32 *)(p + 0x118) = v;
    if (v < 0.0f) {
        *(f32 *)(p + 0x118) = 0.0f;
    }
    *(s32 *)(q + 0x2D8) = 2;
    r = func_00175670(p);
    if (r < 0) {
        p[4] = 2;
        p[0x13C] = 0;
        *(s32 *)(p + 0x118) = 0;
        return;
    }
}
