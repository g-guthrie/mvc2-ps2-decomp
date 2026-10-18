typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_001757E0(void *p, s32 a, s32 b);
extern void func_0020C520(void *p, s32 a);
extern void func_0020C2F0(void *p, s32 a);

void func_0020C4B0(u8 *p, s32 x) {
    u32 t = p[7];
    p[7] = t + 1;
    *(f32 *)(p + 0x5C) = 0;
    *(f32 *)(p + 0x60) = 0;
    *(f32 *)(p + 0x68) = 0;
    *(f32 *)(p + 0x6C) = 0;
    *(f32 *)(p + 0x60) = -6.428571224f;
    func_001757E0(p, 0x14, 5);
    func_0020C520(p, x);
}

void func_0020C280(u8 *p, s32 x) {
    u32 t = p[7];
    p[7] = t + 1;
    *(f32 *)(p + 0x5C) = 0;
    *(f32 *)(p + 0x60) = 0;
    *(f32 *)(p + 0x68) = 0;
    *(f32 *)(p + 0x6C) = 0;
    *(f32 *)(p + 0x60) = 4.285714149f;
    func_001757E0(p, 0x14, 4);
    func_0020C2F0(p, x);
}

void func_003933A0(u8 *p) {
    p[5] = 8;
    *(*(u8 **)(p + 0x18) + 0x1FE) = 0;
    *(f32 *)(p + 0x5C) = *(s16 *)(p + 0x140) != 0 ? -13.333333015f : 13.333333015f;
    *(f32 *)(p + 0x68) = 0;
    *(f32 *)(p + 0x60) = 15.0f;
    *(f32 *)(p + 0x6C) = -0.5357142687f;
    func_001757E0(p, 0x17, 0xD);
}

extern void func_001E3710(void *p, s32 a);
extern void func_003C4990(void *p, s32 a, s32 b);
void func_003C7B90(u8 *p, u8 *q) {
    if (*(f32 *)(q + 0x38) - *(f32 *)(q + 0x430) < 205.7142792f) {
        u32 t = p[5];
        p[5] = t + 1;
        *(s16 *)(p + 0x1C) = 0x3C;
        func_001E3710(q, 0x4B);
        func_003C4990(p, 0x15, 0);
    }
}

extern void func_00175670(void *p);
void func_001B71C0(u8 *p) {
    func_00175670(p);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (1131.428589f < *(f32 *)(p + 0x38)) {
        u32 t = p[5];
        p[5] = t + 1;
        p[0x13C] = 0;
    }
}

extern void func_0015D010(void *p, f32 *v);
extern void func_0018C6E0(void *p);
void func_00214C20(u8 *p) {
    f32 v[4];
    v[0] = -26.66666603f;
    v[1] = 102.8571396f;
    func_0015D010(p, v);
    p[0x1B4] = 10;
    *(f32 *)(p + 0x5C) = 0;
    *(f32 *)(p + 0x68) = 0;
    *(f32 *)(p + 0x60) /= 2.0f;
    *(f32 *)(p + 0x6C) = -0.803571403f;
    func_0018C6E0(p);
    func_001757E0(p, 0xF, 6);
}
