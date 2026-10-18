typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_001B5BD0(u8 *p) {
    extern void func_001754A0(void *, s32, s32);
    f32 v;
    u8 *q = *(u8 **)(p + 0x18);
    u32 t = p[6];
    p[6] = t + 1;
    p[0x13C] = 1;
    if (*(s16 *)(q + 0x140) != 0) {
        v = 13.333333f;
    } else {
        v = -13.333333f;
    }
    *(f32 *)(p + 0x34) += v;
    *(f32 *)(p + 0x38) += 83.571426f;
    func_001754A0(p, 0x1B, 0x22);
    *(u32 *)(p + 0x50) = 0x3F333333;
    *(u32 *)(p + 0x54) = 0x3E99999A;
    p[0x24] = 7;
}

void func_001FB7C0(u8 *p) {
    extern void func_001266A0(void *, s32, s32);
    extern void func_0015D010(void *, void *);
    extern void func_0018C6E0(void *);
    extern void func_001757E0(void *, s32, s32);
    f32 v[4];
    if ((p[0x22] & 2) == 0) {
        u32 t = p[0x1E6];
        p[0x1E6] = t ^ 1;
        *(s16 *)(p + 0x140) = p[0x1E6];
    }
    func_001266A0(p, 5, 5);
    v[0] = -80.0f;
    v[1] = 184.28571f;
    v[2] = 0.0f;
    func_0015D010(p, v);
    p[0x1B4] = 10;
    func_0018C6E0(p);
    func_001757E0(p, 0xF, 3);
}
